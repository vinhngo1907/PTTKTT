#include <stdio.h>
#include <stdlib.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields ;
}recordtype;
void swap(recordtype &x, recordtype &y)
{
	recordtype tempt = x;
	x = y;
	y = tempt;
}

void insertion_sort(recordtype a[], int n)
{
	int i,j;
	for(i = 1; i <= n-1; i++)
	{
		j = i;
		while(j > 0 && a[j].key < a[j-1].key)
		{
			swap(a[j],a[j-1]);
			j--;
		}
	}
}
void xuatmang(recordtype a[], int n)
{
	int i;
	for(i = 0; i <= n-1; i++)
	{
		printf("%4d",a[i]);
	}
}

int main(){
	recordtype a[100];
	int n,i;
	FILE *file = fopen("dayso.inp","rt");
	fscanf(file,"%d",&n);
	for(i = 0; i <= n-1;i++)
	{
		fscanf(file,"%d",&a[i]);
	}
	insertion_sort(a,n);
	xuatmang(a,n);
}
