#ifndef FIRE_AND_RAIN_STATE_HPP
#define FIRE_AND_RAIN_STATE_HPP

#include <iostream>
#include <nlohmann/json.hpp>

struct fireAndRainState {
	int state;
	bool ignited;
	bool rained;
	fireAndRainState() : state(0), ignited(false), rained(false) {}//onFire(false), raining(false){}	
};

std::ostream& operator<<(std::ostream& os, const fireAndRainState& x) {
	//os << "<" << ((x.onFire)? 1 : 0) << ((x.raining)? 1 : 0) << ">";
	os << "<" << x.state << ">";
	return os;
}

bool operator!=(const fireAndRainState& x, const fireAndRainState& y) {
	//return ((x.onFire != y.onFire) && (x.raining != y.raining));
	return x.state != y.state;
}

void from_json(const nlohmann::json& j, fireAndRainState& s) {
	// j.at("onFire").get_to(s.onFire);
	// j.at("raining").get_to(s.raining);
	j.at("state").get_to(s.state);
}
#endif

// "raining": {
//             "state": {"raining": true},
//             "cell_map": [[0, 0], [0, 1], [1, 0], [1, 1]]
//         },

//         "onFire": {
//             "state": {"onFire": true},
//             "cell_map": [[15, 15], [15, 14], [15, 13]]
//         }
// ,
//         {
//             "colors": [[0, 100, 0], [255, 69, 0]], 
//             "breaks": [0, 0.5, 1],
//             "field": "onFire"
//         }     
