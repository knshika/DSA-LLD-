#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {};
};

void deleteNode(Node *&node)
{
    Node *temp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete temp;
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

    // Node *res =
    deleteNode(head->next);

    printList(head);

    return 0;
}