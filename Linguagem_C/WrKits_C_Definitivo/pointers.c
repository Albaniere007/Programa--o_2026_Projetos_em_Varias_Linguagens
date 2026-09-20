#include<stdio.h>
#include<stdlib.h>




int main(){

    int *ptr;
    int var;

    int *ptr_pt = NULL;


    var=5;
    ptr = &var;

    printf("%X\n",&var);
    printf("%X\n",ptr);
    printf("%X\n",&ptr);
    printf("%X\n",var);
    printf("%X\n",*ptr);


    *ptr = 8;

    printf("%X\n", var);


    return 0;
}