#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"

class Z_Block : public Block {
	public:
	Z_Block(int level_generated, int weight = 0);
	void printBlock(int currplayer);
	void clockwise(Board *b, int num_spins = 1);
	void counterclockwise(Board *b, int num_spins = 1);
	~Z_Block();
};

#endif
