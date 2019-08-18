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
        ListNode* result = l1;
        ListNode** pnext = &result;
        int carry = 0;
        int sum = 0;

        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
            pnext = &l1->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL) {
            l1 = l2;
            *pnext = l2;
        }

        while (l1 != NULL) {
            sum = l1->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
            pnext = &l1->next;
            l1 = l1->next;
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
