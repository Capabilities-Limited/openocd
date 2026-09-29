/* SPDX-License-Identifier: GPL-2.0-or-later */

/*
 * TODO: For manually adding CHERI defines until they
 *       are offically generated from
 *       https://github.com/riscv/riscv-opcodes
 */

#ifndef RISCV_ENCODING_CHERI_H
#define RISCV_ENCODING_CHERI_H

#define MISA_Y 0x01000000

/* zcheri instructions.  */
#define MATCH_YPERMC 0x260007b
#define MASK_YPERMC 0xfe00707f
#define MATCH_YADD 0x060007b
#define MASK_YADD 0xfe00707f
#define MATCH_YADDI 0x407b
#define MASK_YADDI 0x707f
#define MATCH_YBLD 0x1e00007b
#define MASK_YBLD 0xfe00707f
#define MATCH_YAMASK 0xf000007b
#define MASK_YAMASK 0xfff0707f
#define MATCH_YBASER 0xf400007b
#define MASK_YBASER 0xfff0707f
#define MATCH_YHIR_RV32 0x0200507b
#define MASK_YHIR_RV32 0xfff0707f
#define MATCH_YHIR_RV64 0x0400507b
#define MASK_YHIR_RV64 0xfff0707f
#define MATCH_YLENR 0xf430007b
#define MASK_YLENR 0xfff0707f
#define MATCH_YMODER 0xf460007b
#define MASK_YMODER 0xfff0707f
#define MATCH_YPERMR 0xf410007b
#define MASK_YPERMR 0xfff0707f
#define MATCH_YTAGR 0xf440007b
#define MASK_YTAGR 0xfff0707f
#define MATCH_YMODESWY 0x5600007b
#define MASK_YMODESWY 0xffffffff
#define MATCH_YMODESWI 0x5610007b
#define MASK_YMODESWI 0xffffffff
#define MATCH_YADDRW 0x1600007b
#define MASK_YADDRW 0xfe00707f
#define MATCH_YBNDSW 0x3600007b
#define MASK_YBNDSW 0xfe00707f
#define MATCH_YBNDSWI 0xe000507b
#define MASK_YBNDSWI 0xe000707f
#define MATCH_YBNDSRW 0x4600007b
#define MASK_YBNDSRW 0xfe00707f
#define MATCH_YEQ 0x0c00007b
#define MASK_YEQ 0xfe00707f
#define MATCH_PACKY 0x0200007b
#define MASK_PACKY 0xfe00707f
#define MATCH_YMODEW 0x5600007b
#define MASK_YMODEW 0xfe00707f
#define MATCH_YSS 0x1c00007b
#define MASK_YSS 0xfe00707f
#define MATCH_YSENTRY 0x2e00007b
#define MASK_YSENTRY 0xfe0ff07f
#define MATCH_LY 0x107b
#define MASK_LY  0x707f
#define MATCH_SY 0x207b
#define MASK_SY  0x707f
#define MATCH_LR_Y 0x1000307b
#define MASK_LR_Y  0xf9f0707f
#define MATCH_SC_Y 0x1800307b
#define MASK_SC_Y  0xf800707f
#define MATCH_AMOSWAP_Y 0x800307b
#define MASK_AMOSWAP_Y  0xf800707f

/* CHERI extension CSR addresses.  */
#define CSR_DDC 0x416
#define CSR_DDDC 0x7bc
#define CSR_DROOTC 0x7bd

/* CHERI extension exception.  */
#define CAUSE_CHERI_INST_ACCESS_FAULT 32
#define CAUSE_CHERI_LOAD_ACCESS_FAULT 33
#define CAUSE_CHERI_SAMO_ACCESS_FAULT 34
#define CAUSE_CHERI_LOAD_CAPABILITY_FAULT 35
#define CAUSE_CHERI_SAMO_PAGE_FAULT 36

#endif /* RISCV_ENCODING_CHERI_H */

#ifdef DECLARE_INSN
DECLARE_INSN(ypermc, MATCH_YPERMC, MASK_YPERMC)
DECLARE_INSN(yadd, MATCH_YADD, MASK_YADD)
DECLARE_INSN(yaddi, MATCH_YADDI, MASK_YADDI)
DECLARE_INSN(ybld, MATCH_YBLD, MASK_YBLD)
DECLARE_INSN(yamask, MATCH_YAMASK, MASK_YAMASK)
DECLARE_INSN(ybaser, MATCH_YBASER, MASK_YBASER)
DECLARE_INSN(yhir_rv64, MATCH_YHIR_RV64, MASK_YHIR_RV64)
DECLARE_INSN(yhir_rv32, MATCH_YHIR_RV32, MASK_YHIR_RV32)
DECLARE_INSN(ylenr, MATCH_YLENR, MASK_YLENR)
DECLARE_INSN(ypermr, MATCH_YPERMR, MASK_YPERMR)
DECLARE_INSN(ytagr, MATCH_GCTAG, MASK_GCTAG)
DECLARE_INSN(ymodeswy, MATCH_YMODESWY, MASK_YMODESWY)
DECLARE_INSN(ymodeswi, MATCH_YMODESWI, MASK_YMODESWI)
DECLARE_INSN(yaddrw, MATCH_YADDRW, MASK_YADDRW)
DECLARE_INSN(ybndsw, MATCH_YBNDSW, MASK_YBNDSW)
DECLARE_INSN(ybndswi, MATCH_YBNDSWI, MASK_YBNDSWI)
DECLARE_INSN(ybndsrw, MATCH_YBNDSRW, MASK_YBNDSRW)
DECLARE_INSN(yeq, MATCH_YEQ, MASK_YEQ)
DECLARE_INSN(packy, MATCH_PACKY, MASK_PACKY)
DECLARE_INSN(ymodew, MATCH_YMODEW, MASK_YMODEW)
DECLARE_INSN(yss, MATCH_YSS, MASK_YSS)
DECLARE_INSN(ysentry, MATCH_YSENTRY, MASK_YSENTRY)
DECLARE_INSN(ly, MATCH_LY, MASK_LY)
DECLARE_INSN(sy, MATCH_SY, MASK_SY)
DECLARE_INSN(lr_y, MATCH_LR_Y, MASK_LR_Y)
DECLARE_INSN(sc_y, MATCH_SC_Y, MASK_SC_Y)
DECLARE_INSN(amoswap_y, MATCH_AMOSWAP_Y, MASK_AMOSWAP_Y)
#endif /* DECLARE_INSN */
#ifdef DECLARE_CAUSE
DECLARE_CAUSE("cheri instruction access fault", CAUSE_CHERI_INST_ACCESS_FAULT)
DECLARE_CAUSE("cheri load access fault", CAUSE_CHERI_LOAD_ACCESS_FAULT)
DECLARE_CAUSE("cheri store/amo access fault", CAUSE_CHERI_SAMO_ACCESS_FAULT)
DECLARE_CAUSE("cheri load capability fault", CAUSE_CHERI_LOAD_CAPABILITY_FAULT)
DECLARE_CAUSE("cheri store/amo page fault", CAUSE_CHERI_SAMO_PAGE_FAULT)
#endif /* DECLARE_CAUSE */
#ifdef DECLARE_CSR
/* The Default Data Capability (DDC) register exists as two entries in the register list:
 * - under its CSR number
 * - under the number expected by GDB
 *
 * For that reason, the CSR item is named ddc_csr' rather than 'ddc' to avoid
 * a name collision with the general 'ddc' register during SMP target description merging.
 *
 * OpenOCD's SMP logic filters duplicates by name, not ID. If both are named
 * 'ddc', the general register 'ddc' is dropped as it has a larger ID. This
 * breaks the GDB org.gnu.gdb.riscv.cheri feature requirement.
 */

DECLARE_CSR(ddc_csr, CSR_DDC)
DECLARE_CSR(dddc, CSR_DDDC)
DECLARE_CSR(drootc, CSR_DROOTC)
#endif /* DECLARE_CSR */

