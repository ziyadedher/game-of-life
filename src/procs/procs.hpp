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
#include <ncurses.h>
#include "../entities/grid.hpp"


namespace proc {
    void initCurses () {
        initscr();
    }

    void terminateCurse () {
        getch();
        endwin();
    }

    void getInitialInput (size_t* width, size_t* height) {
        printw("Welcome to Game of Life - C++ edition.\n");
        printw("Copyright (C) 2016 Ziyad Edher\n\n");

        printw("Width of the grid:  ");
        char w[4];
        getstr(w);

        printw("Height of the grid: ");
        char h[4];
        getstr(h);

        *width = (size_t)std::stoi(std::string(w));
        *height = (size_t)std::stoi(std::string(h));
    }

    [[noreturn]]
    void startEvolutionLoop (Grid* grid) {
        clear();
        while (true) {
            move(0, 0);
            grid->print();
            printw("\nEvolution: %lu\n", grid->evo);
            printw("Press any button to evolve...");
            getch();
            refresh();
            grid->evolve();
        }
    }
}


#endif /* SRC_PROCS_INPUT_H */


/* HEADER END */

/* FILE END */
