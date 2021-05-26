#pragma once
// #include "Board.hpp"
#include "Player.hpp"
// #include "City.hpp"
// #include "Color.hpp"
// #include "Player.hpp"

namespace pandemic
{

class Medic: public Player {
  public:
   //constructor
    Medic(Board& b, City c):Player(b, c){}
    Medic& treat(City city)override;
    Player& drive(City city)override;
  
    Player& fly_direct(City city)override;
    
    Player& fly_charter(City city)override;

    Player& fly_shuttle(City city)override;
    const std::string role() const{
        return "Medic";
    }
 };

}