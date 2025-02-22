#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
    Node *links[2];

public:
    bool containsBit(int bit)
    {
        return links[bit] != nullptr;
    }

    void addLink(int bit)
    {
        links[bit] = new Node();
    }

    Node *getLink(int bit)
    {
        return links[bit];
    }

    Node *putLink(int bit)
    {
        if (!containsBit(bit))
        {
            addLink(bit);
        }

        return getLink(bit);
    }
};

class Trie
{
private:
    Node *root;

    int getBit(int num, int i)
    {
        return (num >> i) & 1;
    }

    void flipBit(int *num, int i)
    {
        *num = *num ^ (1 << i);
    }

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        int const bytesNum = sizeof(int);
        int const bitsNum = bytesNum * 8;

        Node *node = root;

        for (int i = bitsNum - 1; i >= 0; i--)
        {
            int bit = getBit(num, i);
            node = node->putLink(bit);
        }
    }

    int getMaxXor(int num)
    {
        int const bytesNum = sizeof(int);
        int const bitsNum = bytesNum * 8;

        Node *node = root;
        int maxNum = 0;

        for (int i = bitsNum - 1; i >= 0; i--)
        {
            int bit = getBit(num, i);
            if (node->containsBit(!bit))
            {
                node = node->getLink(!bit);
                if (getBit(maxNum, i) == bit)
                // if (!bit == 1)
                {
                    flipBit(&maxNum, i);
                }
            }
            else
            {
                node = node->getLink(bit);

                if (getBit(maxNum, i) == !bit)
                // if (bit == 1)
                {
                    flipBit(&maxNum, i);
                }
            }
        }

        return maxNum;
    }
};

int main()
{
    Trie *trie = new Trie();

    vector<int> nums = {7, 8, 9, 5, 4};

    for (int num : nums)
    {
        trie->insert(num);
    }

    cout << trie->getMaxXor(7) << endl;
}