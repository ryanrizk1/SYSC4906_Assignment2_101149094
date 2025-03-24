# Fire and Rain Project Cadmium
|  Linux | Windows| 
|:--|:--|
|:heavy_check_mark:|:heavy_check_mark:|
## Introduction
This repository contains a cadmium v2 simulation project of the interaction of fire and rain. This project includes one atomic cell model definition. 
Project also contains three test scenarios in /config. Each scenario initializes the rain and fire in different locations are groups across the grid.
To view the results of the simulation, view scenarioOne, scenarioTwo, scenarioThree .webm files for visual execution.

## Dependencies
This project assumes that you have Cadmium installed in a location accessible by the environment variable $CADMIUM.
_This dependency would be met by default if you are using the ARSLAB servers. To check, try `echo $CADMIUM` in the terminal_

## Build
To build this project, run:
```sh
source build_sim.sh
```
__NOTE__: Everytime you run build_sim.sh, the contents of `build/` and `bin/` will be replaced.

## Execute
To run the project, run:
```sh
./bin/fire_and_rain config/fireAndRainVisualization"X"_config.json
```
__NOTE__: Replace "X" with desired scenario, such as: ./bin/fire_and_rain config/fireAndRainVisualizationThree_config.json
