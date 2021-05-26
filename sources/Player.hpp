#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <set>



namespace pandemic
{
    
class Player {

protected:
    string playerRole;
    City currentCity;
    set <City> cards;
    Board& b;
    City c;
    int countCards(Color color);
    void deleteCards(Color color);
public:


    Player(Board& b, City city):b(b), currentCity(city){
          this->cards = {};
    }

    virtual Player& drive(City destinationCity);

    virtual Player& fly_direct(City destinationCity);

    virtual Player& fly_charter(City destinationCity);

    virtual Player& fly_shuttle(City destinationCity);

    virtual void build();

    virtual bool cardExistCheck(City city);

    virtual Player& discover_cure(Color diseaseColor);
    
    virtual Player& treat(City city);

    virtual string role();

    virtual Player& take_card(City city);


    City getCurrent_city(){
        return this->currentCity;
    }
    void set_city(City c){
        this->currentCity=c;
    }

    


};


}