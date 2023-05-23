#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildLinkedList(const vector<int>& values) {
    ListNode* head = NULL;
    ListNode* curr = NULL;
    for (int val : values) {
        if (head == NULL) {
            head = new ListNode(val);
            curr = head;
        } else {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* mergeLinkedLists(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    dummy->next = list1;

    // Find the node at position (a-1)
    ListNode* prev = dummy;
    for (int i = 0; i < a - 1; i++) {
        prev = prev->next;
    }

    // Find the node at position b
    ListNode* curr = prev;
    for (int i = 0; i < b - a + 1; i++) {
        curr = curr->next;
    }

    // Connect the previous node to list2
    prev->next = list2;

    // Find the tail of list2
    ListNode* tail = list2;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Connect the tail of list2 to the remaining nodes in list1
    tail->next = curr->next;

    // Delete the removed nodes from list1
    curr->next = NULL;
    ListNode* newHead = dummy->next;
    delete dummy;

    return newHead;
}

int main() {
    // Input list1
    vector<int> list1Values = {0, 1, 2, 3, 4, 5};
    ListNode* list1 = buildLinkedList(list1Values);

    // Input list2
    vector<int> list2Values = {1000000, 1000001, 1000002};
    ListNode* list2 = buildLinkedList(list2Values);

    // Input values of a and b
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    // Merge the lists
    ListNode* mergedList = mergeLinkedLists(list1, a, b, list2);

    // Print the merged list
    printLinkedList(mergedList);

    return 0;
}
