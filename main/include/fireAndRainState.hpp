#ifndef FIRE_AND_RAIN_STATE_HPP
#define FIRE_AND_RAIN_STATE_HPP

#include <iostream>
#include <nlohmann/json.hpp>

struct fireAndRainState {
	int state; // 0: rain, 1: grass, 2: weak fire, 3: burnt grass, 4: strong fire
	bool ignited;
	bool rained;
	fireAndRainState() : state(0), ignited(false), rained(false) {}
};

std::ostream& operator<<(std::ostream& os, const fireAndRainState& x) {
	os << "<" << x.state << ">";
	return os;
}

bool operator!=(const fireAndRainState& x, const fireAndRainState& y) {
	return x.state != y.state;
}

void from_json(const nlohmann::json& j, fireAndRainState& s) {
	j.at("state").get_to(s.state);
}
#endif
