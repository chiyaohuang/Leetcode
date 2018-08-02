/*
 * Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should
be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

#define NULL nullptr
#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        // foolproof
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        // initail node = (-1, NULL)
        ListNode *tmp = new ListNode(-1);
        ListNode *node = tmp;

        // if l1 or l2 = NULL, stop.
        while(l1!= NULL && l2 != NULL){
            if(l1->val > l2->val){
                node->next = l2;
                l2 = l2->next;
            }
            else{
                node->next = l1;
                l1 = l1->next;
            }
            //std::cout << node->val << std::endl;
            node = node->next;
        }

        // point to the last l1 or l2.
        node->next = l1 ? l1 : l2;
        //std::cout << node->val << '\n' << node->next->val <<std::endl;

        // move to the first node and delete the initail node.
        node = tmp->next;
        delete tmp;

        return node;



    }
};

int main() {

    ListNode e0(1);
    ListNode e1(2);
    ListNode e2(4);

    ListNode f0(1);
    ListNode f1(3);
    ListNode f2(4);

    e0.next = &e1;
    e1.next = &e2;

    f0.next = &f1;
    f1.next = &f2;

    Solution so;
    so.mergeTwoLists(&e0, &f0);
    return 0;
}
