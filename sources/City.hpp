
#pragma once
#include <string>

using namespace std;

	enum City {
		Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington};

    inline string convertCity(City city) {
        switch (city){
            case Algiers: return "Algiers"; break;
            case Atlanta: return "Atlanta"; break;
            case Baghdad: return "Baghdad"; break;
            case Bangkok: return "Bangkok"; break;
            case Beijing: return "Beijing"; break;
            case Bogota: return "Bogota"; break;
            case BuenosAires: return "BuenosAires"; break;
            case Cairo: return "Cairo"; break;
            case Chennai: return "Chennai"; break;
            case Chicago: return "Chicago"; break;
            case Delhi: return "Delhi"; break;
            case Essen: return "Essen"; break;
            case HoChiMinhCity: return "HoChiMinhCity"; break;
            case HongKong: return "HongKong"; break;
            case Istanbul: return "Istanbul"; break;
            case Jakarta: return "Jakarta"; break;
            case Johannesburg: return "Johannesburg"; break;
            case Karachi: return "Karachi"; break;
            case Khartoum: return "Khartoum"; break;
            case Kinshasa: return "Kinshasa"; break;
            case Kolkata: return "Kolkata"; break;
            case Lagos: return "Lagos"; break;
            case Lima: return "Lima"; break;
            case London: return "London"; break;
            case LosAngeles: return "LosAngeles"; break;
            case Madrid: return "Madrid"; break;
            case Manila: return "Manila"; break;
            case MexicoCity: return "MexicoCity"; break;
            case Miami: return "Miami"; break;
            case Milan: return "Milan"; break;
            case Montreal: return "Montreal"; break;
            case Moscow: return "Moscow"; break;
            case Mumbai: return "Mumbai"; break;
            case NewYork: return "NewYork"; break;
            case Osaka: return "Osaka"; break;
            case Paris: return "Paris"; break;
            case Riyadh: return "Riyadh"; break;
            case SanFrancisco: return "SanFrancisco"; break;
            case Santiago: return "Santiago"; break;
            case SaoPaulo: return "SaoPaulo"; break;
            case Seoul: return "Seoul"; break;
            case Shanghai: return "Shanghai"; break;
            case StPetersburg: return "StPetersburg"; break;
            case Sydney: return "Sydney"; break;
            case Taipei: return "Taipei"; break;
            case Tehran: return "Tehran"; break;
            case Tokyo: return "Tokyo"; break;
            case Washington: return "Washington"; break;
            default: return "Not Exist!";
        }
    }

    inline City convertCity(string city) {
		if(city == "Atlanta")
			return City::Atlanta;
		if(city == "Baghdad")
			return City::Baghdad;
		if(city == "Bangkok")
			return City::Bangkok;
        if(city == "Beijing")
			return City::Beijing;
        if(city == "Bogota")
			return City::Bogota;
        if(city == "BuenosAires")
			return City::BuenosAires;
        if(city == "Cairo")
			return City::Cairo;
        if(city == "Chennai")
			return City::Chennai;
        if(city == "Chicago")
			return City::Chicago;
        if(city == "Delhi")
			return City::Delhi;
        if(city == "Essen")
			return City::Essen;
        if(city == "HoChiMinhCity")
			return City::HoChiMinhCity;
        if(city == "HongKong")
			return City::HongKong;
        if(city == "Istanbul")
			return City::Istanbul;
        if(city == "Jakarta")
			return City::Jakarta;
        if(city == "Johannesburg")
			return City::Johannesburg;
        if(city == "Karachi")
			return City::Karachi;
        if(city == "Khartoum")
			return City::Khartoum;
        if(city == "Kinshasa")
			return City::Kinshasa;
        if(city == "Kolkata")
			return City::Kolkata;
        if(city == "Lagos")
			return City::Lagos;
        if(city == "Lima")
			return City::Lima;
        if(city == "London")
			return City::London;
        if(city == "LosAngeles")
			return City::LosAngeles;
        if(city == "Madrid")
			return City::Madrid;
        if(city == "Manila")
			return City::Manila;
        if(city == "MexicoCity")
			return City::MexicoCity;
        if(city == "Miami")
			return City::Miami;
        if(city == "Milan")
			return City::Milan;
        if(city == "Montreal")
			return City::Montreal;
        if(city == "Moscow")
			return City::Moscow;
        if(city == "Mumbai")
			return City::Mumbai;
        if(city == "NewYork")
			return City::NewYork;
        if(city == "Osaka")
			return City::Osaka;
        if(city == "Paris")
			return City::Paris;
        if(city == "Riyadh")
			return City::Riyadh;
        if(city == "SanFrancisco")
			return City::SanFrancisco;
        if(city == "Santiago")
			return City::Santiago;
        if(city == "SaoPaulo")
			return City::SaoPaulo;
        if(city == "Seoul")
			return City::Seoul;
        if(city == "Shanghai")
			return City::Shanghai;
        if(city == "StPetersburg")
			return City::StPetersburg;
        if(city == "Sydney")
			return City::Sydney;
        if(city == "Taipei")
			return City::Taipei;
        if(city == "Tehran")
			return City::Tehran;
        if(city == "Tokyo")
			return City::Tokyo;
		return City::Washington;
    }
