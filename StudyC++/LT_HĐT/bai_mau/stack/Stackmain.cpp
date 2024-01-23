#include "Stack.h"
#include "Stack.cpp"
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Nhap so nguyen n: "; cin>>n;
    Stack::printCount();
    Stack S(8);
    S.printCount();
    Stack::printCount();
    do {
        S.Push(n%16);
        n = n/16;
    } while (n);
    cout<<"Day so thap luc phan: ";
    int x;
    Stack S1 = S;
    char hex[] = "0123456789ABCDEF";
    while (!S.isEmpty()) {
        S.Pop(x);
        cout<<hex[x];
    }
    cout<<endl;
    cout<<S1.isEmpty()<<endl;
    S1.printCount();

    return 0;
}