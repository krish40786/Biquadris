#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include <cstdlib>
#include "i-block.h"
#include "j-block.h"
#include "l-block.h"
#include "o-block.h"
#include "s-block.h"
#include "t-block.h"
#include "z-block.h"

using namespace std;

class Level {
  public:
	virtual ~Level();
	virtual int getLevel() const = 0;
	virtual Block *next() = 0;
};

#endif
