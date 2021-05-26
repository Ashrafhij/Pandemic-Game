#include "Medic.hpp"

namespace pandemic
{

    Medic& Medic::treat(City city){
        if(this->b[city] == 0){
            throw runtime_error("Low Infection ~ 0 ");
        }
        this->b[city] = 0;
        return *this;
    }
    
    Player& Medic::drive(City city){
         if(city == this->getCurrent_city()){
            throw runtime_error("can't fly , Same City");
        }

        if(!this->b.isneighbor(this->getCurrent_city(),city)){
           throw runtime_error("Cities Are Not Neighbors");
        }
        
         this->currentCity = city;
           
           if(this->b.isCured(this->b.getCityColor(city))){ 
                this->b[city] = 0;
            }
        return *this;
    }

    Player& Medic::fly_direct(City city){
        if(city == this->currentCity){
            throw runtime_error("can't fly , Same City");
        }
        if(!cardExistCheck(city)){
            throw runtime_error("Card Not Found!");
        }
        if(cardExistCheck(city)){
            this->cards.erase(city);
            this->currentCity = city;
            if(this->b.isCured(this->b.getCityColor(city))){
                this->b[city] = 0;
            }
        }
        return *this;
    }
    
    Player& Medic::fly_charter(City city){
         if(city == this->currentCity){
            throw runtime_error("can't fly , Same City");
        }

        if(cardExistCheck(this->currentCity)){
            this->cards.erase(this->currentCity); 
            this->currentCity = city;
            if(this->b.isCured(this->b.getCityColor(city))){
                this->b[city] = 0;
            }
        }
        return *this;
    }

    Player& Medic::fly_shuttle(City city){
        if(!this->b.stationCheck(this->currentCity) && !this->b.stationCheck(city)){
            throw runtime_error("Station Doesnt Exist!");
        }
         if(city == this->currentCity){
            throw runtime_error("can't fly , Same City");
        }
        this->currentCity = city;
        if(this->b.isCured(this->b.getCityColor(city))){
            this->b[city] = 0;
        }
        return *this;
    }

}