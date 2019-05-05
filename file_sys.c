#include "sys_utils.h"

int main(void) {

  // page size 4096 (4k) on most systems
  long page_size = sysconf(_SC_PAGE_SIZE);

  // open the disk file with r/w permission, creat if not exists
  int disk_fd = open(DISK_FILE, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
  if (disk_fd<0) { perror("DISK_FILE open"); close(disk_fd); return(EXIT_FAILURE); };

  // get disk file meta data
  // struct stat Disk_stat = {};
  // if (fstat(disk_fd,&Disk_stat)) { perror("fstat failed"); exit(EXIT_FAILURE); };

  // map disk_file to file_sys virtual space first byte is start of FAT partition
  Fat *fat = (Fat *) mmap(NULL, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, disk_fd, 0);
  if (fat == MAP_FAILED) { perror("mmap failed"); close(disk_fd); return(EXIT_FAILURE); };
  // Data partition beginins after the FAT partition
  Block *blocks =(Block *)(fat + DATA_OFFSET);

  // close disk_fd text file descriptor, use later for operations on disk_map
  if (close(disk_fd)) { perror("disk_fd close faild"); return(EXIT_FAILURE); };
  disk_fd = 0;

  // check pointer addresses and size of each
  printf("%p\n", (void *) fat);
  printf("%p\n", &fat[1]);
  printf("%p\n", (void *) blocks);
  printf("%p\n", &blocks[1]);
  printf("%lu\n", sizeof(*fat));
  printf("%lu\n", sizeof(*blocks));

  //initialize FAT
  

  // for (int i = 0; i < (DATA_OFFSET - 1); i++) {
  //   /* code */
  // }

  // create root directory

  // unmap the disk file
  if (munmap(fat, page_size)) { perror("munmap failed"); return(EXIT_FAILURE); };

  return EXIT_SUCCESS;
}
