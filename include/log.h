#ifndef TEST_LOG_H
#define TEST_LOG_H

#define printl printf

#define latxtassert(cond) \
  do { \
    if (!(cond)) { \
      fprintf(stderr, \
              "\033[31m assertion failed in <%s> %s:%d \033[m\n", \
              __FUNCTION__, __FILE__, __LINE__); \
      abort(); \
    } \
  } while (0)

#define latxtassertm(cond, ...) \
  do { \
    if (!(cond)) { \
      fprintf(stderr, "\033[31m assertion failed in <%s> %s:%d \033[m", \
              __FUNCTION__, __FILE__, __LINE__); \
      fprintf(stderr, __VA_ARGS__); \
      abort(); \
    } \
  } while(0)

#define latxtwarning(...) \
  do { \
    fprintf(stderr, "\033[31m warning in <%s> %s:%d \033[m", \
            __FUNCTION__, __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__); \
  } while(0)

#endif
