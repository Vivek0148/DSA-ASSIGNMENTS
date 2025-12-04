#include <iostream>
#include <cstdlib>
using namespace std;
struct DLNode {
    int val;
    DLNode *prev;
    DLNode *next;
    DLNode(int v): val(v), prev(NULL), next(NULL) {}
};
struct DL {
    DLNode *head;
    DL() { head = NULL; }
    void push_back(int x) {
        if(!head) {
            head = new DLNode(x);
            return;
        }
        DLNode *t = head;
        while(t->next) t = t->next;
        DLNode *n = new DLNode(x);
        t->next = n;
        n->prev = t;
    }
    int popcount(int x) {
        int c=0;
        unsigned int y = (unsigned int)x;
        while(y) { c += (y & 1); y >>= 1; }
        return c;
    }
    void removeEvenParity() {
        DLNode *cur = head;
        while(cur) {
            int p = popcount(cur->val);
            DLNode *nxt = cur->next;
            if(p % 2 == 0) {
                if(cur->prev == NULL && cur->next == NULL) {
                    delete cur;
                    head = NULL;
                    return; 
                } else if(cur->prev == NULL) {
                    head = cur->next;
                    head->prev = NULL;
                    delete cur;
                } else if(cur->next == NULL) {
                    cur->prev->next = NULL;
                    delete cur;
                } else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                }
            }
            cur = nxt;
        }
    }
    void print() {
        DLNode *t = head;
        if(!t) { cout << "Empty DL\n"; return; }
        while(t) {
            cout << t->val;
            if(t->next) cout << " <=> ";
            t = t->next;
        }
        cout << "\n";
    }
    ~DL() {
        DLNode *p = head;
        while(p) {
            DLNode *q = p->next;
            delete p;
            p = q;
        }
    }
};
struct CLNode {
    int v;
    CLNode *next;
    CLNode(int _v): v(_v), next(NULL) {}
};
struct CL {
    CLNode *head;
    CL() { head = NULL; }
    void add(int x) {
        CLNode *n = new CLNode(x);
        if(!head) {
            head = n;
            n->next = n; 
            return;
        }
        CLNode *t = head;
        while(t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }
    int popc(int x) {
        int c=0; unsigned int y=(unsigned int)x;
        while(y) { c += (y & 1); y >>= 1; }
        return c;
    }
    void removeEvenParity() {
        if(!head) return;
        CLNode *cur = head;
        CLNode *prev = NULL;
        bool started = false;
        if(head->next == head) {
            if(popc(head->v) % 2 == 0) { delete head; head = NULL; }
            return;
        }
        bool foundEven = true;
        while(foundEven) {
            foundEven = false;
            if(!head) break;
            prev = head;
            cur = head->next;
            while(prev->next != head) prev = prev->next;
            CLNode *iter = head;
            do {
                if(popc(iter->v) % 2 == 0) { 
                    foundEven = true;
                    if(iter == head) {
                        CLNode *tail = prev;
                        CLNode *toDel = head;
                        head = head->next;
                        tail->next = head;
                        delete toDel;
                        iter = head; 
                        if(!head) break;
                        if(head->next == head) break; 
                    } else {
                        CLNode *p = head;
                        while(p->next != iter) p = p->next;
                        p->next = iter->next;
                        CLNode *toDel = iter;
                        iter = iter->next;
                        delete toDel;
                    }
                } else {
                    iter = iter->next;
                }
            } while(iter != head && head != NULL);
            if(head && head->next == head) {
                if(popc(head->v) % 2 == 0) { delete head; head = NULL; }
            }
        } 
    }

    void print() {
        if(!head) { cout << "Empty CL\n"; return; }
        CLNode *t = head;
        bool first = true;
        do {
            if(!first) cout << " -> ";
            cout << t->v;
            first = false;
            t = t->next;
        } while(t != head);
        cout << "\n";
    }
    ~CL() {
        if(!head) return;
        CLNode *t = head->next;
        head->next = NULL; 
        while(t) {
            CLNode *n = t->next;
            delete t;
            t = n;
        }
        delete head;
        head = NULL;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "=== Example 1: CL ===\n";
    CL cl;
    cl.add(9);
    cl.add(11);
    cl.add(34);
    cl.add(6);
    cl.add(13);
    cl.add(21);
    cout << "CL before: ";
    cl.print();
    cl.removeEvenParity();
    cout << "CL after:  ";
    cl.print();
    cout << "\n";
    cout << "=== Example 2: DL ===\n";
    DL dl;
    dl.push_back(18);
    dl.push_back(15);
    dl.push_back(8);
    dl.push_back(9);
    dl.push_back(14);
    cout << "DL before: ";
    dl.print();
    dl.removeEvenParity();
    cout << "DL after:  ";
    dl.print();
    return 0;
}
