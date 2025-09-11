#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = carry + x + y;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to free linked list memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create Solution object
    Solution solution;

    // Test case 1: l1 = [2,4,3], l2 = [5,6,4] (342 + 465 = 807)
    std::vector<int> nums1 = {2, 4, 3};
    std::vector<int> nums2 = {5, 6, 4};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);

    std::cout << "Test Case 1:" << std::endl;
    std::cout << "l1 = ";
    printList(l1);
    std::cout << "l2 = ";
    printList(l2);
    std::cout << "Result = ";
    ListNode* result = solution.addTwoNumbers(l1, l2);
    printList(result);

    // Free memory
    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    // Test case 2: l1 = [0], l2 = [0] (0 + 0 = 0)
    nums1 = {0};
    nums2 = {0};
    l1 = createList(nums1);
    l2 = createList(nums2);

    std::cout << "\nTest Case 2:" << std::endl;
    std::cout << "l1 = ";
    printList(l1);
    std::cout << "l2 = ";
    printList(l2);
    std::cout << "Result = ";
    result = solution.addTwoNumbers(l1, l2);
    printList(result);

    // Free memory
    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    // Test case 3: l1 = [9,9,9], l2 = [1] (999 + 1 = 1000)
    nums1 = {9, 9, 9};
    nums2 = {1};
    l1 = createList(nums1);
    l2 = createList(nums2);

    std::cout << "\nTest Case 3:" << std::endl;
    std::cout << "l1 = ";
    printList(l1);
    std::cout << "l2 = ";
    printList(l2);
    std::cout << "Result = ";
    result = solution.addTwoNumbers(l1, l2);
    printList(result);

    // Free memory
    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return 0;
}