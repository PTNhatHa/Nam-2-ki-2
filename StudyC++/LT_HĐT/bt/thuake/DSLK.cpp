#include <iostream>
#include "node.cpp"
using namespace std;

class dslk
{
    protected:
        node *head;
        node *tail;
    public:
        dslk();
        dslk(int x);
        ~dslk();
        void display();

        void add_last(int data);
        void add_first(int data);
        void delete_after(node* n);
        void delete_first();

        node* find_node(int n) const; //trả về nút thứ n
        int search(int x) const; //trả về vị trí node có data=x

};

dslk::dslk()
{
    head=NULL;
    tail=NULL;
}

dslk::dslk(int x)
{
    node *n=new node(x);
    head=n;
    tail=n;
}

dslk::~dslk()
{
    node* node=head;
    while (node!=NULL)
    {
        head=node->get_next();
        delete node;
        if (head==NULL)
            tail=NULL;
        node=head;
    }
}

void dslk::display()
{
    if (head!=NULL)
    {
        cout<<"DSLK: ";
        node *n=head;
        while (n!=NULL)
        {
            cout<<n->get_data()<<"   ";
            n=n->get_next();
        }
        //return;
    }
    else
        cout<<"\nDSLK rong!!!\n";
}

void dslk::add_last(int data)
{
    node *n=new node(data);
    if(head!=NULL)
    {
        tail->set_next(n);
        tail=n;
        return;
    }
    else
    {
        head=n;
        tail=n;
        return;
    }
}

void dslk::add_first(int data)
{
    node *n=new node(data);
    if(head!=NULL)
    {
        n->set_next(head);
        head=n;
        return;
    }
    else
    {
        head=n;
        tail=n;
        return;
    }
}

void dslk::delete_after(node* n)
{
    if(n!=NULL)
    {
        node* p=n->get_next();
        if(p!=NULL)
        {
            if(tail==p)
                tail=n;
            n->set_next(p->get_next());
            delete p;
            cout<<"Xoa thanh cong\n";
        }
    }
}

void dslk::delete_first()
{
    if(head!=NULL)
    {
        node* p=head;
        head=p->get_next();
        delete p;
        if(head==NULL)
            tail=NULL;
        cout<<"Xoa thanh cong\n";
    }
    else
        cout<<"\nDs rong!!!\n";
}

node* dslk::find_node(int n) const
{
    node* p=head;
    int i=0;
    while(p!=NULL)
    {
        i++;
        if(i==n)
            return p;
        p=p->get_next();
    }
    return NULL;
}

int dslk::search(int x) const
{
    node* p=head;
    int i=0;
    while(p!=NULL)
    {
        if(p->get_data()==x)
            return i;
        p=p->get_next();
        i++;
    }
    return -1;
}