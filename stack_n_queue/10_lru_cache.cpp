#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node()
    {
        key = -1;
        value = -1;
        prev = nullptr;
        next = nullptr;
    }

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;

    void putAfterHead(Node *node)
    {
        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void remove(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap)
    {
        capacity = cap;
        mp.clear();
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        Node *node = mp[key];
        remove(node);
        putAfterHead(node);

        print();

        return node->value;
    }

    void put(int key, int value)
    {
        Node *node = nullptr;

        if (mp.find(key) == mp.end())
        {
            if (mp.size() == capacity)
            {
                Node *extra = tail->prev;
                remove(extra);
                mp.erase(extra->key);
                delete extra;
            }

            node = new Node(key, value);
        }
        else
        {
            node = mp[key];
            node->value = value;
            remove(node);
        }

        putAfterHead(node);
        mp[key] = node;

        print();
    }

    void print()
    {
        Node *node = head->next;
        while (node != tail)
        {
            cout << "{" << node->key << ", " << node->value << "}, ";
            node = node->next;
        }

        cout << endl;
    }
};

int main()
{
    LRUCache *cache = new LRUCache(3);

    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(3, 3);
    cache->put(4, 4);
    cout << cache->get(0) << endl;
    cout << cache->get(2) << endl;
    cache->get(3);
    cache->get(4);
    cache->put(1, 1);
}
