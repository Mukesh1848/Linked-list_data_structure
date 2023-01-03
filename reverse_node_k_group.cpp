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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        int len=0;
        ListNode* temp=next;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(next!=NULL && len>=k){
            head->next=reverseKGroup(next, k);
        }
        else{
            head->next=next;
        }
        return prev;
    }
};
