#ifndef Stack_h
#define Stack_h
class Stack{
    private:
        static int count;
        const int size;
        int top;
        int *data;
    public:
        Stack(const Stack &x);
        Stack(int s=10);
        ~Stack();

        bool Push(int x);
        bool Pop(int &x);
        bool isFull() const ;
        bool isEmpty() const;
        
        static void printCount() ;
        friend void Display(const Stack &x);
};
#endif