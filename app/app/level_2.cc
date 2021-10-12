#include "level_2.h"

Level_2::Level_2(unsigned int seed) : level{2}, seed{seed} {}

int Level_2::getLevel() const {return this->level;}

Block *Level_2::next() {
	int rand_int = rand()%70;
	
	if (rand_int < 10) {
		return new S_Block(2);
	} else if (rand_int < 20) {
		return new Z_Block(2);
	} else if (rand_int < 30) {
		return new L_Block(2);
	} else if (rand_int < 40) {
		return new O_Block(2);
	} else if (rand_int < 50) {
		return new S_Block(2);
	} else if (rand_int < 60) {
		return new T_Block(2);
	} else {
		return new O_Block(2);
	}
}
