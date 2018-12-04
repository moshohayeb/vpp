/*
 * Copyright (c) 2018 Cisco and/or its affiliates.
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

#ifndef __GBP_ENDPOINT_GROUP_H__
#define __GBP_ENDPOINT_GROUP_H__

#include <plugins/gbp/gbp_types.h>

#include <vnet/fib/fib_types.h>

/**
 * An Endpoint Group representation
 */
typedef struct gpb_endpoint_group_t_ {
    /**
     * ID
     */
    epg_id_t gepg_id;

    /**
     * Bridge-domain ID the EPG is in
     */
    u32 gepg_bd;

    /**
     * route-domain/IP-table ID the EPG is in
     */
    u32 gepg_rd[FIB_PROTOCOL_IP_MAX];

    /**
     * resulting FIB indices
     */
    u32 gepg_fib_index[FIB_PROTOCOL_IP_MAX];

    /**
     * Is the EPG an external/NAT
     */
    u8 gepg_is_ext;

    /**
     * the uplink interface dedicated to the EPG
     */
    u32 gepg_uplink_sw_if_index;

    /**
     * The DPO used in the L3 path for forwarding internal subnets
     */
    dpo_id_t gepg_dpo[FIB_PROTOCOL_IP_MAX];
} gbp_endpoint_group_t;

/**
 * EPG DB, key'd on EGP-ID
 */
typedef struct gbp_endpoint_group_db_t_ {
    uword *gepg_hash;
} gbp_endpoint_group_db_t;

extern int gbp_endpoint_group_add(epg_id_t epg_id, u32 bd_id, u32 ip4_table_id, u32 ip6_table_id, u32 uplink_sw_if_index);
extern void gbp_endpoint_group_delete(epg_id_t epg_id);

typedef int (*gbp_endpoint_group_cb_t)(gbp_endpoint_group_t *gbpe, void *ctx);
extern void gbp_endpoint_group_walk(gbp_endpoint_group_cb_t bgpe, void *ctx);

extern gbp_endpoint_group_t *gbp_endpoint_group_find(epg_id_t epg_id);

/**
 * DP functions and databases
 */
extern gbp_endpoint_group_db_t gbp_endpoint_group_db;
extern gbp_endpoint_group_t *gbp_endpoint_group_pool;

always_inline u32
gbp_epg_itf_lookup(epg_id_t epg)
{
    uword *p;

    p = hash_get(gbp_endpoint_group_db.gepg_hash, epg);

    if (NULL != p) {
        gbp_endpoint_group_t *gepg;

        gepg = pool_elt_at_index(gbp_endpoint_group_pool, p[0]);
        return (gepg->gepg_uplink_sw_if_index);
    }
    return (~0);
}

always_inline const dpo_id_t *
gbp_epg_dpo_lookup(epg_id_t epg, fib_protocol_t fproto)
{
    uword *p;

    p = hash_get(gbp_endpoint_group_db.gepg_hash, epg);

    if (NULL != p) {
        gbp_endpoint_group_t *gepg;

        gepg = pool_elt_at_index(gbp_endpoint_group_pool, p[0]);
        return (&gepg->gepg_dpo[fproto]);
    }
    return (NULL);
}

#endif

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
