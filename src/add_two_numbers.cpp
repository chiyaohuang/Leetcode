/*
 * Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order and each of their nodes contain
a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
//#define NULL nullptr

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        // Init
        ListNode *node = new ListNode(-1);
        ListNode *init = node;
        int sum = 0;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {

            // if NULL, val = 0.
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            // consider sum and carry.
            sum = x + y + carry;
            carry = sum / 10;

            // iterater
            node->next = new ListNode(sum % 10);
            node = node->next;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        if (carry > 0)
            node->next = new ListNode(carry);

        node = init->next;
        delete init;

        return node;
    }
};

int main() {

    ListNode *e0 = new ListNode(9);
    ListNode *e1 = new ListNode(8);
    ListNode *e2 = new ListNode(4);

    ListNode *f0 = new ListNode(1);
    ListNode *f1 = new ListNode(3);
    ListNode *f2 = new ListNode(1);

    e0->next = e1;
    e1->next = e2;
    f0->next = f1;
    f1->next = f2;

    Solution so;

    so.addTwoNumbers(e0, f0);

    return 0;
}
