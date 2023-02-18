#pragma once
#include <string>
#include "Agent.h"

using std::vector;
using std::string;
class Agent;
class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);

    // rule of 5
    ~Party();
    Party (const Party& other);
    Party & operator = (const Party& other);
    Party(Party&& other)noexcept;
    Party& operator =(Party&& other)noexcept;


    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId() const ;
    int getTime()const;
    void setTime(int number);
    bool legalOffers(int coalition);// we added;
    vector<Agent> getOffers();
    void setOffers(Agent& agent);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    int time; // we added
    State mState;//we added
    vector<Agent> offers ;// we added


};
