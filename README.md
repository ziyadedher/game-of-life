The **Game of Life**, also known simply as **Life**, is a [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton) devised by the British mathematician John Horton Conway in 1970.

This is a rendition of the Game of Life in the C++ language, using modular and structured systems.


## Limitations ##
Currently, the grid is not interactive, and can only be randomized and set at start.

## Roadmap ##
All of the features that I want to be implemented in the future are here.

#### Near: ####
* Make the grid interactive.

#### Future: ####
* Saving and loading grids.

#### Completed: ####
* Allow the user to input the height and width of the grid, as well as to be able to execute an evolution.
* Better display system.
* Allow the user to input an execution speed and start the execution running a generation then waiting for the inputted amount of time and looping.


## Prerequisites ##
* `sudo apt install libncurses5-dev`


## Installation ##
#### Regular compile ####
* Clone this repository.
* In root folder of the repository execute `make`.
* The executable is then in the root folder of the repository and can be accessed by executing `./golcpp`.

#### Full installation ####
* To install the program to the main `/usr/local/bin` directory, run `sudo make install` in the root folder of the repository.
* The program can then be executed from any place on the system using `golcpp`.

#### Full uninstallation ####
* To uninstall the program from `/usr/local/bin`, run `sudo make uninstall` in the root folder of the repository.

#### Debug ####
* To create a debuggable executable, run `make debug` in the root folder of the repository.

#### Cleaning the build and bin folders ####
* To clean and remove all builds, run `make clean` in the root folder of the repository.


## License ##
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
