// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int data;
    cin>> data;
    
    Node* head = new Node(data);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    private:
    Node* reverse(Node* head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* ptr=NULL;
        while(curr!=NULL)
        {
            ptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ptr;
        }
        head=prev;
        return head;
    }
    
    void insertAttail(Node* &head , Node* &tail , int data)
    {
        Node* temp = new Node(data);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            return;
        }
    }
    Node* addList(Node* l1 , Node* l2)
    {
        int carry = 0,sum;
        Node* anshead = NULL;
        Node* anstail = NULL;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int data1 = 0 , data2 = 0;
            if(l1 != NULL)
                data1 = l1->data;
            if(l2 != NULL)
                data2 = l2->data;
            
            sum = data1 + data2 + carry;
            int digit = sum%10;
            insertAttail(anshead , anstail , digit);
            carry = sum/10;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        return anshead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        Node* ans = addList(l1 , l2);
        
        ans = reverse(ans);
        
        return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
