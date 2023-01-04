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
    int getLength(ListNode* head){
        if(head==NULL){
            return 0;
        }

        ListNode* temp = head;
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        int len = getLength(head);
        int diff = len -n;
        if(n == len) return head->next;
        if(n > len) return head;
        
        ListNode* curr = head;
        int cnt=1;

        while(curr!=NULL && cnt < diff){
            curr= curr->next;
            cnt++;
        }
         curr ->next = curr->next->next;
         return head;
    }
};
