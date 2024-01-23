#include "PhongKS.h"
#include "PhongBT.h"
#include "PhongVIP.h"
#include "QuanLi.h"
#include "Sample.h"

#ifndef LIST_H
#define LIST_H
class List
{
private:
    QuanLi<PhongKS> stack;
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
    void sort(bool);

    friend ostream& operator << (ostream& out, List&);
    PhongKS& operator [] (const int&);

};

#endif