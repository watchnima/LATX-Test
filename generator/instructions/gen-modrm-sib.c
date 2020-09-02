#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/gen-operands.h"

/* 16-bit addressing forms of ModR/M */
typedef enum {
  BX_add_SI_address,
  BX_add_DI_address,
  BP_add_SI_address,
  BP_add_DI_address,
  SI_address,
  DI_address,
  DISP16,
  BX_address,
#define Mod00pos BX_address

  BX_add_SI_address_disp8,
  BX_add_DI_address_disp8,
  BP_add_SI_address_disp8,
  BP_add_DI_address_disp8,
  SI_address_disp8,
  DI_address_disp8,
  BP_address_disp8,
  BX_address_disp8,
#define Mod01 BX_address_disp8

  BX_add_SI_address_disp16,
  BX_add_DI_address_disp16,
  BP_add_SI_address_disp16,
  BP_add_DI_address_disp16,
  SI_address_disp16,
  DI_address_disp16,
  BP_address_disp16,
  BX_address_disp16,
#define Mod10 BX_address_disp16

  EAX_AX_AL_MM0_XMM0,
  ECX_CX_CL_MM1_XMM1,
  EDX_DX_DL_MM2_XMM2,
  EBX_BX_BL_MM3_XMM3,
  ESP_SP_AH_MM4_XMM4,
  EBP_BP_CH_MM5_XMM5,
  ESI_SI_DH_MM6_XMM6,
  EDI_DI_BH_MM7_XMM7
#define Mod11 EDI_DI_BH_MM7_XMM7
#define LATXT_ADDRESS_FORM_LAST (EDI_DI_BH_MM7_XMM7 + 1)
} LATXT_ADDRESS_FORM16_MODRM_TYPE;


/* 32-bit addressing forms of ModR/M*/
typedef enum {
  EAX_address,
  ECX_address,
  EDX_address,
  EBX_address,
  SIB,
  DISP32,
  ESI_address,
  EDI_address,

  EAX_address_disp8,
  ECX_address_disp8,
  EDX_address_disp8,
  EBX_address_disp8,
  SIB_disp8,
  EBP_address_disp8,
  ESI_address_disp8,
  EDI_address_disp8,

  EAX_address_disp32,
  ECX_address_disp32,
  EDX_address_disp32,
  EBX_address_disp32,
  SIB_disp32,
  EBP_address_disp32,
  ESI_address_disp32,
  EDI_address_disp32

  /* EAX_AX_AL_MM0_XMM0 */
  /* ECX_CX_CL_MM1_XMM1 */
  /* EDX_DX_DL_MM2_XMM2 */
  /* EBX_BX_BL_MM3_XMM3 */
  /* ESP_SP_AH_MM4_XMM4 */
  /* EBP_BP_CH_MM5_XMM5 */
  /* ESI_SI_DH_MM6_XMM6 */
  /* EDI_DI_BH_MM7_XMM7 */
} LATXT_ADDRESS_FORM32_MODRM_TYPE;

typedef enum {
  /* EAX_address */
  /* ECX_address */
  /* EDX_address */
  /* EBX_address */
  LATXT_ADDRESS_FORM_SIB_NONE = 4,
  EBP_address,
  /* ESI_address, */
  /* EDI_address, */

  EAX_mul2_address = 8,
  ECX_mul2_address,
  EDX_mul2_address,
  EBX_mul2_address,
  /* LATXT_ADDRESS_FORM_SIB_NONE */
  EBP_mul2_address = 13,
  ESI_mul2_address,
  EDI_mul2_address,

  EAX_mul4_address = 16,
  ECX_mul4_address,
  EDX_mul4_address,
  EBX_mul4_address,
  /* LATXT_ADDRESS_FORM_SIB_NONE */
  EBP_mul4_address = 21,
  ESI_mul4_address,
  EDI_mul4_address,

  EAX_mul8_address = 24,
  ECX_mul8_address,
  EDX_mul8_address,
  EBX_mul8_address,
  /* LATXT_ADDRESS_FORM_SIB_NONE */
  EBP_mul8_address = 29,
  ESI_mul8_address,
  EDI_mul8_address
} LATXT_ADDRESS_FORM_SIB_TYPE;

char address_form_modrm[LATXT_ADDRESS_FORM_LAST][1 << MODRM_REG_BITS] = {
  {0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38},
  {0x01, 0x09, 0x11, 0x19, 0x21, 0x29, 0x31, 0x39},
  {0x02, 0x0A, 0x12, 0x1A, 0x22, 0x2A, 0x32, 0x3A},
  {0x03, 0x0B, 0x13, 0x1B, 0x23, 0x2B, 0x33, 0x3B},
  {0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C, 0x34, 0x3C},
  {0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x35, 0x3D},
  {0x06, 0x0E, 0x16, 0x1E, 0x26, 0x2E, 0x36, 0x3E},
  {0x07, 0x0F, 0x17, 0x1F, 0x27, 0x2F, 0x37, 0x3F},

  {0x40, 0x48, 0x50, 0x58, 0x60, 0x68, 0x70, 0x78},
  {0x41, 0x49, 0x51, 0x59, 0x61, 0x69, 0x71, 0x79},
  {0x42, 0x4A, 0x52, 0x5A, 0x62, 0x6A, 0x72, 0x7A},
  {0x43, 0x4B, 0x53, 0x5B, 0x63, 0x6B, 0x73, 0x7B},
  {0x44, 0x4C, 0x54, 0x5C, 0x64, 0x6C, 0x74, 0x7C},
  {0x45, 0x4D, 0x55, 0x5D, 0x65, 0x6D, 0x75, 0x7D},
  {0x46, 0x4E, 0x56, 0x5E, 0x66, 0x6E, 0x76, 0x7E},
  {0x47, 0x4F, 0x57, 0x5F, 0x67, 0x6F, 0x77, 0x7F},

  {0x80, 0x88, 0x90, 0x98, 0xA0, 0xA8, 0xB0, 0xB8},
  {0x81, 0x89, 0x91, 0x99, 0xA1, 0xA9, 0xB1, 0xB9},
  {0x82, 0x8A, 0x92, 0x9A, 0xA2, 0xAA, 0xB2, 0xBA},
  {0x83, 0x8B, 0x93, 0x9B, 0xA3, 0xAB, 0xB3, 0xBB},
  {0x84, 0x8C, 0x94, 0x9C, 0xA4, 0xAC, 0xB4, 0xBC},
  {0x85, 0x8D, 0x95, 0x9D, 0xA5, 0xAD, 0xB5, 0xBD},
  {0x86, 0x8E, 0x96, 0x9E, 0xA6, 0xAE, 0xB6, 0xBE},
  {0x87, 0x8F, 0x97, 0x9F, 0xA7, 0xAF, 0xB7, 0xBF},

  {0xC0, 0xC8, 0xD0, 0xD8, 0xE0, 0xE8, 0xF0, 0xF8},
  {0xC1, 0xC9, 0xD1, 0xD9, 0xE1, 0xE9, 0xF1, 0xF9},
  {0xC2, 0xCA, 0xD2, 0xDA, 0xE2, 0xEA, 0xF2, 0xFA},
  {0xC3, 0xCB, 0xD3, 0xDB, 0xE3, 0xEB, 0xF3, 0xFB},
  {0xC4, 0xCC, 0xD4, 0xDC, 0xE4, 0xEC, 0xF4, 0xFC},
  {0xC5, 0xCD, 0xD5, 0xDD, 0xE5, 0xED, 0xF5, 0xFD},
  {0xC6, 0xCE, 0xD6, 0xDE, 0xE6, 0xEE, 0xF6, 0xFE},
  {0xC7, 0xCF, 0xD7, 0xDF, 0xE7, 0xEF, 0xF7, 0xFF}
};

char address_form_sib[LATXT_ADDRESS_FORM_LAST][1 << SIB_BASE_BITS] = {
  {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07},
  {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F},
  {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17},
  {0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F},
  {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27},
  {0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F},
  {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37},
  {0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F},

  {0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47},
  {0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F},
  {0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57},
  {0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F},
  {0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67},
  {0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F},
  {0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77},
  {0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F},

  {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87},
  {0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F},
  {0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97},
  {0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F},
  {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7},
  {0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF},
  {0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7},
  {0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF},

  {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7},
  {0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF},
  {0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7},
  {0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF},
  {0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7},
  {0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF},
  {0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7},
  {0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF}
};

uint8_t gen_modrm_sib(uint8_t *opcode_buf, 
        struct latxt_i386_insn_predef_info *predef_info)
{
  return 0;
}
