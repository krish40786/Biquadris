#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include "block.h"

class I_Block : public Block {
	public:
	I_Block(int level_generated, int weight = 0);
	void printBlock(int currplayer);
	void clockwise(Board *b, int num_spins = 1);
	void counterclockwise(Board *b, int num_spins = 1);
	~I_Block();
};

#endif
