#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    // Check if the list has at least two nodes
    if (!head || !head->next) {
        return head;
    }
    
    // Create a dummy node as the new head
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* prev = dummy;
    ListNode* curr = head;
    
    while (curr && curr->next) {
        ListNode* nextNode = curr->next;
        
        // Swapping adjacent nodes
        curr->next = nextNode->next;
        nextNode->next = curr;
        prev->next = nextNode;
        
        // Update pointers for the next iteration
        prev = curr;
        curr = curr->next;
    }
    
    // Return the new head after swapping
    return dummy->next;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to delete the linked list to avoid memory leaks
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    // Read input from the user
    int numElements;
    std::cout << "Enter the number of elements in the linked list: ";
    std::cin >> numElements;

    std::cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < numElements; i++) {
        int val;
        std::cin >> val;

        ListNode* newNode = new ListNode(val);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    std::cout << "Original linked list: ";
    printList(head);

    ListNode* swappedHead = swapPairs(head);

    std::cout << "Linked list after swapping adjacent nodes: ";
    printList(swappedHead);

    // Clean up the memory
    deleteList(swappedHead);

    return 0;
}
