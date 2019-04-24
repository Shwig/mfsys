#ifndef SYS_UTILS_H
#define SYS_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define DEFAULT_STORAGE_FILE "m_disk"

typedef struct sys_fat_t {
  int fat_id;
  int block_id;
} Sys_fat;

#endif
