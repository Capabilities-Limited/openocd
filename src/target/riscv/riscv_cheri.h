/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef OPENOCD_TARGET_RISCV_CHERI_H
#define OPENOCD_TARGET_RISCV_CHERI_H

#include <helper/cheri.h>
#include "riscv.h"

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
