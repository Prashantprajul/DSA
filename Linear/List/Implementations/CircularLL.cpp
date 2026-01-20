#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Ins_at_beg(int val, Node*& head)
{

}
void Ins_at_pos(int pos, int val, Node*& head)
{
    
}
void Ins_at_end(int val, Node*& head)
{
    
}

void Print(Node* head)
{

}

int main()
{
    Node* head = NULL;
    Ins_at_beg(35,head);// 35
    Print(head);
    Ins_at_end(25,head);// 35 25
    Print(head);
    Ins_at_beg(10,head);//10 35 25
    Print(head);
    Ins_at_end(45,head);//10 35 25 45
    Print(head);
    Ins_at_pos(100,2,head);
    Print(head);//10 100 35 25 45
    // Del_at_pos(3,head);
    // Print(head);//10 100 25 45
    // Del_at_pos(1,head);
    // Print(head);//100 25 45

}