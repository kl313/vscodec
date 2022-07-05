//将字符型数字转为整型
#include<stdio.h>
#include<string.h>

long fun(char*p)

{
	int i,len;
	long x=0;
	len=strlen(p);
	while(*p!=0)
	{
		x=(*p-'0')+10*x;
		p++;
	}
	return x;
}
int main()
{
	char s[10];
	int n;
	printf("enter a string:\n");
	gets(s);
	n=fun(s);
	printf("%d\n",n);
	return 0;
	//getchar();
}