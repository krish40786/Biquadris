#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <memory>
#include <vector>

//#include "player.h"
class Player;
class Square;

using namespace std;

class Display {
    Player *p1; 
    Player *p2;
    vector< vector<Square*> > middleBoard;

  public:
    void renderScoreBoard();
    void makeMiddleBoard();
    void renderNextBoard(int currplayer);
    Display(Player *p1, Player *p2);
    ~Display();
};


#endif
