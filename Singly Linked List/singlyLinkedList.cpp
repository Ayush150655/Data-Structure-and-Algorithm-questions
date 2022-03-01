#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)          //Constructor
    {
        this -> data = data;
        this->next = NULL;
    }
    ~Node()                 //Destructor
    {
        if(this->next!=NULL)
        {
            delete next;        //freeing the memory
            this->next = NULL;
        }
    }
};

void insertAtHead(Node* &head, int d)
{
    Node* temp= new Node(d);
    temp->next = head;
    head=temp;
}

void insertAtTail(Node* &tail, int d)
{
    Node* temp=new Node(d);
    tail->next = temp;
    tail=tail->next;
}

void insertAtpos(int pos, int d, Node* &head, Node* &tail)
{
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    Node* ptr = new Node(d);
    Node*temp = head;
    int i=1;
    while(i<pos-1 && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    if(temp->next == NULL)          //Ckecking if it is a last node
    {
        insertAtTail(tail,d);
        return;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}

void deleteNode(Node* &head, Node* &tail, int pos)
{
    Node* curr=head;
    if(pos==1)
    {
        head=head->next;
        curr->next=NULL;
        delete curr;
        return;
    }
    int i=1;
    Node* prev = NULL;
    while(i<pos && curr!=NULL)   
    {
        prev=curr;
        curr=curr->next;
        i++;
    }
    
    prev->next=curr->next;
    // Checking if it is a last node, if yes then updating tail
    if(prev->next == NULL){
        tail=prev;
    }
    curr->next=NULL;
    delete curr;
}

void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertAtHead(head,15);
    insertAtTail(tail,20);
    insertAtHead(head,50);
    insertAtTail(tail,105);
    insertAtTail(tail,55);
    insertAtpos(3,28,head,tail);
    insertAtpos(1,67,head,tail);
    insertAtpos(9,97,head,tail);
    print(head);
    deleteNode(head,tail,9);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,5);
    print(head);
    
    return 0;
}
