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

/* Header for the generic grid. */

/* HEADER START */


#ifndef SRC_ENTITIES_GRID_H
#define SRC_ENTITIES_GRID_H

#include <vector>
#include <cstdio>
#include "cell.hpp"


class Grid {
    public:
        size_t x;
        size_t y;

        size_t evo;

        std::vector<std::vector<Cell>> cells;

        Grid (size_t iX, size_t iY);

        void randomize ();
        void print ();
        void evolve ();

    private:
        void init ();
        void checkCells ();
        void updateCells ();
};


#endif /* SRC_ENTITIES_GRID_H */


/* HEADER END */

/* FILE END */
