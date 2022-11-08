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
int find_pivot(recordtype a[], int i, int j)
{
	keytype firstkey;
	int k ;
   	k = i+1;
   	firstkey = a[i].key;
   	while ( (k <= j) && (a[k].key == firstkey) ) k++;
   	if (k > j)  return -1;
   	else
   	{
	   if (a[k].key>firstkey) return k; 
	   else return i; //a[k].key < firstkey
   	}
}

int partition(recordtype a[], int i, int j, keytype pivot)
{
	int L,R;
	L = i;
	R = j;
	while (L <= R)
	{
	   while (a[L].key < pivot)  L++;
	   while (a[R].key >= pivot) R--;
 	   if (L<R) swap(a[L],a[R]);
	}
	return L;  
}
void quick_sort(recordtype a[], int i, int j)
{
	keytype pivot;
  	int pivotindex, k;
  	pivotindex = find_pivot(a,i,j);
  	if (pivotindex != -1) 
	{
		pivot = a[pivotindex].key;
      	k = partition(a,i,j,pivot);
      	quick_sort(a,i,k-1);
      	quick_sort(a,k,j);
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
	quick_sort(a,0,n-1);
	xuatmang(a,n);
}
