#include <iostream>
#include <unordered_set>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {};
};

void insertNode(Node *&head, int val)
{
    Node *node = new Node(val);
    if (head == nullptr)
    {
        head = node;
        return;
    }
    Node *cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = node;
    return;
}

Node *intersectNode(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return nullptr;
    // unordered_set<Node*> st;
    // while(head1 != nullptr){
    //     st.insert(head1);
    //     head1 = head1->next;
    // }
    // while(head2 != nullptr){
    //     if(st.find(head2) != st.end()) return head2;
    //     head2 = head2->next;
    // }
    // return NULL;

    Node *pt1 = head1;
    Node *pt2 = head2;
    while (pt1 != pt2)
    {

        if (pt1 == nullptr)
            pt1 = head2;
        else
            pt1 = pt1->next;
        pt2 = (pt2 == nullptr) ? head1 : pt2->next;
    }
    return pt1;
}

void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val << endl;
}

int main()
{
    // creation of both lists
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    Node *head1 = head;
    head = head->next->next->next;
    Node *headSec = NULL;
    insertNode(headSec, 3);
    Node *head2 = headSec;
    headSec->next = head;
    // printing of the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);
    // checking if intersection is present
    Node *answerNode = intersectNode(head1, head2);
    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->val << endl;
    return 0;
}