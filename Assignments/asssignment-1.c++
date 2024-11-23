#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    if (head == NULL) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    ListNode* node1 = new ListNode(10);
    ListNode* node2 = new ListNode(20);
    ListNode* node3 = new ListNode(30);

    node1->next = node2;
    node2->next = node3;
    ListNode* head = node1;

    if (hasCycle(head)) {
        cout << "Cycle is present in the linked list" << endl;
    } else {
        cout << "Cycle is not present in the linked list" << endl;
    }

    delete node1;
    delete node2;
    delete node3;

    return 0;
}
