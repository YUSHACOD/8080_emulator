#include "emulator_structures_headers.h"

u_int16_t get_program_size(char *program_file) {
  u_int16_t size;
  struct stat st;
  if (stat(program_file, &st) == 0) {
    size = (u_int16_t)st.st_size;
  }
  return size;
}

u_int8_t *get_program(char *program_file, u_int16_t program_size) {
  u_int8_t *program;

  if ((program = (u_int8_t *)calloc(program_size, sizeof(u_int8_t))) == NULL) {
    printf(
        "ERROR : IN ALLOCATING MEMMORY TO GET PROGRAM.\nexiting program....\n");
    exit(1);
  }

  FILE *f;
  f = fopen(program_file, "r");
  char t;
  int counter;
  for (counter = 0; counter <= program_size; counter++) {
    program[counter] = (u_int8_t)fgetc(f);
  }
  fclose(f);

  return program;
}
