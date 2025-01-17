/* SPDX-License-Identifier: GPL-2.0*/
/*
 * Copyright (c) 2022 nebula-matrix Limited.
 * Author:
 */

#ifndef _NBL_DEF_CHANNEL_H_
#define _NBL_DEF_CHANNEL_H_

#include "nbl_include.h"

#define NBL_CHAN_OPS_TBL_TO_OPS(chan_ops_tbl)	((chan_ops_tbl)->ops)
#define NBL_CHAN_OPS_TBL_TO_PRIV(chan_ops_tbl)	((chan_ops_tbl)->priv)

#define NBL_CHAN_SEND(chan_send, dst_id, mesg_type,						\
		      argument, arg_length, response, resp_length, need_ack)			\
do {												\
	typeof(chan_send)	*__chan_send = &(chan_send);					\
	__chan_send->dstid	= (dst_id);							\
	__chan_send->msg_type	= (mesg_type);							\
	__chan_send->arg	= (argument);							\
	__chan_send->arg_len	= (arg_length);							\
	__chan_send->resp	= (response);							\
	__chan_send->resp_len	= (resp_length);						\
	__chan_send->ack	= (need_ack);							\
} while (0)

#define NBL_CHAN_ACK(chan_ack, dst_id, mesg_type, msg_id, err_code, ack_data, data_length)	\
do {												\
	typeof(chan_ack)	*__chan_ack = &(chan_ack);					\
	__chan_ack->dstid	= (dst_id);							\
	__chan_ack->msg_type	= (mesg_type);							\
	__chan_ack->msgid	= (msg_id);							\
	__chan_ack->err		= (err_code);							\
	__chan_ack->data	= (ack_data);							\
	__chan_ack->data_len	= (data_length);						\
} while (0)

typedef void (*nbl_chan_resp)(void *, u16, u16, void *, u32);

enum {
	NBL_CHAN_RESP_OK,
	NBL_CHAN_RESP_ERR,
};

enum nbl_chan_msg_type {
	NBL_CHAN_MSG_ACK,
	NBL_CHAN_MSG_ADD_MACVLAN,
	NBL_CHAN_MSG_DEL_MACVLAN,
	NBL_CHAN_MSG_ADD_MULTI_RULE,
	NBL_CHAN_MSG_DEL_MULTI_RULE,
	NBL_CHAN_MSG_SETUP_MULTI_GROUP,
	NBL_CHAN_MSG_REMOVE_MULTI_GROUP,
	NBL_CHAN_MSG_REGISTER_NET,
	NBL_CHAN_MSG_UNREGISTER_NET,
	NBL_CHAN_MSG_ALLOC_TXRX_QUEUES,
	NBL_CHAN_MSG_FREE_TXRX_QUEUES,
	NBL_CHAN_MSG_SETUP_QUEUE,
	NBL_CHAN_MSG_REMOVE_ALL_QUEUES,
	NBL_CHAN_MSG_CFG_DSCH,
	NBL_CHAN_MSG_SETUP_CQS,
	NBL_CHAN_MSG_REMOVE_CQS,
	NBL_CHAN_MSG_CFG_QDISC_MQPRIO,
	NBL_CHAN_MSG_CONFIGURE_MSIX_MAP,
	NBL_CHAN_MSG_DESTROY_MSIX_MAP,
	NBL_CHAN_MSG_MAILBOX_ENABLE_IRQ,
	NBL_CHAN_MSG_GET_GLOBAL_VECTOR,
	NBL_CHAN_MSG_GET_VSI_ID,
	NBL_CHAN_MSG_SET_PROSISC_MODE,
	NBL_CHAN_MSG_GET_FIRMWARE_VERSION,
	NBL_CHAN_MSG_GET_QUEUE_ERR_STATS,
	NBL_CHAN_MSG_GET_COALESCE,
	NBL_CHAN_MSG_SET_COALESCE,
	NBL_CHAN_MSG_SET_SPOOF_CHECK_ADDR,
	NBL_CHAN_MSG_SET_VF_SPOOF_CHECK,
	NBL_CHAN_MSG_GET_RXFH_INDIR_SIZE,
	NBL_CHAN_MSG_GET_RXFH_INDIR,
	NBL_CHAN_MSG_GET_RXFH_RSS_KEY,
	NBL_CHAN_MSG_GET_RXFH_RSS_ALG_SEL,
	NBL_CHAN_MSG_GET_PHY_CAPS,
	NBL_CHAN_MSG_GET_PHY_STATE,
	NBL_CHAN_MSG_REGISTER_RDMA,
	NBL_CHAN_MSG_UNREGISTER_RDMA,
	NBL_CHAN_MSG_GET_REAL_HW_ADDR,
	NBL_CHAN_MSG_GET_REAL_BDF,
	NBL_CHAN_MSG_GRC_PROCESS,
	NBL_CHAN_MSG_SET_SFP_STATE,
	NBL_CHAN_MSG_SET_ETH_LOOPBACK,
	NBL_CHAN_MSG_CHECK_ACTIVE_VF,
	NBL_CHAN_MSG_GET_PRODUCT_FLEX_CAP,
	NBL_CHAN_MSG_ALLOC_KTLS_TX_INDEX,
	NBL_CHAN_MSG_FREE_KTLS_TX_INDEX,
	NBL_CHAN_MSG_CFG_KTLS_TX_KEYMAT,
	NBL_CHAN_MSG_ALLOC_KTLS_RX_INDEX,
	NBL_CHAN_MSG_FREE_KTLS_RX_INDEX,
	NBL_CHAN_MSG_CFG_KTLS_RX_KEYMAT,
	NBL_CHAN_MSG_CFG_KTLS_RX_RECORD,
	NBL_CHAN_MSG_ADD_KTLS_RX_FLOW,
	NBL_CHAN_MSG_DEL_KTLS_RX_FLOW,
	NBL_CHAN_MSG_ALLOC_IPSEC_TX_INDEX,
	NBL_CHAN_MSG_FREE_IPSEC_TX_INDEX,
	NBL_CHAN_MSG_ALLOC_IPSEC_RX_INDEX,
	NBL_CHAN_MSG_FREE_IPSEC_RX_INDEX,
	NBL_CHAN_MSG_CFG_IPSEC_TX_SAD,
	NBL_CHAN_MSG_CFG_IPSEC_RX_SAD,
	NBL_CHAN_MSG_ADD_IPSEC_TX_FLOW,
	NBL_CHAN_MSG_DEL_IPSEC_TX_FLOW,
	NBL_CHAN_MSG_ADD_IPSEC_RX_FLOW,
	NBL_CHAN_MSG_DEL_IPSEC_RX_FLOW,
	NBL_CHAN_MSG_NOTIFY_IPSEC_HARD_EXPIRE,
	NBL_CHAN_MSG_GET_MBX_IRQ_NUM,
	NBL_CHAN_MSG_CLEAR_FLOW,
	NBL_CHAN_MSG_CLEAR_QUEUE,
	NBL_CHAN_MSG_GET_ETH_ID,
	NBL_CHAN_MSG_SET_OFFLOAD_STATUS,

	NBL_CHAN_MSG_INIT_OFLD,
	NBL_CHAN_MSG_INIT_CMDQ,
	NBL_CHAN_MSG_DESTROY_CMDQ,
	NBL_CHAN_MSG_RESET_CMDQ,
	NBL_CHAN_MSG_INIT_FLOW,
	NBL_CHAN_MSG_DEINIT_FLOW,
	NBL_CHAN_MSG_OFFLOAD_FLOW_RULE,
	NBL_CHAN_MSG_GET_ACL_SWITCH,
	NBL_CHAN_MSG_GET_VSI_GLOBAL_QUEUE_ID,
	NBL_CHAN_MSG_INIT_REP,
	NBL_CHAN_MSG_GET_LINE_RATE_INFO,

	NBL_CHAN_MSG_REGISTER_NET_REP,
	NBL_CHAN_MSG_UNREGISTER_NET_REP,
	NBL_CHAN_MSG_REGISTER_ETH_REP,
	NBL_CHAN_MSG_UNREGISTER_ETH_REP,
	NBL_CHAN_MSG_REGISTER_UPCALL_PORT,
	NBL_CHAN_MSG_UNREGISTER_UPCALL_PORT,
	NBL_CHAN_MSG_GET_PORT_STATE,
	NBL_CHAN_MSG_SET_PORT_ADVERTISING,
	NBL_CHAN_MSG_GET_MODULE_INFO,
	NBL_CHAN_MSG_GET_MODULE_EEPROM,
	NBL_CHAN_MSG_GET_LINK_STATE,
	NBL_CHAN_MSG_NOTIFY_LINK_STATE,

	NBL_CHAN_MSG_GET_QUEUE_CXT,
	NBL_CHAN_MSG_CFG_LOG,
	NBL_CHAN_MSG_INIT_VDPAQ,
	NBL_CHAN_MSG_DESTROY_VDPAQ,
	NBL_CHAN_GET_UPCALL_PORT,
	NBL_CHAN_MSG_NOTIFY_ETH_REP_LINK_STATE,
	NBL_CHAN_MSG_SET_ETH_MAC_ADDR,
	NBL_CHAN_MSG_GET_FUNCTION_ID,
	NBL_CHAN_MSG_GET_CHIP_TEMPERATURE,

	NBL_CHAN_MSG_DISABLE_PHY_FLOW,
	NBL_CHAN_MSG_ENABLE_PHY_FLOW,
	NBL_CHAN_MSG_SET_UPCALL_RULE,
	NBL_CHAN_MSG_UNSET_UPCALL_RULE,

	NBL_CHAN_MSG_GET_REG_DUMP,
	NBL_CHAN_MSG_GET_REG_DUMP_LEN,

	NBL_CHAN_MSG_CFG_LAG_HASH_ALGORITHM,
	NBL_CHAN_MSG_CFG_LAG_MEMBER_FWD,
	NBL_CHAN_MSG_CFG_LAG_MEMBER_LIST,
	NBL_CHAN_MSG_CFG_LAG_MEMBER_UP_ATTR,
	NBL_CHAN_MSG_ADD_LAG_FLOW,
	NBL_CHAN_MSG_DEL_LAG_FLOW,

	NBL_CHAN_MSG_SWITCHDEV_INIT_CMDQ,
	NBL_CHAN_MSG_SWITCHDEV_DEINIT_CMDQ,
	NBL_CHAN_MSG_SET_TC_FLOW_INFO,
	NBL_CHAN_MSG_UNSET_TC_FLOW_INFO,
	NBL_CHAN_MSG_INIT_ACL,
	NBL_CHAN_MSG_UNINIT_ACL,

	NBL_CHAN_MSG_CFG_LAG_MCC,

	NBL_CHAN_MSG_REGISTER_VSI2Q,
	NBL_CHAN_MSG_SETUP_Q2VSI,
	NBL_CHAN_MSG_REMOVE_Q2VSI,
	NBL_CHAN_MSG_SETUP_RSS,
	NBL_CHAN_MSG_REMOVE_RSS,
	NBL_CHAN_MSG_GET_REP_QUEUE_INFO,
	NBL_CHAN_MSG_CTRL_PORT_LED,
	NBL_CHAN_MSG_NWAY_RESET,
	NBL_CHAN_MSG_SET_INTL_SUPPRESS_LEVEL,
	NBL_CHAN_MSG_GET_ETH_STATS,
	NBL_CHAN_MSG_GET_MODULE_TEMPERATURE,
	NBL_CHAN_MSG_GET_BOARD_INFO,

	NBL_CHAN_MSG_GET_P4_USED,
	NBL_CHAN_MSG_GET_VF_BASE_VSI_ID,

	NBL_CHAN_MSG_ADD_LLDP_FLOW,
	NBL_CHAN_MSG_DEL_LLDP_FLOW,

	NBL_CHAN_MSG_CFG_ETH_BOND_INFO,
	NBL_CHAN_MSG_CFG_DUPPKT_MCC,

	NBL_CHAN_MSG_ADD_ND_UPCALL_FLOW,
	NBL_CHAN_MSG_DEL_ND_UPCALL_FLOW,

	NBL_CHAN_MSG_GET_BOARD_ID,

	NBL_CHAN_MSG_SET_SHAPING_DPORT_VLD,
	NBL_CHAN_MSG_SET_DPORT_FC_TH_VLD,

	NBL_CHAN_MSG_REGISTER_RDMA_BOND,
	NBL_CHAN_MSG_UNREGISTER_RDMA_BOND,

	NBL_CHAN_MSG_RESTORE_NETDEV_QUEUE,
	NBL_CHAN_MSG_RESTART_NETDEV_QUEUE,
	NBL_CHAN_MSG_RESTORE_HW_QUEUE,

	NBL_CHAN_MSG_KEEP_ALIVE,

	NBL_CHAN_MSG_GET_BASE_MAC_ADDR,

	NBL_CHAN_MSG_CFG_BOND_SHAPING,
	NBL_CHAN_MSG_CFG_BGID_BACK_PRESSURE,

	NBL_CHAN_MSG_ALLOC_KT_BLOCK,
	NBL_CHAN_MSG_FREE_KT_BLOCK,

	NBL_CHAN_MSG_GET_USER_QUEUE_INFO,
	NBL_CHAN_MSG_GET_ETH_BOND_INFO,

	NBL_CHAN_MSG_CLEAR_ACCEL_FLOW,
	NBL_CHAN_MSG_SET_BRIDGE_MODE,

	NBL_CHAN_MSG_GET_VF_FUNCTION_ID,
	NBL_CHAN_MSG_SET_VF_LINK_STATE,

	NBL_CHAN_MSG_SET_PMD_DEBUG,

	/* mailbox msg end */
	NBL_CHAN_MSG_MAILBOX_MAX,

	/* adminq msg */
	NBL_CHAN_MSG_ADMINQ_GET_EMP_VERSION = 0x8101,	/* Deprecated, should not be used */
	NBL_CHAN_MSG_ADMINQ_GET_NVM_VERSION = 0x8102,
	NBL_CHAN_MSG_ADMINQ_REBOOT = 0x8104,
	NBL_CHAN_MSG_ADMINQ_FLR_NOTIFY = 0x8105,
	NBL_CHAN_MSG_ADMINQ_LOAD_P4 = 0x8107,
	NBL_CHAN_MSG_ADMINQ_LOAD_P4_DEFAULT = 0x8108,
	NBL_CHAN_MSG_ADMINQ_FLASH_ERASE = 0x8201,
	NBL_CHAN_MSG_ADMINQ_FLASH_READ = 0x8202,
	NBL_CHAN_MSG_ADMINQ_FLASH_WRITE = 0x8203,
	NBL_CHAN_MSG_ADMINQ_FLASH_ACTIVATE = 0x8204,
	NBL_CHAN_MSG_ADMINQ_RESOURCE_WRITE = 0x8205,
	NBL_CHAN_MSG_ADMINQ_RESOURCE_READ = 0x8206,
	NBL_CHAN_MSG_ADMINQ_GET_NVM_BANK_INDEX = 0x820B,
	NBL_CHAN_MSG_ADMINQ_VERIFY_NVM_BANK = 0x820C,
	NBL_CHAN_MSG_ADMINQ_FLASH_LOCK = 0x820D,
	NBL_CHAN_MSG_ADMINQ_FLASH_UNLOCK = 0x820E,
	NBL_CHAN_MSG_ADMINQ_MANAGE_PORT_ATTRIBUTES = 0x8300,
	NBL_CHAN_MSG_ADMINQ_PORT_NOTIFY = 0x8301,
	NBL_CHAN_MSG_ADMINQ_GET_MODULE_EEPROM = 0x8302,
	NBL_CHAN_MSG_ADMINQ_GET_ETH_STATS = 0x8303,
	/* TODO: new kernel and ethtool support show fec stats */
	NBL_CHAN_MSG_ADMINQ_GET_FEC_STATS = 0x408,
	NBL_CHAN_MSG_ADMINQ_EMP_CONSOLE_WRITE = 0x8F01,
	NBL_CHAN_MSG_ADMINQ_EMP_CONSOLE_READ = 0x8F02,

	NBL_CHAN_MSG_MAX,
};

#define NBL_CHAN_ADMINQ_FUNCTION_ID (0xFFFF)

struct nbl_chan_vsi_qid_info {
	u16 vsi_id;
	u16 local_qid;
};

enum nbl_chan_state {
	NBL_CHAN_INTERRUPT_READY,
	NBL_CHAN_RESETTING,
	NBL_CHAN_STATE_NBITS
};

struct nbl_chan_param_add_macvlan {
	u8 mac[ETH_ALEN];
	u16 vlan;
	u16 vsi;
};

struct nbl_chan_param_del_macvlan {
	u8 mac[ETH_ALEN];
	u16 vlan;
	u16 vsi;
};

struct nbl_chan_param_register_net_info {
	u16 pf_bdf;
	u64 vf_bar_start;
	u64 vf_bar_size;
	u16 total_vfs;
	u16 offset;
	u16 stride;
	u64 pf_bar_start;
};

struct nbl_chan_param_alloc_txrx_queues {
	u16 vsi_id;
	u16 queue_num;
};

struct nbl_chan_param_register_vsi2q {
	u16 vsi_index;
	u16 vsi_id;
	u16 queue_offset;
	u16 queue_num;
};

struct nbl_chan_param_setup_queue {
	struct nbl_txrx_queue_param queue_param;
	bool is_tx;
};

struct nbl_chan_param_cfg_dsch {
	u16 vsi_id;
	bool vld;
};

struct nbl_chan_param_setup_cqs {
	u16 vsi_id;
	u16 real_qps;
};

struct nbl_chan_param_set_promisc_mode {
	u16 vsi_id;
	u16 mode;
};

struct nbl_chan_param_cfg_msix_map {
	u16 num_net_msix;
	u16 num_others_msix;
	u16 msix_mask_en;
};

struct nbl_chan_param_enable_mailbox_irq {
	u16 vector_id;
	bool enable_msix;
};

struct nbl_chan_param_get_global_vector {
	u16 vsi_id;
	u16 vector_id;
};

struct nbl_chan_param_get_vsi_id {
	u16 vsi_id;
	u16 type;
};

struct nbl_chan_param_get_eth_id {
	u16 vsi_id;
	u8 eth_mode;
	u8 eth_id;
};

struct nbl_chan_param_get_queue_info {
	u16 queue_num;
	u16 queue_size;
};

struct nbl_chan_param_set_eth_loopback {
	u32 eth_port_id;
	u32 enable;
};

struct nbl_chan_param_get_queue_err_stats {
	u8 queue_id;
	bool is_tx;
};

struct nbl_chan_param_set_coalesce {
	u16 local_vector_id;
	u16 vector_num;
	u16 rx_max_coalesced_frames;
	u16 rx_coalesce_usecs;
};

struct nbl_chan_param_set_spoof_check_addr {
	u16 vsi_id;
	u8 mac[ETH_ALEN];
};

struct nbl_chan_param_set_vf_spoof_check {
	u16 vsi_id;
	u16 vf_id;
	bool enable;
};

struct nbl_chan_param_get_rxfh_indir {
	u16 vsi_id;
	u32 rxfh_indir_size;
};

struct nbl_chan_result_get_real_bdf {
	u8 bus;
	u8 dev;
	u8 function;
};

struct nbl_chan_param_set_upcall {
	u16 vsi_id;
	u8 eth_id;
};

struct nbl_chan_param_set_func_vld {
	u8 eth_id;
	bool vld;
};

struct nbl_chan_param_nvm_version_resp {
	char magic[8];		/* "M181FWV0" */
	u32 version;		/* major << 16 | minor << 8 | revision */
	u32 build_date;		/* 0x20231231 - 2023.12.31 */
	u32 build_time;		/* 0x00123456 - 12:34:56 */
	u32 build_hash;		/* git commit hash */
	u32 rsv[2];
};

struct nbl_chan_param_flash_read {
	u32 bank_id;
	u32 offset;
	u32 len;
#define NBL_CHAN_FLASH_READ_LEN		0x800
};

struct nbl_chan_param_flash_erase {
	u32 bank_id;
	u32 offset;
	u32 len;
#define NBL_CHAN_FLASH_ERASE_LEN	0x1000
};

struct nbl_chan_resource_write_param {
	u32 resid;
	u32 offset;
	u32 len;
	u8 data[];
};

struct nbl_chan_resource_read_param {
	u32 resid;
	u32 offset;
	u32 len;
};

struct nbl_chan_param_flash_write {
	u32 bank_id;
	u32 offset;
	u32 len;
#define NBL_CHAN_FLASH_WRITE_LEN	0x800
	u8 data[NBL_CHAN_FLASH_WRITE_LEN];
};

struct nbl_chan_param_load_p4 {
	u8 name[NBL_P4_SECTION_NAME_LEN];
	u32 addr;
	u32 size;
	u32 section_index;
	u32 section_offset;
	u32 load_start;
	u32 load_end;
	u8 data[];
};

struct nbl_chan_result_flash_activate {
	u32 err_code;
	u32 reset_flag;
};

struct nbl_chan_param_set_sfp_state {
	u8 eth_id;
	u8 state;
};

struct nbl_chan_param_get_module_eeprom {
	u8 eth_id;
	struct ethtool_eeprom eeprom;
};

struct nbl_chan_param_module_eeprom_info {
	u8 eth_id;
	u8 i2c_address;
	u8 page;
	u8 bank;
	u32 write:1;
	u32 rsvd:31;
	u16 offset;
	u16 length;
#define NBL_MODULE_EEPRO_WRITE_MAX_LEN (4)
	u8 data[NBL_MODULE_EEPRO_WRITE_MAX_LEN];
};

struct nbl_chan_param_eth_rep_notify_link_state {
	u8 eth_id;
	u8 link_state;
};

struct nbl_chan_param_set_eth_mac_addr {
	u8 mac[ETH_ALEN];
	u8 eth_id;
};

struct nbl_chan_param_ctrl_port_led {
	u32 eth_id;
	enum nbl_led_reg_ctrl led_status;
};

struct nbl_chan_param_set_intr_suppress_level {
	u16 local_vector_id;
	u16 vector_num;
	u16 level;
};

struct nbl_chan_param_get_private_stat_data {
	u32 eth_id;
	u32 data_len;
};

struct nbl_chan_param_get_module_tempetature {
	u8 eth_id;
	enum nbl_module_temp_type type;
};

struct nbl_chan_param_restore_queue {
	u16 local_queue_id;
	int type;
};

struct nbl_chan_param_restart_queue {
	u16 local_queue_id;
	int type;
};

struct nbl_chan_param_restore_hw_queue {
	u16 vsi_id;
	u16 local_queue_id;
	dma_addr_t dma;
	int type;
};

struct nbl_chan_param_get_vf_func_id {
	u16 vsi_id;
	int vf_id;
};

struct nbl_chan_param_notify_link_state {
	u8 link_state;
	u32 link_speed;
};

struct nbl_chan_send_info {
	u16 dstid;
	u16 msg_type;
	void *arg;
	size_t arg_len;
	void *resp;
	size_t resp_len;
	u16 ack;
};

struct nbl_chan_ack_info {
	u16 dstid;
	u16 msg_type;
	u16 msgid;
	int err;
	void *data;
	u32 data_len;
};

enum nbl_channel_type {
	NBL_CHAN_TYPE_MAILBOX,
	NBL_CHAN_TYPE_ADMINQ,
	NBL_CHAN_TYPE_MAX
};

#define NBL_LINE_RATE_INFO_LENGTH (3)
struct nbl_rep_line_rate_info {
	u16 vsi_id;
	u16 func_id;
	u32 data[NBL_LINE_RATE_INFO_LENGTH];
};

struct nbl_channel_ops {
	int (*send_msg)(void *priv, struct nbl_chan_send_info *chan_send);
	int (*send_ack)(void *priv, struct nbl_chan_ack_info *chan_ack);
	int (*register_msg)(void *priv, u16 msg_type, nbl_chan_resp func, void *callback_priv);
	int (*cfg_chan_qinfo_map_table)(void *priv, u8 chan_type);
	bool (*check_queue_exist)(void *priv, u8 chan_type);
	int (*setup_queue)(void *priv, u8 chan_type);
	int (*set_listener_info)(void *priv, void *shm_ring, struct eventfd_ctx *eventfd);
	int (*set_listener_msgtype)(void *priv, int msgtype);
	void (*clear_listener_info)(void *priv);
	int (*teardown_queue)(void *priv, u8 chan_type);
	int (*set_queue_interrupt_state)(void *priv, u8 chan_type, bool ready);
	void (*clean_queue_subtask)(void *priv, u8 chan_type);
	int (*dump_txq)(void *priv, struct seq_file *m, u8 type);
	int (*dump_rxq)(void *priv, struct seq_file *m, u8 type);
	u32 (*get_adminq_tx_buf_size)(void *priv);
	int (*setup_keepalive)(void *priv, u16 dest_id, u8 chan_type);
	void (*remove_keepalive)(void *priv, u8 chan_type);
	void (*register_chan_task)(void *priv, u8 chan_type, struct work_struct *task);
};

struct nbl_channel_ops_tbl {
	struct nbl_channel_ops *ops;
	void *priv;
};

int nbl_chan_init_common(void *p, struct nbl_init_param *param);
void nbl_chan_remove_common(void *p);

#endif
