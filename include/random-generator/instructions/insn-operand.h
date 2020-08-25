/* latxt_define_operand is a micro with 2 fields
 *   - Operand type
 *   - Operand generating function
 */

/*TODO: complete */

latxt_define_operand(R8, gen_r8)
latxt_define_operand(R16, gen_r16)
latxt_define_operand(R32, gen_r32)
latxt_define_operand(IMM8, gen_imm8)
latxt_define_operand(IMM16, gen_imm16)
latxt_define_operand(IMM32, gen_imm32)
latxt_define_operand(MEM8, gen_mem8)
latxt_define_operand(MEM16, gen_mem16)
latxt_define_operand(MEM32, gen_mem32)
