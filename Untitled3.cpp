#include <stdio.h>
#include <conio.h>
#define Tenfile "D:\\Thu vien lap trinh\\thuvien\\PTTKTT\\FileCanThiet\\dayso.inp"
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void swap(recordtype &x, recordtype &y)
{
	recordtype t  = x;
	x = y;
	y =t;
}

void selection_sort(recordtype a[], int n)
{
	keytype lowkey;
	for(int i = 0 ; i <= n -1; i++)
	{
		lowkey = a[i].key;
		int lowindex = i;
		for(int j = i +1; j < n; j++)
		{
			if(a[j].key < lowkey)
			{
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		swap(a[i],a[lowindex]);
	}
}
void insertion_sort(recordtype a[], int n)
{
	for(int i =1 ; i <= n-1; i++)
	{
		int j = i;
		while((j > 0) && (a[j].key < a[j-1].key))
		{
			swap(a[j],a[j-1]);
			j--;
		}
	}
}

void BubbleSort(recordtype a[], int n) 
{
	for(int i = 0; i <= n-2; i++)
	{
		for(int j = n-1; j >= i+1; j--)
		{
			if(a[j].key < a[j-1].key) swap(a[j],a[j-1]);
		}	
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
void xuatmang(recordtype a[100], int n)
{
	for(int i = 0 ; i <= n-1; i++)
	{
		printf("%5d",a[i]);
	}
}
int find_pivot(recordtype a[], int i, int j)
{
	keytype firstkey;
	int k = i+1;
	firstkey = a[i].key;
	while((k <= j) && a[k].key == firstkey) k++;
	if(k > j) return -1;
	else
	{
		if(a[k].key < firstkey) return k;
		else return i;
	}
}
int partition(recordtype a[], int i, int j, keytype pivot)
{
	int L, R;
	L = i; R = j;
	while(L <= R)
	{
		while(a[L].key < pivot) L++;
		while(a[R].key >= pivot) R--;
		if(L < R) swap(a[L], a[R]);
	}
	return L;
}
void quick_sort(recordtype a[], int i, int j)
{
	keytype pivot;
	int k, pivotindrex;
	pivotindrex = find_pivot(a,i,j);
	while(pivotindrex != 0)
	{
		pivot = a[pivotindrex].key;
		k = partition(a,i,j,pivot);
		quick_sort(a,i,k-1);
		quick_sort(a,k,j);
	}
}
int main(){
	recordtype a[100]; int n;
	if(DocFile(Tenfile,a,n) == 1)
	{
		printf("\t\tMang Sau Khi Sap Xep\t\t\n");
		xuatmang(a,n);
		selection_sort(a,n);
		printf("\n\t\tMang Sau Khi Sap Xep Chon\t\t\n");
		xuatmang(a,n);
		printf("\n\t\tMang Sau Khi Sap Xep Chen\t\t\n");
		insertion_sort(a,n);
		xuatmang(a,n);
		printf("\n\t\tMang Sau Khi Sap Xep Noi Bot\t\t\n");
		BubbleSort(a,n);
		xuatmang(a,n);
	}
	
	
	return 0;
	getch();
}

