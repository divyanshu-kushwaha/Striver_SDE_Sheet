// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
        int N = 0;
        ListNode *curr = head;
        while(curr!=NULL){
            N++;
            curr = curr->next;
        }
        n = N-n+1; // redefining position wrt beginning
        
        //deletion
        curr = head;
        if(n==1){
            head = curr->next;
            delete(curr);
            return head;
        }
        for(int i = 0; i < n-2; i++){
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete(temp);
        return head;
    }
};