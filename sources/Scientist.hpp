#pragma once
#include "Player.hpp"


namespace pandemic
{

class Scientist: public Player {
  private:
    int n; //n = number of cards

  public:
   //constructor Include n = number of cards
    Scientist(Board& b, City c , int n):Player(b, c){
      this->n = n;
     }
    Scientist& discover_cure(Color diseaseColor)override;
    const std::string role() const{
        return "Scientist";
    }
 };

}