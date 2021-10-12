#include "level_3.h"

Level_3::Level_3(unsigned int seed) : level{3}, seed{seed} {}

Level_3::~Level_3() {}

int Level_3::getLevel() const {return this->level;}

Block *Level_3::next() {
	int rand_int = rand()%90;
	
	if (rand_int < 20) {
		return new S_Block(3, 1);
	} else if (rand_int < 40) {
		return new Z_Block(3, 1);
	} else if (rand_int < 50) {
		return new L_Block(3, 1);
	} else if (rand_int < 60) {
		return new O_Block(3, 1);
	} else if (rand_int < 70) {
		return new S_Block(3, 1);
	} else if (rand_int < 80) {
		return new T_Block(3, 1);
	} else {
		return new O_Block(3, 1);
	}

    //Implement Heavy
}
