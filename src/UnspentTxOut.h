//
// Created by kourin on 2018/08/10.
//

#ifndef TINYCHAIN_CPP_UNSPENTTXOUT_H
#define TINYCHAIN_CPP_UNSPENTTXOUT_H

#include <string>
#include <sstream>

#include "OutPoint.h"

class UnspentTxOut {
public:
    int value;
    std::string toAddr;

    //The ID of the transaction this output belongs to.
    std::string txid;
    int txoutIdx;

    //Did this TxOut from a coinbase transaction?
    bool isCoinbase;

    // The blockchain height this TxOut was included in the chain.
    int height;

    UnspentTxOut(): value(0), toAddr(""), txid(""), txoutIdx(0), isCoinbase(false), height(0){};
    UnspentTxOut(const int value, const std::string toAddr, const std::string txid, const int txoutIdx, const bool isCoinbase, const int height)
        : value(value), toAddr(toAddr), txid(txid), txoutIdx(txoutIdx), isCoinbase(isCoinbase), height(height) {};

    UnspentTxOut(const UnspentTxOut&);

    std::string toString() {
        std::stringstream ss;
        ss << "{";
        ss << "\"value\":" << this->value << ",";
        ss << "\"toAddr\":\"" << this->toAddr << "\",";
        ss << "\"txid\":\"" << this->txid << "\",";
        ss << "\"txoutIdx\":" << this->txoutIdx << ",";
        ss << "\"isCoinbase\"" << (this->isCoinbase ? "true" : "false") << ",";
        ss << "\"height\":" << this->height;
        ss << "}";
        return ss.str();
    }

    OutPoint outpoint() {
        return OutPoint(this->txid, this->txoutIdx);
    }
};


#endif //TINYCHAIN_CPP_UNSPENTTXOUT_H
