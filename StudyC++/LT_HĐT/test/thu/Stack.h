#pragma once
#include <iostream>
#include <exception>
#include "PhongKS.h"
#include <string>
using namespace std;

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
    static const int max = 100;
    T contents[max];
    int current;
public:
    Stack();
    ~Stack();
    void push(const T&);
    void pop();
    T peek(); //lay phan tu tren cung ma khong xoa
    bool isEmpty() const;
    bool isFull() const;
    T& operator [] (const int&);

    // searchByIdRoom
    int indexOf(string);
};

#endif