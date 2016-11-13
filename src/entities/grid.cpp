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
#include "grid.hpp"
#include "cell.hpp"


Grid::Grid (size_t iX, size_t iY) : x(iX), y(iY), cells() {
    init();
}

void Grid::init () {
    std::vector<std::vector<Cell>> iCells;
    for (size_t i = 0; i < this->x; i++) {
        std::vector<Cell> row;
        for (size_t j = 0; j < this->y; j++) {
            Cell* cell = new Cell(i, j, this);
            row.push_back(*cell);
        }
        iCells.push_back(row);
    }
    this->cells = iCells;
}

void Grid::randomize () {
    srand((unsigned int)time(NULL));
    std::vector<std::vector<Cell>> iCells;
    for (size_t i = 0; i < this->x; i++) {
        std::vector<Cell> row;
        for (size_t j = 0; j < this->y; j++) {
            Cell* cell = new Cell(i, j, this, rand() % 2 == 1);
            row.push_back(*cell);
        }
        iCells.push_back(row);
    }
    this->cells = iCells;
}

void Grid::print () {
    for (size_t i = 0; i < this->x; i++) {
        for (size_t j = 0; j < this->y; j++) {
            printf("%c ", this->cells.at(i).at(j).curChar);
        }
        printf("\n");
    }
    printf("\n");
}

void Grid::update () {
    Grid::checkCells();
    Grid::updateCells();
}

void Grid::checkCells () {
    for (size_t i = 0; i < this->x; i++) {
        for (size_t j = 0; j < this->y; j++) {
            this->cells.at(i).at(j).checkAlive();
        }
    }
}

void Grid::updateCells () {
    for (size_t i = 0; i < this->x; i++) {
        for (size_t j = 0; j < this->y; j++) {
            this->cells.at(i).at(j).update();
        }
    }
}


/* PROGRAM END */

/* FILE END */
