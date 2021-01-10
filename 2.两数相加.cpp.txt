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
        int flg = 0;
        ListNode *p = l1, *q = l2;
        ListNode *l3 = new ListNode(-1);
        ListNode *r = l3;
        while(p && q){
            int tmp = p->val + q->val;
            l3->next = new ListNode((tmp + flg) % 10);
            flg = (tmp + flg) / 10;
            p = p->next;
            q = q->next;
            l3 = l3->next;
        }
        while(p){
            int tmp = p->val + flg;
            l3->next = new ListNode(tmp % 10);
            flg = tmp / 10;
            p = p->next;
            l3 = l3->next;
        }
        while(q){
            int tmp = q->val + flg;
            l3->next = new ListNode(tmp % 10);
            flg = tmp / 10;
            q = q->next;
            l3 = l3->next;
        }
        if(flg){
            l3->next = new ListNode(1);
        }
        p = r;
        l3 = r->next;
        delete p;
        p = nullptr;
        
        return l3;
    }
};