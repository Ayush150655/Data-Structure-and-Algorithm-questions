#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d)             //Constructor
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node()                 //Destructor
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAtHead(Node* &head, Node* &tail, int d)
{
    Node* ptr = new Node(d);
    //Empty List
    if(head==NULL)              
    {
        head=ptr;
        tail=ptr;
    }
    else{
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d)
{
    Node *ptr = new Node(d);
    //Empty List
    if(tail==NULL)
    {
        head=ptr;
        tail=ptr;
    }
    else{
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr; 
    }
}

void insertAtPos(Node* &head, Node* &tail, int d, int pos)
{
    if(pos == 1)
    {
        insertAtHead(head,tail,d);
        return;
    }
    else{
        Node* c = head;
        int i=1;
        while(i<pos-1)
        {
            c=c->next;
            i++;
        }
        if(c->next==NULL)
        {
            insertAtTail(tail,head,d);
            return;
        }
        Node* ptr = new Node(d);
        ptr->next = c->next;
        c->next->prev=ptr;
        c->next = ptr;
        ptr->prev = c;
    }
}

void deleteNode(Node* &head, Node* &tail, int pos)
{
    
    if(pos==1)
    {
        Node* curr=head;
        curr->next->prev = NULL;
        head = curr->next;
        curr->next=NULL;
        delete curr;
    }
    else{
        Node* curr=head;
        int i=1;
        Node* pr = NULL;
        while(i<pos && curr!=NULL)   
        {
            pr=curr;
            curr=curr->next;
            i++;
        }
        curr->prev = NULL;
        pr->next = curr->next;
        curr->next = NULL;
        delete curr;
        // Checking if it is a last node, if yes then updating tail
        if(pr->next == NULL){
            tail=pr;
        }
    }
}

void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head)
{
    Node* temp=head;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,45);
    print(head);
    insertAtTail(tail,head,63);
    print(head);
    insertAtPos(head,tail,12,2);
    print(head);
    insertAtPos(head,tail,99,3);
    print(head);
    insertAtPos(head,tail,78,5);
    print(head);
    cout<<"Head - "<<head->data<<endl;
    cout<<"Tail - "<<tail->data<<endl;
    deleteNode(head,tail,3);
    print(head);
    cout<<"Head - "<<head->data<<endl;
    cout<<"Tail - "<<tail->data<<endl;
    insertAtPos(head,tail,101,3);
    print(head);
    deleteNode(head,tail,4);
    print(head);
    cout<<"Head - "<<head->data<<endl;
    cout<<"Tail - "<<tail->data<<endl;
    insertAtPos(head,tail,90,4);
    print(head);
    deleteNode(head,tail,1);
    print(head);
    cout<<"Head - "<<head->data<<endl;
    cout<<"Tail - "<<tail->data<<endl;
    return 0;
}
