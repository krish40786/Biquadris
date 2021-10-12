#ifndef __LEVEL2_H__
#define __LEVEL2_H__

#include "level.h"
#include <vector>
#include <string>

class Level_2 : public Level {
	int level;
	unsigned int seed;
  public:
	Level_2(unsigned int seed);
	int getLevel() const;
	Block *next();
};

#endif
