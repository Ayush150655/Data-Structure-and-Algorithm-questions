/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAttail(Node* &head, Node* &tail, int d)
    {
        Node* ptr = new Node(d);
        if(head == NULL)
        {
            head = ptr;
            tail = ptr;
        }        
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
        
    }
public:
    Node* copyRandomList(Node* head) {
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while(temp != NULL)
        {
            insertAttail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
        
        Node* originalnode = head;
        Node* ptr = NULL;
        Node* clonenode = cloneHead;
        while(originalnode != NULL && clonenode != NULL)
        {
            ptr = originalnode->next;
            originalnode->next = clonenode;
            originalnode = ptr;
            ptr = clonenode -> next;
            clonenode->next = originalnode;
            clonenode = ptr;
        }
        temp = head;
        while(temp != NULL)
        {
            if(temp->next != NULL)
            {
                if(temp->random != NULL)
                    temp->next->random = temp->random->next;
            }
            else
            {
                temp->next = temp->random;
            }
            temp = temp->next->next;
        }
        originalnode = head;
        clonenode = cloneHead;
        while(originalnode != NULL && clonenode != NULL)
        {
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;
            if(originalnode != NULL)
            {
                clonenode->next = originalnode->next;
            }
            clonenode = clonenode->next;
        }
        return cloneHead;
    }
};
