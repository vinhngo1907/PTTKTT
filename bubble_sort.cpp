#include <stdio.h>
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

void bubble_sort(recordtype a[], int n)
{
	int i,j;
	for(i = 0; i <= n-2; i++)
	{
		for(j = n-1; j >= i+1; j--)
		{
			if(a[j].key < a[j-1].key)
			{
				swap(a[j],a[j-1]);
			}
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
	bubble_sort(a,n);
	xuatmang(a,n);
}
