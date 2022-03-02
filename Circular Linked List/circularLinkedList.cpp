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
            delete next;
            this->next = NULL;
        }
    }
};


void insertNode(Node* &tail, int d, int ele)
{
    //empty list
    if(tail==NULL)
    {
        Node* ptr=new Node(d);
        tail = ptr;
        ptr->next = ptr;

    }
    //non empty list
    else
    {
        Node* curr = tail;
        while(curr->data != ele)
        {
            curr = curr->next;
        }
        //element found
        Node* ptr = new Node(d);
        ptr->next = curr->next;
        curr->next = ptr;
    }
}

void deleteNode(int val, Node* &tail)
{
    if(tail == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != val)
        {
            prev=curr;
            curr=curr->next;
        }
        //element found
        //only one element in list
        if(curr == prev)
        {
            tail = NULL;
        }
        // when 2 or more nodes are present
        else if(tail == curr)          //when the value is tail->data
        {
            tail=prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
    
}

void print(Node* tail)
{
    if(tail == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else{
        Node* temp = tail;
        do{
            cout<<tail->data<<" ";
            tail=tail->next;
        }
        while(tail != temp);
        cout<<endl;
    }    
}

int main()
{
    Node* tail = NULL;
    insertNode(tail,23,4);
    print (tail);    
    insertNode(tail,56,23);
    print (tail);  
    insertNode(tail,12,56);
    print (tail);  
    insertNode(tail,99,12);
    print (tail);
    insertNode(tail,84,99);
    print (tail);
    insertNode(tail,45,56);
    print (tail);
    insertNode(tail,100,12);
    print (tail);
    deleteNode(56,tail);
    print(tail);
    deleteNode(84,tail);
    print(tail);
    deleteNode(23,tail);
    print(tail);
    return 0;
}
