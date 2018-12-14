/*
 * znode.c - skeleton vpp engine plug-in
 *
 * Copyright (c) <current-year> <your-organization>
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <vnet/vnet.h>
#include <vnet/plugin/plugin.h>
#include <znode/znode.h>

#include <vlibapi/api.h>
#include <vlibmemory/api.h>
#include <vpp/app/version.h>

/* define message IDs */
#include <znode/znode_msg_enum.h>

/* define message structures */
#define vl_typedefs
#include <znode/znode_all_api_h.h>
#undef vl_typedefs

/* define generated endian-swappers */
#define vl_endianfun
#include <znode/znode_all_api_h.h>
#undef vl_endianfun

/* instantiate all the print functions we know about */
#define vl_print(handle, ...) vlib_cli_output (handle, __VA_ARGS__)
#define vl_printfun
#include <znode/znode_all_api_h.h>
#undef vl_printfun

/* Get the API version number */
#define vl_api_version(n,v) static u32 api_version=(v);
#include <znode/znode_all_api_h.h>
#undef vl_api_version

#define REPLY_MSG_ID_BASE sm->msg_id_base
#include <vlibapi/api_helper_macros.h>

znode_main_t znode_main;

/* List of message types that this plugin understands */

#define foreach_znode_plugin_api_msg                           \
_(ZNODE_ENABLE_DISABLE, znode_enable_disable)

/* Action function shared between message handler and debug CLI */

int znode_enable_disable (znode_main_t * sm, u32 sw_if_index,
                                   int enable_disable)
{
  vnet_sw_interface_t * sw;
  int rv = 0;

  /* Utterly wrong? */
  if (pool_is_free_index (sm->vnet_main->interface_main.sw_interfaces,
                          sw_if_index))
    return VNET_API_ERROR_INVALID_SW_IF_INDEX;

  /* Not a physical port? */
  sw = vnet_get_sw_interface (sm->vnet_main, sw_if_index);
  if (sw->type != VNET_SW_INTERFACE_TYPE_HARDWARE)
    return VNET_API_ERROR_INVALID_SW_IF_INDEX;

  vnet_feature_enable_disable ("device-input", "znode",
                               sw_if_index, enable_disable, 0, 0);

  /* Send an event to enable/disable the periodic scanner process */
  vlib_process_signal_event (sm->vlib_main, znode_periodic_node.index, 
                            ZNODE_EVENT_PERIODIC_ENABLE_DISABLE, 
                            (uword)enable_disable);

  return rv;
}

static clib_error_t *
znode_enable_disable_command_fn (vlib_main_t * vm,
                                   unformat_input_t * input,
                                   vlib_cli_command_t * cmd)
{
  znode_main_t * sm = &znode_main;
  u32 sw_if_index = ~0;
  int enable_disable = 1;

  int rv;

  while (unformat_check_input (input) != UNFORMAT_END_OF_INPUT) 
    {
      if (unformat (input, "disable"))
        enable_disable = 0;
      else if (unformat (input, "%U", unformat_vnet_sw_interface,
                         sm->vnet_main, &sw_if_index))
        ;
      else
        break;
  }

  if (sw_if_index == ~0)
    return clib_error_return (0, "Please specify an interface...");

  rv = znode_enable_disable (sm, sw_if_index, enable_disable);

  switch(rv) 
    {
  case 0:
    break;

  case VNET_API_ERROR_INVALID_SW_IF_INDEX:
    return clib_error_return
      (0, "Invalid interface, only works on physical ports");
    break;

  case VNET_API_ERROR_UNIMPLEMENTED:
    return clib_error_return (0, "Device driver doesn't support redirection");
    break;

  default:
    return clib_error_return (0, "znode_enable_disable returned %d",
                              rv);
    }
  return 0;
}

/* *INDENT-OFF* */
VLIB_CLI_COMMAND (znode_enable_disable_command, static) = 
{
  .path = "znode enable-disable",
  .short_help =
  "znode enable-disable <interface-name> [disable]",
  .function = znode_enable_disable_command_fn,
};
/* *INDENT-ON* */

/* API message handler */
static void vl_api_znode_enable_disable_t_handler
(vl_api_znode_enable_disable_t * mp)
{
  vl_api_znode_enable_disable_reply_t * rmp;
  znode_main_t * sm = &znode_main;
  int rv;

  rv = znode_enable_disable (sm, ntohl(mp->sw_if_index),
                                      (int) (mp->enable_disable));

  REPLY_MACRO(VL_API_ZNODE_ENABLE_DISABLE_REPLY);
}

/* Set up the API message handling tables */
static clib_error_t *
znode_plugin_api_hookup (vlib_main_t *vm)
{
  znode_main_t * sm = &znode_main;
#define _(N,n)                                                  \
    vl_msg_api_set_handlers((VL_API_##N + sm->msg_id_base),     \
                           #n,					\
                           vl_api_##n##_t_handler,              \
                           vl_noop_handler,                     \
                           vl_api_##n##_t_endian,               \
                           vl_api_##n##_t_print,                \
                           sizeof(vl_api_##n##_t), 1);
    foreach_znode_plugin_api_msg;
#undef _

    return 0;
}

#define vl_msg_name_crc_list
#include <znode/znode_all_api_h.h>
#undef vl_msg_name_crc_list

static void
setup_message_id_table (znode_main_t * sm, api_main_t * am)
{
#define _(id,n,crc)   vl_msg_api_add_msg_name_crc (am, #n  #crc, id + sm->msg_id_base);
  foreach_vl_msg_name_crc_znode ;
#undef _
}

static clib_error_t * znode_init (vlib_main_t * vm)
{
  znode_main_t * sm = &znode_main;
  clib_error_t * error = 0;
  u8 * name;

  sm->vlib_main = vm;
  sm->vnet_main = vnet_get_main();

  name = format (0, "znode_%08x%c", api_version, 0);

  /* Ask for a correctly-sized block of API message decode slots */
  sm->msg_id_base = vl_msg_api_get_msg_ids
      ((char *) name, VL_MSG_FIRST_AVAILABLE);

  error = znode_plugin_api_hookup (vm);

  /* Add our API messages to the global name_crc hash table */
  setup_message_id_table (sm, &api_main);

  vec_free(name);

  return error;
}

VLIB_INIT_FUNCTION (znode_init);

/* *INDENT-OFF* */
VNET_FEATURE_INIT (znode, static) =
{
  .arc_name = "device-input",
  .node_name = "znode",
  .runs_before = VNET_FEATURES ("ethernet-input"),
};
/* *INDENT-ON */

/* *INDENT-OFF* */
VLIB_PLUGIN_REGISTER () = 
{
  .version = VPP_BUILD_VER,
  .description = "znode plugin description goes here",
};
/* *INDENT-ON* */

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
