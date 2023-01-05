// fisrt solution 

class Solution {
    private:
    bool checkPolindrome(vector<int>&ans){
        int n = ans.size();
        int s=0;
        int e =n-1;

        while(s<=e){
            if(ans[s]!=ans[e]){
            return 0;
            }
            s++;
            e--;
        }
            return 1;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int>ans; 
 
        ListNode* temp = head;

        while(temp!=NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
    
    bool check = checkPolindrome(ans);
    return check;
    }
};

T.C. = O(N)
S.C. = O(N)
  
  
//   second solution
  
class Solution {
    private:
 
  ListNode* getMid(ListNode* head ) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        
         if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        ListNode* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->val != head1->val) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
        
}
};

T.C. = O(N)
S.C. = O(1)
