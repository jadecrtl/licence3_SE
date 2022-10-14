#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

ino_t inode_number(char *file){
  struct stat st;

  if(stat(file, &st)==-1)
    return -1;

  return st.st_ino;
}

int main(int argc, char **argv){
  int i;
  ino_t n;
  
  if(argc<2){
    fprintf(stderr, "usage: %s file1 [file2 ... fileN]\n", argv[0]);
    exit(1);
  }

  for(int i=1; i<argc; i++){
    n = inode_number(argv[i]);
    if(n != -1) printf("%s: %ld\n", argv[i], n);
    else perror(argv[i]);
  }
  
  return 0;
}
