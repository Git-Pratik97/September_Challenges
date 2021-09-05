#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert_at_tail(Node* &head, int val)
{
    Node* n = new Node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

void reverse(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    reverse(head->next);
    cout << head->data << "->";
}

Node* reverse_k(Node* head, int k)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next_ptr;

    int count = 0;
    while(curr != NULL && count < k)
    {
        next_ptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next_ptr;
        count++;
    }

    if(next_ptr != NULL)
    {
        head->next = reverse_k(next_ptr, k);
    }

    return prev;
}

int main()
{
    Node* head = new Node(1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);

    display(head);
    cout << endl;
    // reverse(head);

    Node* new_head = reverse_k(head, 2);

    display(new_head);

    return 0;
}