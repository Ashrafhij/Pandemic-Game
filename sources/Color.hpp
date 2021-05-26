#pragma once
#include <string>

using namespace std;

	enum Color {
		Blue,
		Yellow,
        Black,
		Red,
		Not_Exist
	};

	inline string convertColor(Color color) {
        switch (color){
            case Blue: return "Blue"; break;
			case Yellow: return "Yellow"; break;
			case Black: return "Black"; break;
			case Red: return "Red"; break;
            default: return "Not_Exist";
        }
    }

	inline Color convertColor(string color) {
		if(color == "Blue")
			return Color::Blue;
		if(color == "Yellow")
			return Color::Yellow;
		if(color == "Red")
			return Color::Red;
		if(color == "Black")
			return Color::Black;
		return Color::Not_Exist;
    }
