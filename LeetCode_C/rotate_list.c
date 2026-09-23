#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head -> next == NULL || k == 0) return head;

    int len = 0;
    struct ListNode *current = head;
    while (current) {
        len ++;
        current = current -> next;
    }

    k = k % len;
    if (k == 0) return head;
    int cut = len - k;
    current = head;
    int pos = 1;

    struct ListNode *new_tail = NULL;
    struct ListNode *new_head = NULL;
    struct ListNode *old_tail = NULL;
    while (current) {
        if (pos == cut) {
            new_tail = current;
            new_head = current -> next;
        }
        if (current -> next == NULL) old_tail = current;
        current = current->next;
        pos++;
    }
    old_tail -> next = head;
    new_tail -> next = NULL;

    return new_head;
}  

int main() {
    int head[] = {1,2,3,4,5};
    int len = sizeof(head) / sizeof(head[0]);
    int k = 2;

    struct ListNode dummy = {0, NULL};
    struct ListNode *current = &dummy;
    for (int i = 0 ; i < len; i++) {
            struct ListNode *node = malloc(sizeof(struct ListNode));
            node -> val = head[i];
            node -> next = NULL;
            current -> next = node;
            current = node;
    }
    
    struct ListNode* ans = rotateRight(dummy.next, k);
    current = ans;
    printf("[");
    while (current) {
        struct ListNode *next = current -> next;
        printf("%d", current -> val);
        if (next != NULL) printf(", ");
        free(current);
        current = next;
    }
    printf("]");
    return 0;
}