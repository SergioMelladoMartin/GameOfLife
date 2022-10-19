#pragma once

#include <iostream>
#include <utility>

enum Status { DEAD, ALIVE };

class Grid;

class Cell {
  private:
    Status status_;  
    Status next_status_;  
    std::pair<int, int> position_;
    int alive_neighbors_;
    bool border_;

  public:
    Cell();  

    Status get_status() const;    
    void set_status(Status);
    void update_status();

    Status get_next_status() const;  
    void update_next_status(Status);

    int get_x() const;
    void set_x(int);

    int get_y() const;
    void set_y(int);

    void neighbors(const Grid&);
    int get_alive_neighbors();

		friend std::ostream& operator << (std::ostream&, const Cell&);
};