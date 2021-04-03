#ifndef _BLOCK_H
#define _BLOCK_H
using namespace std;
#include <string>
#include"Transaction.h"

struct Block {
    Block(Transaction transaction){
        this->transaction = transaction;
    };
    Transaction transaction;
    Block* prev_hash_ptr;
};

#endif