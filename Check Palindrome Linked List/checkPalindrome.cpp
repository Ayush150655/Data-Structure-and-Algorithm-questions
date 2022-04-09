/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ptr = NULL;
        while(curr != NULL)
        {
            ptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ptr;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        
        ListNode* mid = findMid(head);
        ListNode* temp = mid->next;
        mid->next = reverse(temp);
        ListNode* curr = head;
        ListNode* curr2 = mid->next;
        while(curr2 != NULL)
        {
            if(curr->val != curr2->val)
                return false;
            curr2 = curr2->next;
            curr = curr->next;
        }
        return true;
        
    }
};
