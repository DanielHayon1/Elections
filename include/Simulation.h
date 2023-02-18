#pragma once

#include <vector>
#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    Graph &getGraph();
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addAgent(Agent& agent);
    void setCoalitions(int coalition, int partyId);
    vector<vector<int>> getCoalitions();// we added
    vector<int> getMandatesOfCoalitions(); // we added

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> coalitions;// we added
    vector<int> mandatesOfCoalitions; // we added



};
