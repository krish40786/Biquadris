#include "level_0.h"
#include "block.h"

#include <fstream>

Level_0::Level_0(string filename) : level{0}, currblock{0} {
	ifstream file{filename};
	char c;
	vector<char> chars_read;
	while (file >> c) {
		if ((c=='I') || (c=='J') || (c=='L') || (c=='O') ||
			(c=='S') || (c=='T') || (c=='Z')) {
			chars_read.emplace_back(c);
		}
	}
	sequence = chars_read;
	// in case the text file does not exist or is empty
	if (chars_read.size()==0) sequence.emplace_back('I');
	num_blocks = sequence.size();
}

Level_0::~Level_0() {}

int Level_0::getLevel() const {return this->level;}

Block *Level_0::next() {
	char type = sequence.at(currblock);
	
	if (currblock != num_blocks-1) {
		++currblock;
	} else {
		currblock = 0;
	}

	if (type == 'I') {
		return new I_Block(0);
	} else if (type == 'J') {
		return new J_Block(0);
	} else if (type == 'L') {
		return new L_Block(0);
	} else if (type == 'O') {
		return new O_Block(0);
	} else if (type == 'S') {
		return new S_Block(0);
	} else if (type == 'T') {
		return new T_Block(0);
	} else if (type == 'Z') {
		return new Z_Block(0);
	}
}
