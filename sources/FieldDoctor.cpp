#include "FieldDoctor.hpp"

namespace pandemic
{

    FieldDoctor& FieldDoctor::treat(City city){
        if(this->b[city] == 0){
            throw runtime_error("Low Infection ~ 0 ");
        }
        if(!this->b.isneighbor(this->getCurrent_city() , city) && this->getCurrent_city() != city){
             throw runtime_error("cities are Not Neighbors!");
        }
        if(this->b.isCured(this->b.getCityColor(city))){
            this->b[city] = 0;
        }
        else{
            this->b[city] = (this->b[city]-1);
        }
        return *this;
    }

}