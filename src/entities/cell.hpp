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

/* Header for the generic cell. */

/* HEADER START */


#ifndef SRC_ENTITIES_CELL_H
#define SRC_ENTITIES_CELL_H

#include <cstdio> // `size_t`

// Forward declaration of Grid in order to bypass a circular dependency
class Grid;

class Cell {
    public:
        Cell (size_t iX, size_t iY, Grid* grid, bool status = false);

        char curChar;
        bool isAlive;

        void setAlive (bool alive);
        void checkAlive ();
        void update ();

    private:
        static const char onChar = '#';
        static const char offChar = '-';

        size_t x;
        size_t y;

        Grid* parentGrid;

        bool willBeAlive;
        int neighbours;


        void checkNeighbours ();
        void checkStatus ();
};


#endif /* SRC_ENTITIES_CELL_H */


/* HEADER END */

/* FILE END */
