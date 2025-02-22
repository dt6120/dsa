#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
};

class List
{
public:
    int size;
    Node *head;
    Node *tail;

    List()
    {
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {};

int main() {}
