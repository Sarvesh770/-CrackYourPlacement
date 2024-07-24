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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergelist(l1,l2);
    }
    ListNode* mergelist(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* pt3 = new ListNode();
        ListNode* head = pt3;
        ListNode* pt1 = l1;
        ListNode* pt2 = l2;
        while(pt1 && pt2){
            if(pt1->val < pt2->val){
                pt3->val = pt1->val;
                pt1 = pt1->next;
            }else{
                pt3->val = pt2->val;
                pt2 = pt2->next;
            }
            pt3->next = new ListNode();
            pt3 = pt3->next;
        }
        if(pt1){
            while(pt1){
                pt3->val = pt1->val;
                pt1 = pt1->next;
                if(!pt1) pt3->next = NULL;
                else pt3->next = new ListNode();
                pt3 = pt3->next;
            }
        }
        if(pt2){
            while(pt2){
                pt3->val = pt2->val;
                pt2 = pt2->next;
                if(!pt2) pt3->next = NULL;
                else pt3->next = new ListNode();
                pt3 = pt3->next;
            }
        }
        return head;
    }
};