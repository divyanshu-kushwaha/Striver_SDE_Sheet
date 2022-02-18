// https://leetcode.com/problems/middle-of-the-linked-list/

// Naive Approach
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
        int n = 0;
        ListNode *curr = head;
        while(curr!=NULL){
            n++;
            curr = curr->next;
        }
        n = n/2 + 1;
        int count = 1;
        curr = head;
        while(count<n){
            count++;
            curr =  curr->next;
        }
        return curr;
    }
};

// Efficient approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        while(!(fast==NULL or fast->next==NULL)){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};