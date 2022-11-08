#include <stdio.h>
#include <stdlib.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void swap(recordtype &x, recordtype &y)
{
	recordtype tempt = x;
	x = y;
	y = tempt; 
}

void selection_sort(recordtype a[], int n)
{
	int i,j;
	keytype lowkey; int lowidx;
	for(i = 0; i <= n-2; i++)
	{
		lowkey = a[i].key;
		lowidx = i;
		for(j = i+1; j <= n-1; j++)
		{
			if(a[j].key < lowkey)
			{
				lowkey = a[j].key;
				lowidx = j;
			}
		}
		swap(a[i],a[lowidx]);
	}
}
void xuatmang(recordtype a[], int n)
{
	int i;
	for(i = 0; i<= n-1; i++)
	{
		printf("%4d",a[i]);
	}
}

int main(){
	recordtype a[100];
	int n, i;
	FILE *file = fopen("dayso.inp","rt");
	fscanf(file,"%d",&n);
	for(i = 0; i <= n-1; i++)
	{
		fscanf(file,"%d",&a[i]);
	}
	selection_sort(a,n);
	xuatmang(a,n);
	return 0;
}
