#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *mergeLinkedList(Node *head1, Node *head2)
    {
        Node *dummy = new Node(-1);
        Node *curr = dummy;

        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val <= head2->val)
            {
                curr->next = head1;
                head1 = head1->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        if (head1 != nullptr)
        {
            curr->next = head1;
        }
        else if (head2 != nullptr)
        {
            curr->next = head2;
        }

        return dummy->next; // 1st node is dummy node
    }

    void printLL(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    Node *createLL(int arr[], int n)
    {
        Node *head = new Node(arr[0]);
        Node *curr = head;
        for (int i = 1; i < n; i++)
        {
            curr->next = new Node(arr[i]);
            curr = curr->next;
        }
        printLL(head);
        return head;
    }
};

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    Solution solution;

    Node *head1 = solution.createLL(arr1, 4);
    Node *head2 = solution.createLL(arr2, 4);

    Node *res = solution.mergeLinkedList(head1, head2);

    solution.printLL(res);

    return 0;
}
