#include <iostream>
#include <unordered_set>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {};
};

Node *reverseLL(Node *head)
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

Node *findMiddle(Node *head)
{
    if (head == nullptr)
        return 0;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool isPalindrome(Node *head)
{
    Node *mid = findMiddle(head);
    Node *rev = reverseLL(mid);
    Node *first = head;
    Node *second = rev;

    while (second != nullptr)
    {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}