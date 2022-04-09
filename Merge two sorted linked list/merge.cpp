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
public:
    ListNode* solve(ListNode* list1, ListNode* list2)
    {
        //if only one element is there in list1
        if(list1->next == NULL)
        {
            list1->next = list2;
            return list1;
        }
        ListNode* l1 = list1;
        ListNode* l2 = l1->next;
        ListNode* l3 = list2;
        ListNode* l4 = l3->next;
        while(l2 != NULL && l3 != NULL)
        {
            if(l3->val >= l1->val && l3->val <= l2->val)
            {
                l1->next = l3;
                l4 = l3->next;
                l3->next = l2;
                l1 = l3;
                l3 = l4;                
            }
            else
            {
                l1 = l2;
                l2 = l2->next;
                if(l2 == NULL)
                {
                    l1->next = l3;
                    return list1;
                }
            }
        }
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        if(list1->val <= list2->val)
            return solve(list1,list2);
        else
            return solve(list2,list1);
    }
};
