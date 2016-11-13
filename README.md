The **Game of Life**, also known simply as **Life**, is a [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton) devised by the British mathematician John Horton Conway in 1970.

This is a rendition of the Game of Life in the C++ language, using modular and structured systems.


## Limitations ##
Currently, the program runs only one generation, it is incomplete. The edges of the grid are considered dead cells, and thus may cause complications when live cells are near the edges.
Furthermore, the program is currently not interactive. The grid is always 10 by 10 and randomized at start, and one generation is always calculated.

## Roadmap ##
All of the features that I want to be implemented in the future are here.

Near:
* Allow the user to input the height and width of the grid, as well as to be able to execute an evolution.

Future:
* Allow the user to input an execution speed and start the execution running a generation then waiting for the inputted amount of time and looping.
* Make the grid interactive.
* Better display system.
* Saving and loading grids.


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
