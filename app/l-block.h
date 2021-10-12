#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include "block.h"

class L_Block : public Block {
	public:
	L_Block(int level_generated, int weight = 0);
	void printBlock(int currplayer);
	void clockwise(Board *b, int num_spins = 1);
	void counterclockwise(Board *b, int num_spins = 1);
	~L_Block();
};


#endif
