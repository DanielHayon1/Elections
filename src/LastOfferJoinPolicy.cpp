//
// Created by spl211 on 11/16/22.
//
#include "JoinPolicy.h"
#include "Party.h"
#include "Simulation.h"
int LastOfferJoinPolicy:: Join (Party& party, Simulation& simulation){
    Agent temp =party.getOffers().back();
    int offerId = temp.GetCoalitionNumber();
    return offerId; 
}
LastOfferJoinPolicy* LastOfferJoinPolicy::copy(){
  return new LastOfferJoinPolicy;
}
