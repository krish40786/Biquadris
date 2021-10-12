#include <iostream>
#include <math.h>
#include "display.h"
#include <string>
#include "player.h"
#include "square.h"
#include "board.h"

using namespace std;

Display :: Display(Player *p1, Player *p2) :
    p1{p1}, p2{p2}
	 {
        // middleBoard{vector< vector<Square*> > *(18, vector<Square*>(22, new Square{x,y, '-'}))}
        vector<Square*> s;
        for (int j = 0; j < 18; ++j) {
			for (int i = 0; i < 11; ++i) {
				s.emplace_back(new Square{i, j, ' '});
			}
			middleBoard.emplace_back(s);
			s.clear();
        }

    }

Display :: ~Display() {
    delete p1, p2;
}

void Display :: renderScoreBoard() {
    string space = " ";
    cout << "Level:    " << p1->getLevelObject()->getLevel() << "     " << "Level:    " << p2->getLevelObject()->getLevel() << endl;
    cout << "Score:" << space*(4-log10((p1->getScore()==0) ? 1 : p1->getScore())) << p1->getScore() << "     " << "Score:" << space*(4-log10((p1->getScore()==0) ? 1 : p1->getScore())) << p2->getScore() << endl;
    cout << "-----------" << "     " << "-----------" << endl;
}


void Display :: makeMiddleBoard() {
    // grab the boards from p1 and p2
    vector< vector<Square*> >* p1Board = p1->getBoardObject()->get_grid_squares();
    vector< vector<Square*> >* p2Board = p2->getBoardObject()->get_grid_squares();

    // store the size of a new row vector
	int num_rows = middleBoard.size();
	int num_cols = middleBoard.at(0).size();
    int num_spaces = 5;
    

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            cout << (*p1Board).at(i).at(j)->getType();
        }
        for (int j = 0; j < num_spaces; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < num_cols; ++j) {
            cout << (*p2Board).at(i).at(j)->getType();
        }
        cout << endl;
    }
}   

void Display :: renderNextBoard(int currplayer) {
    cout << "-----------" << "     " << "-----------" << endl;
    cout << "Next:      " << "     " << "Next:      " << endl;
    if (currplayer == 0) {
        p1->getCurrBlock()->printBlock(currplayer);
}   else if (currplayer == 1) {
        p2->getCurrBlock()->printBlock(currplayer);
    }
}