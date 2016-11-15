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
    for (size_t j = 0; j < this->y; j++) {
        for (size_t i = 0; i < this->x; i++) {
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


// Toggles the cells status at `x`, `y`
void Grid::toggleAliveAt (size_t x_, size_t y_) {
    Cell* curCell = &this->cells.at(x_).at(y_);
    curCell->setAlive(!curCell->isAlive);
}


// Converts the grid to a string format in order to be saved
std::string Grid::toString () {
    std::string save = "";
    save.append(std::to_string(this->x));
    save.append(" ");
    save.append(std::to_string(this->y));
    save.append("\n");
    for (size_t i = 0; i < this->x; i++) {
        for (size_t j = 0; j < this->y; j++) {
            save.append(std::to_string(this->cells.at(i).at(j).isAlive));
        }
    }
    return save;
}


// Converts a string in the right format to a grid
Grid* Grid::fromString (std::string save) {
    size_t index = 0;   // Stores which character we are working on
    std::string x_, y_; // Stores temporary values of the string that will be converted to a digit

    // Initialize the variable to store each character, assign it to the first character,
    // and begin looping and appending each character we across until a space is reached (breaker)
    char c = save.at(index);
    while (c != ' ') {
        x_ += c;
        index++;
        c = save.at(index);
    }
    index++; // To skip the space

    // Set the character to the next character and begin doing the same thing as before except until a new line is hit
    c = save.at(index);
    while (c != '\n') {
        y_ += c;
        index++;
        c = save.at(index);
    }
    index++; // To skip the newline

    // Convert the strings to numbers
    size_t xMax = std::stoul(x_);
    size_t yMax = std::stoul(y_);

    // Create a new grid with default values
    Grid* grid = new Grid(xMax, yMax, false);

    // Temporary storage of the cells before assigning to the main cells
    std::vector<std::vector<Cell>> iCells;

    // Loop through every cell in the grid and check the corresponding place in the string and attach its boolean value
    for (size_t i = 0; i < xMax; i++) {
        std::vector<Cell> col;
        for (size_t j = 0; j < yMax; j++) {
            Cell* cell = new Cell(i, j, grid, (bool)(save.at(index) - '0')); //  - '0' because the char is technically an int, and subtracting '0' will convert it from normal char to actual number
            col.push_back(*cell);
            index++;
        }
        iCells.push_back(col);
    }

    grid->cells = iCells;
    return grid;
}


/* PROGRAM END */

/* FILE END */
