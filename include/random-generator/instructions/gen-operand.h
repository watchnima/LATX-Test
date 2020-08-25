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

typedef void (*gen_opnd_func_type)(struct latxt_operand*);

void gen_r8(struct latxt_operand *opnd);
void gen_r16(struct latxt_operand *opnd);
void gen_r32(struct latxt_operand *opnd);
void gen_imm8(struct latxt_operand *opnd);
void gen_imm16(struct latxt_operand *opnd);
void gen_imm32(struct latxt_operand *opnd);
void gen_mem8(struct latxt_operand *opnd);
void gen_mem16(struct latxt_operand *opnd);
void gen_mem32(struct latxt_operand *opnd);

#endif
