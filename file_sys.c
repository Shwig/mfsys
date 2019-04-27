#include "sys_utils.h"

int main(void) {

  // page size 4096 (4k) on most systems
  long page_size = sysconf(_SC_PAGE_SIZE);

  // open the disk file with r/w permission, creat if not exists
  int disk_fd = open("mf_disk.bin", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
  if (disk_fd<0) { perror("mf_disk.bin open"); return(EXIT_FAILURE); };

  // get disk file meta data
  // struct stat Disk_stat = {};
  // if (fstat(disk_fd,&Disk_stat)) { perror("fstat failed"); exit(EXIT_FAILURE); };

  // map file to file_sys virtual space
  void *disk_map = mmap(NULL, page_size, PROT_READ|PROT_WRITE,
                                                  MAP_SHARED, disk_fd, 0);
  if (disk_map == MAP_FAILED) { perror("mmap failed"); return(EXIT_FAILURE); };

  // close disk_fd text file descriptor, use later for operations on disk_map
  if (close(disk_fd)) { perror("disk_fd close faild"); return(EXIT_FAILURE); };

  //partition file into FAT and DataBlock segemnts
  /* ?????  */



  // unmap the disk file
  if (munmap(NULL, page_size)) { perror("munmap failed"); return(EXIT_FAILURE); };

  return EXIT_SUCCESS;
}
