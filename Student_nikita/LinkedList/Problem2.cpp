#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert a new node at the end of a linked list
void insert(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    ListNode* result;
    if (list1->val <= list2->val) {
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
    }
    return result;
}

// Function to print the merged list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;

    // Input the sorted linked lists from the user
    int num1, num2;
    std::cout << "Enter the elements of the first sorted linked list (-1 to stop): ";
    while (std::cin >> num1 && num1 != -1) {
        insert(list1, num1);
    }

    std::cout << "Enter the elements of the second sorted linked list (-1 to stop): ";
    while (std::cin >> num2 && num2 != -1) {
        insert(list2, num2);
    }

    // Merge the two lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    std::cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
