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
    int getDecimalValue(ListNode* head) {
        int num = 0;
        int len = 0;
        ListNode *temp = head;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        while(head != NULL){
            num += head->val*pow(2,len);
            len--;
            head = head->next;
        }
        return num;
    }
};