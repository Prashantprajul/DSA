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

#pragma region Insertion

void Ins_at_beg(int val, Node*& head)
{
    //Also handle empty LL
    Node* ins = new Node(val);
    if(head == NULL)
        head = ins;
    else
    {
        ins->next = head;
        head = ins;
    }
}

void Ins_at_end(int val, Node*& head)
{
    //Also handle empty LL
    Node* tmp = head;
    Node* ins = new Node(val);
    if(tmp == NULL)
        head = ins;
    else
    {
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = ins;
    }
}

void Ins_at_pos(int val, int pos, Node*& head)
{
    if (pos <= 0)
    {
        cout << "Not have Enough Positions" << endl;
        return;
    }

    if (pos == 1)
    {
        Ins_at_beg(val, head);
        return;
    }

    Node* tmp = head;
    pos -= 2;

    while (pos-- && tmp != NULL)
        tmp = tmp->next;

    if (tmp == NULL)
    {
        cout << "Not have Enough Positions!!!" << endl;
        return;
    }

    Node* ins = new Node(val);
    ins->next = tmp->next;
    tmp->next = ins;
}

#pragma endregion

#pragma region Deletion

void Del_at_beg(Node*& head)
{
    //Also handle empty LL
    if(head == NULL)
    {
        cout<<"Empty Linked List !!!"<<endl;
        return;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

void Del_at_end(Node*& head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List !!!" << endl;
        return;
    }

    // Single node case
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* tmp = head;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    delete tmp->next;
    tmp->next = NULL;
}

void Del_at_pos(int pos, Node*& head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List !!!" << endl;
        return;
    }

    if (pos <= 0)
    {
        cout << "Invalid Position !!!" << endl;
        return;
    }

    if (pos == 1)
    {
        Del_at_beg(head);
        return;
    }

    Node* tmp = head;
    pos -= 2;

    while (pos-- && tmp != NULL)
        tmp = tmp->next;

    if (tmp == NULL || tmp->next == NULL)
    {
        cout << "Position to be deleted out of Bound !!!" << endl;
        return;
    }

    Node* temp = tmp->next;
    tmp->next = tmp->next->next;
    delete temp;
}

#pragma endregion

#pragma region Print

void Print(Node* head)
{
    cout<<"Elements in LL : ";
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
#pragma endregion

#pragma Operations 
void Rec_Reverse(Node* head) //Reverse Recursively 
{
    Node* tmp = head;
}
void Itr_Reverse(Node*& head)
{
    if(head == NULL || head->next == NULL)
        return;
    Node* prev = head;
    Node* curr = prev->next;
    prev->next = NULL;
    while(curr != NULL)
    {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

int Length_of_Loop(Node* head)
{
    Node* start = Cycle_start_point(head);
    if (start == NULL)
        return 0;

    int length = 1;
    Node* temp = start->next;

    while (temp != start)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* Cycle_start_point(Node* head)
{
    Node* hare = head;
    Node* tor = head;
    while(hare != NULL && hare->next != NULL)
    {
        tor = tor->next;
        hare = hare->next->next;

        if(tor == hare)
            break;
    }
    if(tor == hare)
    {
        tor = head;
        while(tor != hare)
        {
            tor = tor->next;
            hare = hare->next;
        }
            return tor;
    }
    
    return NULL;
}

#pragma endregion
void FreeList(Node*& head)
{
    while (head)
        Del_at_beg(head);
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
    Del_at_pos(3,head);
    Print(head);//10 100 25 45
    Del_at_pos(1,head);
    Print(head);//100 25 45

    FreeList(head);
}