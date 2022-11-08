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
void push_down(recordtype a[], int first, int last)
{
	int r = first;
	while(r <= (last-1)/2)
	{
		if(last == 2*r+1)
		{
			if(a[r].key > a[last].key)	swap(a[r],a[last]);
			r = last;
		}
		else if(a[r].key > a[2*r+1].key && (a[2*r+1].key <= a[2*r+2].key))
		{
			swap(a[r],a[2*r+1]);
			r = 2*r+1;
		}
			
		else if(a[r].key > a[2*r+2].key && a[2*r+2].key < a[2*r+1].key)
		{
			swap(a[r],a[2*r+2]);
			r = 2*r+2;
		}
		else r = last;
	}
}

void heap_sort(recordtype a[], int n)
{
	int i;
	for(i  =(n-2)/2; i >= 0; i--)
	{
		push_down(a,i,n-1);

	}
	for(i = n-1; i >= 2; i--)
	{
		swap(a[0],a[i]);
		push_down(a,0,i-1);
	}
	swap(a[0],a[1]);
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
	heap_sort(a,n);
	xuatmang(a,n);
	return 0;
}
