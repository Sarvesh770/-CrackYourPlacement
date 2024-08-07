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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        for(ListNode* x:lists){
            if(x)pq.push(x);
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            ListNode* x = pq.top();
            pq.pop();
            if(head == NULL){
                head = x;
                tail = x;
            }else{
                tail->next = x;
                tail = x;
            }
            if(x->next) pq.push(x->next);
        }
        return head;
    }
    struct comp{
        bool operator() (ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }   
    };
};