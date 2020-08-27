#ifndef TEST_GEN_OPERAND_H
#define TEST_GEN_OPERAND_H

/* x86 instruction operand type */
typedef enum {
#define latxt_define_operand(a, b) a,
#include "random-generator/instructions/insn-operand.h"
  OPERAND_LAST
} LATXT_OPERAND_TYPE;
#undef latxt_define_operand

struct latxt_operand {
  LATXT_OPERAND_TYPE type;
  uint8_t len;
  uint8_t *bytes;
};

uint8_t gen_operands(uint8_t *operands_buf,
                            struct latxt_i386_insn_predef_info *predef_info);

#endif
