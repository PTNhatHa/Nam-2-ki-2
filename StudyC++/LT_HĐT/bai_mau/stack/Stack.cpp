#include "Stack.h"
#include <iostream>
using namespace std;
int Stack::count = 0;
Stack::Stack(int s):size(s), top(-1), data(new int [s]){
    count++;
    // size = s;
    // top = -1;
    // data = new int [size];
}
Stack::Stack(const Stack &x): size(x.size){
    //this->size = x.size;
    count++;
    top = x.top;
    data = new int [size];
    for(int i =0; i<= top; i++) 
        data[i] = x.data[i];
}
Stack::~Stack(){
    delete [] data;
    count--;
}
bool Stack::Push(int x){
    if (!isFull()) {
        data[++top] = x;
        return 1;
    }
    return 0;
}
bool Stack::Pop(int &x){
    if (!isEmpty()) {
        x = data[top--];
        return 1;
    }
    return 0;
}
bool Stack::isFull() const {
    return (top == size-1);
}
bool Stack::isEmpty() const {
    return (top == -1);
}
void Display(const Stack &x){
    for(int i =0; i<= x.top; i++)
        cout<<x.data[i]<<" ";
    cout<<endl;
}
void Stack::printCount() {
    cout<<"Co "<<count<<" Stack."<<endl;
}