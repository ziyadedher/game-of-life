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
#include <unistd.h>
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

    void getInitialInput (size_t* width, size_t* height, size_t* speed) {
        printw("Welcome to Game of Life - C++ edition.\n");
        printw("Copyright (C) 2016 Ziyad Edher\n\n");

        printw("Width of the grid:    ");
        char w[4];
        getstr(w);

        printw("Height of the grid:   ");
        char h[4];
        getstr(h);

        printw("Execution speed (ms): ");
        char s[16];
        getstr(s);

        *width = (size_t)std::stoi(std::string(w));
        *height = (size_t)std::stoi(std::string(h));
        *speed = (size_t)std::stoi(std::string(s));
    }

    void displayGrid (Grid* grid) {
        move(0, 0);
        grid->print();
        printw("\nEvolution: %lu\n", grid->evo);
    }

    void startEvolutionLoop (Grid* grid, size_t speed) {
        clear();
        while (true) {
            displayGrid(grid);
            printw("[Space] Evolve once        [Enter] Run evolutions        [q] Exit\n");

            int c = getch();
            if (c == ' ') {
                grid->evolve();
            } else if (c == 'q') {
                return;
            } else if (c == '\n') {
                nodelay(stdscr, TRUE);
                while (true) {
                    grid->evolve();
                    displayGrid(grid);

                    printw("Press any key to end execution...                       \n");
                    if (getch() != ERR) {
                        break;
                    }

                    usleep((__useconds_t)speed * 1000);
                }
            }
        }
    }
}


#endif /* SRC_PROCS_INPUT_H */


/* HEADER END */

/* FILE END */
