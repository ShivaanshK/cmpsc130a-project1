#ifndef _TRANSACTION_H
#define _TRANSACTION_H
using namespace std;
#include <string>

class Transaction
{
    public:
    Transaction(int amount, string sender, string receiver){
        this->amount=amount;
        this->sender=sender;
        this->receiver=receiver;
    };
    Transaction(){};
    int getAmount(){return amount;}
    string getSender(){return sender;}
    string getReceiver(){return receiver;}
    string getNonce(){return nonce;}
    string getHash(){return hash;}
    void setAmount(int amount){this->amount=amount;}
    void setSender(string sender){this->sender=sender;}
    void setReceiver(string receiver){this->receiver=receiver;}
    void setNonce(string nonce){this->nonce=nonce;}
    void setHash(string hash){this->hash=hash;}

    private: 
    Transaction *prev;
    int amount;                              
    string sender;                
    string receiver;             
    string nonce;                       
    string hash;                  
};

#endif