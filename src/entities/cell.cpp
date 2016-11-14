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

/* Single Cell */
/* Contains all controllers and statuses of all cells in a grid. */

/* PROGRAM START */


#include "cell.hpp"
#include "grid.hpp"


Cell::Cell (size_t iX, size_t iY, Grid* grid, bool status) : curChar(), isAlive(status), x(iX), y(iY), parentGrid(grid), willBeAlive(), neighbours() {
    // Sets initial `curChar` depending on the initial status
    if (status) {
        this->curChar = Cell::onChar;
    } else {
        this->curChar = Cell::offChar;
    }
}

// Wrapper function to fully check if the cell should be alive next evolution
void Cell::checkAlive () {
    Cell::checkNeighbours();
    Cell::checkStatus();
}

// Updates the cell to its desired state, also updates the `curChar`
void Cell::update () {
    this->isAlive = this->willBeAlive;
    if (this->isAlive) {
        curChar = Cell::onChar;
    } else {
        curChar = Cell::offChar;
    }
}

// Checks all eight cells around this cell to see how many live neighbours it has
void Cell::checkNeighbours () {
    this->neighbours = 0;

    // Runs through each cell in a 3x3 area
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Skip this cell if it itself
            if (i == 0 && j == 0) {
                continue;
            }

            // If the theoretical absolute position of the cell is outside the bounds of the grid, then skip this cell
            int x_ = (int)this->x + i;
            int y_ = (int)this->y + j;
            if (x_ < 0 || y_ < 0 || x_ >= (int)this->parentGrid->x || y_ >= (int)this->parentGrid->y) {
                continue;
            }

            // If the cell at the now checked position is alive, then add one to the amount of live neighbours
            if (this->parentGrid->cells.at((size_t)x_).at((size_t)y_).isAlive) {
                this->neighbours++;
            }
        }
    }
}

// Checks whether the cell will be dead or alive next round based on the rules of Conway's Game of Life:
void Cell::checkStatus () {
    if (this->isAlive) {
        if (this->neighbours < 2 || this->neighbours > 3) {
            this->willBeAlive = false;
        } else {
            this->willBeAlive = true;
        }
    } else {
        if (this->neighbours == 3) {
            this->willBeAlive = true;
        } else {
            this->willBeAlive = false;
        }
    }
}


/* PROGRAM END */

/* FILE END */
