#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
    Node *links[26];
    int prefixCount = 0;
    int endCount = 0;

public:
    bool containsChar(char c)
    {
        return links[c - 'a'] != nullptr && links[c - 'a']->prefixCount > 0;
    }

    Node *getNodeForChar(char c)
    {
        return links[c - 'a'];
    }

    void incrementPrefixCount(char c)
    {
        links[c - 'a']->prefixCount++;
    }

    void decrementPrefixCount(char c)
    {
        if (links[c - 'a']->prefixCount > 0)
        {
            links[c - 'a']->prefixCount--;
        }
    }

    void setNodeForChar(char c, Node *node)
    {
        links[c - 'a'] = node;
    }

    int getPrefixCount()
    {
        return prefixCount;
    }

    int getEndCount()
    {
        return endCount;
    }

    bool isEnd()
    {
        return endCount > 0;
    }

    void setEnd()
    {
        endCount++;
    }

    void removeEnd()
    {
        if (endCount > 0)
        {
            endCount--;
        }
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;

        for (char c : word)
        {
            if (!node->containsChar(c))
            {
                delete node->getNodeForChar(c);
                node->setNodeForChar(c, new Node());
            }

            node->incrementPrefixCount(c);
            node = node->getNodeForChar(c);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (char c : word)
        {
            if (!node->containsChar(c))
            {
                return false;
            }

            node = node->getNodeForChar(c);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (char c : prefix)
        {
            if (!node->containsChar(c))
            {
                return false;
            }

            node = node->getNodeForChar(c);
        }

        return true;
    }

    int countWordsEqualTo(string word)
    {
        Node *node = root;

        for (char c : word)
        {
            if (!node->containsChar(c))
            {
                return 0;
            }

            node = node->getNodeForChar(c);
        }

        return node->getEndCount();
    }

    int countWordsStartingWith(string prefix)
    {
        Node *node = root;

        for (char c : prefix)
        {
            if (!node->containsChar(c))
            {
                return 0;
            }

            node = node->getNodeForChar(c);
        }

        return node->getPrefixCount();
    }

    void erase(string word)
    {
        if (!search(word))
        {
            return;
        }

        Node *node = root;

        for (char c : word)
        {
            node->decrementPrefixCount(c);
            node = node->getNodeForChar(c);
        }

        node->removeEnd();
    }
};

int main()
{
    Trie *t = new Trie();

    t->insert("apple");
    t->insert("apply");
    t->insert("apple");
    cout << t->search("apple") << endl;
    cout << t->search("applo") << endl;
    cout << t->search("apply") << endl;
    cout << t->startsWith("appl") << endl;
    cout << t->startsWith("xxx") << endl;
    cout << t->countWordsEqualTo("apple") << endl;
    cout << t->countWordsStartingWith("appl") << endl;
    t->erase("apple");
    t->erase("apple");
    cout << t->countWordsEqualTo("apple") << endl;
    t->insert("apple");
    cout << t->countWordsEqualTo("apple") << endl;
}
