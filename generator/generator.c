#include "latxtest-common.h"
#include "generator/generator.h"

struct generator_params generator_params =
{
  .isRandom = true
};

bool gen_init(void)
{
  srand((unsigned)time(NULL));
  return true;
}
