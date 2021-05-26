#include "OperationsExpert.hpp"

namespace pandemic
{

void OperationsExpert::build(){
    if(!b.stationCheck(getCurrent_city())){
        b.buildUpStation(getCurrent_city());
    }
}

}