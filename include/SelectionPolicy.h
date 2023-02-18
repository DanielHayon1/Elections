#pragma once
#include "Agent.h"

class SelectionPolicy {
public:
    virtual int select (Agent& agent, Simulation& simulation) = 0;
    virtual ~SelectionPolicy()= default;
    virtual SelectionPolicy* copy()=0;
};
class MandatesSelectionPolicy: public SelectionPolicy{
    virtual int select (Agent& agent, Simulation& simulation);
    virtual ~MandatesSelectionPolicy()= default;
    virtual MandatesSelectionPolicy* copy();
};


class EdgeWeightSelectionPolicy: public SelectionPolicy{
    virtual int select (Agent& agent, Simulation& simulation) ;
    virtual ~EdgeWeightSelectionPolicy()= default;
    virtual EdgeWeightSelectionPolicy* copy();

};