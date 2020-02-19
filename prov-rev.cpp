/*
  Child process
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/mman.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <iostream>

int main(void)
{
  FILE *fp2;
  fp2 = fopen("res.txt", "a+");

  struct stat fs;
  fstat(fileno(fp2), &fs);

  void* map;
  map = mmap(NULL, fs.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fileno(fp2), 0);
  fclose(fp2);
}
