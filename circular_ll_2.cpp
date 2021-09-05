#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert_at_tail(node* head, int val)
{
    if(head == NULL)
    {
        insert_at_head(head, val);
    }

    node* n = new node(val);
    node* temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }
    
    temp->next = n;
    n->next = head;
}