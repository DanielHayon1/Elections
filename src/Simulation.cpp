#include "Simulation.h"
#include "Agent.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents),coalitions(),mandatesOfCoalitions()
{
    int i = 0;
    for(Agent& agent: mAgents){
        coalitions.push_back(vector<int> {agent.getPartyId()} );
        mGraph.getParty(agent.getPartyId()).setState(Joined);
        mandatesOfCoalitions.push_back(mGraph.getMandates(agent.getPartyId()));
        agent.SetCoalitionNumber(i) ;
        agent.SetParties1(*this);
        i = i +1;
    }
}

void Simulation::step()
{
    for (int i = 0 ; i < mGraph.getNumVertices();i++){
       mGraph.getParty(i).step(*this);// we have an option to add a nonconst function
    }
    for (Agent& agent : mAgents){
        agent.step(*this);
    }
}
vector<vector<int>> Simulation:: getCoalitions(){// we added
    return this->coalitions;

};
vector<int> Simulation:: getMandatesOfCoalitions(){// we added
    return this->mandatesOfCoalitions;
};
void Simulation::addAgent(Agent &agent) {
    this->mAgents.push_back(agent);
}

bool Simulation::shouldTerminate() const {
    bool t = false;
    bool allJoined = true;
    for (int i: this->mandatesOfCoalitions){// if one of the coalition has more then 60 mandates
        if (i > 60)
            t = true;
    }

    for (Party &p: this->mGraph.getParties()) { // we check each party if its joined
        if (p.getState() != Joined){
            allJoined= false;
        }
    }
    return (t || allJoined);



}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return this->coalitions;
}

    void Simulation::setCoalitions(int coalition, int partyId){ // we create a methood that change the coalitions fields
        this->coalitions[coalition].push_back(partyId);
        this->mandatesOfCoalitions[coalition]+= getParty(partyId).getMandates();
    }
