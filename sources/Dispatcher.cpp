#include "Dispatcher.hpp"

namespace pandemic
{

Dispatcher& Dispatcher::fly_direct(City destinationCity){
    if(getCurrent_city()==destinationCity){
            throw runtime_error("Already in The City");
        }
    if(b.stationCheck(getCurrent_city())){
        set_city(destinationCity);

    }else{
        Player::fly_direct(destinationCity);
    }
        return *this;
}

}