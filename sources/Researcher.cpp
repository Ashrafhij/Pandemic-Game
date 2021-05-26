#include "Researcher.hpp"

namespace pandemic
{

Researcher& Researcher::discover_cure(Color diseaseColor){
        int  dieseaseCount = 0;
        for(City c : this->cards){
            if(this->b.getCityColor(c) == diseaseColor){
                dieseaseCount++;
            }
        }
        const int five = 5;
        if(dieseaseCount < five){
           throw runtime_error("Not Enought Cards!");
        }
        
        if(!(this->b.isCured(diseaseColor))){
            set<City> cityCards;

            for(City card:this->cards){
                cityCards.insert(card);
            }
           
            int counter = 0;
            for(City card : this->cards){
                if(this->b.getCityColor(card) == diseaseColor){
                    cityCards.erase(card);
                    if(counter == 4){
                        break;
                    }
                    counter++;
                }
            }
            this->cards.clear();
            for(City card : cityCards){
                this->cards.insert(card);
            }
            this->b.updateCureList(diseaseColor);
        }
        return *this;
}

}