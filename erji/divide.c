//ͳ�Ƴ�x�����пɱ�e������Ԫ�ظ������벻�ܱ�e������Ԫ�ظ���֮��
#include<stdio.h>
//#define N 10
#pragma warning(disable:4996)

int fun(int x[], int e, int *sum){
	int i,num=0;
	*sum=0;
	for(i=0;i<10;i++){
	if (x[i]%e==0) num++;
	else *sum = *sum+x[i];
	return num;
	}

}
int main(){
	int x[10]={1,7,8,6,10,15,11,13,29,31}, e=3, n,sum;
	n=fun(x,e,&sum);
	printf("n=%d ,sum=%d\n", n,sum);
	return 0;
}
