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

#include <unistd.h> // `usleep`
#include <string>   // `std::string`, `std::stoi`
#include <ncurses.h>
#include "../entities/grid.hpp"


namespace proc {
    // Initializes curses, formalities
    void initCurses () {
        initscr();
        keypad(stdscr, TRUE);
    }

    // Terminates curses, formalities
    void terminateCurse () {
        getch();
        endwin();
    }

    // Gets pointers to the variables wanting to be set, and assigns their startup values
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

        // Converts the `char` array into a string,
        // then from string into an `int`,
        // then from `int` into a `size_t` for each
        *width = (size_t)std::stoi(std::string(w));
        *height = (size_t)std::stoi(std::string(h));
        *speed = (size_t)std::stoi(std::string(s));
    }

    // Small macro to display the grid, overwrite any grid before it, and display the evolution count
    void displayGrid (Grid* grid) {
        move(0, 0);
        grid->print();
        printw("\nEvolution: %lu\n", grid->evolution);
    }

    // Heart of the display of the program
    void startEvolutionLoop (Grid* grid, size_t speed) {
        clear();
        move(0, 0);

        // Stores the cursor position between prints
        size_t cursorPosX = 0;
        size_t cursorPosY = 0;

        // Infinitely loops until 'q' is pressed
        while (true) {
            // First of all displays the grid with supporting information
            displayGrid(grid);
            printw("[Space] Evolve once        [Enter] Run evolutions        [q] Exit         [a] Toggle cell\n");

            // Move the cursor and display it
            move((int)cursorPosY, (int)cursorPosX);
            refresh();

            // Gets the most recently touched character
            int c = getch();

            //  - if space (' ') evolves and loops again
            //  - if ('q') ends the loops
            //  - if enter ('\n') starts a sub-loop similar to the main one, but waits for any character to stop
            //  - if any of the arrow keys, set the cursor position accordingly (X moves by 2 since there are spaces between the characters)
            if (c == ' ') {
                grid->evolve();
            } else if (c == 'q') {
                return;
            } else if (c == '\n') {
                nodelay(stdscr, TRUE); // Getting of the input is asyncronous
                // Infinitely loops until any key is pressed
                while (true) {
                    grid->evolve();
                    displayGrid(grid);

                    printw("Press any key to end execution...\n");

                    // If there has been something inputted, then break out of this sub-loop
                    if (getch() != ERR) {
                        break;
                    }

                    usleep((__useconds_t)speed * 1000); // Sleep the desired amount of time (in micro seconds converted to milliseconds)
                }
            } else if (c == 'a') {
                Cell* curCell = &grid->cells.at(cursorPosY).at(cursorPosX / 2);
                curCell->setAlive(!curCell->isAlive);
            }

            // Checks the arrow keys, and makes sure that moving the cursor won't overflow the `size_t` or go out of bounds of the array
            else if (c == KEY_UP) {
                if (cursorPosY < 1) {
                    continue;
                }
                cursorPosY -= 1;
            } else if (c == KEY_LEFT) {
                if (cursorPosX < 2) {
                    continue;
                }
                cursorPosX -= 2;
            } else if (c == KEY_DOWN) {
                if (cursorPosY >= grid->y - 1) {
                    continue;
                }
                cursorPosY += 1;
            } else if (c == KEY_RIGHT) {
                if (cursorPosX / 2 >= grid->x - 1) {
                    continue;
                }
                cursorPosX += 2;
            }

        }
    }
}


#endif /* SRC_PROCS_INPUT_H */


/* HEADER END */

/* FILE END */
