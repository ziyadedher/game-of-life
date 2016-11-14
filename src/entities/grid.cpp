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

/* Full Grid */
/* Contains all grid properties and actions. */

/* PROGRAM START */


#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include "grid.hpp"
#include "cell.hpp"


Grid::Grid (size_t iX, size_t iY, bool random) : x(iX), y(iY), evolution(0), cells() {
    init(random);
}

// Initializes the vector of Cells by allocating a new cell to each index of a 2d array of size `x` by `y`
void Grid::init (bool random) {
    // Assigns a random seed based off the current time
    srand((unsigned int)time(NULL));

    // Temp storing of the cells before being allocated to the real property
    std::vector<std::vector<Cell>> iCells;

    // Loops through all the positions where a cell could be
    for (size_t i = 0; i < this->x; i++) {
        std::vector<Cell> col;

        for (size_t j = 0; j < this->y; j++) {
            bool status = false;

            // If random is passed, then assign status to a random value, otherwise, just set it to false
            if (random) {
                status = rand() % 2 == 1;
            }

            Cell* cell = new Cell(i, j, this, status);
            col.push_back(*cell);
        }
        iCells.push_back(col);
    }

    // Assigns the original cells to the newly created vector
    this->cells = iCells;
}

// Wrapper function to randomize the grid
void Grid::randomize () {
    Grid::init(true);
}

// Prints the grid to curses
void Grid::print () {
    for (size_t i = 0; i < this->x; i++) {
        for (size_t j = 0; j < this->y; j++) {
            printw("%c ", this->cells.at(i).at(j).curChar);
        }
        printw("\n");
    }
    printw("\n");
}

// Wrapper function to evolve the entire grid, by first checking each cell, then updating them
void Grid::evolve () {
    Grid::checkCells();
    Grid::updateCells();
    this->evolution++;
}


// Wrapper function to check each cell of the grid
void Grid::checkCells () {
    for (size_t i = 0; i < this->x; i++) {
        for (size_t j = 0; j < this->y; j++) {
            this->cells.at(i).at(j).checkAlive();
        }
    }
}


// Wrapper function to update each cell of the grid
void Grid::updateCells () {
    for (size_t i = 0; i < this->x; i++) {
        for (size_t j = 0; j < this->y; j++) {
            this->cells.at(i).at(j).update();
        }
    }
}


/* PROGRAM END */

/* FILE END */
