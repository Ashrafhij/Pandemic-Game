#pragma once
// #include "Board.hpp"
#include "Player.hpp"
// #include "City.hpp"
// #include "Color.hpp"
// #include "Player.hpp"

namespace pandemic
{

class FieldDoctor: public Player {
  public:
   //constructor
    FieldDoctor(Board& b, City c):Player(b, c){}
    FieldDoctor& treat(City city)override;
    const std::string role() const{
        return "FieldDoctor";
    }
 };

}