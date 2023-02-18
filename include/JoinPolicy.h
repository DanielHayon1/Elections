#pragma once
#include "Party.h"

class JoinPolicy {
public:

    virtual int Join (Party& party,Simulation& simulation) = 0;
    virtual ~JoinPolicy()=default;
    virtual JoinPolicy* copy()=0;

};


class MandatesJoinPolicy : public JoinPolicy {
      virtual int Join (Party& party, Simulation& simulation) ;
      virtual~MandatesJoinPolicy() =default ;
      virtual MandatesJoinPolicy* copy();
};

class LastOfferJoinPolicy : public JoinPolicy {
      virtual int Join(Party& party, Simulation& simulation);
      virtual~LastOfferJoinPolicy() =default;
      virtual LastOfferJoinPolicy* copy();
};