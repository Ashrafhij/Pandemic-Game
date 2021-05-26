#include "GeneSplicer.hpp"

namespace pandemic
{

    GeneSplicer& GeneSplicer::discover_cure(Color color){
        int  count = this->cards.size();
        const int five = 5;
        if(count < five){
            throw runtime_error("Not Enough Cards!");
        }
        if(!(this->b.stationCheck(this->currentCity))){
            throw runtime_error("Station Doesn't Exist");
        }
        if(!(this->b.isCured(color))){
            set <City> cityCards;
            for(City card:this->cards){
                cityCards.insert(card);
            }
            int counter = 0;
            for(City card : this->cards){
                cityCards.erase(card);
                if(counter == 4){
                    break;
                }
                counter++;
            }
            this->cards.clear();
           
            for(City card : cityCards){
                this->cards.insert(card);
            }
            this->b.updateCureList(color);
        }
        return *this;
    }

}