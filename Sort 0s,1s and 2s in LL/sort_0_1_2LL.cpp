/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
void insert(Node* &tail,Node* curr)
{
	tail->next = curr;
	tail =curr;
}
Node* sortList(Node *head)
{
    // Write your code here.
	Node* zerohead = new Node(-1);
	Node* onehead = new Node(-1);
	Node* twohead = new Node(-1);
	Node* zerotail = zerohead;
	Node* onetail = onehead;
	Node* twotail = twohead;
	Node* curr = head;
	while(curr!=NULL)
	{
		int val = curr->data;
		if(val == 0)
		{
			insert(zerotail,curr);
		}
		else if(val == 1)
		{
			insert(onetail,curr);
		}
		else if(val == 2)
		{
			insert(twotail,curr);
		}
		curr = curr->next;
	}
	//Merging
	
	if(onehead->next != NULL)
		zerotail->next = onehead->next;
	else
		zerotail->next = twohead->next;
	
	onetail->next = twohead->next;
	twotail->next = NULL;
	
	//updating head
	head = zerohead->next;
	
	//deleting dummy nodes
	delete zerohead;
	delete onehead;
	delete twohead;
	
	return head;
}
