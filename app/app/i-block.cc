#include <iostream>
#include "i-block.h"
#include "board.h"
#include "square.h"

/*	vector<Square*> squares;
	int rotation, level_generated, weight;
	bool collisionDetected(const string direction);
*/

I_Block::I_Block(int level_generated, int weight) 
	: Block{level_generated, weight}  {
	squares->emplace_back(new Square{0, 3, 'I'});
	squares->emplace_back(new Square{1, 3, 'I'});
	squares->emplace_back(new Square{2, 3, 'I'});
	squares->emplace_back(new Square{3, 3, 'I'});
}

I_Block::~I_Block() {}

void I_Block::clockwise(Board *b, int num_spins) {
	int x0 = squares->at(0)->getX();
	int y0 = squares->at(0)->getY();
	int x1 = squares->at(1)->getX();
	int y1 = squares->at(1)->getY();
	int x2 = squares->at(2)->getX();
	int y2 = squares->at(2)->getY();
	int x3 = squares->at(3)->getX();
	int y3 = squares->at(3)->getY();
	int new_x0, new_y0, new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;

	int pos = (rotation>=3) ? 0 : (rotation + 1);
	for (int i = num_spins; i > 0; --i) {
		cout << "pos: " << pos << endl;
		if (pos==0) {
			new_x0 = x0 - 3;
			new_y0 = y0;
			new_x1 = x1 - 2;
			new_y1 = y1 + 1;
			new_x2 = x2 - 1;
			new_y2 = y2 + 2;
			new_x3 = x3;
			new_y3 = y3 + 3;
		} else if (pos==1) {
			new_x0 = x0;
			new_y0 = y0 - 3;
			new_x1 = x1 - 1;
			new_y1 = y1 - 2;
			new_x2 = x2 - 2;
			new_y2 = y2 - 1;
			new_x3 = x3 - 3;
			new_y3 = y3;
		} else if (pos==2) {
			new_x0 = x0 + 3;
			new_y0 = y0;
			new_x1 = x1 + 2;
			new_y1 = y1 - 1;
			new_x2 = x2 + 1;
			new_y2 = y2 - 2;
			new_x3 = x3;
			new_y3 = y3 - 3;
		} else if (pos==3) {
			new_x0 = x0;
			new_y0 = y0 + 3;
			new_x1 = x1 + 1;
			new_y1 = y1 + 2;
			new_x2 = x2 + 2;
			new_y2 = y2 + 1;
			new_x3 = x3 + 3;
			new_y3 = y3;
		} else {
			cerr << "Error: Unexpected rotation" << endl;
			return;
		}
		int pos = (pos>=3) ? 0 : (pos + 1);
	}

	squares->at(0)->changeX(new_x0);
	squares->at(0)->changeY(new_y0);
	squares->at(1)->changeX(new_x1);
	squares->at(1)->changeY(new_y1);
	squares->at(2)->changeX(new_x2);
	squares->at(2)->changeY(new_y2);
	squares->at(3)->changeX(new_x3);
	squares->at(3)->changeY(new_y3);

	if (b->isValidPosition(*squares)) {
		cout << "rotation was valid" << endl;
		b->clearSquare(x0, y0);
		b->clearSquare(x1, y1);
		b->clearSquare(x2, y2);
		b->clearSquare(x3, y3);
		rotation = pos;
	} else {
		squares->at(0)->changeX(x0);
		squares->at(0)->changeY(y0);
		squares->at(1)->changeX(x1);
		squares->at(1)->changeY(y1);
		squares->at(2)->changeX(x2);
		squares->at(2)->changeY(y2);
		squares->at(3)->changeX(x3);
		squares->at(3)->changeY(y3);
	}
	b->update_grid_squares();
}

void I_Block::counterclockwise(Board *b, int num_spins) {
	int x0 = squares->at(0)->getX();
	int y0 = squares->at(0)->getY();
	int x1 = squares->at(1)->getX();
	int y1 = squares->at(1)->getY();
	int x2 = squares->at(2)->getX();
	int y2 = squares->at(2)->getY();
	int x3 = squares->at(3)->getX();
	int y3 = squares->at(3)->getY();
	int new_x0, new_y0, new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;

	int pos = (rotation<=0) ? 3 : (rotation - 1);
	for (int i = num_spins; i > 0; --i) {
		if (pos==0) {
			new_x0 = x0;
			new_y0 = y0 + 3;
			new_x1 = x1 + 1;
			new_y1 = y1 + 2;
			new_x2 = x2 + 2;
			new_y2 = y2 + 1;
			new_x3 = x3 + 3;
			new_y3 = y3;
		} else if (pos==1) {
			new_x0 = x0 - 3;
			new_y0 = y0;
			new_x1 = x1 - 2;
			new_y1 = y1 + 1;
			new_x2 = x2 - 1;
			new_y2 = y2 + 2;
			new_x3 = x3;
			new_y3 = y3 + 3;
		} else if (pos==2) {
			new_x0 = x0;
			new_y0 = y0 - 3;
			new_x1 = x1 - 1;
			new_y1 = y1 - 2;
			new_x2 = x2 - 2;
			new_y2 = y2 - 1;
			new_x3 = x3 - 3;
			new_y3 = y3;
		} else if (pos==3) {
			new_x0 = x0 + 3;
			new_y0 = y0;
			new_x1 = x1 + 2;
			new_y1 = y1 - 1;
			new_x2 = x2 + 1;
			new_y2 = y2 - 2;
			new_x3 = x3;
			new_y3 = y3 - 3;
		} else {
			cerr << "Error: Unexpected rotation" << endl;
			return;
		}
		int pos = (pos<=0) ? 3 : (pos - 1);
	}

	squares->at(0)->changeX(new_x0);
	squares->at(0)->changeY(new_y0);
	squares->at(1)->changeX(new_x1);
	squares->at(1)->changeY(new_y1);
	squares->at(2)->changeX(new_x2);
	squares->at(2)->changeY(new_y2);
	squares->at(3)->changeX(new_x3);
	squares->at(3)->changeY(new_y3);

	if (b->isValidPosition(*squares)) {
		b->clearSquare(x0, y0);
		b->clearSquare(x1, y1);
		b->clearSquare(x2, y2);
		b->clearSquare(x3, y3);
		rotation = pos;
	} else {
		squares->at(0)->changeX(x0);
		squares->at(0)->changeY(y0);
		squares->at(1)->changeX(x1);
		squares->at(1)->changeY(y1);
		squares->at(2)->changeX(x2);
		squares->at(2)->changeY(y2);
		squares->at(3)->changeX(x3);
		squares->at(3)->changeY(y3);
	}
	b->update_grid_squares();
}

void I_Block::printBlock(int currplayer) {
	string space = " ";
    cout << space * currplayer * 16 << "IIII" << endl;
}
