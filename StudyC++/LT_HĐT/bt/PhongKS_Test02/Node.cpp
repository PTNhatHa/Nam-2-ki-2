#include <iostream>
#include <string>
#include "PhongKS.cpp"
using namespace std;

template<class T>
class Node
{
    private:
        T data;
        Node<T> *next;
    public:
        Node();
        Node(const Node &x);

        template<typename U>
        friend istream &operator >> (istream &in, Node<U> &x);
        template<typename U>
        friend ostream &operator << (ostream &out, const Node<U> &x);

        void set_data(T data);
        void set_next(Node *Node);
        T get_data();
        Node<T>* get_next();

};

template<class T>
Node<T>::Node()
{
    data = new T;
    next=NULL;
}

template<class T>
Node<T>::Node(const Node &x)
{
    this->data=x.data;
    this->next=x.next;
}

template<typename T>
istream &operator >> (istream &in, Node<T> &x)
{
    T dt;
    cin>>dt;
    x.data=dt;
    x.next=NULL;
    return in;
}

template<typename T>
ostream &operator << (ostream &out, const Node<T> &x)
{
    cout<<x.data;
    return out;
}


template<class T>
void Node<T>::set_data(T data)
{
    this->data=data;
}

template<class T>
void Node<T>::set_next(Node *node)
{
    this->next=node;
}

template<class T>
T Node<T>::get_data()
{
    return data;
}

template<class T>
Node<T>* Node<T>::get_next()
{
     return next;    
}
