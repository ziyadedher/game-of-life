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
    if (status) {
        this->curChar = Cell::onChar;
    } else {
        this->curChar = Cell::offChar;
    }
}

void Cell::checkAlive () {
    Cell::checkNeighbours();
    Cell::checkStatus();
}

void Cell::update () {
    this->isAlive = this->willBeAlive;
    if (this->isAlive) {
        curChar = Cell::onChar;
    } else {
        curChar = Cell::offChar;
    }
}

void Cell::checkNeighbours () {
    this->neighbours = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int x_ = (int)this->x + i;
            int y_ = (int)this->y + j;
            if (x_ < 0 || y_ < 0) {
                continue;
            }

            try {
                if (this->parentGrid->cells.at((size_t)x_).at((size_t)y_).isAlive) {
                    this->neighbours++;
                }
            } catch (...) {
                continue;
            }
        }
    }
}

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
