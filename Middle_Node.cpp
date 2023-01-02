// first solution 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

      ListNode *slow = head;
      ListNode* fast = head;
      
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
         return slow;
    }
};

// second solution 

class Solution {
    private:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
public:
    ListNode* middleNode(ListNode* head) {

      int len = getLength(head);
        int ans = len/2;
        int cnt=0;
        ListNode* temp = head;
        
        while(cnt < ans){
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
};
