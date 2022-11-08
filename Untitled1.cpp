#include <stdio.h>
#include <conio.h>
#define Tenfile "D:\\Thu vien lap trinh\\thuvien\\PTTKTT\\FileCanThiet\\dayso.inp"
typedef int keytype;
typedef float ordertype;
typedef struct{
	keytype key;
	ordertype orderfields;
}recordtype;

void Swap(recordtype &x, recordtype &y)
{
	recordtype tempt = x;
	x = y;
	y = tempt;
}

void Selection_Sort(recordtype a[], int n)
{
	int lowindex; 
	keytype lowkey;
	for(int i = 0; i <= n-2; i++)
	{
		lowkey = a[i].key;
		lowindex = i;
		for(int j = i+1; j <= n-1; j++)
		{
			if(a[j].key < lowkey)
			{
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		Swap(a[i],a[lowindex]);
	}
}

void insertion_Sort(recordtype a[], int n)
{
	int i,j;
	for(i = 1; i <= n-1; i++)
	{
		j  = i;
		while(j > 0 && (a[j].key < a[j-1].key))
		{
			Swap(a[j],a[j-1]);
			j--;
		}
		
	}
}

void Bubble_Sort(recordtype a[], int n)
{
	for(int i = 0; i <= n-2; i++)
	{
		for(int j = n-1; j >= i+1; j--)
		{
			if(a[j].key < a[j-1].key)
			{
				Swap(a[j],a[j-1]);
			}
		}
	}
}
int Doc_File(char *FileName, recordtype a[100], int &n)
{
	FILE *f = fopen(Tenfile,"rt");
	if(f == NULL) 
	{
		printf("Error: PLease try again !\n");
		return 0;
	}
	fscanf(f,"%d",&n);
	for(int i =0 ; i<= n -1; i++)
	{
		fscanf(f,"%d",&a[i]);
	}
	return 1;
}
void XuatFile(recordtype a[100], int n)
{
	for(int i =0 ; i<= n -1; i++)
	{
		printf(" %3d ",a[i]);
	}
}
int main(){
	recordtype a[100]; int n;
	if(Doc_File(Tenfile,a,n) == 1)
	{
		printf("\n\t\tMang Vua Nhap\t\t\n"); XuatFile(a,n);
		
		printf("\n\t\tDanh Sach Sau Khi Sap Xep - Selection_Sort\t\t\n"); Selection_Sort(a,n); XuatFile(a,n);
		printf("\n\t\tDanh Sach Sau Khi Sap Xep - Insertion_Sort\t\t\n"); insertion_Sort(a,n); XuatFile(a,n);
		printf("\n\t\tDanh Sach Sau Khi Sap Xep - Bubble_Sort\t\t\n"); Bubble_Sort(a,n); XuatFile(a,n);
	}
	return 0;
	getch();
}
