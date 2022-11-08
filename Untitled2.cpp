#include <stdio.h>
#include <conio.h>
#define Max 100
#define Tenfile "D:\\Thu vien lap trinh\\thuvien\\PTTKTT\\FileCanThiet\\dayso.inp"
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;
void Swap(recordtype &x,recordtype &y)
{
	recordtype tempt = x;
	x = y; 
	y = tempt;
}
int FindPivot(recordtype a[], int i,int j)
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
	   else return i;
   	}
}

int Partition(recordtype a[], int i, int j, keytype pivot)
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
void QuickSort(recordtype a[], int i,int j)
{ 
	keytype pivot;
  	int pivotindex, k;
  	pivotindex = FindPivot(a,i,j);
  	if (pivotindex != -1) 
	{
		pivot = a[pivotindex].key;
      	k = Partition(a,i,j,pivot);
      	QuickSort(a,i,k-1);
      	QuickSort(a,k,j);
  	}
}

void xuatmang(recordtype a[100], int n)
{
	for(int i = 0 ; i <= n-1; i++)
	{
		printf("%5d",a[i]);
	}
}
int DocFile(char *FileName, recordtype a[100], int &n)
{
	FILE *f = fopen(Tenfile,"rt");
	if(f == NULL) 
	{
		printf("Error: Please try again !");
		return 0;
	}
	fscanf(f,"%d",&n);
	for(int i = 0 ; i <= n-1; i++)
	{
		fscanf(f,"%d",&a[i]);
	}
	return 1;
}
int main(){
	recordtype a[100]; int n,k;
	DocFile(Tenfile,a,n);
	printf("\t\tMang Vua Nhap\t\n");
	xuatmang(a,n);
	printf("\n\t\tMang Sau Khi Sap Xep\t\n");
	QuickSort(a,0,n-1);
	xuatmang(a,n);
	return 0;
}


