
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
