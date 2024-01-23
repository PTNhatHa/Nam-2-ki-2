#include "PhongKS.h"
#include "Stack.h"
#include "Sample.h"

#ifndef LIST_H
#define LIST_H

class List
{
private:
    // Stack<T> stack;
    Stack<PhongKS> stack;
    int length;
public:
    List();
    ~List();
    void setLength(int);
    int getLength();
    void displayList();

    void insert(const PhongKS&, int);
    void addFront(const PhongKS&);
    void addBack(const PhongKS&);
    void removeAt(int index);
    int findById(string id);
    void update(const PhongKS&);
    PhongKS& search(string);

    friend ostream& operator << (ostream& out, List&);
    PhongKS& operator [] (const int&);

};

#endif