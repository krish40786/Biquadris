#include "level_1.h"

Level_1::Level_1(unsigned int seed) : level{1}, seed{seed} {}

int Level_1::getLevel() const {return this->level;}

Level_1::~Level_1() {}

Block *Level_1::next() {
	int rand_int = rand()%54;
	
	if (rand_int < 12) {
		return new S_Block(1);
	} else if (rand_int < 24) {
		return new Z_Block(1);
	} else if (rand_int < 30) {
		return new L_Block(1);
	} else if (rand_int < 36) {
		return new O_Block(1);
	} else if (rand_int < 42) {
		return new S_Block(1);
	} else if (rand_int < 48) {
		return new T_Block(1);
	} else {
		return new O_Block(1);
	}
}
