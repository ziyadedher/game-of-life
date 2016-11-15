/* FILE START */

/*/
 * This file is part of Game of Life.
 *
 * Game of Life is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Game of Life is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Game of Life. If not, see <http://www.gnu.org/licenses/>.
 *
/*/

/* MAIN */
/* Main application file, the execution starts, and should end here. */

/* PROGRAM START */


#include "procs/procs.hpp"


int main () {
    proc::initCurses();

    size_t width, height, speed;
    bool randomize;

    try {
        proc::getInitialInput(&width, &height, &speed, &randomize);
        Grid* grid = new Grid(width, height, randomize);
        proc::mainLoop(grid, speed);
    } catch (...) {
        clear();
        printw("One or more inputs were not valid.\nPress any key to terminate...");
    }

    proc::terminateCurse();
}


/* PROGRAM END */

/* FILE END */
