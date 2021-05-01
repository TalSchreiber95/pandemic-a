#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;


Player& Dispatcher::fly_direct(City c){
    if(board.is_research_station(c)) {
        city = c;
        return *this;
    }
    else {
        return Player::fly_direct(c);
    }
}