#include "latxtest-common.h"
#include "random-generator/instructions/instruction.h"
#include "random-generator/instructions/gen-insn.h"
#include "random-generator/instructions/arith-seed.h"
#include "unit-tests/insn-test.h"
#include "unit-tests/code-cache.h"

static bool test_add(void) {
  ccache_head_wrap();

  add_seed.predef_info.operandsType = R8_IMM8;
  gen_random_insn(&add_seed);
  printl("instruction generated: add AL,0x0f: 0x%02x%02x\n", add_seed.bytes[0], 
         add_seed.bytes[1]);
  //ccache_put_bytes(add_seed.bytes, add_seed.insn_len);

  ccache_tail_wrap();
  ccache_execute();
  return true;
}

bool test_arith(void) {
  printl("TEST arith started.\n");
  ccache_init();
  if (test_add()) {
    printl("ADD test success!\n");
  }
  ccache_finish();
  printl("TEST arith finished.\n\n");
  return true;
}
