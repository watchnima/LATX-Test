#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/gen-operands.h"

static bool NO_AL(LATXT_OPCODE_TYPE opcodeType)
{
  bool no_AL = false;
  switch (opcodeType) {
    case X86_ISA_ADD:
    case X86_ISA_ADC:
    case X86_ISA_AND:
    case X86_ISA_XOR:
      no_AL = true;
      break;
    default:
      break;
  }
  return no_AL;
}

static bool NO_AX(LATXT_OPCODE_TYPE opcodeType)
{
  bool no_AX = false;
  switch (opcodeType) {
    case X86_ISA_ADD:
    case X86_ISA_ADC:
    case X86_ISA_AND:
    case X86_ISA_XOR:
      no_AX = true;
      break;
    default:
      break;
  }
  return no_AX;
}

static bool NO_eAX(LATXT_OPCODE_TYPE opcodeType)
{
  return false;
}

/*TODO: realize */
void gen_r8(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_r16(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_r32(struct latxt_operand *opnd)
{
  return ;
}
