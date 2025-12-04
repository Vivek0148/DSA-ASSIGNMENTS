#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node(int val) 
    {
        data=val;
        next=nullptr;
    }
};
Node *head=nullptr;
void insertAtEnd(int val) 
{
    Node* newNode=new Node(val);
    newNode->data=val;
    if (head==NULL) 
    {
        head=newNode;
        newNode->next=head;
    } 
    else 
    {
        Node* temp=head;
        while(temp->next!=head)
        temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
    }
}
void split(Node* head, Node** head1, Node** head2) {
    if (head==nullptr)
        return;
    Node *slow=head,*fast=head;
    while (fast->next!=head && fast->next->next!=head) 
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    if (fast->next->next==head)
    fast=fast->next;
    *head1=head;
    if (head->next!=head)
    *head2=slow->next;
    fast->next=slow->next;
    slow->next=head;
}
int main()
{
    int size,val;
    cout<<"Enter number of elements: ";
    cin>>size;
    cout<<"Enter elements: ";
    for (int i=0;i<size;i++)
    {
        cin>>val;
        insertAtEnd(val);
    }
    Node *head1=nullptr,*head2=nullptr;
    split(head,&head1,&head2);
    cout<<"First Linked List: ";
    Node* temp=head1;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while (temp!=head1);
    cout<<endl;
    cout<<"Second Linked List: ";
    temp=head2;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while (temp!=head2);
    cout<<endl;
}