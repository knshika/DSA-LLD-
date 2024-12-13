#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int _val)
    {
        val = _val;
        next = nullptr;
    }
    // Node(int _val) : val(_val),next(nullptr) {}
};

Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node *head)
{
    Node *temp = head;
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr" << std::endl;
    head = temp;
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(5);

    printList(head);

    Node *rev = reverseLinkedList(head);

    printList(rev);

    return 0;
}

// #include <iostream>

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *prev = nullptr;
//         ListNode *current = head;

//         while (current != nullptr)
//         {
//             ListNode *next = current->next; // Store the next node
//             current->next = prev;           // Reverse the current node's pointer
//             prev = current;                 // Move prev one step forward
//             current = next;                 // Move current one step forward
//         }

//         return prev; // New head of the reversed list
//     }
// };

// // Helper function to print the list
// void printList(ListNode *head)
// {
//     ListNode *temp = head;
//     while (temp != nullptr)
//     {
//         std::cout << temp->val << " -> ";
//         temp = temp->next;
//     }
//     std::cout << "nullptr" << std::endl;
// }

// // Example usage
// int main()
// {
//     ListNode *head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);

//     std::cout << "Original List: ";
//     printList(head);

//     Solution solution;
//     ListNode *reversedHead = solution.reverseList(head);

//     std::cout << "Reversed List: ";
//     printList(reversedHead);

//     return 0;
// }
