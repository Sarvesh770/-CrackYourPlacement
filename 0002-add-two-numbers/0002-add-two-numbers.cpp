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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->next == NULL && l1->val == 0) return l2;
        if(l2->next == NULL && l2->val == 0) return l1;
        ListNode* l = l1;
        ListNode* r = l2;
        int carry = 0;
        ListNode* temp = new ListNode();
        ListNode* temp2 = temp;
        while(l != NULL && r != NULL){
            int sum = l->val + r->val;
            sum += carry;
            carry = sum/10;
            int val = sum%10;
            temp->next = new ListNode(val);
            temp = temp->next;
            l = l->next;
            r = r->next;
        }
        while(l != NULL){
            int sum = l->val;
            sum += carry;
            carry = sum/10;
            int val = sum%10;
            temp->next = new ListNode(val);
            temp = temp->next;
            l = l->next;
        }
        while(r != NULL){
            int sum = r->val;
            sum += carry;
            carry = sum/10;
            int val = sum%10;
            temp->next = new ListNode(val);
            temp = temp->next;
            r = r->next;
        }
        if(carry != 0){
            temp->next = new ListNode(carry);
        }
        return temp2->next;
    }
};