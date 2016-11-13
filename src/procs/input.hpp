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

/* Header for all general input function, contains the code as well. */

/* HEADER START */


#ifndef SRC_PROCS_INPUT_H
#define SRC_PROCS_INPUT_H

#include <iostream>
#include <string>


namespace proc {
    void getInitialInput (size_t* width, size_t* height) {
        std::cout << "Welcome to Game of Life - C++ edition." << '\n'
                  << "Copyright (C) 2016 Ziyad Edher" << "\n\n";

        std::cout << "Width of the grid:  ";
        std::string w;
        std::cin >> w;

        std::cout << "Height of the grid: ";
        std::string h;
        std::cin >> h;

        std::cout << '\n';

        *width = (size_t)std::stoi(w);
        *height = (size_t)std::stoi(h);
    }
}


#endif /* SRC_PROCS_INPUT_H */


/* HEADER END */

/* FILE END */
