#include "elf.h"
#include "lib.h"

struct ElfHeader {
  struct Id {
    uint8_t magic[4];
    uint8_t class;
    uint8_t encoding;
    uint8_t version;
    uint8_t abi;
    uint8_t abi_version;
    uint8_t reserve[7];
  } id;
  uint16_t type;
  uint16_t machine;
  uint32_t version;
  uint32_t entry;
  uint32_t program_header_table_offset;
  uint32_t section_header_table_offset;
  uint32_t flags;
  uint16_t elf_header_size;
  uint16_t program_header_table_size;
  uint16_t program_header_table_number;
  uint16_t section_header_table_size;
  uint16_t section_header_table_number;
  uint16_t section_name_string_table_index;
};

struct ElfProgramHeader {
  uint32_t type;
  uint32_t offset;
  uint32_t virtual_address;
  uint32_t physical_address;
  uint32_t file_size;
  uint32_t memory_size;
  uint32_t flags;
  uint32_t align;
};

static bool elf_check(const struct ElfHeader* header) {
  if (header->id.magic[0] != 0x7f) return false;
  if (header->id.magic[1] != 'E') return false;
  if (header->id.magic[2] != 'L') return false;
  if (header->id.magic[3] != 'F' ) return false;
  if (header->id.magic[0] != 0x7f ||
      header->id.magic[1] != 'E'  ||
      header->id.magic[2] != 'L'  ||
      header->id.magic[3] != 'F' ) return false;
  if (header->id.class    != 1)    return false;  // 32-bit
  if (header->id.encoding != 1)    return false;  // LSB
  if (header->id.version  != 1)    return false;  // current version
  if (header->type        != 2)    return false;  // executable file
  if (header->machine     != 40)   return false;  // ARM(40)

  return true;
}


static bool elf_load_program(const struct ElfHeader* header) {
  puts("Elf Header address: "); putxvald((unsigned long)header,8); puts("\n");
  puts("Program Headers:\n");
  puts("Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align\n");
  for (int i = 0; i < header->program_header_table_number; i++) {
    struct ElfProgramHeader* p_header = (struct ElfProgramHeader*)(
        (char*)header
        + header->program_header_table_offset
        + header->program_header_table_size * i);

    if (p_header->type != 1) return false;  // loadable

    putxvald(p_header->offset,          6); puts(" ");
    putxvald(p_header->virtual_address, 8); puts(" ");
    putxvald(p_header->physical_address,8); puts(" ");
    putxvald(p_header->file_size,       5); puts(" ");
    putxvald(p_header->memory_size,     5); puts(" ");
    putxvald(p_header->flags,           1); puts(" ");
    putxvald(p_header->align,           3); puts("\n");
  }
}

char* elf_load(char* elf_file) {
  struct ElfHeader* header = (struct ElfHeader*)elf_file;

  if (!elf_check(header)) {
    return NULL;
  }
  if (!elf_load_program(header)) {
    return NULL;
  }

  return (char*)header->entry;
}
