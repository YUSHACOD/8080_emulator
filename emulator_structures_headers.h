#ifndef EMULATOR_STRUCTURES_HEADERS
#define EMULATOR_STRUCTURES_HEADERS

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/io.h>
#include <sys/stat.h>

typedef struct ConditionCodes {
  u_int8_t z : 1;
  u_int8_t s : 1;
  u_int8_t p : 1;
  u_int8_t cy : 1;
  u_int8_t ac : 1;
  u_int8_t pad : 3;
} ConditionCodes;

typedef struct State8080 {
  u_int8_t a;
  u_int8_t b;
  u_int8_t c;
  u_int8_t d;
  u_int8_t e;
  u_int8_t h;
  u_int8_t l;
  u_int16_t sp;
  u_int16_t pc;
  u_int8_t *memory;
  struct ConditionCodes cc;
  u_int8_t int_enable;
} State8080;

#endif
