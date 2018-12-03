#include "..\..\stdafx.h"
using namespace std;
NS(707)
//struct Node
//{
//    Node(int _val, Node* _prev = nullptr, Node* _next = nullptr)
//    {
//        val = _val;
//        prev = _prev;
//        next = _next;
//    }
//    Node* prev;
//    Node* next;
//    int val;
//};
//// double linked list
//class MyLinkedList {
//public:
//    /** Initialize your data structure here. */
//    MyLinkedList() {
//        len = 0;
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    void Print()
//    {
//        Node* cur = head;
//        while (cur != nullptr)
//        {
//            cout << cur->val << " ";
//            cur = cur->next;
//        }
//        cout << endl;
//    }
//    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
//    int get(int index) {
//        if (index >= len || index < 0) return -1;
//        Node* current = head;
//        while (index--) current = current->next;
//        return current->val;
//    }
//
//    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
//    void addAtHead(int val) {
//        len++;
//        Node* newNode = new Node(val);
//        if (len == 1)
//            head = tail = newNode;
//        else
//        {
//            newNode->next = head;
//            head->prev = newNode;
//            head = newNode;
//        }
//    }
//
//    /** Append a node of value val to the last element of the linked list. */
//    void addAtTail(int val) {
//        len++;
//        Node* newNode = new Node(val);
//        if (len == 1)
//            head = tail = newNode;
//        else
//        {
//            newNode->prev = tail;
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//
//    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
//    void addAtIndex(int index, int val) {
//        if (index < 0 || index > len) return;
//        if (index == len) addAtTail(val);
//        else if (index == 0) addAtHead(val);
//        else
//        {
//            Node* prev = nullptr;
//            Node* current = head;
//            while (index--)
//            {
//                prev = current;
//                current = current->next;
//            }
//            Node* newNode = new Node(val);
//            newNode->next = current;
//            newNode->prev = prev;
//            prev->next = newNode;
//            current->prev = newNode;
//            len++;
//        }
//    }
//    void deleteHead()
//    {
//        len--;
//        if (len == 0)
//        {
//            delete head;
//            head = tail = nullptr;
//        }
//        else
//        {
//            Node* current = head;
//            head = head->next;
//            head->prev = nullptr;
//            delete current;
//        }
//    }
//
//    void deleteTail()
//    {
//        len--;
//        if (len == 0)
//        {
//            delete head;
//            head = tail = nullptr;
//        }
//        else
//        {
//            Node* current = tail;
//            tail = tail->prev;
//            tail->next = nullptr;
//            delete current;
//        }
//    }
//
//    /** Delete the index-th node in the linked list, if the index is valid. */
//    void deleteAtIndex(int index) {
//        if (index < 0 || index >= len) return;
//        if (index == 0) deleteHead();
//        else if (index == len - 1) deleteTail();
//        else
//        {
//            Node* prev = nullptr;
//            Node* current = head;
//            while (index--)
//            {
//                prev = current;
//                current = current->next;
//            }
//            Node* next = current->next;
//            prev->next = next;
//            next->prev = prev;
//            delete current;
//            len--;
//        }
//    }
//
//    Node* head;
//    Node* tail;
//    int len;
//};
struct Node
{
    Node(int _val, Node* _next = nullptr)
    {
        val = _val;
        next = _next;
    }
    Node* next;
    int val;
};
// single linked list
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        len = 0;
        head = nullptr;
        tail = nullptr;
    }

    void Print()
    {
        Node* cur = head;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len || index < 0) return -1;
        Node* current = head;
        while (index--) current = current->next;
        return current->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        len++;
        Node* newNode = new Node(val);
        if (len == 1)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        len++;
        Node* newNode = new Node(val);
        if (len == 1)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > len) return;
        if (index == len) addAtTail(val);
        else if (index == 0) addAtHead(val);
        else
        {
            Node* prev = nullptr;
            Node* current = head;
            while (index--)
            {
                prev = current;
                current = current->next;
            }
            Node* newNode = new Node(val);
            newNode->next = current;
            prev->next = newNode;
            len++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;
        Node* prev = nullptr;
        Node* current = head;
        while (index--)
        {
            prev = current;
            current = current->next;
        }

        if (len == 1)
        {
            head = tail = nullptr;
        }
        else if (current == head)
        {
            head = current->next;
        }
        else if (current == tail)
        {
            tail = prev;
            tail->next = nullptr;
        }
        else
        {
            prev->next = current->next;
        }
        
        delete current;
        len--;
    }

    Node* head;
    Node* tail;
    int len;
};

void Test()
{
    MyLinkedList list;
    list.addAtHead(5);
    list.Print();
    list.addAtHead(2);
    list.Print();
    list.deleteAtIndex(1);
    list.Print();
    list.addAtIndex(1, 9);
    list.Print();
    list.addAtHead(4);
    list.Print();
    list.addAtHead(9);
    list.Print();
    list.addAtHead(8);
    list.Print();
    list.get(3);
    list.Print();
    list.addAtTail(1);
    list.Print();
    list.addAtIndex(3, 6);
    list.Print();
    list.addAtHead(3);
    list.Print();
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
END_NS