#include <stdio.h>
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
	y =tempt;
}
void PushDown(recordtype a[], int first, int last)
{
	int r = first;
	while(r <= (last-1)/2)
	{
		if(last == 2*r+1)
		{
			if(a[r].key > a[last].key) 
				Swap(a[r],a[last]);
				r = last;
		}else 
		if(a[r].key > a[2*r+1].key && a[2*r+1].key <= a[2*r+2].key)
		{
			Swap(a[r],a[2*r+1]);
			r = 2*r+1;
		}else
		if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key<a[2*r+1].key))
		{
			Swap(a[r],a[2*r+2]);
			r = 2*r+2;
		}
		else r = last;
	}
}

void PushDown_1(recordtype a[], int first,int last)
{ 
	int  r= first;
  	while (r <= (last-1)/2)
	{
		if (last == 2*r+1)
		{
	     	if (a[r].key > a[last].key) Swap(a[r],a[last]);
	     	r = last;
	   	} else
	   	if ((a[r].key>a[2*r+1].key) && (a[2*r+1].key<=a[2*r+2].key))
	   	{
	      Swap(a[r],a[2*r+1]);
	      r = 2*r+1 ;
	   	} else
	    if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key<a[2*r+1].key))
	    {
			 Swap(a[r],a[2*r+2]);
			 r = 2*r+2 ;
	    }
	    else r = last;
	}
}

void HeapSort(recordtype a[], int n)
{
	int i;
	for(i = (n-2)/2; i >= 0; i--)
	{
		PushDown(a,i,n-1);	
	}
	for(i = n-1; i >= 2; i--)
	{
		Swap(a[0],a[i]);
		PushDown(a,0,i-1);
	}
	Swap(a[0],a[1]);
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
	HeapSort(a,n);
	xuatmang(a,n);
}
