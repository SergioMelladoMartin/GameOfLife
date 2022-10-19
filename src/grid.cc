#include "../lib/grid.h"

/**
 * @brief Construct a new Grid:: Grid object
 * 
 * @param x 
 * @param y 
 * @param random 
 */
Grid::Grid(int x, int y, bool random) {
    this->size_.first = x;
    this->size_.second = y;
    this->grid_.resize(this->size_.first + 2, std::vector<Cell>(this->size_.second + 2));

    for(auto i = 0; i < this->size_.first; ++i) {
        for(auto j = 0; j < this->size_.second; ++j) {
            this->grid_[i + 1][j + 1].set_x(i);
            this->grid_[i + 1][j + 1].set_y(j);
        }   
    }

    if (random) {
        srand(time(NULL));
        int number_alive = (x * y) * 0.25;
        for(auto i = 0; i < number_alive; ++i) {
            this->grid_[rand() % x + 1][rand() % y + 1].set_status(ALIVE);
        }
    } else {
        int number_alive;
        std::cout << "How many cells are alive in the first turn?: ";
        std::cin >> number_alive;

        for(auto i = 0; i < number_alive; ++i) {
            int x, y;
            std::cout << "\nX: ";
            std::cin >> x;
            std::cout << "Y: ";
            std::cin >> y;
            this->grid_[x + 1][y + 1].set_status(ALIVE);
        }
    }

    this->turn_ = 0;
}

/**
 * @brief Print all the cells of the Grid
 * 
 */
void Grid::print() {
    for(auto i = 0; i < this->size_.first + 1; ++i) {
        for(auto j = 0; j < this->size_.second + 1; ++j) {
            std::cout << grid_[i][j];
        }
    std::cout << "\n";   
    }
}

/**
 * @brief Return the status of the cell in the (x, y) position
 * 
 * @param x 
 * @param y 
 * @return Status 
 */
Status Grid::at(int x, int y) const {
    return this->grid_[x + 1][y + 1].get_status();
}

/**
 * @brief Generate the next generation of cells, calculating the number of alive
 *  neighboars for each cell and applicating the rules
 * 
 */
void Grid::next_generation() {
    for (auto i = 0; i < this->size_.first; ++i) {
        for (auto j = 0; j < this->size_.second; ++j) {
            this->grid_[i + 1][j + 1].neighbors(*this);
        }
    }

    for (auto i = 0; i < this->size_.first; ++i) {
        for (auto j = 0; j < this->size_.second; ++j) {
            if ((this->grid_[i + 1][j + 1].get_status() == ALIVE)) {
                if ((this->grid_[i + 1][j + 1].get_alive_neighbors() == 2) || (this->grid_[i + 1][j + 1].get_alive_neighbors() == 3)) {
                    this->grid_[i + 1][j + 1].update_next_status(ALIVE);
                } else {
                    this->grid_[i + 1][j + 1].update_next_status(DEAD);
                }
            }

            if ((this->grid_[i + 1][j + 1].get_status() == DEAD) && (this->grid_[i + 1][j + 1].get_alive_neighbors() == 3)) {
                this->grid_[i + 1][j + 1].update_next_status(ALIVE);
            }
            
            if ((this->grid_[i + 1][j + 1].get_status() == DEAD) && (this->grid_[i + 1][j + 1].get_alive_neighbors() != 3)) {
                this->grid_[i + 1][j + 1].update_next_status(DEAD);
            }
        }
    }
}

/**
 * @brief Start the game
 * 
 * @param turns 
 */
void Grid::start_game(int turns) {
    while(this->turn_ != turns + 1) {
        system("clear");
        std::cout << "Turn: " << this->turn_ << "\n";
        this->print();
        sleep(1);
        this->next_generation();
        for (auto i = 0; i < this->size_.first; ++i) {
            for (auto j = 0; j < this->size_.second; ++j) {
                this->grid_[i + 1][j + 1].update_status();
            }
        }
        this->turn_++;
    }
}