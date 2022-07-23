#include<stdio.h>
#include<stdlib.h>
int main()
{
    //malloc()--> return void pointer (memory allocation)
  /*  //calloc()--> continous memory
    //default memory from 0//
*/

    //free()
    //realloc()
    int *ptr;
    ptr=(int *)malloc(69*sizeof(int));
    return 0;
}
