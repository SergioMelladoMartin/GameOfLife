#include <string>

#include "../lib/grid.h"
#include "../lib/cell.h"

/**
 * @brief Information about the use of the program
 * 
 */
void usage() {
    std::cout << "Usage:";
    std::cout << "\n./GameOfLife [X axis] [Y axis] [turns] [-r (Optional)]";
    std::cout << "\n\t [X axis]: How many cells are in X axis";
    std::cout << "\n\t [Y axis]: How many cells are in Y axis";
    std::cout << "\n\t [Turns]: Game turns";
    std::cout << "\n\t [-r] (Optional): Random initialize of cells\n";
}

/**
 * @brief Error message 
 * 
 * @param option 
 */
void errorExit(int option) {
    std::cout << "==¡¡ERROR!!==\n";

    switch (option) {
        case 1:
            std::cout << "\nInvalid number of arguments";
            usage();
            break;

        default: 
            break;
    }

    std::cout << "\nPress enter to continue...";
    getchar();
    system("clear");
    exit(0);
}


int main(int argc, char* argv[]) {
    std::string R = "-r";
    std::string HELP = "--help";
    
    if ((argc == 1) && (argv[1] == HELP)) {
        usage();
        exit(0);
    }
    
    if (argc < 4) {
        errorExit(1);
    }

    bool random = false;
    if ((argc > 4) && (argv[4] == R)) {
        random = true;
    }

    Grid my_grid(atoi(argv[1]),atoi(argv[2]), random);
    my_grid.start_game(atoi(argv[3]));
}