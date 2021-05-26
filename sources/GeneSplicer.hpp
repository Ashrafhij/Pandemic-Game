#pragma once
// #include "Board.hpp"
#include "Player.hpp"
// #include "City.hpp"
// #include "Color.hpp"
// #include "Player.hpp"

namespace pandemic
{

class GeneSplicer: public Player {
  public:
   //constructor
    GeneSplicer(Board& b, City c):Player(b, c){}
    GeneSplicer& discover_cure(Color color)override;
    const std::string role() const{
        return "GeneSplicer";
    }
 };

}