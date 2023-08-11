#include "emulator.c"
#include "emulator_structures_headers.h"
#include "init.c"

////////////////////////////////////
/// The only 8080 state variable. //
State8080 state; ///////////////////
////////////////////////////////////

/// Program specifications //
u_int8_t *program;      /////
u_int16_t program_size; /////
/////////////////////////////

void init(char *program_name) {
  program_size = get_program_size(program_name) - 1;
  program = get_program(program_name, program_size);

  if ((state.memory = (u_int8_t *)calloc(0x10000, sizeof(u_int8_t))) == NULL) {
    printf("ERROR : IN ALLOCATING MEMMORY TO 8080.\nexiting program....\n");
    exit(1);
  }

  for (u_int16_t i = 0x0; i <= program_size; i++) {
    state.memory[i] = program[i];
  }
  free(program);
  program = NULL;

  state.pc = 0;
}

void emulate(State8080 *state) {
  while (1) {
    u_int8_t flag = 0;
    flag = Emulate_8080_Op(state);
    if (flag != 1) {
      break;
    }
  }
}

int main(int argc, char *argv[]) {

  printf("Hello, World\n");
  init(argv[1]);
  emulate(&state);

  return 0;
}
