#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node(int val)
    {
        prev = nullptr;
        data = val;
        next = nullptr;
    }
};

#pragma region Insertion

void Ins_at_beg(int val, Node*& head)
{
    Node* ins = new Node(val);
    //Also handle empty LL
    if(head == NULL)
    {
        head = ins;
        return;
    }
    else
    {
        ins->next = head;
        head->prev = ins;
        head = ins;
    }
}

void Ins_at_end(int val, Node*& head)
{
    Node* ins = new Node(val);
    //Also handle empty LL
    if(head == NULL)
    {
        head = ins;
        return;
    }
    else
    {
        Node* tmp = head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = ins;
        ins->prev = tmp;
    }
}

void Ins_at_pos(int val, int pos, Node*& head)
{
    if(pos <= 0)
        return;

    if(pos == 1)
    {
        Ins_at_beg(val, head);
        return;
    }

    if(head == NULL)
        return;

    Node* tmp = head;

    for(int i = 1; i < pos - 1 && tmp != NULL; i++)
    {
        tmp = tmp->next;
    }

    // position out of bounds
    if(tmp == NULL)
        return;

    Node* ins = new Node(val);

    Node* nxt = tmp->next;

    tmp->next = ins;
    ins->prev = tmp;

    ins->next = nxt;
    if(nxt != NULL)
        nxt->prev = ins;
}


#pragma endregion

#pragma region Deletion

void Del_at_beg(Node*& head)
{
    if(head == NULL)
    {
        cout<<"Empty Linked List !!!";
        return;
    }

    Node* del = head;

    if(head->next == NULL) // single node
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    delete del;
}

void Del_at_end(Node*& head)
{
    if(head == NULL)
    {
        cout<<"Empty Linked List !!!";
        return;
    }

    if(head->next == NULL) // single node
    {
        delete head;
        head = NULL;
        return;
    }

    Node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->prev->next = NULL;
    delete tmp;
}

void Del_at_pos(int pos, Node*& head)
{
    if(pos <= 0)
        return;

    if(pos == 1)
    {
        Del_at_beg(head);
        return;
    }

    if(head == NULL)
        return;

    Node* tmp = head;
    for(int i = 1; i < pos && tmp != NULL; i++)
    {
        tmp = tmp->next;
    }
    if(tmp == NULL)
        return;
        
    Node* prv = tmp->prev;
    Node* nxt = tmp->next;

    if(prv != NULL)
        prv->next = nxt;
    if(nxt != NULL)
        nxt->prev = prv;

    delete tmp;
}

#pragma endregion

#pragma region Print

void PrintLtoR(Node* head)
{
    if(head == NULL)
        return;
    cout<<"Elements in LL : ";
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void PrintRtoL(Node* head)
{
    if(head == NULL)
        return;
    cout<<"Elements in LL : ";
    while(head->next != NULL)
    {
        head = head->next;
    }
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<endl;
}
#pragma endregion

#pragma region Reverse

void Itr_Reverse(Node*& head)
{

}

void Rec_Reverse(Node*& head)
{

}
#pragma endregion

void Del_Occ_key(Node*& head, int key)
{
    if (head == NULL)
        return;

    Node* curr = head;

    while (curr != NULL)
    {
        if (curr->data == key)
        {
            Node* del = curr;

            // deleting head
            if (curr->prev == NULL)
            {
                head = curr->next;
                if (head != NULL)
                    head->prev = NULL;
            }
            else
            {
                curr->prev->next = curr->next;
            }

            // deleting middle or tail
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }

            curr = curr->next;
            delete del;
        }
        else
        {
            curr = curr->next;
        }
    }
}

vector<vector<int>> findPairsWithGivenSum(Node* head, int target) 
{
    
}
Node * removeDuplicates(Node *head) //Input will be sorted 
{

}

int main()
{
    Node* head = NULL;
    Ins_at_beg(35,head);// 35
    PrintLtoR(head);
    Ins_at_end(25,head);// 35 25
    PrintLtoR(head);
    Ins_at_beg(10,head);//10 35 25
    PrintLtoR(head);
    Ins_at_end(45,head);//10 35 25 45
    PrintLtoR(head);
    PrintRtoL(head);
}