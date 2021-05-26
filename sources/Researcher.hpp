#pragma once
// #include "Board.hpp"
#include "Player.hpp"
// #include "City.hpp"
// #include "Color.hpp"
// #include "Player.hpp"

namespace pandemic
{

class Researcher: public Player {
  public:
   //constructor
    Researcher(Board& b, City c):Player(b, c){}
    Researcher& discover_cure(Color diseaseColor)override;
    const std::string role() const{
        return "Researcher";
    }
 };

}