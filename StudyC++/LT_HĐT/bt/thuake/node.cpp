#include <iostream>
using namespace std;

class node
{
    protected:
        int data;
        node *next;
    public:
        node(int x);
        node(const node &x);
        void set_data(int data);
        void set_next(node *node);
        int get_data();
        node* get_next();
};

node::node(int x)
{
    data=x;
    next=NULL;
}

node::node(const node &x)
{
    this->data=x.data;
    this->next=x.next;
}

void node::set_data(int data)
{
    this->data=data;
}

void node::set_next(node *node)
{
    this->next=node;
}

int node::get_data()
{
    return data;
}

node* node::get_next()
{
    return next;
}