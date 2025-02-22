#include <bits/stdc++.h>

using namespace std;

class BankAccount
{
private:
    int accountId;
    double balance;
    mutable mutex mtx;

public:
    BankAccount(int accountId, double balance) : accountId(accountId), balance(balance) {}

    bool withdraw(double amount)
    {
        lock_guard<mutex> lock(mtx);
        if (amount > balance)
        {
            return false;
        }
        balance -= amount;
        return true;
    }

    bool deposit(double amount)
    {
        lock_guard<mutex> lock(mtx);
        balance += amount;
        return true;
    }

    double getBalance()
    {
        lock_guard<mutex> lock(mtx);
        return balance;
    }

    int getAccountId()
    {
        return accountId;
    }
};

class Card
{
private:
    int cardNumber;
    int pin;
    int linkedAccountId;

public:
    Card(int cardNumber, int pin, int linkedAccountId) : cardNumber(cardNumber), pin(pin), linkedAccountId(linkedAccountId) {}

    bool validatePin(int inputPin)
    {
        return inputPin == pin;
    }

    int getCardNumber()
    {
        return cardNumber;
    }

    int getLinkedAccountId()
    {
        return linkedAccountId;
    }
};

class Transaction
{
protected:
    int id;
    BankAccount *account;
    double amount;

public:
    Transaction(int id, BankAccount *account, double amount) : id(id), account(account), amount(amount) {}

    virtual bool execute()
    {
        return false;
    }

    double getAmount()
    {
        return amount;
    }
};

class WithdrawTransaction : public Transaction
{
public:
    WithdrawTransaction(int id, BankAccount *account, double amount) : Transaction(id, account, amount) {}

    bool execute() override
    {
        return account->withdraw(amount);
    }
};

class DepositTransaction : public Transaction
{
public:
    DepositTransaction(int id, BankAccount *account, double amount) : Transaction(id, account, amount) {}

    bool execute() override
    {
        return account->deposit(amount);
    }
};

class BankServer
{
private:
    unordered_map<int, BankAccount *> accounts;
    mutex mtx;

public:
    BankServer() {}

    void createAccount(int accountId, double balance = 0)
    {
        lock_guard<mutex> lock(mtx);
        accounts[accountId] = new BankAccount(accountId, balance);
    }

    BankAccount *getAccount(int accountId)
    {
        if (accounts.find(accountId) == accounts.end())
        {
            return nullptr;
        }
        return accounts[accountId];
    }

    bool authenticate(Card *card, int inputPin)
    {
        return card->validatePin(inputPin);
    }

    bool processTransaction(Transaction *transaction)
    {
        return transaction->execute();
    }
};

class CashDispenser
{
private:
    int balance;
    mutex mtx;

public:
    CashDispenser(int balance = 0) : balance(balance) {}

    int getBalance()
    {
        return balance;
    }

    bool dispenseCash(int amount)
    {
        lock_guard<mutex> lock(mtx);
        if (amount > balance)
        {
            return false;
        }

        balance -= amount;
        return true;
    }
};

class ATM
{
private:
    BankServer *bankServer;
    CashDispenser *cashDispenser;
    int transactionCounter;

public:
    ATM(BankServer *bankServer, CashDispenser *cashDispenser) : bankServer(bankServer), cashDispenser(cashDispenser) {}

    bool authenticateUser(Card *card, int inputPin)
    {
        return card->validatePin(inputPin);
    }

    double getBalance(int accountId)
    {

        BankAccount *account = bankServer->getAccount(accountId);
        if (account == nullptr)
        {
            return -1;
        }
        return account->getBalance();
    }

    bool withdraw(int accountId, int amount)
    {
        BankAccount *account = bankServer->getAccount(accountId);
        if (account == nullptr)
        {
            return false;
        }
        if (amount > (cashDispenser->getBalance()))
        {
            return false;
        }

        WithdrawTransaction *transaction = new WithdrawTransaction(generateTransactionId(), account, amount);
        if (!bankServer->processTransaction(transaction))
        {
            return false;
        }

        return cashDispenser->dispenseCash(amount);
    }

    bool deposit(int accountId, int amount)
    {
        BankAccount *account = bankServer->getAccount(accountId);
        if (account == nullptr)
        {
            return false;
        }
        DepositTransaction *transaction = new DepositTransaction(generateTransactionId(), account, amount);
        return bankServer->processTransaction(transaction);
    }

    int generateTransactionId()
    {
        return ++transactionCounter;
    }
};

int main()
{
    BankServer *bankServer = new BankServer();
    CashDispenser *cashDispenser = new CashDispenser(1000);
    ATM *atm = new ATM(bankServer, cashDispenser);

    bankServer->createAccount(123, 1000);
    bankServer->createAccount(456, 2000);

    Card *card = new Card(789, 0000, 123);

    cout << "User authenticated " << atm->authenticateUser(card, 0000) << endl;

    cout << "User balance " << atm->getBalance(123) << endl;

    cout << "Withdraw success " << atm->withdraw(123, 1500) << endl;
    cout << "Withdraw success " << atm->withdraw(123, 750) << endl;

    cout << "Deposit success " << atm->deposit(123, 250) << endl;

    cout << "User balance " << atm->getBalance(123) << endl;
}