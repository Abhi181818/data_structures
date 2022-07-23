#include<stdio.h>
#include<stdlib.h>
struct student {
    char name[25];
    int age;
    
};

int main()
{
    /* code */

    struct student abhi={"Abhishek",19};
    struct student *ptr;
    ptr=&abhi;
    (*ptr).age=20;
    ptr -> age=69;
    printf("age= %d",abhi.age);
    return 0;
}
