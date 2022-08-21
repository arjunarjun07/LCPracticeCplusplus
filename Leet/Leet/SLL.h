#pragma once
#include <iostream>
#pragma once

template<typename T>class Node 
{
private:
    T data;
    Node<T>* next;
    template<typename U>friend class LinkedList;
public:
    Node() {
        this->next = NULL;
    }
};

template<typename T>class LinkedList 
{
private:

public:
    Node<T>* head;

    LinkedList() {
        this->head = NULL;
    }

    void add(T item) 
    {
        Node<T>* node = new Node<T>();
        
        node->data = item;

        if (head == NULL) 
        {
            head = node;
            cout << "new node added(firstnode) !" << endl;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        cout << "new node added at back!" << endl;
    }

    void addFront(T item) 
    {
        Node<T>* node = new Node<T>();
        node->data = item;
        
        if (head == NULL) 
        {
            head = node;
            cout << "new node added(firstnode) !" << endl;
            return;
        }

        node->next = head;
        head = node;
        cout << "new node added at front !" << endl;
    }

    void add(int index, T item) 
    {
        if (index > length() || index < 0) {
            cout << "index out of bound !" << endl;
            return;
        }

        Node<T>* node = new Node<T>();
        node->data = item;

        int count = 0;
        Node<T>* temp = head;

        while (temp != NULL && count < index) {
            if (count == index - 1) {
                if (temp->next != NULL) {
                    node->next = temp->next;
                }
                temp->next = node;
                cout << "new node added at index " << index << " !" << endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    void myadd(int index, int data)
    {
        if (index > length() || index < 0) {
            cout << "index out of bound !" << endl;
            return;
        }

        int count = 0;
        Node<T>* temp = head;

        while (temp != NULL && count < index)
        {
            if (count == index - 1)
            {
                break;
            }

            count++;
            temp = temp->next;
        }

        Node<T>* node = new Node<T>();
        node->data = data;
        node->next = temp->next;
        temp->next = node;

    }

    int length() 
    {
        int len = 0;
        Node<int>* temp = head;
        while (temp != NULL) 
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void displayAll() 
    {
        if (head == NULL) {
            cout << "linked list is empty" << endl;
            return;
        }
        cout << endl << "----link list items------" << endl;
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " | ";
            temp = temp->next;
        }
        cout << endl << "--------------------------" << endl;
    }

    void remove() 
    {
        if (head == NULL) {
            cout << "linked list is empty !" << endl;
            return;
        }
        if (head->next == NULL) {
            head = NULL;
            cout << "last item removed" << endl;
            return;
        }

        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->next->next == NULL) {
                temp->next = NULL;
                cout << "last item removed" << endl;
                break;
            }
            temp = temp->next;
        }

    }

    void remove(int index) {
        if (head == NULL) {
            cout << "linked list is empty !" << endl;
            return;
        }
        if (index >= length() || index < 0) {
            cout << "index out of bound !" << endl;
            return;
        }
        if (index == 0) {
            removeFront();
            cout << "item removed at index " << index << endl;
            return;
        }

        int count = 0;
        Node<T>* temp = head;
        while (temp != NULL) {
            if (count == index - 1) {
                temp->next = temp->next->next;
                cout << "item removed at index " << index << endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    void removeFront() 
    {
        if (head == NULL) {
            cout << "linked list is empty !" << endl;
            return;
        }
        head = head->next;
        cout << "front item removed" << endl;
    }

    T get(int index) {
        if (head == NULL) {
            cout << "linked list is empty !" << endl;
            return -9999;
        }
        if (index >= length() || index < 0) {
            cout << "index out of bound !" << endl;
            return -9999;
        }
        if (index == 0) {
            return head->data;
        }
        int count = 0;
        T res;
        Node<T>* temp = head;
        while (temp != NULL) {
            if (count++ == index) {
                res = temp->data;
                break;
            }
            temp = temp->next;
        }
        return res;
    }

    //-------------------------------------- LEET ---------------------------------------------

    Node<T>* getMiddle(Node<T>* head)
    {
        int length = 0;

        Node<T>* temp = head;

        while (temp)
        {
            length++;
            temp = temp->next;
        }

        int middle = int(length / 2);

        Node<T>* temp2 = head;

        int countr = 0;
        while (temp2 && countr <= middle)
        {
            if (countr == middle)
            {
                break;
            }

            countr++;
            temp2 = temp2->next;
        }

        return temp2;
    }

    Node<T>* middleNode_Optimized(Node<T>* head) {

        Node<T>* slow = head;
        Node<T>* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node<T>* reverseList(Node<T>* head) {

        Node<T>* prev = NULL;
        Node<T>* nxt = NULL;
        Node<T>* curr = head;

        while (curr)
        {

            nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;

        }

        return prev;
    }

    void deleteNode(Node<T>* node) {

        Node<T>* prev = NULL;

        while (node->next)
        {
            prev = node;
            node->val = node->next->val;
            node = node->next;
        }

        prev->next = NULL;

        delete(node);
    }
};