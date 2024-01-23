#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int n;
    fstream inp;
    inp.open("D:\\StudyC++\\heloo.txt",ios::trunc);
    cout<<"n=";
    cin>>n;
    inp<<n;
    inp<<"\n";
    inp.close();
    return 0;
}