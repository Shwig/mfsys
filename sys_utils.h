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

#define DEFAULT_OFFSET 2048

// An entry in the FAT segment of the disk_map file
typedef struct fat_t {
  int f_number; // file number first data_block of file or current data_block index
  int next;     // next block index, -2 free block, -1 last block of file
} Fat;

// A data block in the data_block segment of the disk_map file
typedef struct disk_block_t {
  char data[DEFAULT_BLOCK_SIZE];
} Block;

// holds the meta data for a file stored in the data_block segment of disk_map file
typedef struct m_file_t {
  int f_number;
  int f_type;
  char file_name[32];
} M_file;

// A directory
// A list of metat data for files stored in the data_block segment of disk_map file
typedef struct m_dir_t {
  M_file file_list[64];
} M_dir;

// functions to operate on disk_map
// mf_open, mf_close(), mf_read(), mf_write()

#endif
