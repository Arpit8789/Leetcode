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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int ctr=0;
        if(head==NULL)
            return head;
        while(temp!=NULL)
        {
            temp=temp->next;
            ctr++;
        }
        int n=(ctr/2)+1;
        int i=1;
        temp=head;
        while(i<=n-1)
        {
            temp=temp->next;
            i++;
        }
        return temp;
        
    }
};