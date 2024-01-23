#include <iostream>
using namespace std;

struct vecto
{
	float x,y,z;
};

istream& operator >>(istream& in, vecto& v);
ostream& operator <<(ostream& out, vecto& v);
vecto operator +(vecto a, vecto b);
vecto operator -(vecto a, vecto b);
float operator *(vecto a, vecto b);

main()
{
	vecto a,b,c;
	float t;
	cout << "Toa do vecto a: " << endl;
	cin >> a;
	cout << "Toa do vecto b: " << endl;
	cin >> b;
	
	c=a+b;
	cout << "a+b= " << c << endl;
	c=a-b;
	cout << "a-b= " << c << endl;
	t=a*b;
	cout << "a*b= " << t << endl;
	system("pause");
}

istream& operator >>(istream& in, vecto& v)
{
	cout << "x= ";
	cin >> v.x;
	cout << "y= ";
	cin >> v.y;
	cout << "z= ";
	cin >> v.z;
	return in;
}

ostream& operator <<(ostream& out, vecto& v)
{
	cout << "x=" << v.x << " ,y=" << v.y << " ,z=" << v.z;
	return out;
}

vecto operator +(vecto a, vecto b)
{
	vecto v;
	v.x= a.x + b.x;
	v.y= a.y + b.y;
	v.z= a.z + b.z;
	return v;
}

vecto operator -(vecto a, vecto b)
{
	vecto v;
	v.x= a.x - b.x;
	v.y= a.y - b.y;
	v.z= a.z - b.z;
	return v;
}

float operator *(vecto a, vecto b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
