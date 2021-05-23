#include<stdio.h>

int main()
{
    int a =1025; // 1025 = 00000000 00000000 00000100 00000001
                               // 0        0        4        1
    int *p=&a;
    printf("address: %d, value: %d\n", p, *p);
    printf("address: %d, value: %d\n", p+1, *(p+1));
    char *p1=(char*)p;
    printf("address: %d, value: %d\n", p1, *p1);
    printf("address: %d, value: %d\n", p1+1, *(p1+1));
    *p1=2;
    void *p2=p;
    printf("generic pointer type: %d\n", p2);
    printf("the value of a: %d", a);
}