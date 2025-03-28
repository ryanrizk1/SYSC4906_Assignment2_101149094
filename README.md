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

## Results
To view simulation output:
Open grid_log.csv file. This shows numerical value of all cells at the given time.
![image](https://github.com/user-attachments/assets/a307d3f1-c02a-4d7b-bb65-797747c4e7c1)


To visualize output:
Open https://devssim.carleton.ca/cell-devs-viewer/
Add grid_log and corresponding config file to browser window and click view simulation.
Press play to begin visual simulation
![image](https://github.com/user-attachments/assets/fb32ee57-8e19-42db-b9c8-7f8862df0040)
![image](https://github.com/user-attachments/assets/48e8ae20-c128-4f61-8808-9b578ca04537)
![image](https://github.com/user-attachments/assets/8b61612e-facb-49ef-9079-223fcb67a09a)
