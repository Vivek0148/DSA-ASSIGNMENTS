#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class CircularLL{
public:
    Node* head;
    CircularLL(){
        head = NULL;
    }
    void insertEnd(int val){
        Node* n = new Node(val);
        if (!head){
            head = n;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
    void displayWithRepeat() {
        if (!head)
        return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};
int main() {
    CircularLL list;
    list.insertEnd(20);
    list.insertEnd(100);
    list.insertEnd(40);
    list.insertEnd(80);
    list.insertEnd(60);
    cout << "Output: ";
    list.displayWithRepeat();
    return 0;
}
