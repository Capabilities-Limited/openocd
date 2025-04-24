/* SPDX-License-Identifier: GPL-2.0-or-later */

/*
 * TODO: For manually adding CHERI defines until they
 *       are offically generated from
 *       https://github.com/riscv/riscv-opcodes
 */

#ifndef RISCV_ENCODING_CHERI_H
#define RISCV_ENCODING_CHERI_H

#define MSECCFG_CRE    0x00000008

/* zcheri instructions.  */
#define MATCH_ACPERM 0xc002033
#define MASK_ACPERM 0xfe00707f
#define MATCH_CADD 0xc000033
#define MASK_CADD 0xfe00707f
#define MATCH_CADDI 0x201b
#define MASK_CADDI 0x707f
#define MATCH_CBLD 0xc005033
#define MASK_CBLD 0xfe00707f
#define MATCH_CRAM 0x10700033
#define MASK_CRAM 0xfff0707f
#define MATCH_GCBASE 0x10500033
#define MASK_GCBASE 0xfff0707f
#define MATCH_GCHI 0x10400033
#define MASK_GCHI 0xfff0707f
#define MATCH_GCLEN 0x10600033
#define MASK_GCLEN 0xfff0707f
#define MATCH_GCMODE 0x10300033
#define MASK_GCMODE 0xfff0707f
#define MATCH_GCPERM 0x10100033
#define MASK_GCPERM 0xfff0707f
#define MATCH_GCTAG 0x10000033
#define MASK_GCTAG 0xfff0707f
#define MATCH_MODESW_CAP 0x12001033
#define MASK_MODESW_CAP 0xffffffff
#define MATCH_MODESW_INT 0x14001033
#define MASK_MODESW_INT 0xffffffff
#define MATCH_SCADDR 0xc001033
#define MASK_SCADDR 0xfe00707f
#define MATCH_SCBNDS 0xe000033
#define MASK_SCBNDS 0xfe00707f
#define MATCH_SCBNDSI 0x4005013
#define MASK_SCBNDSI 0xfc00707f
#define MATCH_SCBNDSR 0xe001033
#define MASK_SCBNDSR 0xfe00707f
#define MATCH_SCEQ 0xc004033
#define MASK_SCEQ 0xfe00707f
#define MATCH_SCHI 0xc003033
#define MASK_SCHI 0xfe00707f
#define MATCH_SCMODE 0xc007033
#define MASK_SCMODE 0xfe00707f
#define MATCH_SCSS 0xc006033
#define MASK_SCSS 0xfe00707f
#define MATCH_SENTRY 0x10800033
#define MASK_SENTRY 0xfff0707f
#define MATCH_LQ 0x400f
#define MASK_LQ  0x707f
#define MATCH_SQ 0x4023
#define MASK_SQ  0x707f
#define MATCH_LR_B 0x1000002f
#define MASK_LR_B  0xf9f0707f
#define MATCH_SC_B 0x1800002f
#define MASK_SC_B  0xf800707f
#define MATCH_LR_H 0x1000102f
#define MASK_LR_H  0xf9f0707f
#define MATCH_SC_H 0x1800102f
#define MASK_SC_H  0xf800707f
#define MATCH_LR_Q 0x1000402f
#define MASK_LR_Q  0xf9f0707f
#define MATCH_SC_Q 0x1800402f
#define MASK_SC_Q  0xf800707f
#define MATCH_AMOSWAP_Q 0x800402f
#define MASK_AMOSWAP_Q  0xf800707f

/* CHERI extension CSR addresses.  */
#define CSR_STVAL2 0x14b
#define CSR_VSTVAL2 0x24b
#define CSR_DDC 0x416
#define CSR_DDDC 0x7bc
#define CSR_DINFC 0x7bd

/* CHERI extension exception.  */
#define CAUSE_CHERI_FAULT 0x1c

#endif /* RISCV_ENCODING_CHERI_H */

#ifdef DECLARE_INSN
DECLARE_INSN(acperm, MATCH_ACPERM, MASK_ACPERM)
DECLARE_INSN(cadd, MATCH_CADD, MASK_CADD)
DECLARE_INSN(caddi, MATCH_CADDI, MASK_CADDI)
DECLARE_INSN(cbld, MATCH_CBLD, MASK_CBLD)
DECLARE_INSN(cram, MATCH_CRAM, MASK_CRAM)
DECLARE_INSN(gcbase, MATCH_GCBASE, MASK_GCBASE)
DECLARE_INSN(gchi, MATCH_GCHI, MASK_GCHI)
DECLARE_INSN(gclen, MATCH_GCLEN, MASK_GCLEN)
DECLARE_INSN(gcperm, MATCH_GCPERM, MASK_GCPERM)
DECLARE_INSN(gctag, MATCH_GCTAG, MASK_GCTAG)
DECLARE_INSN(modesw, MATCH_MODESW, MASK_MODESW)
DECLARE_INSN(scaddr, MATCH_SCADDR, MASK_SCADDR)
DECLARE_INSN(scbnds, MATCH_SCBNDS, MASK_SCBNDS)
DECLARE_INSN(scbndsi, MATCH_SCBNDSI, MASK_SCBNDSI)
DECLARE_INSN(scbndsr, MATCH_SCBNDSR, MASK_SCBNDSR)
DECLARE_INSN(sceq, MATCH_SCEQ, MASK_SCEQ)
DECLARE_INSN(schi, MATCH_SCHI, MASK_SCHI)
DECLARE_INSN(scmode, MATCH_SCMODE, MASK_SCMODE)
DECLARE_INSN(scss, MATCH_SCSS, MASK_SCSS)
DECLARE_INSN(sentry, MATCH_SENTRY, MASK_SENTRY)
DECLARE_INSN(lq, MATCH_LQ, MASK_LQ)
DECLARE_INSN(sq, MATCH_SQ, MASK_SQ)
DECLARE_INSN(lr_b, MATCH_LR_B, MASK_LR_B)
DECLARE_INSN(sc_b, MATCH_SC_B, MASK_SC_B)
DECLARE_INSN(lr_h, MATCH_LR_H, MASK_LR_H)
DECLARE_INSN(sc_h, MATCH_SC_H, MASK_SC_H)
DECLARE_INSN(lr_q, MATCH_LR_Q, MASK_LR_Q)
DECLARE_INSN(sc_q, MATCH_SC_Q, MASK_SC_Q)
DECLARE_INSN(amoswap_q, MATCH_AMOSWAP_Q, MASK_AMOSWAP_Q)
#endif /* DECLARE_INSN */
#ifdef DECLARE_CAUSE
DECLARE_CAUSE("cheri fault", CAUSE_CHERI_FAULT)
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
DECLARE_CSR(dinfc, CSR_DINFC)
DECLARE_CSR(stval2, CSR_STVAL2)
DECLARE_CSR(vstal2, CSR_VSTVAL2)
#endif /* DECLARE_CSR */

