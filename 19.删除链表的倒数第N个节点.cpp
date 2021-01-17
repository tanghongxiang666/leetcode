    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        while (n-- > 0) {
            p = p->next;
        }
        ListNode* q = new ListNode(-1);
        q->next = head;
        ListNode* tmp = q;
        while (p) {
            p = p->next;
            q = q->next;
        }
        ListNode* d = q->next;
        q->next = q->next->next;
        delete d;
        d = tmp;
        q = tmp->next;
        delete d;
        return q;
    }