#include "emulator_structures_headers.h"

void unimplemented_instruction(u_int8_t opcode) {
  printf("Implement intruction with opcode : %x.\n", (int)opcode);
  exit(1);
}

u_int8_t Emulate_8080_Op(State8080 *state) {
  u_int8_t *opcode = &state->memory[state->pc];

  switch (*opcode) {
  case 0x00:
    break;

  case 0x01:
    unimplemented_instruction(*opcode);
    break;

  case 0x02:
    unimplemented_instruction(*opcode);
    break;

  case 0x03:
    unimplemented_instruction(*opcode);
    break;

  case 0x04:
    unimplemented_instruction(*opcode);
    break;

  case 0x05:
    unimplemented_instruction(*opcode);
    break;

  case 0x06:
    unimplemented_instruction(*opcode);
    break;

  case 0x07:
    unimplemented_instruction(*opcode);
    break;

  case 0x08:
    unimplemented_instruction(*opcode);
    break;

  case 0x09:
    unimplemented_instruction(*opcode);
    break;

  case 0x0a:
    unimplemented_instruction(*opcode);
    break;

  case 0x0b:
    unimplemented_instruction(*opcode);
    break;

  case 0x0c:
    unimplemented_instruction(*opcode);
    break;

  case 0x0d:
    unimplemented_instruction(*opcode);
    break;

  case 0x0e:
    unimplemented_instruction(*opcode);
    break;

  case 0x0f:
    unimplemented_instruction(*opcode);
    break;

  case 0x10:
    unimplemented_instruction(*opcode);
    break;

  case 0x11:
    unimplemented_instruction(*opcode);
    break;

  case 0x12:
    unimplemented_instruction(*opcode);
    break;

  case 0x13:
    unimplemented_instruction(*opcode);
    break;

  case 0x14:
    unimplemented_instruction(*opcode);
    break;

  case 0x15:
    unimplemented_instruction(*opcode);
    break;

  case 0x16:
    unimplemented_instruction(*opcode);
    break;

  case 0x17:
    unimplemented_instruction(*opcode);
    break;

  case 0x18:
    unimplemented_instruction(*opcode);
    break;

  case 0x19:
    unimplemented_instruction(*opcode);
    break;

  case 0x1a:
    unimplemented_instruction(*opcode);
    break;

  case 0x1b:
    unimplemented_instruction(*opcode);
    break;

  case 0x1c:
    unimplemented_instruction(*opcode);
    break;

  case 0x1d:
    unimplemented_instruction(*opcode);
    break;

  case 0x1e:
    unimplemented_instruction(*opcode);
    break;

  case 0x1f:
    unimplemented_instruction(*opcode);
    break;

  case 0x20:
    unimplemented_instruction(*opcode);
    break;

  case 0x21:
    unimplemented_instruction(*opcode);
    break;

  case 0x22:
    unimplemented_instruction(*opcode);
    break;

  case 0x23:
    unimplemented_instruction(*opcode);
    break;

  case 0x24:
    unimplemented_instruction(*opcode);
    break;

  case 0x25:
    unimplemented_instruction(*opcode);
    break;

  case 0x26:
    unimplemented_instruction(*opcode);
    break;

  case 0x27:
    unimplemented_instruction(*opcode);
    break;

  case 0x28:
    unimplemented_instruction(*opcode);
    break;

  case 0x29:
    unimplemented_instruction(*opcode);
    break;

  case 0x2a:
    unimplemented_instruction(*opcode);
    break;

  case 0x2b:
    unimplemented_instruction(*opcode);
    break;

  case 0x2c:
    unimplemented_instruction(*opcode);
    break;

  case 0x2d:
    unimplemented_instruction(*opcode);
    break;

  case 0x2e:
    unimplemented_instruction(*opcode);
    break;

  case 0x2f:
    unimplemented_instruction(*opcode);
    break;

  case 0x30:
    unimplemented_instruction(*opcode);
    break;

  case 0x31:
    unimplemented_instruction(*opcode);
    break;

  case 0x32:
    unimplemented_instruction(*opcode);
    break;

  case 0x33:
    unimplemented_instruction(*opcode);
    break;

  case 0x34:
    unimplemented_instruction(*opcode);
    break;

  case 0x35:
    unimplemented_instruction(*opcode);
    break;

  case 0x36:
    unimplemented_instruction(*opcode);
    break;

  case 0x37:
    unimplemented_instruction(*opcode);
    break;

  case 0x38:
    unimplemented_instruction(*opcode);
    break;

  case 0x39:
    unimplemented_instruction(*opcode);
    break;

  case 0x3a:
    unimplemented_instruction(*opcode);
    break;

  case 0x3b:
    unimplemented_instruction(*opcode);
    break;

  case 0x3c:
    unimplemented_instruction(*opcode);
    break;

  case 0x3d:
    unimplemented_instruction(*opcode);
    break;

  case 0x3e:
    unimplemented_instruction(*opcode);
    break;

  case 0x3f:
    unimplemented_instruction(*opcode);
    break;

  case 0x40:
    unimplemented_instruction(*opcode);
    break;

  case 0x41:
    unimplemented_instruction(*opcode);
    break;

  case 0x42:
    unimplemented_instruction(*opcode);
    break;

  case 0x43:
    unimplemented_instruction(*opcode);
    break;

  case 0x44:
    unimplemented_instruction(*opcode);
    break;

  case 0x45:
    unimplemented_instruction(*opcode);
    break;

  case 0x46:
    unimplemented_instruction(*opcode);
    break;

  case 0x47:
    unimplemented_instruction(*opcode);
    break;

  case 0x48:
    unimplemented_instruction(*opcode);
    break;

  case 0x49:
    unimplemented_instruction(*opcode);
    break;

  case 0x4a:
    unimplemented_instruction(*opcode);
    break;

  case 0x4b:
    unimplemented_instruction(*opcode);
    break;

  case 0x4c:
    unimplemented_instruction(*opcode);
    break;

  case 0x4d:
    unimplemented_instruction(*opcode);
    break;

  case 0x4e:
    unimplemented_instruction(*opcode);
    break;

  case 0x4f:
    unimplemented_instruction(*opcode);
    break;

  case 0x50:
    unimplemented_instruction(*opcode);
    break;

  case 0x51:
    unimplemented_instruction(*opcode);
    break;

  case 0x52:
    unimplemented_instruction(*opcode);
    break;

  case 0x53:
    unimplemented_instruction(*opcode);
    break;

  case 0x54:
    unimplemented_instruction(*opcode);
    break;

  case 0x55:
    unimplemented_instruction(*opcode);
    break;

  case 0x56:
    unimplemented_instruction(*opcode);
    break;

  case 0x57:
    unimplemented_instruction(*opcode);
    break;

  case 0x58:
    unimplemented_instruction(*opcode);
    break;

  case 0x59:
    unimplemented_instruction(*opcode);
    break;

  case 0x5a:
    unimplemented_instruction(*opcode);
    break;

  case 0x5b:
    unimplemented_instruction(*opcode);
    break;

  case 0x5c:
    unimplemented_instruction(*opcode);
    break;

  case 0x5d:
    unimplemented_instruction(*opcode);
    break;

  case 0x5e:
    unimplemented_instruction(*opcode);
    break;

  case 0x5f:
    unimplemented_instruction(*opcode);
    break;

  case 0x60:
    unimplemented_instruction(*opcode);
    break;

  case 0x61:
    unimplemented_instruction(*opcode);
    break;

  case 0x62:
    unimplemented_instruction(*opcode);
    break;

  case 0x63:
    unimplemented_instruction(*opcode);
    break;

  case 0x64:
    unimplemented_instruction(*opcode);
    break;

  case 0x65:
    unimplemented_instruction(*opcode);
    break;

  case 0x66:
    unimplemented_instruction(*opcode);
    break;

  case 0x67:
    unimplemented_instruction(*opcode);
    break;

  case 0x68:
    unimplemented_instruction(*opcode);
    break;

  case 0x69:
    unimplemented_instruction(*opcode);
    break;

  case 0x6a:
    unimplemented_instruction(*opcode);
    break;

  case 0x6b:
    unimplemented_instruction(*opcode);
    break;

  case 0x6c:
    unimplemented_instruction(*opcode);
    break;

  case 0x6d:
    unimplemented_instruction(*opcode);
    break;

  case 0x6e:
    unimplemented_instruction(*opcode);
    break;

  case 0x6f:
    unimplemented_instruction(*opcode);
    break;

  case 0x70:
    unimplemented_instruction(*opcode);
    break;

  case 0x71:
    unimplemented_instruction(*opcode);
    break;

  case 0x72:
    unimplemented_instruction(*opcode);
    break;

  case 0x73:
    unimplemented_instruction(*opcode);
    break;

  case 0x74:
    unimplemented_instruction(*opcode);
    break;

  case 0x75:
    unimplemented_instruction(*opcode);
    break;

  case 0x76:
    unimplemented_instruction(*opcode);
    break;

  case 0x77:
    unimplemented_instruction(*opcode);
    break;

  case 0x78:
    unimplemented_instruction(*opcode);
    break;

  case 0x79:
    unimplemented_instruction(*opcode);
    break;

  case 0x7a:
    unimplemented_instruction(*opcode);
    break;

  case 0x7b:
    unimplemented_instruction(*opcode);
    break;

  case 0x7c:
    unimplemented_instruction(*opcode);
    break;

  case 0x7d:
    unimplemented_instruction(*opcode);
    break;

  case 0x7e:
    unimplemented_instruction(*opcode);
    break;

  case 0x7f:
    unimplemented_instruction(*opcode);
    break;

  case 0x80:
    unimplemented_instruction(*opcode);
    break;

  case 0x81:
    unimplemented_instruction(*opcode);
    break;

  case 0x82:
    unimplemented_instruction(*opcode);
    break;

  case 0x83:
    unimplemented_instruction(*opcode);
    break;

  case 0x84:
    unimplemented_instruction(*opcode);
    break;

  case 0x85:
    unimplemented_instruction(*opcode);
    break;

  case 0x86:
    unimplemented_instruction(*opcode);
    break;

  case 0x87:
    unimplemented_instruction(*opcode);
    break;

  case 0x88:
    unimplemented_instruction(*opcode);
    break;

  case 0x89:
    unimplemented_instruction(*opcode);
    break;

  case 0x8a:
    unimplemented_instruction(*opcode);
    break;

  case 0x8b:
    unimplemented_instruction(*opcode);
    break;

  case 0x8c:
    unimplemented_instruction(*opcode);
    break;

  case 0x8d:
    unimplemented_instruction(*opcode);
    break;

  case 0x8e:
    unimplemented_instruction(*opcode);
    break;

  case 0x8f:
    unimplemented_instruction(*opcode);
    break;

  case 0x90:
    unimplemented_instruction(*opcode);
    break;

  case 0x91:
    unimplemented_instruction(*opcode);
    break;

  case 0x92:
    unimplemented_instruction(*opcode);
    break;

  case 0x93:
    unimplemented_instruction(*opcode);
    break;

  case 0x94:
    unimplemented_instruction(*opcode);
    break;

  case 0x95:
    unimplemented_instruction(*opcode);
    break;

  case 0x96:
    unimplemented_instruction(*opcode);
    break;

  case 0x97:
    unimplemented_instruction(*opcode);
    break;

  case 0x98:
    unimplemented_instruction(*opcode);
    break;

  case 0x99:
    unimplemented_instruction(*opcode);
    break;

  case 0x9a:
    unimplemented_instruction(*opcode);
    break;

  case 0x9b:
    unimplemented_instruction(*opcode);
    break;

  case 0x9c:
    unimplemented_instruction(*opcode);
    break;

  case 0x9d:
    unimplemented_instruction(*opcode);
    break;

  case 0x9e:
    unimplemented_instruction(*opcode);
    break;

  case 0x9f:
    unimplemented_instruction(*opcode);
    break;

  case 0xa0:
    unimplemented_instruction(*opcode);
    break;

  case 0xa1:
    unimplemented_instruction(*opcode);
    break;

  case 0xa2:
    unimplemented_instruction(*opcode);
    break;

  case 0xa3:
    unimplemented_instruction(*opcode);
    break;

  case 0xa4:
    unimplemented_instruction(*opcode);
    break;

  case 0xa5:
    unimplemented_instruction(*opcode);
    break;

  case 0xa6:
    unimplemented_instruction(*opcode);
    break;

  case 0xa7:
    unimplemented_instruction(*opcode);
    break;

  case 0xa8:
    unimplemented_instruction(*opcode);
    break;

  case 0xa9:
    unimplemented_instruction(*opcode);
    break;

  case 0xaa:
    unimplemented_instruction(*opcode);
    break;

  case 0xab:
    unimplemented_instruction(*opcode);
    break;

  case 0xac:
    unimplemented_instruction(*opcode);
    break;

  case 0xad:
    unimplemented_instruction(*opcode);
    break;

  case 0xae:
    unimplemented_instruction(*opcode);
    break;

  case 0xaf:
    unimplemented_instruction(*opcode);
    break;

  case 0xb0:
    unimplemented_instruction(*opcode);
    break;

  case 0xb1:
    unimplemented_instruction(*opcode);
    break;

  case 0xb2:
    unimplemented_instruction(*opcode);
    break;

  case 0xb3:
    unimplemented_instruction(*opcode);
    break;

  case 0xb4:
    unimplemented_instruction(*opcode);
    break;

  case 0xb5:
    unimplemented_instruction(*opcode);
    break;

  case 0xb6:
    unimplemented_instruction(*opcode);
    break;

  case 0xb7:
    unimplemented_instruction(*opcode);
    break;

  case 0xb8:
    unimplemented_instruction(*opcode);
    break;

  case 0xb9:
    unimplemented_instruction(*opcode);
    break;

  case 0xba:
    unimplemented_instruction(*opcode);
    break;

  case 0xbb:
    unimplemented_instruction(*opcode);
    break;

  case 0xbc:
    unimplemented_instruction(*opcode);
    break;

  case 0xbd:
    unimplemented_instruction(*opcode);
    break;

  case 0xbe:
    unimplemented_instruction(*opcode);
    break;

  case 0xbf:
    unimplemented_instruction(*opcode);
    break;

  case 0xc0:
    unimplemented_instruction(*opcode);
    break;

  case 0xc1:
    unimplemented_instruction(*opcode);
    break;

  case 0xc2:
    unimplemented_instruction(*opcode);
    break;

  case 0xc3:
    unimplemented_instruction(*opcode);
    break;

  case 0xc4:
    unimplemented_instruction(*opcode);
    break;

  case 0xc5:
    unimplemented_instruction(*opcode);
    break;

  case 0xc6:
    unimplemented_instruction(*opcode);
    break;

  case 0xc7:
    unimplemented_instruction(*opcode);
    break;

  case 0xc8:
    unimplemented_instruction(*opcode);
    break;

  case 0xc9:
    unimplemented_instruction(*opcode);
    break;

  case 0xca:
    unimplemented_instruction(*opcode);
    break;

  case 0xcb:
    unimplemented_instruction(*opcode);
    break;

  case 0xcc:
    unimplemented_instruction(*opcode);
    break;

  case 0xcd:
    unimplemented_instruction(*opcode);
    break;

  case 0xce:
    unimplemented_instruction(*opcode);
    break;

  case 0xcf:
    unimplemented_instruction(*opcode);
    break;

  case 0xd0:
    unimplemented_instruction(*opcode);
    break;

  case 0xd1:
    unimplemented_instruction(*opcode);
    break;

  case 0xd2:
    unimplemented_instruction(*opcode);
    break;

  case 0xd3:
    unimplemented_instruction(*opcode);
    break;

  case 0xd4:
    unimplemented_instruction(*opcode);
    break;

  case 0xd5:
    unimplemented_instruction(*opcode);
    break;

  case 0xd6:
    unimplemented_instruction(*opcode);
    break;

  case 0xd7:
    unimplemented_instruction(*opcode);
    break;

  case 0xd8:
    unimplemented_instruction(*opcode);
    break;

  case 0xd9:
    unimplemented_instruction(*opcode);
    break;

  case 0xda:
    unimplemented_instruction(*opcode);
    break;

  case 0xdb:
    unimplemented_instruction(*opcode);
    break;

  case 0xdc:
    unimplemented_instruction(*opcode);
    break;

  case 0xdd:
    unimplemented_instruction(*opcode);
    break;

  case 0xde:
    unimplemented_instruction(*opcode);
    break;

  case 0xdf:
    unimplemented_instruction(*opcode);
    break;

  case 0xe0:
    unimplemented_instruction(*opcode);
    break;

  case 0xe1:
    unimplemented_instruction(*opcode);
    break;

  case 0xe2:
    unimplemented_instruction(*opcode);
    break;

  case 0xe3:
    unimplemented_instruction(*opcode);
    break;

  case 0xe4:
    unimplemented_instruction(*opcode);
    break;

  case 0xe5:
    unimplemented_instruction(*opcode);
    break;

  case 0xe6:
    unimplemented_instruction(*opcode);
    break;

  case 0xe7:
    unimplemented_instruction(*opcode);
    break;

  case 0xe8:
    unimplemented_instruction(*opcode);
    break;

  case 0xe9:
    unimplemented_instruction(*opcode);
    break;

  case 0xea:
    unimplemented_instruction(*opcode);
    break;

  case 0xeb:
    unimplemented_instruction(*opcode);
    break;

  case 0xec:
    unimplemented_instruction(*opcode);
    break;

  case 0xed:
    unimplemented_instruction(*opcode);
    break;

  case 0xee:
    unimplemented_instruction(*opcode);
    break;

  case 0xef:
    unimplemented_instruction(*opcode);
    break;

  case 0xf0:
    unimplemented_instruction(*opcode);
    break;

  case 0xf1:
    unimplemented_instruction(*opcode);
    break;

  case 0xf2:
    unimplemented_instruction(*opcode);
    break;

  case 0xf3:
    unimplemented_instruction(*opcode);
    break;

  case 0xf4:
    unimplemented_instruction(*opcode);
    break;

  case 0xf5:
    unimplemented_instruction(*opcode);
    break;

  case 0xf6:
    unimplemented_instruction(*opcode);
    break;

  case 0xf7:
    unimplemented_instruction(*opcode);
    break;

  case 0xf8:
    unimplemented_instruction(*opcode);
    break;

  case 0xf9:
    unimplemented_instruction(*opcode);
    break;

  case 0xfa:
    unimplemented_instruction(*opcode);
    break;

  case 0xfb:
    unimplemented_instruction(*opcode);
    break;

  case 0xfc:
    unimplemented_instruction(*opcode);
    break;

  case 0xfd:
    unimplemented_instruction(*opcode);
    break;

  case 0xfe:
    unimplemented_instruction(*opcode);
    break;

  case 0xff:
    unimplemented_instruction(*opcode);
    break;

  default:
    unimplemented_instruction(*opcode);
    break;
  }
  state->pc += 1;
  return 1;
}
