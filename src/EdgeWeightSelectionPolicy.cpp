//
// Created by spl211 on 11/19/22.
//
#include "SelectionPolicy.h"
#include "Simulation.h"
#include "Party.h"
int EdgeWeightSelectionPolicy::select (Agent& agent, Simulation& simulation) {
    vector<int> options = agent.GetParties();// return a vector with all the parties
    Graph &tempGraph = simulation.getGraph();//we create a reference 
    if (options.size() > 0) {// we check if he can offer
        int max = 0;
        int partyNumber;
        bool toAdd = false;
        int agentParty = agent.getPartyId();
        for (int i: options) { // we checking al the options to select
            Party temp = simulation.getParty(i);
            if (temp.getState() == Joined || !temp.legalOffers(agent.GetCoalitionNumber())) {
                // we dont do nothing
            } else {
                int maxEdge = tempGraph.getEdgeWeight(i, agentParty);
                if (maxEdge > max) {
                    partyNumber = temp.getId();
                    max = maxEdge;
                    toAdd = true;

                }
            }

        }
        if (toAdd) {
            return partyNumber;
        }
    }
        return -1;



    }

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::copy(){
  return new EdgeWeightSelectionPolicy;
}
