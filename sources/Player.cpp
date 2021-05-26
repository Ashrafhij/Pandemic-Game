
#include "Player.hpp"


namespace pandemic
{
    bool Player::cardExistCheck(City city){
        bool ans = false;
        for(const City c : this->cards){
            if(c == city){
                ans = true;
                break;
            }
        }
        return ans;
    }

    Player& Player::drive(City destinationCity){
        if(getCurrent_city() != destinationCity && b.isneighbor(getCurrent_city(),destinationCity)){
            set_city(destinationCity);
        }
        else{
            throw runtime_error("These Two Cities are Not Neighbors!");
        }
        return *this;
    }

    Player& Player::fly_direct(City destinationCity){
        if(getCurrent_city() != destinationCity && cardExistCheck(destinationCity)){
            cards.erase(destinationCity);
            set_city(destinationCity);
        }
        else{
            throw runtime_error("City Card Not Found");
        }
        return *this;
    }

    Player& Player::fly_charter(City destinationCity){
        if(getCurrent_city() == destinationCity){
            throw runtime_error("Fly Denied , Same City");
        }
        if(!cardExistCheck(getCurrent_city())){
            throw runtime_error("Card Not Found");
        }
        this->cards.erase(getCurrent_city());
        set_city(destinationCity);
        return *this;
    }

    Player& Player::fly_shuttle(City destinationCity){
        if(!this->b.stationCheck(getCurrent_city()) || !this->b.stationCheck(destinationCity)){
            throw runtime_error("Cant Fly , No Station Detected");
        }
        if(destinationCity == getCurrent_city()){
            throw runtime_error("Fly Denied , Same City");
        }
        set_city(destinationCity);
        return *this;
    }

    void Player::build(){
        if(!cardExistCheck(getCurrent_city())){
            throw runtime_error("City Card Not Found");
        }

        bool ans = this->b.stationCheck(getCurrent_city());
        if(!ans){ 
            this->cards.erase(getCurrent_city()); 
            this->b.buildUpStation(getCurrent_city());
        }
    }

    Player& Player::discover_cure(Color diseaseColor){
        int  dieseaseCount = 0;
        for(City c : this->cards){
            if(this->b.getCityColor(c) == diseaseColor){
                dieseaseCount++;
            }
        }
        const int five = 5;
        if(dieseaseCount < five){
            throw runtime_error{"Not Enough Cards!"};
        }

        if(!(this->b.stationCheck(this->currentCity))){
            throw runtime_error{"no reaserch station!"};
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
    
    Player& Player::treat(City city){
        if(city != getCurrent_city()){
            throw runtime_error("Wrong City!");
        }
        if(this->b[getCurrent_city()] == 0){
            throw runtime_error("Low Infection ~ 0 ");
        }
        if(this->b.isCured(this->b.getCityColor(city))){
            this->b[getCurrent_city()] = 0;
        }

        else{ 
            this->b[getCurrent_city()]--;
        }
        return *this;
    }

    string Player::role(){
        return this->playerRole;
    }

    Player& Player::take_card(City city){
        this->cards.insert(city);
        return *this;
    }

    int Player::countCards(Color color){
        int counter=0;
        for (auto card : cards){
            if(b.getCityColor(card)==color){
                counter++;
            }
        }
        // cout << "counter is : " << counter << endl;
        return counter; 
    }

    void Player::deleteCards(Color color){
        for(City card : this->cards){
            cout << "here" << endl;
            if(b.getCityColor(card) == color && cardExistCheck(card)){
                cout << "card check : " << cardExistCheck(card) << endl;
                this->cards.erase(card);
            }
        }
    }

}