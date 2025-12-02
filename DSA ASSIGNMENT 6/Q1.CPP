#include <iostream>
using namespace std;
class CNode {
public:
    int data;
    CNode* next;
    CNode(int val){
        data = val;
        next = NULL;
    }
};
class CircularLL{
    CNode* last;
public:
    CircularLL(){
        last = NULL;
    }
    void insertFirst(int val) {
        CNode* n = new CNode(val);
        if (!last) {
            last = n;
            last->next = last;
        } else {
            n->next = last->next;
            last->next = n;
        }
    }
    void insertLast(int val){
        CNode* n = new CNode(val);
        if (!last) {
            last = n;
            last->next = last;
        } else {
            n->next = last->next;
            last->next = n;
            last = n;
        }
    }
    void insertAfter(int key, int val) {
        if (!last){ 
            cout << "List empty!\n";
            return;
        }
        CNode* temp = last->next;
        do {
            if (temp->data == key) {
                CNode* n = new CNode(val);
                n->next = temp->next;
                temp->next = n;
                if (temp == last) last = n;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found!\n";
    }
    void insertBefore(int key, int val) {
        if (!last){
            cout << "List empty!\n";
            return;
        }
        CNode* curr = last->next;
        CNode* prev = last;
        do {
            if (curr->data == key) {
                CNode* n = new CNode(val);
                n->next = curr;
                prev->next = n;
                if (curr == last->next)  
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
        cout << "Node " << key << " not found!\n";
    }
    void deleteNode(int key) {
        if(!last){
            cout << "List empty!\n";
            return;
        }
        CNode* curr = last->next;
        CNode* prev = last;
        do {
            if (curr->data == key) {
                if (curr == last && curr->next == last) { 
                    last = NULL;
                }
                else if (curr == last->next) { 
                    last->next = curr->next;
                }
                else if (curr == last) { 
                    prev->next = curr->next;
                    last = prev;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Node deleted!\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
        cout << "Node not found!\n";
    }
    void search(int key) {
        if (!last) {
            cout << "List empty!\n";
            return;
        }
        CNode* temp = last->next;
        do {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node not found!\n";
    }
    void display() {
        if (!last){
            cout << "List empty!\n";
            return;
        }
        CNode* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};
class DNode{
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val){
        data = val;
        prev = next = NULL;
    }
};
class DoublyLL{
    DNode* head;
public:
    DoublyLL(){
        head = NULL;
    }
    void insertFirst(int val){
        DNode* n = new DNode(val);
        if (!head)
        head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }
    void insertLast(int val) {
        DNode* n = new DNode(val);
        if (!head)
        head = n;
        else {
            DNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }
    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) {
                DNode* n = new DNode(val);
                n->next = temp->next;
                n->prev = temp;
                if (temp->next)
                    temp->next->prev = n;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found!\n";
    }
    void insertBefore(int key, int val) {
        if (!head){
            cout << "List empty!\n";
            return;
        }
        if (head->data == key){
            insertFirst(val);
            return;
        }
        DNode* curr = head->next;
        while (curr) {
            if (curr->data == key) {
                DNode* n = new DNode(val);
                n->prev = curr->prev;
                n->next = curr;
                curr->prev->next = n;
                curr->prev = n;
                return;
            }
            curr = curr->next;
        }
        cout << "Node not found!\n";
    }
    void deleteNode(int key) {
        if (!head) { cout << "List empty!\n";
            return;
        }
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) {
                if (temp == head && !temp->next)
                    head = NULL;
                else if (temp == head)
                    head = temp->next, head->prev = NULL;
                else if (!temp->next)
                    temp->prev->next = NULL;
                else
                    temp->prev->next = temp->next, temp->next->prev = temp->prev;
                delete temp;
                cout << "Node deleted!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found!\n";
    }
    void search(int key) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not found!\n";
    }
    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    CircularLL cll;
    DoublyLL dll;
    int ch, listType;
    do {
        cout << "\nChoose List:\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> listType;
        if (listType == 3)
        break;
        int op, val, key;
        do {
            cout << "\nOperations:\n";
            cout << "1. Insert First\n2. Insert Last\n3. Insert After\n4. Insert Before\n";
            cout << "5. Delete Node\n6. Search\n7. Display\n8. Back\nEnter choice: ";
            cin >> op;
            if (op == 8)
            break;
            switch (op) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? cll.insertFirst(val) : dll.insertFirst(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? cll.insertLast(val) : dll.insertLast(val);
                break;

            case 3:
                cout << "Insert after which value? ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? cll.insertAfter(key, val) : dll.insertAfter(key, val);
                break;

            case 4:
                cout << "Insert before which value? ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? cll.insertBefore(key, val) : dll.insertBefore(key, val);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                (listType == 1) ? cll.deleteNode(key) : dll.deleteNode(key);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                (listType == 1) ? cll.search(key) : dll.search(key);
                break;

            case 7:
                (listType == 1) ? cll.display() : dll.display();
                break;
            }
        } while (true);
    } while (true);
    return 0;
}
