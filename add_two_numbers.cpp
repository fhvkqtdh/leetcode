#include <cstddef>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode** pnext = &result;
        int carry = 0;
        int sum = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            sum = carry;
            sum += l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;
            carry = sum / 10;
            *pnext = new ListNode(sum % 10);
            pnext = &(*pnext)->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry != 0)
            *pnext = new ListNode(carry);

        return result;
    }

    ListNode* buildList(const std::vector<int>& nums) {
        ListNode* result;
        ListNode** pnext = &result;
        for (auto i : nums) {
            *pnext = new ListNode(i);
            pnext = &(*pnext)->next;
        }
        return result;
    }

    void printList(ListNode* root) {
        for (ListNode* node = root; node != NULL; node = node->next) {
            std::cout << node->val;
            if (node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    ListNode* result = NULL;

    result = solution.addTwoNumbers(l1, l2);
    solution.printList(result);

    l1 = solution.buildList({2,4,3});
    l2 = solution.buildList({7,0,8});
    result = solution.addTwoNumbers(l1, l2);
    solution.printList(result);

    return 0;
}
