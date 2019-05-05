#include "sys_utils.h"

int main(void) {

  // page size 4096 (4k) on most systems
  long page_size = sysconf(_SC_PAGE_SIZE);

  // open the disk file with r/w permission, creat if not exists
  int disk_fd = open(DEFAULT_STORAGE_FILE, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
  if (disk_fd<0) { perror("DEFAULT_STORAGE_FILE open"); close(disk_fd); return(EXIT_FAILURE); };

  // get disk file meta data
  // struct stat Disk_stat = {};
  // if (fstat(disk_fd,&Disk_stat)) { perror("fstat failed"); exit(EXIT_FAILURE); };

  // map file to file_sys virtual space
  // void *disk_map = mmap(NULL, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, disk_fd, 0);
  // if (disk_map == MAP_FAILED) { perror("mmap failed"); close(disk_fd); return(EXIT_FAILURE); };
  Fat *fat_table = (Fat *) mmap(NULL, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, disk_fd, 0);
  if (fat_table == MAP_FAILED) { perror("mmap failed"); close(disk_fd); return(EXIT_FAILURE); };
  Block *blocks =(Block *)(fat_table + DEFAULT_OFFSET);

  // close disk_fd text file descriptor, use later for operations on disk_map
  if (close(disk_fd)) { perror("disk_fd close faild"); return(EXIT_FAILURE); };
  disk_fd = 0;

  // check pointer addresses and size of each
  // printf("%p\n", (void *) fat_table);
  // printf("%p\n", (void *) blocks);
  // printf("%lu\n", sizeof(*fat_table));
  // printf("%lu\n", sizeof(*blocks));


  // unmap the disk file
  if (munmap(fat_table, page_size)) { perror("munmap failed"); return(EXIT_FAILURE); };

  return EXIT_SUCCESS;
}
