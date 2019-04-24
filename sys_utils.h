#ifndef SYS_UTILS_H
#define SYS_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DEFAULT_STORAGE_FILE "mf_disk.bin"

typedef struct sys_fat_t {
  int fat_id;
  int block_id;
} Sys_fat;

#endif
