#include<iostream>
using namespace std;

//Throw Exception during revision

// You used new, so you must think about:
// Destructor ✅ (done)
// Copy Constructor ❌
// Copy Assignment ❌

class Stack
{
private:
    /* data */
    int top = -1;
    int Size;
    int* arr;
public:
    //Stack(int Size) : Size(Size) , top(-1)
    Stack(int size)
    {
        arr = new int[size];
        Size = size;//Can we take same name ??
        //this->Size = Size; //Yes we can take but the condition is we should use like it 
        //Or use an initilizer list
    }
    ~Stack()
    {
        //Free memory here
        delete[] arr;
    }
    void push(int val)
    {
        if(top == Size-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else
        {
            arr[++top]=val;
        }
    }
    void print()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow !!!"<<endl;
            return;
        }
        else
        {
            //What If we also free deleted memory?Performance prespective
            //Bad for GPU, at the end memory will be deallocated, 
            //during use of object it will. be utilized at onother push
            top--;
        }
    }
    int peek()
    {
        if(top == -1)
        {
            cout<<"Empty Stack !!!"<<endl;
            return -1; //Throw Exception during revision
        }
        return arr[top];
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false;
    }
};

int main()
{
    int size=5;
    // cout<<"Enter size of stack : ";
    // cin>>size;

    Stack st(size);
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);
    st.print();
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;
    st.print();
    // st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    st.peek();
    cout<<st.isEmpty()<<endl;

}
