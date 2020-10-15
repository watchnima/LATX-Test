#include "latxtest-common.h"
#include "unit-tests/insn-test.h"

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
  if (!gen_test_file_MOV()) {
      printl("genrate MOV test file failed!\n");
  }
  return 0;
}
