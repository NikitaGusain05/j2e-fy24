#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to insert a node at the beginning of the linked list
void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while (curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Step 1: Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: Split the linked list into two halves
    ListNode* secondHalf = slow->next;
    slow->next = NULL;
    
    // Step 3: Reverse the second half of the linked list
    secondHalf = reverseList(secondHalf);
    
    // Step 4: Merge the first and reversed second halves alternatively
    ListNode* current = head;
    
    while (secondHalf != NULL) {
        ListNode* nextNode = current->next;
        current->next = secondHalf;
        secondHalf = secondHalf->next;
        current->next->next = nextNode;
        current = nextNode;
    }
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    
    cout << endl;
}

int main() {
	ListNode* head = nullptr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        insertNode(head, num);
    }
    
    cout << "Original List: ";
    printList(head);

    reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
