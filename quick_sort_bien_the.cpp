#include <stdio.h>
#include <stdlib.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void Swap(recordtype &x, recordtype &y)
{
	recordtype tempt = x;
	x = y;
	y = tempt;
}
int FindPivot(recordtype a[], int i, int j)
{
 	keytype firstkey;
	int k ;
   	k = i+1;
   	firstkey = a[i].key;
   	while ( (k <= j) && (a[k].key == firstkey) ) k++;
   	if (k > j)  return -1;
   	else
   	{
	   if (a[k].key <= firstkey) return i; 
	   else return k; //a[k].key < firstkey
   	}
}
int Partation(recordtype a[], int i, int j, keytype pivot)
{
	int L,R;
	L = i;
	R = j;
	while (L <= R)
	{
	   while (a[L].key < pivot)  L++;
	   while (a[R].key >= pivot) R--;
 	   if (L<R) Swap(a[L],a[R]);
	}
	return L;  
}
void QuickSort(recordtype a[], int i, int j)
{
	keytype pivot;
	int pivotidx, k;
	pivotidx = FindPivot(a,i,j);
	if(pivotidx != -1)
	{
		pivot = a[pivotidx].key;
		k = Partation(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
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
	int n,i; 
	recordtype a[100];
		FILE *file = fopen("dayso.inp","rt");
	fscanf(file,"%d",&n);
	for(i = 0; i <= n-1;i++)
	{
		fscanf(file,"%d",&a[i]);
	}
	QuickSort(a,0,n-1);
	xuatmang(a,n);
}
