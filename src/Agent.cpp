#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),partiesToOffer(),coalitionNumber()
{

}

Agent::~Agent() {
    if(mSelectionPolicy){
        delete mSelectionPolicy;
        mSelectionPolicy= nullptr;
    }
   // if(coalitionToOffer nullptr){} how we check that vector is null
}
//copy assignment operator
Agent& Agent::operator=(const Agent &other) {
    if(this != &other){
        delete this; // we delete this before we start to build
        this->mAgentId=other.mAgentId;
        this->mSelectionPolicy = other.mSelectionPolicy->copy();// we create a copy because its in the heap 
        this->coalitionNumber = other.coalitionNumber;
        this->mPartyId = other.mPartyId;
        this->partiesToOffer = other.partiesToOffer;
    }
    return *this;
}
//copy constructor
Agent::Agent(const Agent& other) :mAgentId{other.mAgentId},mPartyId{other.mPartyId},mSelectionPolicy{other.mSelectionPolicy->copy()},partiesToOffer{other.partiesToOffer}
,coalitionNumber{other.coalitionNumber}{

}
//Move copy constractor Operator
Agent::Agent(Agent &&other) noexcept : mAgentId{other.mAgentId},mPartyId{other.mPartyId},mSelectionPolicy{other.mSelectionPolicy},partiesToOffer{other.partiesToOffer}
        ,coalitionNumber{other.coalitionNumber}
{
    other.mSelectionPolicy= nullptr;

    
}
// move assignment operator
Agent& Agent:: operator =(Agent&& other) noexcept{
    if(this != &other){
        delete this;
        this->mAgentId=other.mAgentId;
        this->mSelectionPolicy = other.mSelectionPolicy;
        this->coalitionNumber = other.coalitionNumber;
        this->mPartyId = other.mPartyId;
        this->partiesToOffer = other.partiesToOffer;
        other.mSelectionPolicy = nullptr;
        //we change the other pointer, but we need to check if its
    }
    return *this;

}
vector<int> Agent::GetParties() {
    return this->partiesToOffer;
}
// all the parties that an agent can make an offer to
void Agent::SetParties1(Simulation &s) { // set parties to offer
    partiesToOffer = {}; 
    int i = this->mPartyId;
    // vector<vector<int>> temp = s->getGraph().getEdges();
    Graph &gr = s.getGraph();
    int sizeT = gr.getNumVertices();
    // int vSize =  temp[i].size();
    for(int j=0;j<sizeT;j++){
        if (s.getGraph().getEdgeWeight(j,i)!=0){
            partiesToOffer.push_back(j); 
    }
    }
    
}



int Agent::GetCoalitionNumber() {
    return this->coalitionNumber;
}

void Agent::SetCoalitionNumber(int number) {
    this->coalitionNumber = number;
}

int Agent::getId() const
{
    return mAgentId;
}
void Agent::setId(int id)
{
    this->mAgentId=id;
}
void Agent::setPartyId(int i)
{
    this->mPartyId=i;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim) {
    int partyNumber = this->getSelectionPolicy(*this)->select(*this, sim);
    if(partyNumber!= -1) { // checking if we need to make an offer
        Party& chosen = sim.getGraph().getParty(partyNumber);
        if (chosen.getState() == Waiting) {// if the the party is waiting
            chosen.setState(CollectingOffers);
        }
            chosen.setOffers(*this);
        }
    }

    SelectionPolicy *Agent::getSelectionPolicy(Agent &agent) {
        return agent.mSelectionPolicy;
    }
