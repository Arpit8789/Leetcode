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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next == NULL)
            return true;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr)
        {
            ListNode* p=curr->next;
            curr->next=prev;
            prev=curr;
            curr=p;
        }
        ListNode* left=head;
        ListNode* right=prev;
        while(right)
        {
            if(left->val!=right->val)
                return false;
            right=right->next;
            left=left->next;
        }
        return true;

    }
};