#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/insn-operands-abbrev.h"
#include "generator/instructions/gen-opcode.h"

struct latxt_opcode_info {
  uint8_t len;
  uint8_t bytes[3];
};

/* map { opcode type, operands abbreviation } to opcode bytes */
struct latxt_opcode_info opcode_map(LATXT_OPCODE_TYPE opcodeType,
        LATXT_OPERANDS_ABBREV operandsAbbrev)
{
  struct latxt_opcode_info opcodeInfo;
#define opcodeLen opcodeInfo.len
#define opcodeByte1 opcodeInfo.bytes[0]
#define opcodeByte2 opcodeInfo.bytes[1]
#define opcodeByte3 opcodeInfo.bytes[2]
  switch (opcodeType) {
    case X86_ISA_ADD:
      opcodeLen = 1;
      switch (operandsAbbrev) {
        case LATXT_OPERANDS_ABBREV_Eb_Gb:
          opcodeByte1 = 0x00;
          break;
        case LATXT_OPERANDS_ABBREV_Ev_Gv:
          opcodeByte1 = 0x01;
          break;
        case LATXT_OPERANDS_ABBREV_Gb_Eb:
          opcodeByte1 = 0x02;
          break;
        case LATXT_OPERANDS_ABBREV_Gv_Ev:
          opcodeByte1 = 0x03;
          break;
        case LATXT_OPERANDS_ABBREV_AL_Ib:
          opcodeByte1 = 0x04;
          break;
        case LATXT_OPERANDS_ABBREV_rAX_Iz:
          opcodeByte1 = 0x05;
          break;
        default:
          latxtassertm(false, "Wrong operands abbreviation type!");
          break;
      }
      break;
    case X86_ISA_ADC:
      opcodeLen = 1;
      switch (operandsAbbrev) {
        case LATXT_OPERANDS_ABBREV_Eb_Gb:
          opcodeByte1 = 0x10;
          break;
        case LATXT_OPERANDS_ABBREV_Ev_Gv:
          opcodeByte1 = 0x11;
          break;
        case LATXT_OPERANDS_ABBREV_Gb_Eb:
          opcodeByte1 = 0x12;
          break;
        case LATXT_OPERANDS_ABBREV_Gv_Ev:
          opcodeByte1 = 0x13;
          break;
        case LATXT_OPERANDS_ABBREV_AL_Ib:
          opcodeByte1 = 0x14;
          break;
        case LATXT_OPERANDS_ABBREV_rAX_Iz:
          opcodeByte1 = 0x15;
          break;
        default:
          latxtassertm(false, "Wrong operands abbreviation type!");
          break;
      }
      break;
    case X86_ISA_AND:
      opcodeLen = 1;
      switch (operandsAbbrev) {
        case LATXT_OPERANDS_ABBREV_Eb_Gb:
          opcodeByte1 = 0x20;
          break;
        case LATXT_OPERANDS_ABBREV_Ev_Gv:
          opcodeByte1 = 0x21;
          break;
        case LATXT_OPERANDS_ABBREV_Gb_Eb:
          opcodeByte1 = 0x22;
          break;
        case LATXT_OPERANDS_ABBREV_Gv_Ev:
          opcodeByte1 = 0x23;
          break;
        case LATXT_OPERANDS_ABBREV_AL_Ib:
          opcodeByte1 = 0x24;
          break;
        case LATXT_OPERANDS_ABBREV_rAX_Iz:
          opcodeByte1 = 0x25;
          break;
        default:
          latxtassertm(false, "Wrong operands abbreviation type!");
          break;
      }
      break;
    case X86_ISA_XOR:
      opcodeLen = 1;
      switch (operandsAbbrev) {
        case LATXT_OPERANDS_ABBREV_Eb_Gb:
          opcodeByte1 = 0x30;
          break;
        case LATXT_OPERANDS_ABBREV_Ev_Gv:
          opcodeByte1 = 0x31;
          break;
        case LATXT_OPERANDS_ABBREV_Gb_Eb:
          opcodeByte1 = 0x32;
          break;
        case LATXT_OPERANDS_ABBREV_Gv_Ev:
          opcodeByte1 = 0x33;
          break;
        case LATXT_OPERANDS_ABBREV_AL_Ib:
          opcodeByte1 = 0x34;
          break;
        case LATXT_OPERANDS_ABBREV_rAX_Iz:
          opcodeByte1 = 0x35;
          break;
        default:
          latxtassertm(false, "Wrong operands abbreviation type!");
          break;
      }
      break;
    case X86_ISA_PUSH:
      opcodeLen = 1;
      switch (operandsAbbrev) {
        case LATXT_PP_REG_ES:
          opcodeByte1 = 0x06;
          break;
        case LATXT_PP_REG_SS:
          opcodeByte1 = 0x16;
          break;
        case LATXT_PP_REG_rAX:
          opcodeByte1 = 0x50;
          break;
        case LATXT_PP_REG_rCX:
          opcodeByte1 = 0x51;
          break;
        case LATXT_PP_REG_rDX:
          opcodeByte1 = 0x52;
          break;
        case LATXT_PP_REG_rBX:
          opcodeByte1 = 0x53;
          break;
        case LATXT_PP_REG_rSP:
          opcodeByte1 = 0x54;
          break;
        case LATXT_PP_REG_rBP:
          opcodeByte1 = 0x55;
          break;
        case LATXT_PP_REG_rSI:
          opcodeByte1 = 0x56;
          break;
        case LATXT_PP_REG_rDI:
          opcodeByte1 = 0x57;
          break;
        default:
          latxtassertm(false, "Wrong push reg!");
          break;
      }
      break;
    case X86_ISA_POP:
      opcodeLen = 1;
      switch (operandsAbbrev) {
        case LATXT_PP_REG_ES:
          opcodeByte1 = 0x07;
          break;
        case LATXT_PP_REG_SS:
          opcodeByte1 = 0x17;
          break;
        case LATXT_PP_REG_rAX:
          opcodeByte1 = 0x58;
          break;
        case LATXT_PP_REG_rCX:
          opcodeByte1 = 0x59;
          break;
        case LATXT_PP_REG_rDX:
          opcodeByte1 = 0x5A;
          break;
        case LATXT_PP_REG_rBX:
          opcodeByte1 = 0x5B;
          break;
        case LATXT_PP_REG_rSP:
          opcodeByte1 = 0x5C;
          break;
        case LATXT_PP_REG_rBP:
          opcodeByte1 = 0x5D;
          break;
        case LATXT_PP_REG_rSI:
          opcodeByte1 = 0x5E;
          break;
        case LATXT_PP_REG_rDI:
          opcodeByte1 = 0x5F;
          break;
        default:
          latxtassertm(false, "Wrong pop reg!");
          break;
      }
      break;
    default:
      latxtassertm(false, "Wrong opcode!");
      break;
  }
  return opcodeInfo;
#undef opcodeLen
#undef opcodeByte1
#undef opcodeByte2
#undef opcodeByte3
};

static LATXT_OPERANDS_ABBREV operands_type_to_abbrev(
        struct latxt_i386_insn_predef_info *predef_info)
{
  LATXT_OPERANDS_TYPE operandsType = predef_info->operands.type;
  LATXT_OPERANDS_ABBREV operandsAbbrev = LATXT_OPERANDS_ABBREV_LAST;
  switch(operandsType) {
    case AL_IMM8:
      operandsAbbrev = LATXT_OPERANDS_ABBREV_AL_Ib;
      break;
    case R8_R8:
    case MEM8_R8:
      operandsAbbrev = LATXT_OPERANDS_ABBREV_Eb_Gb;
      break;
    case R16_R16:
    case MEM16_R16:
    case R32_R32:
    case MEM32_R32:
      operandsAbbrev = LATXT_OPERANDS_ABBREV_Ev_Gv;
      break;
    case R8_MEM8:
    /* TODO: R8_R8 is belong to both EbGb and GbEb */
      operandsAbbrev = LATXT_OPERANDS_ABBREV_Gb_Eb;
      break;
    case R16_MEM16:
    case R32_MEM32:
    /* TODO: R16_R16 and R32_R32 are belong to both EvGv and GvEv */
      operandsAbbrev = LATXT_OPERANDS_ABBREV_Gv_Ev;
      break;
    case R8_IMM8:
    case MEM8_IMM8:
      operandsAbbrev = LATXT_OPERANDS_ABBREV_Eb_Ib;
      break;
    case R16_IMM16:
    case MEM16_IMM16:
    case R32_IMM32:
    case MEM32_IMM32:
      operandsAbbrev = LATXT_OPERANDS_ABBREV_Ev_Iz;
      break;
    case R16_IMM8:
	  case MEM16_IMM8:
    case R32_IMM8:
    case MEM32_IMM8:
      operandsAbbrev = LATXT_OPERANDS_ABBREV_Ev_Ib;
      break;
    default:
      perror("Wrong operandsType! Orz");
      abort();
      break;
  }
  return operandsAbbrev;
}

uint8_t gen_opcode(char *opcode_buf, 
        struct latxt_i386_insn_predef_info *predef_info)
{
  uint8_t opcode_len = -1;
  LATXT_OPERANDS_ABBREV operandsAbbrev = operands_type_to_abbrev(predef_info);
  assert(operandsAbbrev < LATXT_OPERANDS_ABBREV_LAST);
  struct latxt_opcode_info curr_opcode = opcode_map(predef_info->opcode.type,
    operandsAbbrev);
  opcode_len = curr_opcode.len;
  for (int i = 0; i < curr_opcode.len; ++i) {
    opcode_buf[i] = curr_opcode.bytes[i];
  }
  return opcode_len;
}
