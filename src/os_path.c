#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

double st_xtime2double(struct timespec time){
  return (double)time.tv_sec+((double)time.tv_nsec)*1.e-9;
}

double getatime_c(char *path) {
  struct stat statbuf;
  if(stat(path, &statbuf) != 0)                                                                     /* error */
    return -1.0;
  return st_xtime2double(statbuf.st_atim);
}

double getctime_c(char *path) {
  struct stat statbuf;
  if(stat(path, &statbuf) != 0)                                                                     /* error */
    return -1.0;
  return st_xtime2double(statbuf.st_ctim);
}

double getmtime_c(char *path) {
  struct stat statbuf;
  if(stat(path, &statbuf) != 0)                                                                     /* error */
    return -1.0;
  return st_xtime2double(statbuf.st_mtim);
}

long getsize_c(char *path) {
  struct stat statbuf;
  if(stat(path, &statbuf) != 0)                                                                     /* error */
    return -1;
  return (long)statbuf.st_size;
}

int isdir_c(char *path) {
  struct stat statbuf;
  if(stat(path, &statbuf) != 0)                                                                     /* error */
    return 0;
  return S_ISDIR(statbuf.st_mode);                                                                  /* 1 => is directory, 0 => this is NOT a directory */
}

int isfile_c(char *path) {
  struct stat statbuf;
  if(stat(path, &statbuf) != 0)                                                                     /* error */
    return 0;
  return S_ISREG(statbuf.st_mode);                                                                  /* 1 => is directory, 0 => this is NOT a directory */
}

int islink_c(char *path) {
  struct stat statbuf;
  if(lstat(path, &statbuf) != 0)                                                                     /* error */
    return 0;
  return S_ISLNK(statbuf.st_mode);                                                                 /* 1 => is directory, 0 => this is NOT a directory */
}

/* https://stackoverflow.com/questions/479226 */
/* https://stackoverflow.com/questions/45921123 */
int ismount_c(char *path) {

  struct stat statbuf_path;
  if(stat(path, &statbuf_path) != 0)                                                                /* error */
    return 0;

  char parent[strlen(path)+4];
  strcpy(parent,path);
  strcat(parent,"/..");                                                                             /* Careful, no parameter */
  struct stat statbuf_parent;
  if(stat(parent, &statbuf_parent) != 0)                                                            /* error, assume mounted */
    return 1;

  return (statbuf_path.st_dev != statbuf_parent.st_dev)
       ||(statbuf_path.st_ino == statbuf_parent.st_ino);
}

int samefile_c(char *path1, char *path2) {
  struct stat statbuf1;
  if(stat(path1, &statbuf1) != 0)                                                                   /* error */
    return -1;
  struct stat statbuf2;
  if(stat(path2, &statbuf2) != 0)                                                                   /* error */
    return -1;
  return statbuf1.st_dev == statbuf2.st_dev && statbuf1.st_ino == statbuf2.st_ino;
}
