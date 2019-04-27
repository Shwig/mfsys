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

// defualt storage file to be mapped into the processes virtual space
#define DEFAULT_STORAGE_FILE "mf_disk.bin"
// default size of one block in the data segment of the disk_map
#define DEFAULT_BLOCK_SIZE 512

// A block in the FAT segment of the disk_map file
typedef struct fat_block_t {
  int fat_number;
  int block_number;
} Fat_block;

// A data block in the data_block segment of the disk_map file
typedef struct data_block_t {
  int block_address;
  void *data;
} Data_block;

// holds the meta data for a file stored in the data_block segment of disk_map file
typedef struct mfsys_file_t {
  int fat_number;
  int f_type;
  char *file_name;
} Sys_file;

// A directory
// A list of metat data for files stored in the data_block segment of disk_map file
typedef struct mfsys_dir_t {
  Sys_file *file_list;
} Sys_Dir;

// functions to operate on disk_map
// mf_open, mf_close(), mf_read(), mf_write()

#endif
