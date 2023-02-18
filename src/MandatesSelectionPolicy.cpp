//
// Created by spl211 on 11/19/22.
//
#include "SelectionPolicy.h"
#include "Simulation.h"
#include "Agent.h"

int MandatesSelectionPolicy::select (Agent& agent, Simulation& simulation) {
    vector<int> options = agent.GetParties();
    if (options.size() > 0) {// we check if he can offer
        int max = 0;
        int partyNumber;
        bool toAdd = false;
        for (int i: options) {
            Party temp = simulation.getParty(i);// we dont create a reference because its const
            if (temp.getState() == Joined || !temp.legalOffers(agent.GetCoalitionNumber())) {
                // we don't do anything because the party belongs to a coalition or another agent from the same coalition has made an offer.
            } else {
                int mandates = temp.getMandates();
                if (mandates > max) {
                    partyNumber = temp.getId();
                    max = mandates;
                    toAdd = true;
                }
            }
        }
        if(toAdd){
            return partyNumber;
        }
    }
        return -1;


}


MandatesSelectionPolicy* MandatesSelectionPolicy::copy(){
  return new MandatesSelectionPolicy;
}
