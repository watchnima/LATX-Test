#ifndef TEST_GEN_MODRM_SIB_H
#define TEST_GEN_MODRM_SIB_H

uint8_t gen_modrm_sib(uint8_t *opcode_buf, 
        struct latxt_i386_insn_predef_info *predef_info);

#endif
