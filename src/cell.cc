#include "../lib/cell.h"
#include "../lib/grid.h"

/**
 * @brief Construct a new Cell:: Cell object
 * 
 */
Cell::Cell() {
  this->status_ = DEAD; 
}

/**
 * @brief Return the status 
 * 
 * @return Status 
 */
Status Cell::get_status() const{
  return this->status_;
}

/**
 * @brief Set the status
 * 
 * @param status 
 */
void Cell::set_status(Status status) {
  this->status_ = status;
}

/**
 * @brief Update the status with the value in next_status_
 * 
 */
void Cell::update_status() {
  this->status_ = this->next_status_;
}

/**
 * @brief Get next_status_
 * 
 * @return Status 
 */
Status Cell::get_next_status() const{
  return this->next_status_;
}

/**
 * @brief Set next_status_
 * 
 * @param next_status 
 */
void Cell::update_next_status(Status next_status) {
	this->next_status_ = next_status;
}

/**
 * @brief Get position X of the cell in the grid
 * 
 * @return int 
 */
int Cell::get_x() const{
  return this->position_.first;
}

/**
 * @brief Set position X of the cell in the Grid
 * 
 * @param x 
 */
void Cell::set_x(int x) {
  this->position_.first = x;
}

/**
 * @brief Get position y of the cell in the grid
 * 
 * @return int 
 */
int Cell::get_y() const{
  return this->position_.second;
}

/**
 * @brief  Set position y of the cell in the Grid
 * 
 * @param y 
 */
void Cell::set_y(int y) {
  this->position_.second = y;
}

/**
 * @brief Calculate the number of alive cells which are next to this
 * 
 * @param my_grid 
 */
void Cell::neighbors(const Grid& my_grid) {
  int x = this->position_.first;
  int y = this->position_.second;

  int number_alive = 0;

  for (int i = x - 1; i <= x + 1; ++i) {
    for (int j = y - 1; j <= y + 1; ++j) {
      if(my_grid.at(i, j) == ALIVE) { number_alive++; }
    }
  }

  if (this->get_status() == ALIVE) { number_alive--; }
  this->alive_neighbors_ = number_alive;
}

int Cell::get_alive_neighbors() {
  return this->alive_neighbors_;
}

/**
 * @brief Overload of operator <<
 * 
 * @param out 
 * @param my_cell 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& out, const Cell& my_cell) {
  if (my_cell.get_status() == ALIVE) {
    out <<  "⬜";
  } else {
    out << "⬛";
  }

  return out;
}