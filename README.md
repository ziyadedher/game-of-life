The **Game of Life**, also known simply as **Life**, is a [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton) devised by the British mathematician John Horton Conway in 1970.

This is a rendition of the Game of Life in the C++ language, using modular and structured systems.


## Features ##
 * Play a fully functional rendition of Conway's Game of Life in C++.
 * Create a grid with inputted size parameters.
 * Evolve step-by-step.
 * Automatically evolve every interval set by the user.
 * Modify cell status between evolutions.


<br>


## Roadmap ##

#### Near: ####
* Saving and loading grids.

#### Future: ####
 * Pre-built "templates" that insert certain well-known Game of Life entities at the cursor.

#### Completed: ####
* Allow the user to input the height and width of the grid, as well as to be able to execute an evolution.
* Better display system.
* Allow the user to input an execution speed and start the execution running a generation then waiting for the inputted amount of time and looping.
* Make the grid interactive.


<br>


## Limitations ##
 * The grid is not of infinite size; thus, the program behaves incorrectly when cells are at the edges of the grid.
 * Attempting to make the size of the grid larger than the size of the terminal the program is executed in will result in unpredictable complications.


<br>


## Prerequisites ##
* `sudo apt install libncurses5-dev`


## Installation ##
#### Regular compile ####
* Clone this repository. [`git clone https://github.com/Wintro/game-of-life.git`]
* Navigate to the root folder of the repository. [`cd game-of-life`]
* In root folder of the repository compile the program. [`make`]
* The compiler program is then in the root folder of the repository and can be executed. [`./golcpp`]

#### Full installation ####
* To install the program to `/usr/local/bin`, run `sudo make install` in the root folder of the repository.
* The program can then be executed from any place on the system using `golcpp`.

#### Full uninstallation ####
* To uninstall the program from `/usr/local/bin`, run `sudo make uninstall` in the root folder of the repository.

#### Debug ####
* To create a debuggable executable, run `make debug` in the root folder of the repository.

#### Cleaning the build and bin folders ####
* To clean and remove all builds, run `make clean` in the root folder of the repository.


<br>


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
