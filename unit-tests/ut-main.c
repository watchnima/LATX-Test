#include "latxtest-common.h"
#include "unit-tests/insn-test.h"
#include "generator/generator.h"

extern struct generator_params generator_params;

enum {
  OK_ARG,
  EXIT_ARG,
  ERR_ARG
};

static void usage(void)
{
  printl("usage: ut\n");
  printl("  %-15s%-40s\n", "-h", "print this help");
  printl("  %-15s\n", "-help");
  printl("  %-15s%-40s\n", "-boundary", "generator boundary test (default is random)");
}

static int parse_args(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    char *param = argv[i];
    if (strcmp(param, "-h") == 0 || strcmp(param, "-help") == 0) {
      usage();
      return EXIT_ARG;
    } else if(strcmp(param, "-boundary") == 0) {
      generator_params.isRandom = false;
    } else {
      printl("Parse arguments error!\n");
      usage();
      return ERR_ARG;
    }
  }
  return OK_ARG;
}

/* ==========================================================================*/
/* Entry point                                                               */
/* ==========================================================================*/
 
int main(int argc, char *argv[])
{
  int op = parse_args(argc, argv);
  if (op == ERR_ARG || op == EXIT_ARG) {
    return 0;
  }
  if (!gen_init())
    return 0;
  if (test_arith()) {
    ;
  }
  return 0;
}
