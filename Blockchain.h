#ifndef _BLOCKCHAIN_H
#define _BLOCKCHAIN_H
using namespace std;
#include <string>
#include "Transaction.h"
#include "Block.h"
#include <cstdlib>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class Blockchain
{
private:
    void insert(Transaction transaction)
    {
        Block *block = new Block(transaction);
        if (head == NULL)
        {
            block->prev_hash_ptr = NULL;
            head = block;
            return;
        }
        else
        {
            block->prev_hash_ptr = head;
            head = block;
            return;
        }
    }

public:
    Block *head;
    Blockchain() { head = NULL; }

    void add(int amount, string sender, string receiver)
    {
        Transaction t = Transaction(amount, sender, receiver);
        string nonce;
        string hash;
        while (true)
        {
            nonce = string(1, char(rand() % 26 + 97)) + string(1, char(rand() % 26 + 97)) + string(1, char(rand() % 26 + 97));
            string s = sha256((to_string(amount) + sender + receiver + nonce));
            if (s[s.length() - 1] == '0')
            {
                if (head == NULL)
                    hash = "NULL";
                else
                    hash = sha256((to_string(head->transaction.getAmount()) + head->transaction.getSender() + head->transaction.getReceiver() + head->transaction.getHash() + head->transaction.getNonce()));
                break;
            }
        }
        t.setHash(hash);
        t.setNonce(nonce);
        insert(t);
        return;
    }

    int getBalance(string person)
    {
        Block *temp = head;
        int balance = 50;
        while (temp != NULL)
        {
            if (temp->transaction.getReceiver() == person)
                balance += temp->transaction.getAmount();
            else if (temp->transaction.getSender() == person)
                balance -= temp->transaction.getAmount();
            temp = temp->prev_hash_ptr;
        }
        return balance;
    }

    void print()
    {
        Block *temp = head;
        recursive_print(temp);
    }

    void recursive_print(Block *temp)
    {
        if (temp == NULL)
            return;
        recursive_print(temp->prev_hash_ptr);
        cout << "Amount: " << temp->transaction.getAmount() << endl;
        cout << "Sender: " << temp->transaction.getSender() << endl;
        cout << "Receiver: " << temp->transaction.getReceiver() << endl;
        cout << "Nonce: " << temp->transaction.getNonce() << endl;
        cout << "Hash: " << temp->transaction.getHash() << endl;
    }
};

#endif