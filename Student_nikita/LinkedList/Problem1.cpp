#include <iostream>

// Definition of a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to handle cases where the head needs to be removed
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // Find the length of the list
    int length = 0;
    ListNode* curr = head;
    while (curr) {
        length++;
        curr = curr->next;
    }

    // Calculate the position of the node to be removed from the beginning
    int position = length - n;

    // Find the node just before the node to be removed
    ListNode* prev = dummy;
    for (int i = 0; i < position; i++) {
        prev = prev->next;
    }

    // Remove the node
    ListNode* nodeToRemove = prev->next;
    prev->next = nodeToRemove->next;
    delete nodeToRemove;

    // Update the head of the list
    head = dummy->next;

    // Clean up memory
    delete dummy;

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    std::cout << "Enter the values of the linked list (enter -1 to stop): ";
    int val;
    while (std::cin >> val && val != -1) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    std::cout << "Original list: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    std::cout << "Updated list: ";
    printList(head);

    // Clean up memory
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
