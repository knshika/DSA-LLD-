#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {};
};

int nFromEnd(Node *head, int n)
{
    Node *first = head;
    Node *second = head;

    for (int i = 0; i < n; i++)
    {
        first = first->next;
    }

    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    return second->val;
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
    head->next->next->next->next = new Node(3);

    printList(head);

    int res = nFromEnd(head, 1);

    cout << res;
    return 0;
}