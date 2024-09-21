#include <stdio.h>
int main()
{
    char str[] = "hello";
    int f[] = {'j','k','l','\0'};
    char *t = "back";
    t+=2;
    printf("str=%s r=%s t=%s\n", str+1,f+1,t);
    return 0;
}