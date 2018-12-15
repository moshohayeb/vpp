/*
 * xfilter.c - skeleton vpp engine plug-in
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
#include <xfilter/xfilter.h>

#include <vlibapi/api.h>
#include <vlibmemory/api.h>
#include <vpp/app/version.h>

/* define message IDs */
#include <xfilter/xfilter_msg_enum.h>

/* define message structures */
#define vl_typedefs
#include <xfilter/xfilter_all_api_h.h>
#undef vl_typedefs

/* define generated endian-swappers */
#define vl_endianfun
#include <xfilter/xfilter_all_api_h.h>
#undef vl_endianfun

/* instantiate all the print functions we know about */
#define vl_print(handle, ...) vlib_cli_output(handle, __VA_ARGS__)
#define vl_printfun
#include <xfilter/xfilter_all_api_h.h>
#undef vl_printfun

/* Get the API version number */
#define vl_api_version(n, v) static u32 api_version = (v);
#include <xfilter/xfilter_all_api_h.h>
#undef vl_api_version

#define REPLY_MSG_ID_BASE sm->msg_id_base
#include <vlibapi/api_helper_macros.h>

xfilter_main_t xfilter_main;

/* List of message types that this plugin understands */

#define foreach_xfilter_plugin_api_msg \
    _(XFILTER_ENABLE_DISABLE, xfilter_enable_disable)

/* Action function shared between message handler and debug CLI */

int
xfilter_enable_disable(xfilter_main_t *sm, u32 sw_if_index,
        int enable_disable)
{
    vnet_sw_interface_t *sw;
    int rv = 0;

    /* Utterly wrong? */
    if (pool_is_free_index(sm->vnet_main->interface_main.sw_interfaces,
                sw_if_index))
    {
        return VNET_API_ERROR_INVALID_SW_IF_INDEX;
    }

    /* Not a physical port? */
    sw = vnet_get_sw_interface(sm->vnet_main, sw_if_index);
    if (sw->type != VNET_SW_INTERFACE_TYPE_HARDWARE) {
        return VNET_API_ERROR_INVALID_SW_IF_INDEX;
    }

    vnet_feature_enable_disable("device-input", "xfilter",
            sw_if_index, enable_disable, 0, 0);

    /* Send an event to enable/disable the periodic scanner process */
    vlib_process_signal_event(sm->vlib_main, xfilter_periodic_node.index,
            XFILTER_EVENT_PERIODIC_ENABLE_DISABLE,
            (uword) enable_disable);

    return rv;
}

static clib_error_t *
xfilter_enable_disable_command_fn(vlib_main_t *vm,
        unformat_input_t                      *input,
        vlib_cli_command_t                    *cmd)
{
    xfilter_main_t *sm = &xfilter_main;
    u32 sw_if_index = ~0;
    int enable_disable = 1;

    int rv;

    while (unformat_check_input(input) != UNFORMAT_END_OF_INPUT) {
        if (unformat(input, "disable")) {
            enable_disable = 0;
        } else if (unformat(input, "%U", unformat_vnet_sw_interface,
                           sm->vnet_main, &sw_if_index))
        { } else {
            break;
        }
    }

    if (sw_if_index == ~0) {
        return clib_error_return(0, "Please specify an interface...");
    }

    rv = xfilter_enable_disable(sm, sw_if_index, enable_disable);

    switch (rv) {
    case 0:
    {
        break;
    }

    case VNET_API_ERROR_INVALID_SW_IF_INDEX:
    {
        return clib_error_return
                   (0, "Invalid interface, only works on physical ports");
        break;
    }

    case VNET_API_ERROR_UNIMPLEMENTED:
    {
        return clib_error_return(0, "Device driver doesn't support redirection");
        break;
    }

    default:
        return clib_error_return(0, "xfilter_enable_disable returned %d",
                rv);
    }
    return 0;
}

/* *INDENT-OFF* */
VLIB_CLI_COMMAND (xfilter_enable_disable_command, static) = 
{
  .path = "xfilter enable-disable",
  .short_help =
  "xfilter enable-disable <interface-name> [disable]",
  .function = xfilter_enable_disable_command_fn,
};
/* *INDENT-ON* */

/* API message handler */
static void
vl_api_xfilter_enable_disable_t_handler(vl_api_xfilter_enable_disable_t *mp)
{
    vl_api_xfilter_enable_disable_reply_t *rmp;
    xfilter_main_t *sm = &xfilter_main;
    int rv;

    rv = xfilter_enable_disable(sm, ntohl(mp->sw_if_index),
            (int) (mp->enable_disable));

    REPLY_MACRO(VL_API_XFILTER_ENABLE_DISABLE_REPLY);
}

/* Set up the API message handling tables */
static clib_error_t *
xfilter_plugin_api_hookup(vlib_main_t *vm)
{
    xfilter_main_t *sm = &xfilter_main;

#define _(N, n)                                               \
    vl_msg_api_set_handlers((VL_API_ ## N + sm->msg_id_base), \
            #n,                                               \
            vl_api_ ## n ## _t_handler,                       \
            vl_noop_handler,                                  \
            vl_api_ ## n ## _t_endian,                        \
            vl_api_ ## n ## _t_print,                         \
            sizeof(vl_api_ ## n ## _t), 1);
    foreach_xfilter_plugin_api_msg;
#undef _

    return 0;
}

#define vl_msg_name_crc_list
#include <xfilter/xfilter_all_api_h.h>
#undef vl_msg_name_crc_list

static void
setup_message_id_table(xfilter_main_t *sm, api_main_t *am)
{
#define _(id, n, crc) vl_msg_api_add_msg_name_crc(am, #n  #crc, id + sm->msg_id_base);
    foreach_vl_msg_name_crc_xfilter;
#undef _
}

static clib_error_t *
xfilter_init(vlib_main_t *vm)
{
    xfilter_main_t *sm = &xfilter_main;
    clib_error_t   *error = 0;
    u8 *name;

    sm->vlib_main = vm;
    sm->vnet_main = vnet_get_main();

    name = format(0, "xfilter_%08x%c", api_version, 0);

    /* Ask for a correctly-sized block of API message decode slots */
    sm->msg_id_base = vl_msg_api_get_msg_ids
                          ((char *) name, VL_MSG_FIRST_AVAILABLE);

    error = xfilter_plugin_api_hookup(vm);

    /* Add our API messages to the global name_crc hash table */
    setup_message_id_table(sm, &api_main);

    vec_free(name);

    return error;
}

clib_error_t *
xfilter_early_init(vlib_main_t *vm)
{
    printf("in xfilter early init\n");
    return NULL;
}


static clib_error_t *
xfilter_config(vlib_main_t *vm, unformat_input_t *input)
{
    printf("in xfilter config func\n");
    return NULL;
}

VLIB_CONFIG_FUNCTION(xfilter_config, "xfilter");
VLIB_INIT_FUNCTION(xfilter_init);

/* *INDENT-OFF* */
VNET_FEATURE_INIT (xfilter, static) =
{
  .arc_name = "device-input",
  .node_name = "xfilter",
  .runs_before = VNET_FEATURES ("ethernet-input"),
};
/* *INDENT-ON */

/* *INDENT-OFF* */
VLIB_PLUGIN_REGISTER () = 
{
  .version = VPP_BUILD_VER,
  .description = "xfilter plugin description goes here",
  .early_init = "xfilter_early_init",
};
/* *INDENT-ON* */

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
