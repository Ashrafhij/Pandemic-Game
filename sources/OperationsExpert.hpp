#pragma once
// #include "Board.hpp"
#include "Player.hpp"
// #include "City.hpp"
// #include "Color.hpp"
// #include "Player.hpp"

namespace pandemic
{

class OperationsExpert: public Player {
  public:
   //constructor
    OperationsExpert(Board& b, City c):Player(b, c){}
    void build()override;
    const std::string role() const{
        return "OperationsExpert";
    }
 };

}