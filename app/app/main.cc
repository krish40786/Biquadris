#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <exception>

#include "player.h"
#include "board.h"
#include "display.h"
#include "level_0.h"

using namespace std;

int pointsFromLines(int linesCleared, int level) {
	cout << "Points from lines:" << (linesCleared + level) * (linesCleared + level) <<endl;
	return (linesCleared + level) * (linesCleared + level);
} 

int pointsFromBlocks(vector<int> level_vector) {
	cout << "Size of level vector:" << level_vector.size() << endl;
	int added_points = 0;
	for (auto &x: level_vector) {
		added_points += ((x + 1) * (x + 1));
	}
	cout << "Points from blocks:" << added_points <<endl;
	return added_points;
}

int main(int argc, char *argv[]) {
	bool text_only{false};
	unsigned int seed{time(0)}; // initialize the seed randomly
	
	int initial_level{0};
	string scriptfile1{"sequence1.txt"}, scriptfile2{"sequence2.txt"};

	// read command line arguments
	for(int i = 1; i < argc; i++) {
       if (string(argv[i]) == "-text") {
			text_only = true;
		
		} else if (string(argv[i]) == "-seed") {
			++i;
			unsigned int temp = seed;
			istringstream ss{argv[i]};
			ss >> seed;
			if (ss.fail()) {
				cerr << "Error: Invalid seed given" << endl;
				seed = temp;
			}

		} else if (string(argv[i]) == "-scriptfile1") {
			++i;
			istringstream ss{argv[i]};
			ss >> scriptfile1;

		} else if (string(argv[i]) == "-scriptfile2") {
			++i;
			istringstream ss{argv[i]};
			ss >> scriptfile2;

		} else if (string(argv[i]) == "-startlevel") {
			++i;
			int temp = initial_level;
			istringstream ss{argv[i]};
			ss >> initial_level;
			if ((ss.fail()) || (initial_level < 0) || (initial_level > 4)) {
				cerr << "Error: Invalid starting level given" << endl;
				seed = temp;
			}
		} 
    }

	// create players and display
	Player *p; // will represent the current player
	Player *p1 = new Player{scriptfile1, seed, initial_level}; //Change to not only make level_0, but dynamic
    Player *p2 = new Player{scriptfile2, seed, initial_level};
    Display d{p1, p2};
	int currplayer = 0;
	int hi_score = 0;
	
	// update board information with each player's current block
	p1->getBoardObject()->update_grid_squares();
	p2->getBoardObject()->update_grid_squares(); 

	// render the intial display
	d.renderScoreBoard();
	d.makeMiddleBoard();
    d.renderNextBoard(currplayer);

	string cmd;
	int multiplier;
	
	while (cin >> cmd) {
	p = (currplayer==0)? p1 : p2;

//	cout << "Current Player: " << currplayer << endl;

		if (cmd == "left") {
			p->getCurrBlock()->left(p->getBoardObject());

		} else if (cmd == "right") {
			p->getCurrBlock()->right(p->getBoardObject());

		} else if (cmd == "down") {
			p->getCurrBlock()->down(p->getBoardObject());
	
		} else if (cmd == "clockwise") {
			p->getCurrBlock()->clockwise(p->getBoardObject());

		} else if (cmd == "counterclockwise") {
			p->getCurrBlock()->counterclockwise(p->getBoardObject());
		
		} else if (cmd == "drop") {
			p->getCurrBlock()->drop(p->getBoardObject()); //Drop the curr block 
			int num_rows_cleared = p->getBoardObject()->drop_blocks(); //Clear rows and drop the rest of blocks
			p->addScore(pointsFromLines(num_rows_cleared, p->getLevelObject()->getLevel())); //Computes score for lines cleared
			p->addScore(pointsFromBlocks(p->getBoardObject()->clearBlocks()));  //Computes score for blocks cleared
			if (p->getScore() > hi_score) {
				hi_score = p->getScore(); //Update hi-score if new score is higher
			}
			p->swapCurrBlock(); //Swap curr and next blocks
			if(num_rows_cleared >= 2){
				string action, bl;
				cin >> action;
				currplayer = (currplayer==0) ? 0 : 1;
				p = (currplayer==0) ? p2 : p1;
				/*if(action == "force"){
					
					cin >> bl;
					if (cmd == "I") {
						p->replaceCurrBlock('I');

					} else if (cmd == "J") {
						p->replaceCurrBlock('J');

					} else if (cmd == "L") {
						p->replaceCurrBlock('L');

					} else if (cmd == "O") {
						p->replaceCurrBlock('O');

					} else if (cmd == "S") {
						p->replaceCurrBlock('S');

					} else if (cmd == "Z") {
						p->replaceCurrBlock('Z');

					} else if (cmd == "T") {
						p->replaceCurrBlock('T');

					}
				} else if(action == "apply_heavy"){
					Block *dead = p->getCurrBlock();
					p->apply_heavy(dead, 2);
				} else if(action == "blind"){
					//p->blindRender();
				}
			}*/
			currplayer = (currplayer==0) ?  1: 0;
			//p = (currplayer==0) ? p2 : p1; //Change the player
			cout << "currplayer: " << currplayer << endl;

		} else if (cmd == "levelup") {
			p->levelUp();


		} else if (cmd == "leveldown") {
			p->levelDown();


		} else if (cmd == "norandom") {
			// worry about it later
			string file, block;
            cin >> file;
            ifstream ss{file};
			while (ss >> block) {
				//if (block == 
			}
  			

		} else if (cmd == "random") {
			// worry about it later


		} else if (cmd == "sequence") {


		} else if (cmd == "restart") {
			delete p1;
			delete p2;
			Player *p1 = new Player{scriptfile1, seed, initial_level};
    		Player *p2 = new Player{scriptfile2, seed, initial_level};
    	//	d(p1, p2);

		} else if (cmd == "I") {
			p->replaceCurrBlock('I');

		} else if (cmd == "J") {
			p->replaceCurrBlock('J');

		} else if (cmd == "L") {
			p->replaceCurrBlock('L');

		} else if (cmd == "O") {
			p->replaceCurrBlock('O');

		} else if (cmd == "S") {
			p->replaceCurrBlock('S');

		} else if (cmd == "Z") {
			p->replaceCurrBlock('Z');

		} else if (cmd == "T") {
			p->replaceCurrBlock('T');

		} else if (cmd == "*") {
	

		// exception handling		
		} else { 

		}
	//	p->getBoardObject()->update_grid_squares();
		p->getBoardObject()->update_grid_squares();
		d.renderScoreBoard();
		d.makeMiddleBoard();
    	d.renderNextBoard(currplayer);
	}	 
	delete p1;
	delete p2;
}

