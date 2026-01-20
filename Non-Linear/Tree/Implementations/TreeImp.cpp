#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

#pragma region DFS Recursive Approach
void Rec_Inorder(Node* head) //Left Head Right
{
    if(head == NULL)
        return;
    Rec_Inorder(head->left);
    cout<<head->data<<" ";
    Rec_Inorder(head->right);
}

void Rec_Preorder(Node* head) //Root Left Right
{
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    Rec_Preorder(head->left);
    Rec_Preorder(head->right);
}

void Rec_Postorder(Node* head) //Left Right Root
{
    if(head == NULL)
        return;
    Rec_Postorder(head->left);
    Rec_Postorder(head->right);
    cout<<head->data<<" ";
}
#pragma endregion

#pragma region Iterative Approach 

void Itr_Inorder(Node* head) //Left Head Right
{

}
void Itr_Preorder(Node* head) //Root Left Right
{
    stack<Node*> st;
    st.push(head);

    while(!st.empty())
    {
        Node* tmp = st.top();
        st.pop();
        cout<<tmp->data<<" ";
        if(tmp->right)
        {
            st.push(tmp->right);
        }
        if(tmp->left)
        {
            st.push(tmp->left);
        }
    }
}
void Itr_Postorder(Node* head) //Left Right Root
{
    
}

#pragma endregion

#pragma region BFS

void BFS(Node* head)
{
    if(head == NULL)
        return;
    queue<Node*> q;
    q.push(head);

    while(!q.empty())
    {
        Node* tmp = q.front();
        q.pop();
        cout<<tmp->data<<" ";
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
}

#pragma endregion

int main()
{
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);



    // Rec_Preorder(head); //1 2 4 5 3 6 7
    // cout<<endl;
    // Rec_Inorder(head); //4 2 5 1 6 3 7
    // cout<<endl;
    // Rec_Postorder(head); //4 5 2 6 7 3 1
    //cout<<endl;

    // BFS(head);
    //cout<<endl;

    // Itr_Preorder(head);
    //cout<<endl;
    // Itr_Inorder(head);
    // cout<<endl;
    Itr_Postorder(head);
    cout<<endl;
}