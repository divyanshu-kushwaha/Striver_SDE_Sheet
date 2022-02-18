// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *next, *curr=head, *prev=NULL;
        
        while(curr!=NULL){
            
/*Step 1*/   nextt = curr->next;  // First we are storing the next node's adress
                                  // in nextt variable ..bcz we gonna lose it 
                                  // in next step :(
            
/*Step 2*/  curr->next = prev;    // Yes.. we lost it ..as curr->next no longer
                                  // points to the next node's address..it now 
                                  // points to previous node's address (which is 
                                  // coming from the step 3 of last iteration
            
/*Step 3*/   prev = curr;         // yes.. this is what I was talking about.. 
                                  // This prev variable will be useful in step 2                                     
                                  // of next iteration :)
            
            curr = nextt;         // Come on ! This line is written in every
                                  // normal LL traversal XD
        }
        
        return prev;
    }
};