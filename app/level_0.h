#ifndef __LEVEL0_H__
#define __LEVEL0_H__

#include "level.h"
#include <vector>
#include <string>

using namespace std;

class Block;

class Level_0 : public Level {
	vector<char> sequence;
	int level, currblock, num_blocks;
  public:
	Level_0(string filename);
	int getLevel() const override;
	Block *next() override;
	~Level_0();
};

#endif
