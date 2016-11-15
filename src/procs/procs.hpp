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
#include <fstream>  // file operations
#include <sstream>  // `std::stringstream`
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


    // Returns true if the first and returns false if second
    bool getBoolChoice (char first = 'y', char second = 'n') {
        char choice;
        getstr(&choice);
        if (choice == first) {
            return true;
        } else if (choice == second) {
            return false;
        } else {
            printw("Unknown value `%c`, defaulting to `%c`.\n", choice, second);
            return false;
        }
    }


    // Initial welcome screen with all the choices to begin the program
    bool welcomeScreen () {
        printw("Welcome to Game of Life - C++ edition.\n");
        printw("Copyright (C) 2016 Ziyad Edher\n\n");

        printw("[n] Start a new grid        [l] Load an existing grid\n");
        printw("Enter a choice: ");
        return getBoolChoice('n', 'l');
    }


    // Gets pointers to the variables wanting to be set, and assigns their startup values
    void getInitialInput (size_t* width, size_t* height, size_t* speed, bool* randomize) {
        clear();

        printw("Width of the grid:    ");
        char w[4];
        getstr(w);

        printw("Height of the grid:   ");
        char h[4];
        getstr(h);

        printw("Execution speed (ms): ");
        char s[16];
        getstr(s);

        printw("Randomize grid (y/n): ");
        *randomize = getBoolChoice();

        printw("\nPress any button to generate...");
        getch();

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


    // Asks for a file name and checks whether or not it exists and sets the parameter to the name of that file
    bool askAndCheckFile (std::string* retName) {
        clear();
        move(0, 0);

        printw("Enter the file name: ");
        char name[64];
        getstr(name);

        std::ifstream file("saves/full/" + std::string(name));

        *retName = std::string(name);
        return file.good();
    }


    // Saves a given grid to a given file with no questions asked
    void fullSaveToFile (Grid* grid, std::string fileName) {
        std::ofstream file;
        file.open("saves/full/" + fileName);
        file << grid->toString();
        file.close();
    }


    // Asks the user for input on what and where to save a given grid
    void askFileSave (Grid* grid) {
        std::string name;

        if (askAndCheckFile(&name)) {
            printw("This file already exists, overwrite (y/n): ");
            bool choice = getBoolChoice();
            if (!choice) {
                printw("Aborting file save.\nPress any key to continue...");
                getch();
                return;
            }
        }

        fullSaveToFile(grid, name);
        printw("The file has been saved to `saves/full/%s`.\n", name.c_str());
        printw("Press any key to continue...");
        getch();
    }


    // Loads a given file and converts it into a grid then returns that grid
    Grid* fullLoadFromFile (std::string fileName) {
        std::ifstream file;
        file.open("saves/full/" + fileName);
        std::stringstream buffer;
        std::string save;

        buffer << file.rdbuf();
        save = buffer.str();
        file.close();
        return Grid::fromString(save);
    }


    // Asks the user for input on what file to load
    Grid* loadFile () {
        std::string name;

        if (!askAndCheckFile(&name)) {
            printw("This file does not exist.\nAborting file load.\nPress any key to continue...");
            getch();
            return NULL;
        }

        return fullLoadFromFile(name);
    }


    // Settings change menu, the parameters are the settings
    void changeSettings (size_t* speed) {
        clear();
        move(0, 0);

        printw("Execution speed (ms): ");
        char s[16];
        getstr(s);

        *speed = (size_t)std::stoi(std::string(s));
    }


    // Loops evolutions without user input until a key is pressed
    void loopEvos (Grid* grid, size_t speed) {
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
    }


    // Heart of the display of the program
    void mainLoop (Grid* grid, size_t speed) {
        clear();
        move(0, 0);

        // Stores the cursor position between prints
        size_t cursorPosX = 0;
        size_t cursorPosY = 0;

        // Infinitely loops until 'q' is pressed
        while (true) {
            // First of all displays the grid with supporting information
            displayGrid(grid);
            printw("[Space] Evolve once        [Enter] Run evolutions\n[a] Toggle cell            [c] Change Settings\n[s] Save to file           [q] Exit");

            // Move the cursor and display it
            move((int)cursorPosY, (int)cursorPosX);
            refresh();

            // Gets the most recently touched character
            int c = getch();

            // Parses what to do with that character
            if (c == ' ') {
                grid->evolve();
            } else if (c == 'q') {
                return;
            } else if (c == '\n') {
                loopEvos(grid, speed);
                nodelay(stdscr, FALSE);
            } else if (c == 'a') {
                grid->toggleAliveAt(cursorPosX / 2, cursorPosY);
            } else if (c == 's') {
                askFileSave(grid);
            } else if (c == 'c') {
                changeSettings(&speed);
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
