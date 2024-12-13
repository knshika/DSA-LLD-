#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {};
};

Node *addTwoNum(Node *num1, Node *num2)
{
    Node *dummy = new Node(0);
    Node *curr = dummy;
    int carry = 0;

    while (num1 != nullptr || num2 != nullptr || carry != 0)
    {
        int sum = carry;
        if (num1 != nullptr)
        {
            sum += num1->val;
            num1 = num1->next;
        }
        if (num2 != nullptr)
        {
            sum += num2->val;
            num2 = num2->next;
        }
        curr->next = new Node(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }
    return dummy->next;
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

int main()
{
    int n1[] = {2, 4, 3}; // num is 342
    int n2[] = {5, 6, 4}; // num is 465

    Node *num1 = createLL(n1, 3);
    Node *num2 = createLL(n2, 3);

    Node *res = addTwoNum(num1, num2);
    printLL(res); //{7,0,8} sum is 807

    return 0;
}
