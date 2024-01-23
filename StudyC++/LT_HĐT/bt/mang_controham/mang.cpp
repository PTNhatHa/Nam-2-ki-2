#include <iostream>
using namespace std;

int n;
istream& operator >>(istream& in, float *a);
ostream& operator <<(ostream& out, float *a);
void ptvt(float *a);

bool ascending(float left, float right);
bool descending(float left, float right);
void selection_sort(float *a, int n, bool CompFunc(float,float));
void insertion_sort(float *a, int n, bool CompFunc(float,float));
void bubble_sort(float *a, int n, bool CompFunc(float,float));
void quick_sort(float *a, int l, int r, bool CompFunc(float,float));

int tim_tuantu(float *a, int n, float x);
int tim_nhiphan(float *a, int n, float x);

main()
{
	do
	{
		cout << "So phan tu cua mang n= ";
		cin >> n;
	} 
	while (n<=0);
	
	float a[n];
	cout << "Nhap mang a:" << endl;
	cin >> a;
	cout << a;
	
	int size = sizeof a;
	cout << "Kich thuoc mang: " << (sizeof(a)/sizeof(float)) << endl;
	ptvt(a);
	
	cout << endl << "Selection Sort : " << endl;
	cout << "Tang dan:" << endl;
	selection_sort(a,n,ascending);
	cout << "Giam dan:" << endl;
	selection_sort(a,n,descending);
	
	cout << endl << "Insert Sort : " << endl;
	cout << "Tang dan:" << endl;
	insertion_sort(a,n,ascending);
	cout << "Giam dan:" << endl;
	insertion_sort(a,n,descending);
	
	cout << endl << "Bubble Sort : " << endl;
	cout << "Tang dan:" << endl;
	bubble_sort(a,n,ascending);
	cout << "Giam dan:" << endl;
	bubble_sort(a,n,descending);
	
	cout << endl << "Quick Sort : " << endl;
	cout << "Tang dan:" << endl;
	quick_sort(a,0,n-1,ascending); cout << a;
	cout << "Giam dan:" << endl;
	quick_sort(a,0,n-1,descending); cout << a;
	
	float x, vt;
	cout << "Nhap phan tu can tim x= ";
	cin >> x;
	vt=tim_tuantu(a,n,x);
	cout << "Tim kiem tuan tu" << endl;
	if (vt==-1) cout << "Khong tim thay" << endl;
	else cout << "Tim thay x tai vi tri: " << vt << endl;
	
	vt=tim_nhiphan(a,n,x);
	cout << "Tim kiem nhi phan" << endl;
	if (vt==-1) cout << "Khong tim thay" << endl;
	else cout << "Tim thay x tai vi tri: " << vt << endl;
	
	system("pause");
}

istream& operator >>(istream& in, float *a)
{
	for(int i=0;i<n;i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	return in;
}

ostream& operator <<(ostream& out, float *a)
{
	cout << "Mang da nhap la:" << endl;
	for(int i=0;i<n;i++)
		cout << "a[" << i << "]=" << a[i] << endl;
	return out;
}

void ptvt(float *a)
{
	int i;
	do
	{
		cout << "Vi tri i= ";
		cin >> i;
	}
	while (i<0 || i>=n);
	cout << "a[" << i << "]=" << a[i] << endl;
}

bool ascending(float left, float right)
{
	return left<right;
}

bool descending(float left, float right)
{
	return left>right;
}
 //sx chọn
void selection_sort(float *a, int n, bool CompFunc(float,float)) //con trỏ hàm comfund
{
	int i,j,m;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if (CompFunc(a[j],a[m])) m=j;
		swap(a[i],a[m]);
	}
	cout << a;
}

//sx chèn: tìm min/max hoán đổi vs pt đầu a[i]
void insertion_sort(float *a, int n, bool CompFunc(float,float))
{
	int i,j; float x;
	for(i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while ((j>=0)&&(CompFunc(x,a[j])))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
	cout << a;
}

//sx nổi bọt: ss 2 pt kề nhau
void bubble_sort(float *a, int n, bool CompFunc(float,float))
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=n-1;j>i;j--)
			if(CompFunc(a[j],a[j-1]))
				swap(a[j],a[j-1]);
	cout << a;
}

//sx nhanh
void quick_sort(float *a, int l, int r, bool CompFunc(float,float))
{
	int CF;
	if(CompFunc(0,1)) CF=0;//asc
	else CF=1;//des
	
	int i, j, x;
	x=a[(l+r)/2];
	i=l; j=r;
	do
	{
		while(CompFunc(a[i],x)) i++;
		while(CompFunc(x,a[j])) j--;
		if(i <= j){
			swap(a[i],a[j]);
			i++; j--;
		}
	}while(i<=j);
	
	if(l<j)
		if(CF) quick_sort(a, l, j, descending);
		else quick_sort(a, l, j, ascending);
	
	if(i<r)
		if(CF) quick_sort(a, i, r, descending);
		else quick_sort(a, i, r, ascending);
}



int tim_tuantu(float *a, int n, float x)
{
	int i=0;
	a[n]=x;
	while (x!=a[i]) i++;
	if (i==n) return -1;
	else return i;
}

int tim_nhiphan(float *a, int n, float x)
{
	selection_sort(a,n,ascending);
	int t,p,g;
	t=0; p=n-1;
	while (t<=p)
	{
		g=(t+p)/2;
		if (x<a[g]) p=g-1;
		else if (x>a[g]) t=g+1;
			else return g;
	}
	return -1;
}
