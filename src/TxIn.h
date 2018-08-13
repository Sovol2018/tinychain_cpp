//
// Created by kourin on 2018/08/10.
//

#ifndef TINYCHAIN_CPP_TXIN_H
#define TINYCHAIN_CPP_TXIN_H


#include <vector>
#include <string>
#include <memory>

#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>

#include "OutPoint.h"

class TxIn {
    //Inputs to a Transaction.
public:
    //A reference to the output we're spending. This is None for coinbase
    //transactions.
    std::shared_ptr<OutPoint> toSpend;

    // The (signature, pubkey) pair which unlocks the TxOut for spending.
    std::vector<char> unlockSig;
    std::vector<char> unlockPk;

    // A sender-defined sequence number which allows us replacement of the txn
    // if desired.
    int sequence;

    TxIn()
    {
        this->toSpend = std::make_shared<OutPoint>();
        this->unlockSig = std::vector<char>();
        this->unlockPk = std::vector<char>();
        this->sequence = 0;
    }

    TxIn(std::shared_ptr<OutPoint> toSpend, const std::string unlockSig, const std::string unnlockPk, const int sequence)
            : toSpend(toSpend), sequence(sequence)
    {
        this->unlockSig = std::vector<char>(unlockSig.begin(), unlockSig.end());
        this->unlockPk = std::vector<char>(unlockPk.begin(), unlockPk.end());
    }

    TxIn(const TxIn&);

    template<class Archive>
    void serialize(Archive & archive) {
        archive(CEREAL_NVP(toSpend), CEREAL_NVP(unlockSig), CEREAL_NVP(unlockPk), CEREAL_NVP(sequence));
    }
};


#endif //TINYCHAIN_CPP_TXIN_H
