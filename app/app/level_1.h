#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include "level.h"
#include <vector>
#include <string>

class Level_1 : public Level {
	int level;
	unsigned int seed;
  public:
	Level_1(unsigned int seed);
	int getLevel() const;
	Block *next();
	~Level_1();
};

#endif
