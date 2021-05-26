#include "Virologist.hpp"

namespace pandemic
{

    Virologist& Virologist::treat(City city){
        if(this->b[city] == 0){
            throw runtime_error("Low Infection ~ 0 ");
        }
        if(!cardExistCheck(city)&& city != this->getCurrent_city()){
            throw runtime_error("Card Doesn't Exist!");
        }
        if(this->b.isCured(this->b.getCityColor(city))){
            this->b[city] = 0;
        }
        else{
            this->b[city]--;
        }
        this->cards.erase(city);
        return *this;
    }

}