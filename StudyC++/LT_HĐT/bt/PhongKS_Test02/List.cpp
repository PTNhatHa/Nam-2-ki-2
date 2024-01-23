#include <iostream>
#include <string>
#include <cstdlib>
#include "List.h"

using namespace std;

List::List()
{

    this->length = 0;
}

List::~List()
{

}

void List::setLength(int length)
{
    this->length = length;
}


int List::getLength()
{
    return this->length;
}

void List::displayList()
{
    if (this->length == 0)
    {
        cout << "Hien tai khach san khong co phong nao ca." << endl;
    }
    else 
    {
        for (int i = 0; i < this->length; i++)
        {
            cout << "Phong thu " << i + 1 << ": " << endl;
            cout << this->stack[i];
            cout << endl << endl;
        }
    }

}

void List::insert(const PhongKS& room, int index)
{
    this->length++;
    Stack<PhongKS> temp;
    for (int i = 0; i < index; i++) 
    {
        temp.push(this->stack.top());
        this->stack.pop();       
        if (this->stack.isEmpty() == true) break;
    }
    this->stack.push(room);
    for (int i = 0; i < index; i++) 
    {
        this->stack.push(temp.top());
        temp.pop();  
        if (temp.isEmpty() == true) break;

    }    
}

void List::addFront(const PhongKS& room)
{
    this->insert(room, 0);
}

void List::addBack(const PhongKS& room)
{
    this->insert(room, this->length);
}

void List::removeAt(int index){
    // danh so theo so phong
    this->length--;
    Stack<PhongKS> temp;
    for (int i = 0; i < index; i++) 
    {
        temp.push(this->stack.top());
        this->stack.pop();       
        if (this->stack.isEmpty() == true) break;
    }
    temp.pop();
    for (int i = 0; i < index - 1; i++) 
    {
        this->stack.push(temp.top());
        temp.pop();  
        if (temp.isEmpty() == true) break;
    }    
}

int List::findById(string id)
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->stack[i].getmp() == id)
        {
            return i;
        }
    }
    return -1;
}

void List::update(const PhongKS& room)
{
    int index = findById(room.getmp());
    if (index >= 0)
    { 
        stack[index] = room;
    }
}

PhongKS& List::search(string id)
{
    return this->stack[this->findById(id)];
}

void List::sort(bool c)
{
    this->stack.mergeSort(0, this->length - 1, c);
}

PhongKS& List::operator [] (const int& index)
{
    return this->stack[index];
}