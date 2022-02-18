// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL, *tail, *curr1 = list1, *curr2 = list2;
        bool flag = 1;
        
        while(curr1!=NULL or curr2!=NULL){
            ListNode* temp = new ListNode(); // creating a new node

            int p,q;
            // for handling cases when one of the list becomes empty
            curr1==NULL? p = 101 : p = curr1->val;  
            curr2==NULL? q = 101 : q = curr2->val;

            // logic for insertion in sorted order
            if(p<q){
                temp->val = p;
                curr1 = curr1->next;
            }
            else{
                temp->val = q;
                curr2 = curr2->next;
            }

            if(flag) { // for first insertion
                head = temp;
                tail = temp;
                flag = 0;
                continue;
            }

            // updating the tail 
            tail->next = temp;
            tail = temp;
        }
        return head;
    }
};