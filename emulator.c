#include "emulator_structures_headers.h"

void unimplemented_instruction(u_int8_t opcode) {
  printf("Implement intruction with opcode : %x.\n", (int)opcode);
}

int get_parity(u_int8_t number) {
  int count = 0;
  count += ((number & 0b00000001) == 0b00000001);
  count += ((number & 0b00000010) == 0b00000010);
  count += ((number & 0b00000100) == 0b00000100);
  count += ((number & 0b00001000) == 0b00001000);
  count += ((number & 0b00010000) == 0b00010000);
  count += ((number & 0b00100000) == 0b00100000);
  count += ((number & 0b01000000) == 0b01000000);
  count += ((number & 0b10000000) == 0b10000000);
  return ((count % 2) == 0) ? (1) : (0);
}

u_int8_t Emulate_8080_Op(State8080 *state) {
  u_int8_t *opcode = &state->memory[state->pc];

  switch (*opcode) {
  case 0x00: {
  } break;

  case 0x01: {
    state->b = opcode[1];
    state->c = opcode[2];
    state->pc += 2;
  } break;

  case 0x02: {
    u_int16_t location = (((u_int16_t)state->b) << 8) | ((u_int16_t)state->c);
    state->memory[location] = state->a;
  } break;

  case 0x03: {
    u_int32_t answer =
        ((u_int32_t)state->c | (((u_int32_t)state->b) << 8)) + 0x1;
    state->c = answer & 0xff;
    state->b = (answer & 0xffff) >> 8;
  } break;

  case 0x04: {
    u_int16_t answer = (u_int16_t)state->b + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->b = answer & 0xff;
  } break;

  case 0x05: {
    u_int16_t answer = (u_int16_t)state->b - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->b = answer & 0xff;
  } break;

  case 0x06: {
    state->b = opcode[1];
    state->pc += 1;
  } break;

  case 0x07: {
    state->cc.cy = (0x80 == (state->a & 0x80));
    state->a = (state->a << 1) | (((u_int8_t)state->cc.cy) >> 7);
  } break;

  case 0x08: {
  } break;

  case 0x09: {
    u_int32_t answer = ((u_int32_t)state->l | (((u_int32_t)state->h) << 8)) +
                       ((u_int32_t)state->c | (((u_int32_t)state->b) << 8));
    state->cc.cy = (answer > 0xffff);
    state->l = answer & 0xff;
    state->h = (answer & 0xffff) >> 8;
  } break;

  case 0x0a: {
    u_int16_t location = (((u_int16_t)state->b) << 8) | ((u_int16_t)state->c);
    state->a = state->memory[location];
  } break;

  case 0x0b: {
    u_int32_t answer =
        ((u_int32_t)state->c | (((u_int32_t)state->b) << 8)) - 0x1;
    state->c = answer & 0xff;
    state->b = (answer & 0xffff) >> 8;
  } break;

  case 0x0c: {
    u_int16_t answer = (u_int16_t)state->c + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->c = answer & 0xff;
  } break;

  case 0x0d: {
    u_int16_t answer = (u_int16_t)state->c - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->c = answer & 0xff;
  } break;

  case 0x0e: {
    state->c = opcode[1];
    state->pc += 1;
  } break;

  case 0x0f: {
    state->cc.cy = (1 == (state->a & 0x1));
    state->a = (state->a >> 1) | (((u_int8_t)state->cc.cy) << 7);
  } break;

  case 0x10: {
  } break;

  case 0x11: {
    state->e = opcode[1];
    state->d = opcode[2];
    state->pc += 2;
  } break;

  case 0x12: {
    u_int16_t location = (((u_int16_t)state->d) << 8) | ((u_int16_t)state->e);
    state->memory[location] = state->a;
  } break;

  case 0x13: {
    u_int32_t answer =
        ((u_int32_t)state->e | (((u_int32_t)state->d) << 8)) + 0x1;
    state->e = answer & 0xff;
    state->d = (answer & 0xffff) >> 8;
  } break;

  case 0x14: {
    u_int16_t answer = (u_int16_t)state->d + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->d = answer & 0xff;
  } break;

  case 0x15: {
    u_int16_t answer = (u_int16_t)state->d - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->d = answer & 0xff;
  } break;

  case 0x16: {
    state->d = opcode[1];
    state->pc += 1;
  } break;

  case 0x17: {
    state->a = (state->a << 1) | (((u_int8_t)state->cc.cy) >> 7);
    state->cc.cy = (0x80 == (state->a & 0x80));
  } break;

  case 0x18: {
  } break;

  case 0x19: {
    u_int32_t answer = ((u_int32_t)state->l | (((u_int32_t)state->h) << 8)) +
                       ((u_int32_t)state->e | (((u_int32_t)state->d) << 8));
    state->cc.cy = (answer > 0xffff);
    state->l = answer & 0xff;
    state->h = (answer & 0xffff) >> 8;
  } break;

  case 0x1a: {
    state->a =
        state->memory[(((u_int16_t)state->d) << 8) | ((u_int16_t)state->e)];
  } break;

  case 0x1b: {
    u_int32_t answer =
        ((u_int32_t)state->e | (((u_int32_t)state->d) << 8)) - 0x1;
    state->e = answer & 0xff;
    state->d = (answer & 0xffff) >> 8;
  } break;

  case 0x1c: {
    u_int16_t answer = (u_int16_t)state->e + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->e = answer & 0xff;
  } break;

  case 0x1d: {
    u_int16_t answer = (u_int16_t)state->e - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->e = answer & 0xff;
  } break;

  case 0x1e: {
    state->e = opcode[1];
    state->pc += 1;
  } break;

  case 0x1f: {
    u_int8_t temp = state->a;
    state->cc.cy = (1 == (state->a & 0x1));
    state->a = (state->a >> 1) | ((temp)&0x80);
  } break;

  case 0x20: {
  } break;

  case 0x21: {
    state->h = opcode[2];
    state->l = opcode[1];
    state->pc += 2;
  } break;

  case 0x22: {
    u_int16_t location = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
    state->memory[location] = state->l;
    state->memory[location + 1] = state->h;
    state->pc += 2;
  } break;

  case 0x23: {
    u_int32_t answer =
        ((u_int32_t)state->l | (((u_int32_t)state->h) << 8)) + 0x1;
    state->l = answer & 0xff;
    state->h = (answer & 0xffff) >> 8;
  } break;

  case 0x24: {
    u_int16_t answer = (u_int16_t)state->h + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->h = answer & 0xff;
  } break;

  case 0x25: {
    u_int16_t answer = (u_int16_t)state->h - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->h = answer & 0xff;
  } break;

  case 0x26: {
    state->h = opcode[1];
    state->pc += 1;
  } break;

  case 0x27: {
    unimplemented_instruction(*opcode);
  } break;

  case 0x28: {
  } break;

  case 0x29: {
    u_int32_t answer = ((u_int32_t)state->l | (((u_int32_t)state->h) << 8)) +
                       ((u_int32_t)state->l | (((u_int32_t)state->h) << 8));
    state->cc.cy = (answer > 0xffff);
    state->l = answer & 0xff;
    state->h = (answer & 0xffff) >> 8;
  } break;

  case 0x2a: {
    u_int16_t location = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
    state->l = state->memory[location];
    state->h = state->memory[location + 1];
    state->pc += 2;
  } break;

  case 0x2b: {
    u_int32_t answer =
        ((u_int32_t)state->l | (((u_int32_t)state->h) << 8)) - 0x1;
    state->l = answer & 0xff;
    state->h = (answer & 0xffff) >> 8;
  } break;

  case 0x2c: {
    u_int16_t answer = (u_int16_t)state->l + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->l = answer & 0xff;
  } break;

  case 0x2d: {
    u_int16_t answer = (u_int16_t)state->l - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->l = answer & 0xff;
  } break;

  case 0x2e: {
    state->l = opcode[1];
    state->pc += 1;
  } break;

  case 0x2f: {
    state->a = !state->a;
  } break;

  case 0x30: {
  } break;

  case 0x31: {
    state->sp = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
    state->pc += 2;
  } break;

  case 0x32: {
    u_int16_t location = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
    state->memory[location] = state->a;
    state->pc += 2;
  } break;

  case 0x33: {
    state->sp += 1;
  } break;

  case 0x34: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int8_t temp = state->memory[location];
    u_int16_t answer = (u_int16_t)temp + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->memory[location] = answer & 0xff;
  } break;

  case 0x35: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int8_t temp = state->memory[location];
    u_int16_t answer = (u_int16_t)temp - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->memory[location] = answer & 0xff;
  } break;

  case 0x36: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = opcode[1];
    state->pc += 1;
  } break;

  case 0x37: {
    state->cc.cy = 1;
  } break;

  case 0x38: {
  } break;

  case 0x39: {
    u_int32_t answer = ((u_int32_t)state->l | (((u_int32_t)state->h) << 8)) +
                       (u_int32_t)state->sp;
    state->cc.cy = (answer > 0xffff);
    state->l = answer & 0xff;
    state->h = (answer & 0xffff) >> 8;
  } break;

  case 0x3a: {
    u_int16_t location = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
    state->a = state->memory[location];
    state->pc += 2;
  } break;

  case 0x3b: {
    state->sp -= 1;
  } break;

  case 0x3c: {
    u_int16_t answer = (u_int16_t)state->a + 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x3d: {
    u_int16_t answer = (u_int16_t)state->a - 0x01;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x3e: {
    state->a = opcode[1];
    state->pc += 1;
  } break;

  case 0x3f: {
    state->cc.cy = !state->cc.cy;
  } break;

  case 0x40: {
    state->b = state->b;
  } break;

  case 0x41: {
    state->b = state->c;
  } break;

  case 0x42: {
    state->b = state->d;
  } break;

  case 0x43: {
    state->b = state->e;
  } break;

  case 0x44: {
    state->b = state->h;
  } break;

  case 0x45: {
    state->b = state->l;
  } break;

  case 0x46: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->b = state->memory[location];
  } break;

  case 0x47: {
    state->b = state->a;
  } break;

  case 0x48: {
    state->c = state->b;
  } break;

  case 0x49: {
    state->c = state->c;
  } break;

  case 0x4a: {
    state->c = state->d;
  } break;

  case 0x4b: {
    state->c = state->e;
  } break;

  case 0x4c: {
    state->c = state->h;
  } break;

  case 0x4d: {
    state->c = state->l;
  } break;

  case 0x4e: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->c = state->memory[location];
  } break;

  case 0x4f: {
    state->c = state->a;
  } break;

  case 0x50: {
    state->d = state->b;
  } break;

  case 0x51: {
    state->d = state->c;
  } break;

  case 0x52: {
    state->d = state->d;
  } break;

  case 0x53: {
    state->d = state->e;
  } break;

  case 0x54: {
    state->d = state->h;
  } break;

  case 0x55: {
    state->d = state->l;
  } break;

  case 0x56: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->d = state->memory[location];
  } break;

  case 0x57: {
    state->d = state->a;
  } break;

  case 0x58: {
    state->e = state->b;
  } break;

  case 0x59: {
    state->e = state->c;
  } break;

  case 0x5a: {
    state->e = state->d;
  } break;

  case 0x5b: {
    state->e = state->e;
  } break;

  case 0x5c: {
    state->e = state->h;
  } break;

  case 0x5d: {
    state->e = state->l;
  } break;

  case 0x5e: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->e = state->memory[location];
  } break;

  case 0x5f: {
    state->e = state->a;
  } break;

  case 0x60: {
    state->h = state->b;
  } break;

  case 0x61: {
    state->h = state->c;
  } break;

  case 0x62: {
    state->h = state->d;
  } break;

  case 0x63: {
    state->h = state->e;
  } break;

  case 0x64: {
    state->h = state->h;
  } break;

  case 0x65: {
    state->h = state->l;
  } break;

  case 0x66: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->h = state->memory[location];
  } break;

  case 0x67: {
    state->h = state->a;
  } break;

  case 0x68: {
    state->l = state->b;
  } break;

  case 0x69: {
    state->l = state->c;
  } break;

  case 0x6a: {
    state->l = state->d;
  } break;

  case 0x6b: {
    state->l = state->e;
  } break;

  case 0x6c: {
    state->l = state->h;
  } break;

  case 0x6d: {
    state->l = state->l;
  } break;

  case 0x6e: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->l = state->memory[location];
  } break;

  case 0x6f: {
    state->l = state->a;
  } break;

  case 0x70: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = state->b;
  } break;

  case 0x71: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = state->c;
  } break;

  case 0x72: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = state->d;
  } break;

  case 0x73: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = state->e;
  } break;

  case 0x74: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = state->h;
  } break;

  case 0x75: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = state->l;
  } break;

  case 0x76: {
    unimplemented_instruction(*opcode);
  } break;

  case 0x77: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->memory[location] = state->a;
  } break;

  case 0x78: {
    state->a = state->b;
  } break;

  case 0x79: {
    state->a = state->c;
  } break;

  case 0x7a: {
    state->a = state->d;
  } break;

  case 0x7b: {
    state->a = state->e;
  } break;

  case 0x7c: {
    state->a = state->h;
  } break;

  case 0x7d: {
    state->a = state->l;
  } break;

  case 0x7e: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    state->a = state->memory[location];
  } break;

  case 0x7f: {
    state->a = state->a;
  } break;

  case 0x80: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->b);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x81: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->c);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x82: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->d);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x83: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->e);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x84: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->h);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x85: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->l);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x86: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer =
        ((u_int16_t)state->a) + ((u_int16_t)state->memory[location]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x87: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->a);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x88: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->b) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x89: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->c) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x8a: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->d) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x8b: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->e) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x8c: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->h) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x8d: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->l) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x8e: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer = ((u_int16_t)state->a) +
                       ((u_int16_t)state->memory[location]) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x8f: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)state->a) +
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x90: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->b);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x91: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->c);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x92: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->d);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x93: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->e);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x94: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->h);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x95: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->l);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x96: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer =
        ((u_int16_t)state->a) - ((u_int16_t)state->memory[location]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x97: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->a);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x98: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->b) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x99: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->c) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x9a: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->d) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x9b: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->e) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x9c: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->h) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x9d: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->l) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x9e: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer = ((u_int16_t)state->a) -
                       ((u_int16_t)state->memory[location]) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0x9f: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->a) -
                       ((u_int16_t)state->cc.cy);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa0: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)state->b);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa1: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)state->c);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa2: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)state->d);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa3: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)state->e);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa4: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)state->h);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa5: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)state->l);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa6: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer =
        ((u_int16_t)state->a) & ((u_int16_t)state->memory[location]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa7: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)state->a);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa8: {
    u_int16_t answer = ((u_int16_t)state->a) ^ ((u_int16_t)state->b);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xa9: {
    u_int16_t answer = ((u_int16_t)state->a) ^ ((u_int16_t)state->c);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xaa: {
    u_int16_t answer = ((u_int16_t)state->a) ^ ((u_int16_t)state->d);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xab: {
    u_int16_t answer = ((u_int16_t)state->a) ^ ((u_int16_t)state->e);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xac: {
    u_int16_t answer = ((u_int16_t)state->a) ^ ((u_int16_t)state->h);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xad: {
    u_int16_t answer = ((u_int16_t)state->a) ^ ((u_int16_t)state->l);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xae: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer =
        ((u_int16_t)state->a) ^ ((u_int16_t)state->memory[location]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xaf: {
    u_int16_t answer = ((u_int16_t)state->a) ^ ((u_int16_t)state->a);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb0: {
    u_int16_t answer = ((u_int16_t)state->a) | ((u_int16_t)state->b);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb1: {
    u_int16_t answer = ((u_int16_t)state->a) | ((u_int16_t)state->c);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb2: {
    u_int16_t answer = ((u_int16_t)state->a) | ((u_int16_t)state->d);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb3: {
    u_int16_t answer = ((u_int16_t)state->a) | ((u_int16_t)state->e);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb4: {
    u_int16_t answer = ((u_int16_t)state->a) | ((u_int16_t)state->h);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb5: {
    u_int16_t answer = ((u_int16_t)state->a) | ((u_int16_t)state->l);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb6: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer =
        ((u_int16_t)state->a) | ((u_int16_t)state->memory[location]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb7: {
    u_int16_t answer = ((u_int16_t)state->a) | ((u_int16_t)state->a);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
  } break;

  case 0xb8: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->b);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xb9: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->c);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xba: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->d);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xbb: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->e);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xbc: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->h);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xbd: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->l);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xbe: {
    u_int16_t location = (((u_int16_t)state->h) << 8) | ((u_int16_t)state->l);
    u_int16_t answer =
        ((u_int16_t)state->a) - ((u_int16_t)state->memory[location]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xbf: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)state->a);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
  } break;

  case 0xc0: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xc1: {
    state->c = state->memory[state->sp];
    state->b = state->memory[state->sp + 0x1];
    state->sp += 2;
  } break;

  case 0xc2: {
    if (state->cc.z) {
      state->pc = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
      state->pc -= 1;
    } else {
      state->pc += 2;
    }
  } break;

  case 0xc3: {
    state->pc = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
    state->pc -= 1;
  } break;

  case 0xc4: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xc5: {
    state->memory[state->sp - 0x2] = state->c;
    state->memory[state->sp - 0x1] = state->b;
    state->sp -= 2;
  } break;

  case 0xc6: {
    u_int16_t answer = ((u_int16_t)state->a) + ((u_int16_t)opcode[1]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
    state->pc += 1;
  } break;

  case 0xc7: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xc8: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xc9: {
    state->pc = (((u_int16_t)state->memory[state->sp + 1]) << 8) |
                ((u_int16_t)state->memory[state->sp]);
    state->pc -= 1;
    state->sp += 2;
  } break;

  case 0xca: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xcb: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xcc: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xcd: {
    u_int16_t temp = state->pc;
    state->memory[state->sp - 1] = (((temp & 0xff00) >> 8) & 0xff);
    state->memory[state->sp - 2] = (temp & 0xff);
    state->sp -= 2;
    state->pc = (((u_int16_t)opcode[2]) << 8) | ((u_int16_t)opcode[1]);
    state->pc -= 1;
  } break;

  case 0xce: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xcf: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xd0: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xd1: {
    state->e = state->memory[state->sp];
    state->d = state->memory[state->sp + 1];
    state->sp += 2;
  } break;

  case 0xd2: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xd3: {
    // OUT D8
    state->pc += 1;
  } break;

  case 0xd4: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xd5: {
    state->memory[state->sp - 0x2] = state->e;
    state->memory[state->sp - 0x1] = state->d;
    state->sp -= 2;
  } break;

  case 0xd6: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xd7: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xd8: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xd9: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xda: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xdb: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xdc: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xdd: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xde: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xdf: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xe0: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xe1: {
    state->l = state->memory[state->sp];
    state->h = state->memory[state->sp + 0x1];
    state->sp += 2;
  } break;

  case 0xe2: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xe3: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xe4: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xe5: {
    state->memory[state->sp - 0x2] = state->l;
    state->memory[state->sp - 0x1] = state->h;
    state->sp -= 2;
  } break;

  case 0xe6: {
    u_int16_t answer = ((u_int16_t)state->a) & ((u_int16_t)opcode[1]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
    state->pc += 1;
  } break;

  case 0xe7: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xe8: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xe9: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xea: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xeb: {
    u_int8_t temp = state->h;
    state->h = state->d;
    state->d = temp;
    temp = state->l;
    state->l = state->e;
    state->e = temp;
  } break;

  case 0xec: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xed: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xee: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xef: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf0: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf1: {
    u_int8_t psw = state->memory[state->sp];
    state->cc.z = (0x01 == (psw & 0x01));
    state->cc.s = (0x02 == (psw & 0x02));
    state->cc.p = (0x04 == (psw & 0x04));
    state->cc.cy = (0x05 == (psw & 0x08));
    state->cc.ac = (0x10 == (psw & 0x10));
    state->a = state->memory[state->sp + 1];
    state->sp += 2;
  } break;

  case 0xf2: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf3: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf4: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf5: {
    u_int8_t psw = (state->cc.z | state->cc.s << 1 | state->cc.p << 2 |
                    state->cc.cy << 3 | state->cc.ac << 4);
    state->memory[state->sp - 2] = psw;
    state->memory[state->sp - 1] = state->a;
    state->sp = state->sp - 2;
  } break;

  case 0xf6: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf7: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf8: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xf9: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xfa: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xfb: {
    // EI special
    state->int_enable = 0x1;
  } break;

  case 0xfc: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xfd: {
    unimplemented_instruction(*opcode);
  } break;

  case 0xfe: {
    u_int16_t answer = ((u_int16_t)state->a) - ((u_int16_t)opcode[1]);
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = get_parity(answer & 0xff);
    state->cc.ac = 0; // not implemented
    state->a = answer & 0xff;
    state->pc += 1;
  } break;

  case 0xff: {
    unimplemented_instruction(*opcode);
  } break;

  default: {
    unimplemented_instruction(*opcode);
  } break;
  }
  state->pc += 1;
  return 1;
}
