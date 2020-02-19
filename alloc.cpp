/*
  Allocator Program
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
using namespace std;

void question2();

//asks the first user question, continously loops
void question1()
{
     char yORn;

     cout << "Allocate more resources(y/n)? ";

     cin >> yORn;

     if (yORn == 'y')
     {
       question2();
     }
     else if (yORn == 'n')
     {
       question1();
     }
     else {printf("INVALID INPUT\n");}
}

//asks second user question, stores values
void question2()
{
  int r1;
  int r2;

  cout << "Enter the resource number and number of resources needed: ";
  cin >> r1;
  cin >> r2;

  question1();
}

int main(void)
{
  //saves input into array for testing
  char res[9999];
  int tc = 0;
  char c;
  FILE *fp;
   fp = fopen("res.txt", "r");
   //sorts file into 1D array
   while ((c = getc(fp)) != EOF)
   {
     if (isdigit(c))
     {
       res[tc] = c;
       tc++;
     }
   }
   fclose(fp);

   /*
   int i;

   for(i = 0; i < tc; i++)
   {
     printf("%c\n", res[i]);
   }

   int x = res[3];
   printf("%d\n", x);
   */

   //Saves input in mmap
   FILE *fp2;
   fp2 = fopen("res.txt", "a+");

   struct stat fs;
   fstat(fileno(fp2), &fs);

   void* map;
   map = mmap(NULL, fs.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fileno(fp2), 0);
   fclose(fp2);

   question1();
}
