#include <iostream>
using namespace std;

struct ListNode{
    ListNode *next;
    int val;
    ListNode(int value){
        this->next = nullptr;
        this->val = value;
    }

    void print_list(ListNode *node){
        ListNode *itr = node;
        while(itr != nullptr){
            cout << itr->val << endl;
            itr = itr->next;
        }
        return;
    }

    void insert_back(ListNode *&node, int val){
        ListNode *newnode = new ListNode(val);
        if (node->next == nullptr){
            node->next = newnode;
        } else {
            ListNode *itr = node;
            while (itr->next != nullptr){
                itr = itr->next;
            }
            itr->next = newnode;
        }
    return;
    }

    void insert_front(ListNode *&node, int val){
        ListNode *newnode = new ListNode(val);
        newnode->next = node;
        node = newnode;
    }

    void delete_back(ListNode *&node){
        ListNode *itr = node;
        while (itr->next->next != nullptr){
            itr = itr->next;
        }
        delete(itr->next);
        itr->next = nullptr;
    }

    void delete_front(ListNode *&node){
        ListNode *itr = node;
        node = node->next;
        delete(itr);
    }

    ListNode *search_list(ListNode *node, int val){
        ListNode *itr = node;
        while (itr != nullptr){
            if (itr->val == val){
                cout << "Value Found" << endl;
                return itr;
            }
            itr = itr->next;
        }
        cout << "Not Found" << endl;
        return NULL;
    }
};

int main(){

    ListNode *node = new ListNode(9);
    node->insert_back(node,8);
    node->insert_back(node,5);
    node->insert_back(node,4);
    node->print_list(node);
    cout << endl;
    node->insert_front(node,15);
    node->insert_front(node,2);
    node->print_list(node);
    cout << endl;
    node->delete_back(node);
    node->print_list(node);
    node->delete_front(node);
    cout << endl;
    node->print_list(node);
    cout << endl;
    ListNode *snode = node->search_list(node,4);
    snode = node->search_list(node,5);
    cout << snode->val << endl;
    return 1;
}