#pragma once
// #include "Board.hpp"
#include "Player.hpp"
// #include "City.hpp"
// #include "Color.hpp"
// #include "Player.hpp"

namespace pandemic
{

class Virologist: public Player {
  public:
   //constructor
    Virologist(Board& b, City c):Player(b, c){}
    Virologist& treat(City city)override;
    const std::string role() const{
        return "Virologist";
    }
 };

}