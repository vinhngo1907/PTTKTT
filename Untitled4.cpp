#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef int keytype;
typedef float ordertype;
typedef struct{
	keytype key;
	ordertype orderfields;
}recordtype;

void swap(recordtype &x, recordtype &y)
{
	recordtype tempt = x;
	x = y;
	y = tempt;
}

int findpivot(recordtype a[], int i, int j)
{
	keytype firstkey;
	int k = i+1; firstkey = a[i].key;
	while((k <= j) && a[k].key == firstkey) k++;
	if(k>j) return -1;
	else{
		if(k>j)return k;
		else return i;
	}
}

int partition(recordtype a[], int i, int j, keytype pivot)
{
	int L,R;
	L = i; R = j;
	while(L <= R){
		while(a[L].key < pivot) L++;
		while(a[L].key >= pivot) R--;
		if(L < R) swap(a[L],a[R]);
	}
	return L;
}
void quick_sort(recordtype a[],int i, int j)
{
	keytype pivot;
	int pivotindex,k;
	pivotindex = findpivot(a,i,j);
	if(pivotindex != -1)
	{
		pivot = a[pivotindex].key;
		k = partition(a,i,j,pivot);
		quick_sort(a,i,k-1);
		quick_sort(a,k,j);
	}
}
void PushDown(recordtype a[], int first, int last){
int r = first;
while (r <= (last-1)/2)
if (last == 2*r+1){
if (a[r].key > a[last].key) swap(a[r],a[last]);
r = last;
}
else
if ((a[r].key>a[2*r+1].key) && (a[2*r+1].key < a[2*r+2].key)){
swap(a[r],a[2*r+1]);
r = 2*r+1;
}
else
if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key < a[2*r+1].key)){
swap(a[r],a[2*r+2]);
r = 2*r+2;
}
else r = last;
}
/*HeapSort*/
void HeapSort(recordtype a[], int n){
int i;
for (i = (n-2)/2; i>=0; i--)
PushDown(a,i,n-1);
for (i= n-1; i>=2; i--){
swap(a[0],a[i]);
PushDown(a,0,i-1);
}
swap(a[0],a[1]);
}
void xuatmang(recordtype a[], int n)
{
	for(int i = 0; i <= n-1; i++)
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
	HeapSort(a,n);
	xuatmang(a,n);
	return 0;
}
