#include "sys_utils.h"

int main(void) {

  // page size 4096 (4k) on most systems
  long page_size = sysconf(_SC_PAGE_SIZE);

  // open the disk file with r/w permission, creat if not exists
  int disk_fd = open("mf_disk.bin", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
  if (disk_fd<0) { perror("mf_disk.bin open"); exit(EXIT_FAILURE); };

  // get disk file meta data
  struct stat Disk_stat = {};
  if (fstat(disk_fd,&Disk_stat)) { perror("fstat"); exit(EXIT_FAILURE); };

  void *disk_map = mmap(NULL, page_size, PROT_READ|PROT_WRITE,
                                                  MAP_SHARED, disk_fd, 0);
  if (disk_map == MAP_FAILED) { perror("mmap"); exit(EXIT_FAILURE); };

  close(disk_fd);

  return EXIT_SUCCESS;
}
