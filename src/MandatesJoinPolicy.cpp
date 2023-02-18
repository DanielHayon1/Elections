//
// Created by spl211 on 11/16/22.
//
#include "JoinPolicy.h"
#include "Party.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

int MandatesJoinPolicy::Join(Party& party, Simulation& simulation){
    int number = 0 ;
    int coalitionToJoin ;
    for(Agent &offer:party.getOffers()){// we run throw all the agents by refernce
        int offerId = offer.GetCoalitionNumber();// we compare the coalition number
        int mandatesOfCoalition = simulation.getMandatesOfCoalitions()[offerId];
        if(mandatesOfCoalition>number){
            number = mandatesOfCoalition; // the coalition with maximum mandates
            coalitionToJoin =offerId; // the coalition number we want to join .

        }
        
    }
return coalitionToJoin;

}
MandatesJoinPolicy* MandatesJoinPolicy::copy(){
  return new MandatesJoinPolicy;
}


