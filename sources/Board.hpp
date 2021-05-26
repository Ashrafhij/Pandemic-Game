#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <unordered_set>
#include "City.hpp"
#include "Color.hpp"

using namespace std;
namespace pandemic
{
class Board { 
  public:
  Board();

  int& operator[](City c);

  friend std::ostream& operator<<(std::ostream& output, const Board& b);

  bool is_clean();
  bool isneighbor(City c1,City c2);
  bool stationCheck(City c);
  void buildUpStation(City c);
  bool isCured(Color color);
  void updateCureList(Color color);
  Color getCityColor(City city);
  void remove_cures();
  void remove_stations();

  // protected:
     map<City,unordered_set<City>> neighborsMap;
     map<City,Color> cities;
     map<City,int> cubesMap;
     unordered_set<City> researchStation;
     unordered_set<Color>cureColorList;
  
};
}