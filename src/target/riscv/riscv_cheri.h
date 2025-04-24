/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef OPENOCD_TARGET_RISCV_CHERI_H
#define OPENOCD_TARGET_RISCV_CHERI_H

#include <helper/cheri.h>
#include "riscv.h"

/* 128 bit Capability fields  */
#define CLEN_128_CAP_BOUNDS		(0x000000007FFFFFFUL)
#define CLEN_128_CAP_CT			(0x000000008000000UL)
#define CLEN_128_CAP_CL			(0x000080000000000UL)
#define CLEN_128_CAP_AP			(0x00FF00000000000UL)
#define CLEN_128_CAP_M			(0x010000000000000UL)
#define CLEN_128_CAP_SDP		(0x1E0000000000000UL)
#define CLEN_128_CAP_META_MASK	\
			(CLEN_128_CAP_SDP | CLEN_128_CAP_M | CLEN_128_CAP_AP |     \
			 CLEN_128_CAP_CL | CLEN_128_CAP_CT | CLEN_128_CAP_BOUNDS)

/* 64 bit Capability definitions */
#define CLEN_64_CAP_BOUNDS		(0x000FFFFFUL)
#define CLEN_64_CAP_CT			(0x00100000UL)
#define CLEN_64_CAP_CL			(0x01000000UL)
#define CLEN_64_CAP_AP_M		(0x3E000000UL)
#define		CLEN_64_CAP_AP_M_BIT0	(0x02000000UL)
#define		CLEN_64_CAP_AP_M_BIT1	(0x04000000UL)
#define		CLEN_64_CAP_AP_M_BIT2	(0x08000000UL)
#define		CLEN_64_CAP_AP_M_MODE_MASK	\
				(CLEN_64_CAP_AP_M_BIT0 | CLEN_64_CAP_AP_M_BIT1 | CLEN_64_CAP_AP_M_BIT2)
#define		CLEN_64_CAP_AP_M_QUADRANT_MASK	(0x30000000UL)
#define			CLEN_64_CAP_AP_M_QUADRANT_NON_CAP_DATA_RW			(0x00000000UL)
#define			CLEN_64_CAP_AP_M_QUADRANT_EXE_CAP					(0x10000000UL)
#define			CLEN_64_CAP_AP_M_QUADRANT_RESTRICTED_CAP_DATA_RW	(0x20000000UL)
#define			CLEN_64_CAP_AP_M_QUADRANT_CAP_DATA_RW				(0x30000000UL)
#define CLEN_64_CAP_SDP			(0xC0000000UL)
#define CLEN_64_CAP_META_MASK	\
			(CLEN_64_CAP_SDP | CLEN_64_CAP_AP_M | CLEN_64_CAP_CL | \
			 CLEN_64_CAP_CT | CLEN_64_CAP_BOUNDS)

static inline void buf_set_cheri_capability(uint8_t *buffer,
	riscv_reg_t value, unsigned int clen)
{
	buf_set_cheri_capability_value(buffer, value.value, clen);
	buf_set_cheri_capability_meta(buffer, value.meta, clen);
	buf_set_cheri_capability_tag(buffer, value.tag, clen);
}

static inline void buf_get_cheri_capability(const uint8_t *buffer,
	riscv_reg_t *value, unsigned int clen)
{
	value->value = buf_get_cheri_capability_value(buffer, clen);
	value->meta = buf_get_cheri_capability_meta(buffer, clen);
	value->tag = buf_get_cheri_capability_tag(buffer, clen);
}

#endif /* OPENOCD_TARGET_RISCV_CHERI_H */
