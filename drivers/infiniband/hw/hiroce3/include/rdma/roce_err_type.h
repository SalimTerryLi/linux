/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2024 Huawei Technologies Co., Ltd */

#ifndef ROCE_ERR_TYPE_H
#define ROCE_ERR_TYPE_H

#include "typedef.h"
#include "roce_pub_cmd.h"
#include "roce_api.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/* **********************macro define************************ */
enum ROCE_ERR_STATE_E {
	ROCE_AEQE_NOERR_STATE = 0,
	ROCE_AEQE_ERR_STATE,
};

enum ROCE_QP_ERR_STATE_E {
	ROCE_QP_NOERR_STATE = 0,
	ROCE_QP_ERR_STATE,
};

/* *********ROCE_AEQE_SUBTYPE_E******* */
enum ROCE_AEQE_SUBTYPE_E {
	ROCE_AEQE_SUBTYPE_PATH_MIGRATED = 0,   /* * APM */
	ROCE_AEQE_SUBTYPE_COMM_ESTABLISHED,	/* *RQ RTR RCV FIRST PKT */
	ROCE_AEQE_SUBTYPE_SQ_DRAINED,		  /* * sq empty and change to SQ DRANNING STATE */
	ROCE_AEQE_SUBTYPE_SRQ_LIMIT_REACHED,   /* *SRQ LIMIT_REACHED from RXDMA api rsp */
	ROCE_AEQE_SUBTYPE_QP_LAST_WQE_REACHED, /* *srq en & LAST_WQE_REACHED */
	ROCE_AEQE_SUBTYPE_CQ_ERR,			  /* *api rsp cq err */
	ROCE_AEQE_SUBTYPE_QP_FATAL,			/* *LOC_WORK_QUEUE_CATASTROPHIC_ERR */
	ROCE_AEQE_SUBTYPE_QP_REQ_ERR,		  /* *INVALID_REQ_LOC_WORK_QUEUE_ERR */
	ROCE_AEQE_SUBTYPE_QP_ACCESS_ERR,	   /* *LOC_ACCESS_VIOLATION_WORK_QUEUE_ERR */
	ROCE_AEQE_SUBTYPE_PATH_MIG_ERR,
	ROCE_AEQE_SUBTYPE_GID_CHANGE_EVENT,
	ROCE_AEQE_SUBTYPE_CQ_OVERRUN,
	ROCE_AEQE_SUBTYPE_SRQ_CATASTROPHIC_ERR,
	ROCE_AEQE_SUBTYPE_CFG_ERR,
	ROCE_AEQE_SUBTYPE_CHIP_ERR,
	ROCE_AEQE_SUBTYPE_DIF_ERR,
	ROCE_AEQE_SUBTYPE_XRC_DOMAIN_VIOLATION_ERR,
	ROCE_AEQE_SUBTYPE_INVALID_XRCETH_ERR,
	ROCE_AEQE_SUBTYPE_UCODE_FATAL_ERR,
	ROCE_AEQE_SUBTYPE_ODP_PAGE_FAULT,
	ROCE_AEQE_SUBTYPE_RSVD,
};

/* *********ROCE SQ ERR type******* */
enum ROCE_COMPLETION_EVENT_ERR_TYPE_E {
	ROCE_COMPLTE_EVENT_NO_ERR = 0,
	ROCE_COMPLTE_EVENT_LOC_LEN_ERR = 0x1,
	ROCE_COMPLTE_EVENT_LOC_QP_OPERATION_ERR,
	ROCE_COMPLTE_EVENT_LOC_PROTECTION_ERR = 0x4,
	ROCE_COMPLTE_EVENT_LOC_MEM_MANAGEMENT_ERR = 0x4,
	ROCE_COMPLTE_EVENT_WR_FLUSH_ERR,
	ROCE_COMPLTE_EVENT_MW_BIND_ERR,
	ROCE_COMPLTE_EVENT_BAD_RESP_ERR = 0x10,
	ROCE_COMPLTE_EVENT_LOC_ACCESS_ERR,
	ROCE_COMPLTE_EVENT_REM_INV_REQ_ERR,
	ROCE_COMPLTE_EVENT_REM_ACCESS_ERR,
	ROCE_COMPLTE_EVENT_REM_OPERATION_ERR,
	ROCE_COMPLTE_EVENT_RETRY_CTR_EXCEED_ERR,
	ROCE_COMPLTE_EVENT_RNR_RETRY_CTR_EXCEED_ERR,
	ROCE_COMPLTE_EVENT_REM_ABORTED_ERR = 0x22,
	ROCE_COMPLTE_EVENT_XRC_VIOLATION_ERR,
};

enum ROCE_AEQE_EVENT_ERR_TYPE_E {
	ROCE_AEQE_QP_FATAL_SQ_FETCH_WQE_STATUS_ERR = 0,
	ROCE_AEQE_QP_FATAL_SQ_DMA_GEN_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_SQ_DMA_GEN_MPT_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_SQ_DMA_GEN_CQ_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_SQ_COMPLETE_WQE_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_SQ_COMPLETE_CQ_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RQ_RXDMA_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RQ_RXDMA_MPT_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RQ_RXDMA_CQ_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RQ_RXDMA_SRQ_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RQ_RDMA_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RQ_RDMA_MPT_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_CQ_CQE_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_CQ_ARM_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_SRQ_ARM_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RDMARC_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_RDMARC_RSP_PSN_ERR = 0x10,
	ROCE_AEQE_QP_FATAL_MINVLD_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_CQ_RESIZE_STATUS_ERR,
	ROCE_AEQE_QP_FATAL_CQ_OVERFLOW,
	ROCE_AEQE_CFG_TYPE_STATELESS_MAC = 0x20,
	ROCE_AEQE_CFG_TYPE_STATELESS_FUNC,
	ROCE_AEQE_CFG_TYPE_QPC_PREFETCH_RSP_ERR,
	ROCE_AEQE_CFG_TYPE_QPC_STATE_ERR,
	ROCE_AEQE_CFG_TYPE_QPC_STATE_NOT_RTS,
	ROCE_AEQE_CHIP_TYPE_CPB_BUF_FULL,
	ROCE_AEQE_CHIP_TYPE_IPSU_RSP_ERR,
	ROCE_AEQE_CHIP_TYPE_QU_QUERY_RSP_ERR,
	ROCE_AEQE_LOC_QP_REQ_ERR_TOO_MANY_READ_ATOMIC = 0x30,
	ROCE_AEQE_LOC_QP_REQ_ERR_OPCODE_MISMATCH,
	ROCE_AEQE_LOC_QP_REQ_ERR_LEN_ERR,
	ROCE_AEQE_LOC_QP_OPERATION_ERR,
	ROCE_AEQE_LOC_QP_NUM_RANGE_ERR,
	ROCE_AEQE_MPT_NUM_RANGE_ERR,
	ROCE_AEQE_MASTER_QP_MODIFY_ERR,
};

#define ROCE_AEQE_EVENT(module_type, subtype, type, err_code) \
	(((u32)(module_type) << 28) | ((subtype) << 20) | ((type) << 8) | (err_code))

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* ROCE_ERR_TYPE_H */
