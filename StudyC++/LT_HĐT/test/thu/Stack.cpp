#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack()
{
    this->current = 0;
}

template <class T>
Stack<T>::~Stack()
{

}

template <class T>
void Stack<T>::push(const T& i)
{
    if (this->current < this->max) 
    {
        this->contents[this->current] = i;
        this->current++;
    }
    else 
    {
        throw logic_error("Stack is full.");
    }
}

template <class T>
void Stack<T>::pop()
{
    if (this->current > 0)
    {
        this->current--;
    }
    else 
    {
        throw logic_error("Stack is empty.");
    }
}

template <class T>
T Stack<T>::peek()
{
    return contents[current - 1];
}

template <class T>
bool Stack<T>::isEmpty() const 
{
    return (this->current == 0);
}

template <class T>
bool Stack<T>::isFull() const 
{
    return (this->current == this->max);
}

template <class T>
T& Stack<T>::operator [] (const int& index)
{
    return contents[current - index - 1];
}

template <class T>
int Stack<T>::indexOf(string id)
{
    int *arr = new int [this->current];
    for (int i = 0; i < this->current; i++)
    {
        arr[i] = stoi(contents[i].getIdRoom());
    }
    int idRoom = stoi(id);
    int low = 0, high = this->current - 1;
    while (low <= high && ((idRoom >= arr[low] && idRoom <= arr[high]) || (idRoom <= arr[low] && idRoom >= arr[high])))
    {
        if (low == high)
        {
            if (arr[low] == idRoom) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (idRoom - arr[low]));
        if (arr[pos] == idRoom)
            return pos;
        if ((arr[pos] < idRoom && idRoom <= arr[high]) || (arr[pos] > idRoom && idRoom >= arr[high]))
            low = pos + 1;
        else 
            high = pos - 1;
    }
}

