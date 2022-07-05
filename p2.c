#include <stdio.h>
int main()
{
    char str[] = "hello";
    char f[] = {'j','k','l','\0'};
    char *t = "back";
    printf("str=%s r=%s t=%s\n", str,f,t);
    return 0;
}