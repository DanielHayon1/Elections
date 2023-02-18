#include "Party.h"
#include "Simulation.h"
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp),time(0), mState(Waiting)
,offers()
{
    // You can change the implementation of the constructor, but not the signature!
}
Party::~Party() {
    if(mJoinPolicy){
        delete mJoinPolicy;
        mJoinPolicy= nullptr;
    }
}
//copy assignment operator
Party& Party::operator=(const Party &other) {
    if(this != &other){
        delete this;
        this->mId=other.mId;
        this->mState = other.mState;
        this->mMandates = other.mMandates;
        this->mName = other.mName;
        this->time=other.time;
        this->mJoinPolicy=other.mJoinPolicy->copy();
        this->offers=other.offers;
    }
    return *this;
}
//copy constructor
Party::Party(const Party& other): mId{other.mId},mName{other.mName},mMandates{other.mMandates},mJoinPolicy{other.mJoinPolicy->copy()},time{other.time},mState{other.mState}
        ,offers{other.offers}
{
}
//Move copy constructor 
Party::Party(Party &&other) noexcept : mId{other.mId},mName{other.mName},mMandates{other.mMandates},mJoinPolicy{other.mJoinPolicy},time{other.time},mState{other.mState}
        ,offers{other.offers}
{
    other.mJoinPolicy= nullptr;


}
// move assignment operator
Party& Party:: operator =(Party&& other) noexcept{
    if(this != &other){
        delete this;
        this->mId=other.mId;
        this->mState = other.mState;
        this->mMandates = other.mMandates;
        this->mName = other.mName;
        this->time=other.time;
        this->mJoinPolicy=other.mJoinPolicy;
        this->offers=other.offers;
        other.mJoinPolicy=nullptr;
    }
    return *this;

}

vector<Agent> Party:: getOffers(){
    return this->offers;
}
void Party:: setOffers(Agent& agent){
    this->offers.push_back(agent);
}


bool Party:: legalOffers(int coalition){
    bool h = true;
    for(Agent& tempAgent :this->offers){
        if (tempAgent.GetCoalitionNumber() == coalition)
            h = false;
    }
    return h;
}
int Party::getTime() const {
    return time;
}
void Party::setTime(int number) {
    time=number;
}
State Party::getState() const
{
    return mState;
}

int Party::getId() const {
    return mId;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s) {

    if (getTime() == 2 && this->getState()!=Joined) {
       int offerId = this->mJoinPolicy->Join(*this, s);
       s.setCoalitions(offerId,this->getId());
       this->setState(Joined);

    Agent cloneAgent =Agent(s.getAgents()[offerId]);
    cloneAgent.setId(s.getAgents().size());//we change the id of the clone
    cloneAgent.setPartyId(this->getId());//we set the party id
    cloneAgent.SetParties1(s);//we added the parties Edges
    cloneAgent.SetCoalitionNumber(offerId);// we set the coaltion number in the clone agent
    s.addAgent(cloneAgent);
        
   
    }
    
    if (this->getState() == CollectingOffers) {
         int num = getTime();
         this->setTime(num + 1);
      }

    


}

