#include "Board.hpp"

namespace pandemic
{

  Board::Board() {
    ifstream fileName{"cities_map.txt"};
    if (fileName.is_open())
    {
      string line;
      string city;
      string neighbor;
      string color;
      while(getline(fileName,line)){
        istringstream str(line);

        str>>city;
        str>>color;
        Board::cities[convertCity(city)] = convertColor(color);
        Board::cubesMap[convertCity(city)] = 0;
      }
      this->cureColorList ={};
      this->researchStation ={};
      Board::cities[City::Algiers] = Color::Black;
      
      this->neighborsMap = {{City::Algiers,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}}
      ,{City::Atlanta,{City::Chicago, City::Miami, City::Washington}}
      ,{City::Baghdad,{ City::Tehran ,City::Istanbul ,City::Cairo, City::Riyadh ,City::Karachi}}
      ,{City::Bangkok,{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}
      ,{City::Beijing,{City::Shanghai, City::Seoul}}
      ,{City::Bogota,{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}
      ,{City::BuenosAires,{ City::Bogota, City::SaoPaulo}}
      ,{City::Cairo,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}
      ,{City::Chennai,{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok ,City::Jakarta}}
      ,{City::Chicago,{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}
      ,{City::Delhi,{City::Tehran, City::Karachi, City::Mumbai ,City::Chennai, City::Kolkata}}
      ,{City::Essen,{City::London, City::Paris, City::Milan, City::StPetersburg}}
      ,{City::HoChiMinhCity,{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}
      ,{City::HongKong,{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}
      ,{City::Istanbul,{City::Milan, City::Algiers ,City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}
      ,{City::Jakarta,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}
      ,{City::Johannesburg,{City::Kinshasa, City::Khartoum}}
      ,{City::Karachi,{City::Tehran ,City::Baghdad ,City::Riyadh, City::Mumbai, City::Delhi}}
      ,{City::Khartoum,{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}
      ,{City::Kinshasa,{City::Lagos, City::Khartoum, City::Johannesburg}}
      ,{City::Kolkata,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}
      ,{City:: Lagos,{City::SaoPaulo, City::Khartoum, City::Kinshasa}}
      ,{City::Lima,{City::MexicoCity, City::Bogota, City::Santiago}}
      ,{City:: London,{City::NewYork, City::Madrid, City::Essen, City::Paris}}
      ,{City::LosAngeles,{City::SanFrancisco, City::Chicago ,City::MexicoCity, City::Sydney}}
      ,{City::Madrid,{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}
      ,{City::Manila,{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney,City::HongKong}}
      ,{City::MexicoCity,{City::LosAngeles, City::Chicago, City::Miami, City::Lima ,City::Bogota}}
      ,{City:: Miami,{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}
      ,{City::Milan,{City::Essen, City::Paris, City::Istanbul}}
      ,{City::Montreal,{City::Chicago, City::Washington, City::NewYork}}
      ,{City::Moscow,{City::StPetersburg, City::Istanbul, City::Tehran}}
      ,{City::Mumbai,{City::Karachi, City::Delhi, City::Chennai}}
      ,{City::NewYork,{City::Montreal, City::Washington ,City::London, City::Madrid}}
      ,{City::Osaka,{City::Taipei, City::Tokyo}}
      ,{City::Paris,{City::Algiers, City::Essen, City::Madrid, City::Milan ,City::London}}
      ,{City::Riyadh,{City::Baghdad, City::Cairo, City::Karachi}}
      ,{City::SanFrancisco,{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}
      ,{City::Santiago,{City::Lima}}
      ,{City::SaoPaulo,{City::Bogota, City::BuenosAires, City::Lagos ,City::Madrid}}
      ,{City::Seoul,{City::Beijing, City::Shanghai, City::Tokyo}}
      ,{City::Shanghai,{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}
      ,{City::StPetersburg,{City::Essen, City::Istanbul, City::Moscow}}
      ,{City::Sydney,{City::Jakarta, City::Manila, City::LosAngeles}}
      ,{City::Taipei,{City::Shanghai, City::HongKong, City::Osaka, City::Manila}}
      ,{City::Tehran,{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}
      ,{City::Tokyo,{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}
      ,{City::Washington,{City::Atlanta, City::NewYork, City::Montreal, City::Miami}}};
    }
    else{
      throw runtime_error("Unable to open file");
    }
  }


  int& Board::operator[](City c){
      return Board::cubesMap[c];
  }

  std::ostream& operator<<(std::ostream& output, const Board& b){
  
    output << " Current Board: " << endl;
    for(auto const& it :b.cubesMap)
    {
        output << convertCity(it.first) << " : " << it.second << endl;
    }
    
    for(const Color c: b.cureColorList){
      output << "A cure that was discovered: " << convertColor(c) << endl;
    }

    for(const City c : b.researchStation){
      output << "There is a research station in: " << convertCity(c) << endl;
    }
    return output;
  }


  bool Board::is_clean(){
    for(auto const& it : Board::cubesMap)
    {
        if(it.second != 0 ){
          return false;
        }
    }
    return true;
  }

  bool Board::isneighbor(City c1,City c2){
    bool ans = false;
      for(const City city: this->neighborsMap.at(c1)){
        if(city == c2){
          ans = true;
          break;
        }
      }
      return ans;
  }

  bool Board::stationCheck(City c){
    bool ans = false;
      for(const City city: this->researchStation){
        if(city == c){
          ans = true;
          break;
        }
      }
      return ans;
  }

  void Board::buildUpStation(City c){
        this->researchStation.insert(c);
  }

  bool Board::isCured(Color color){
    bool ans = false;
    for(const Color c : this->cureColorList){ 
      if(c == color){
        ans = true;
        break;
      }
    }
    return ans;
  }
  void Board::updateCureList(Color color){
      this->cureColorList.insert(color);
  }
  Color Board::getCityColor(City city){
    return this->cities[city];
  }
  void Board::remove_cures(){
       this->cureColorList.clear();
  }

  void Board::remove_stations(){
      this->researchStation.clear();
  }

}