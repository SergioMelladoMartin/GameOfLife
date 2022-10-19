#pragma once

#include <vector>
#include <utility>
#include <unistd.h>

#include "cell.h"

class Grid {
	private: 
		std::vector<std::vector<Cell>> grid_;
		std::pair<int, int> size_;; 
		int turn_;

	public: 
		Grid(int, int, bool);

		void print();
		Status at(int, int) const;
		void next_generation();
		void start_game(int);
};