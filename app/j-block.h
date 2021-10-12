#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include "block.h"

class J_Block : public Block {
	public:
	J_Block(int level_generated, int weight = 0);
	void printBlock(int currplayer);
	void clockwise(Board *b, int num_spins = 1);
	void counterclockwise(Board *b, int num_spins = 1);
	~J_Block();
};

#endif
