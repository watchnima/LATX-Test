#include "latxtest-common.h"
#include "unit-tests/insn-test.h"
#include "x86-insn-generator/include/generator.h"
#include "output/ofmt.h"

static const char *buf;
static insn_seed MOV_seed =
{
    .opcode = I_MOV
};

bool gen_test_file_MOV(void)
{
    ofmt->init("test_MOV.s");
    generator_init(true);

    assign_arr5(MOV_seed.opd, REG_GPR|BITS16,REG_SREG,0,0,0);
    while ((buf = generate_str(&MOV_seed)) != NULL) {
        ofmt->output(buf);
    }

    generator_exit();
    ofmt->cleanup();
    return true;
}
