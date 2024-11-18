#include <iostream>

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
};

int findMiddle(Node *head)
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

    return slow->val;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(5);
    // head->next->next->next->next = new Node(2);

    int ans = findMiddle(head);
    cout << ans;

    return 0;
}