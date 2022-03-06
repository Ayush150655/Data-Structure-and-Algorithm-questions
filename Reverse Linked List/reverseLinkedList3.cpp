//RECURSIVE SOLUTION


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


Node* reverseLinkedList(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* secHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return secHead;
}

int main()
{
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
    head = reverseLinkedList(head);
    cout<<"Reverse Linked List : ";
    print(head);
    return 0;
}
