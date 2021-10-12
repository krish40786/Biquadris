#include "level_4.h"

Level_4::Level_4(unsigned int seed) : level{4}, seed{seed} {}

Level_4::~Level_4() {}

int Level_4::getLevel() const {return this->level;}

Block *Level_4::next() {
	int rand_int = rand()%90;
	
	if (rand_int < 20) {
		return new S_Block(4, 1);
	} else if (rand_int < 40) {
		return new Z_Block(4, 1);
	} else if (rand_int < 50) {
		return new L_Block(4, 1);
	} else if (rand_int < 60) {
		return new O_Block(4, 1);
	} else if (rand_int < 70) {
		return new S_Block(4, 1);
	} else if (rand_int < 80) {
		return new T_Block(4, 1);
	} else {
		return new O_Block(4, 1);
	}

    //Implement 5 block drop rule
}
