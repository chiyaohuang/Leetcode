/*
 * Swap nodes in pairs
 * Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be
changed.
*/

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {

        // foolproof
        if (head == NULL || head->next == NULL)
            return head;

        // Parameters
        ListNode *origin = head->next;
        ListNode *first = head;
        ListNode *second;
        ListNode *tmp;

        while (first != NULL && first->next != NULL) {

            second = first->next;

            tmp = second->next;
            second->next = first;

            if(tmp->next != NULL){
                first->next = tmp->next;
            }
            else{
                first->next = tmp;
            }

            first = tmp;
        }

        return origin;
    }
};


#include<iostream>
#include"src/swap_nodes_in_pairs.cpp"

int main(){
    Solution so;

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    std::cout << "input: \n";
    ListNode* it = node1;
    while(it != NULL) {
        std::cout << it->val << "->";
        it = it->next;
    }
    std::cout << "NULL" <<std::endl;

    ListNode* ans = so.swapPairs(node1);
    while(ans != NULL) {
        std::cout << ans->val << std::endl;
        ans = ans->next;
    }

    return 0;
}
