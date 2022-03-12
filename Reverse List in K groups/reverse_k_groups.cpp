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

Node* Kreverse(Node* &head, int k)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int c = 0;
    if(head == NULL)
        return NULL;
    
    while(curr != NULL && c<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;        
        c++;
    }
    if(next != NULL)
    {
        head->next = Kreverse(next,k);
    }
    return prev;
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
    int k;
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=NULL;
    tail=node1;
    insertAtHead(head,5);
    insertAtTail(tail,3);
    insertAtTail(tail,7);
    insertAtTail(tail,23);
    insertAtTail(tail,15);
    cout<<"Linked List : ";
    print(head);
    cout<<endl;
    cout<<"Enter value of k:";
    cin>>k;
    head = Kreverse(head,k);
    cout<<"Reverse Linked List in K groups: ";
    print(head);
    cout<<endl;
    return 0;
}
