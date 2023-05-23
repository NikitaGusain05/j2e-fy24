#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr) {
        while (curr->next && curr->val == curr->next->val) {
            curr = curr->next;
        }

        if (prev->next == curr) {
            prev = prev->next;
        } else {
            prev->next = curr->next;
        }

        curr = curr->next;
    }

    return dummy->next;
}

void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    std::cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;

        if (!head) {
            head = new ListNode(num);
            tail = head;
        } else {
            tail->next = new ListNode(num);
            tail = tail->next;
        }
    }

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    ListNode* result = deleteDuplicates(head);

    std::cout << "Modified Linked List: ";
    printLinkedList(result);

    return 0;
}
