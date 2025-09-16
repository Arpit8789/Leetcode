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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* prev;
        int ctr=0;
        if(n==1 && !head->next)
            return NULL;
        while(temp!=NULL)
        {
            temp=temp->next;
            ctr++;
        }
        cout<<ctr;
        temp=head;
        int x= ctr-n+1;
       
        for(int i=0;i<x-1;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        if(x==1) return head->next;
        prev->next=temp->next;
        return head;
        
    }
};