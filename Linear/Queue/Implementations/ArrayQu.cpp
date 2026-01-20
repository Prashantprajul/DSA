#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int front;
    int back;
    int size;
public :
    Queue(int size)
    {
        arr = new int[size];
        front = -1;
        back = -1;
        this->size = size;
    }
    void push(int val)
    {
        if(back  < size-1)
        {
            arr[++back] = val;
        }
        else
        {
            cout<<"Queue Overflow !!!"<<endl;
            return;
        }
    }
    int pop()
    {
        if(back == -1)
        {
            cout<<"Queue is Empty !!!"<<endl;
            return;
        }
        else
        {
            front++;
            
        }
    }
    int size()
    {
        return this->size;
    }
    void print()
    {

    }
};

int main()
{
    int size=5;
    // cout<<"Enter size of Queue : ";
    // cin>>size;

    Queue Q(size);
    Q.push(5);
    Q.push(5);
    Q.push(5);
    Q.push(5);
    Q.print();
    Q.pop();
    Q.pop();
    // cout<<Q.isEmpty()<<endl;
    Q.print();
    // Q.pop();
    Q.pop();
    // cout<<Q.peek()<<endl;
    Q.pop();
    // Q.peek();
    // cout<<Q.isEmpty()<<endl;

}
