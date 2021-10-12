#ifndef __LEVEL4_H__
#define __LEVEL4_H__

#include "level.h"
#include <vector>
#include <string>

using namespace std;

class Block;

class Level_4 : public Level {
	vector<Block*> sequence;
	int level;
    unsigned int seed;
  public:
	Level_4(unsigned int seed);
	int getLevel() const override;
	Block *next() override;
	~Level_4();
};

#endif
