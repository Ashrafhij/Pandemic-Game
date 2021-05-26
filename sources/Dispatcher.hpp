#pragma once
// #include "Board.hpp"
#include "Player.hpp"
// #include "City.hpp"
// #include "Color.hpp"
// #include "Player.hpp"

namespace pandemic
{

class Dispatcher: public Player {
  public:
   //constructor
    Dispatcher(Board& b, City c):Player(b, c){}
    Dispatcher& fly_direct(City destinationCity)override;
    const std::string role() const{
        return "Dispatcher";
    }
 };

}