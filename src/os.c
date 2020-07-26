#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "internal.h"

int chdir_c(const char *path){
  return chdir(path);
}

void getcwd_c(char cwd[], int *stat){
  char cwd_tmp[PathLen];
  if(getcwd(cwd_tmp, sizeof(cwd_tmp)) == cwd_tmp){
    strcpy(cwd,cwd_tmp);
    *stat = 0;
  }
  else{
    *stat = 1;
  }
}

int mkdir_c(const char *path, int *mode){
  return mkdir(path,(mode_t)*mode);
}

int rename_c(const char *src, const char *dst){
  return rename(src,dst);
}

int rmdir_c(const char *path){
  return rmdir(path);
}

int unlink_c(const char *path){
  return unlink(path);
}
