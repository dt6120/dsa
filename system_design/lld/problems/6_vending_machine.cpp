#include <bits/stdc++.h>

using namespace std;

enum Denomination
{
    ONE = 1,
    TWO = 2,
    FIVE = 5,
    TEN = 10,
    TWENTY = 20
};

class Coin
{
private:
    Denomination denomination;

public:
    Coin(Denomination denomination)
    {
        this->denomination = denomination;
    }

    Denomination getDenomination()
    {
        return denomination;
    }
};

enum ItemType
{
    ITEM_1,
    ITEM_2,
    ITEM_3,
    ITEM_4
};

class Item
{
private:
    ItemType type;
    int price;

public:
    Item(ItemType type, int price)
    {
        this->type = type;
        this->price = price;
    }

    ItemType getType()
    {
        return type;
    }

    int getPrice()
    {
        return price;
    }
};

class ItemPlaceholder
{
private:
    Item *item;
    int code;
    bool empty;

public:
    ItemPlaceholder(int code)
    {
        this->code = code;
        empty = true;
    }

    void add(Item *item)
    {
        if (!empty)
        {
            cout << "Item placeholder not empty" << endl;
            return;
        }

        this->item = item;
        empty = false;
    }

    void dispense()
    {
        if (empty)
        {
            cout << "Item placeholder is empty" << endl;
            return;
        }

        empty = true;
    }

    bool isEmpty()
    {
        return this->empty;
    }

    int getCode()
    {
        return code;
    }
};

class Inventory
{
private:
    vector<ItemPlaceholder *> inventory;

    void initialize(int capacity)
    {
        for (int i = 1; i <= capacity; i++)
        {
            inventory.push_back(new ItemPlaceholder(i));
        }
    }

public:
    Inventory(int capacity)
    {
        initialize(capacity);
    }

    int getSize()
    {
        return inventory.size();
    }

    void addItem(Item *item, int code)
    {
        for (int i = 0; i < getSize(); i++)
        {
            if (inventory[i]->getCode() == code)
            {
                if (inventory[i]->isEmpty())
                {
                    inventory[i]->add(item);
                }
                else
                {
                    cout << "Item placeholder is not empty" << endl;
                }

                break;
            }
        }
    }

    void dispenseItem(int code)
    {
        for (int i = 0; i < getSize(); i++)
        {
            if (inventory[i]->getCode() == code)
            {
                if (!inventory[i]->isEmpty())
                {
                    inventory[i]->dispense();
                }
                else
                {
                    cout << "Item placeholder is empty" << endl;
                }

                break;
            }
        }
    }
};

enum MachineState
{
    IDLE,
    HAS_MONEY,
    SELECTION,
    DISPENSE
};

class State
{
};

class IdleState : public State
{
};

class VendingMachine
{
private:
    static VendingMachine *instance;
    static mutex mtx;

    Inventory *inventory;
    vector<Coin *> coins;
    MachineState state;

    VendingMachine(const VendingMachine &) = delete;
    VendingMachine &operator=(const VendingMachine &) = delete;

    VendingMachine() {}

public:
    static VendingMachine *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new VendingMachine();
            }
        }

        return instance;
    }
};

VendingMachine *VendingMachine::instance = nullptr;
mutex VendingMachine::mtx;

int main()
{
}

/*

Design Pattern
- State Design
    - Used when problem has specific states defined
    - Each state has specific operations allowed
    - Popular examples are vending machine, TV

    - Define abstract state class with all possible states
    - Define classes for every state possible
    - Every state class will inherit abstract state class and implement required functions

Entities
- Coin
- Item
- Shelf
- State
- Machine

Inheritance
- IdleState is State
- HasMoneyState is State
- SelectionState is State
- DispenseState is State

Relations
- Shelf has items
- Inventory has shelves
- Machine has state
- Machine has coins
- Machine has inventory
*/
