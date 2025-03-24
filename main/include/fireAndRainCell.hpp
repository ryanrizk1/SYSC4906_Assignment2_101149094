#ifndef FIRE_AND_RAIN_CELL_HPP
#define FIRE_AND_RAIN_CELL_HPP

#include <limits>
#include <cmath>
#include <nlohmann/json.hpp>
#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include <cadmium/modeling/celldevs/grid/config.hpp>
#include "fireAndRainState.hpp"

using namespace cadmium::celldevs;

class fireAndRain : public GridCell<fireAndRainState, double> {
	public:
	fireAndRain(const std::vector<int>& id, const std::shared_ptr<const GridCellConfig<fireAndRainState, double>>& config): GridCell<fireAndRainState, double>(id, config) {}
	
	[[nodiscard]] fireAndRainState localComputation(fireAndRainState state, const std::unordered_map<std::vector<int>, NeighborData<fireAndRainState, double>>& neighborhood) const override {
		int fire_neighbors = 0;	
		int rain_neighbors = 0;	
		for(const auto& [neighborId, neighborData]: neighborhood) {
			auto nState = neighborData.state;
			if(nState->state == 2 || nState->state == 4){
				fire_neighbors++;
			}
			if(nState->state == 0 || nState->state == 3){
				rain_neighbors++;
			}
		}
		if(rain_neighbors >= 1 && state.rained == false){
			state.state = 0;
			state.rained = true;
			return state;
		} 
		if(state.rained == true){
			if(state.ignited == true){
				state.state = 3;
				return state;
			} else {
				state.state = 1;
				return state;
			}
		}
		if(fire_neighbors >= 3 && fire_neighbors < 7){
			state.state = 2;
			state.ignited = true;
			return state;
		}
		else if(fire_neighbors >= 7){
			state.state = 4;
			state.ignited = true;
			return state;
		}
		return state;
	}
		
	
	[[nodiscard]] double outputDelay(const fireAndRainState& state) const override {
		if(state.state == 0 || state.state == 3){
			return 2.0;
		} else if(state.state == 1){
			return std::numeric_limits<double>::infinity();
		} else {
			return 1.0;
		}
	}
};
#endif
		
			