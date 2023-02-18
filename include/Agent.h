#pragma once
#include <vector>
#include "Graph.h"
#include "Party.h"


using std::vector;
class Simulation;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    // rule of 5
    ~Agent();
    Agent (const Agent& other);
    Agent & operator = (const Agent& other);
    Agent(Agent&& other)noexcept;
    Agent& operator =(Agent&& other)noexcept;

    int getPartyId() const;
    void setPartyId(int i);
    int getId() const;
    void setId(int id);
    void step(Simulation &);
    void SetCoalitionNumber(int number);
    int GetCoalitionNumber();
    SelectionPolicy* getSelectionPolicy (Agent& agent);
    vector<int> GetParties();
    void SetParties1(Simulation& s);




private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    vector<int>partiesToOffer;
    int coalitionNumber;
};
