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


#include "grid.hpp"


int main () {
    Grid* grid = new Grid(10, 10);
    
    grid->randomizeGrid();
    grid->printGrid();
    grid->checkAll();
    grid->updateAll();
    grid->printGrid();
}


/* PROGRAM END */

/* FILE END */