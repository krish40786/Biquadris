#ifndef __LEVEL3_H__
#define __LEVEL3_H__

#include "level.h"
#include <vector>
#include <string>

using namespace std;

class Block;

class Level_3 : public Level {
	vector<Block*> sequence;
	int level;
    unsigned int seed;
  public:
	Level_3(unsigned int seed);
	int getLevel() const override;
	Block *next() override;
	~Level_3();
};

#endif
