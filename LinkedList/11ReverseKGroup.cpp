#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {};
};

Node *reverse(Node *head)
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

int noOfKGroups(Node *head, int k)
{
    Node *temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        if (i == k)
            break;
        temp = temp->next;
        i++;
    }
    return temp;
}

Node *kReverse(Node *head, int k)
{
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *curr = dummy;
    int i = 0, n = noOfKGroups(head, k);
    while (i < n)
    {
        Node *grpStart = curr->next;
        Node *grpEnd = grpStart;
        for (int j = 1; j < k; j++)
        {
            grpEnd
        }
        if ((i + 1) % k == 0)
        {
            Node *rev = reverse(findKelement(head, i));
        }
        temp = temp->next;
        i++;
    }
    return head;
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
    // values 5, 4, 3, 7, 9 and 2
    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = kReverse(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}