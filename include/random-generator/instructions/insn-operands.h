/* latxt_define_operands is a micro with 3 fields
 *   - Operands combination abbreviation
 *   - First operand
 *   - Second operand
 */

/* TODO: complete */

/* Typical binary */
latxt_define_operands(R8_IMM8, R8, IMM8)
latxt_define_operands(R16_IMM8, R16, IMM8)
latxt_define_operands(R16_IMM16, R16, IMM16)
latxt_define_operands(R32_IMM8, R32, IMM8)
latxt_define_operands(R32_IMM32, R32, IMM32)

latxt_define_operands(MEM8_IMM8, MEM8, IMM8)
latxt_define_operands(MEM16_IMM8, MEM16, IMM8)
latxt_define_operands(MEM16_IMM16, MEM16, IMM16)
latxt_define_operands(MEM32_IMM8, MEM32, IMM8)
latxt_define_operands(MEM32_IMM32, MEM32, IMM32)

latxt_define_operands(R8_R8, R8, R8)
latxt_define_operands(R16_R16, R16, R16)
latxt_define_operands(R32_R32, R32, R32)

latxt_define_operands(MEM8_R8, MEM8, R8)
latxt_define_operands(MEM16_R16, MEM16, R16)
latxt_define_operands(MEM32_R32, MEM32, R32)

latxt_define_operands(R8_MEM8, R8, MEM8)
latxt_define_operands(R16_MEM16, R16, MEM16)
latxt_define_operands(R32_MEM32, R32, MEM32)
