#include <iostream>
#include "Block.h"
#include "Blockchain.h"
#include "Transaction.h"
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
    Blockchain blockchain;
    string input;
    while (true)
    {
        cout << "Welcome to the transaction-chain application...." << endl;
        cout << "1) Add a transaction to the chain." << endl;
        cout << "2) Find Balance of a person." << endl;
        cout << "3) Print the chain." << endl;
        cout << "4) Exit." << endl;
        cout << "Which operation do you want to make? (1,2,3,4): " << endl;
        getline(cin, input);
        if(input == "1"){
            string amount;
            string sender;
            string receiver;
            cout << "Integer amount of money:" << endl;
            getline(cin,amount);
            cout << "Sender Name:" << endl;
            getline(cin,sender);
            cout << "Receiver Name:" << endl;
            getline(cin,receiver);
            blockchain.add(stoi(amount),sender,receiver);
            continue;
        } else if(input == "2"){
            string person;
            cout << "Person's name:" << endl;
            getline(cin,person);
            cout << blockchain.getBalance(person) << endl;
            continue;
        } else if(input == "3"){
            blockchain.print();
            continue;
        } else if(input == "4"){
            break;
        } else {
            cout << "wrong operation!" << endl;
            break;
        }
    }
}