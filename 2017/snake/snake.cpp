#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

struct coordinate {
	int x;
	int y;
};

struct direction {
	struct coordinate left;
	struct coordinate right;
};

typedef struct coordinate *Coordinate;

vector <char> navigate(Coordinate goal,Coordinate current,struct direction directions[4],int directionCounter,vector <char> moves);
int selectMove(Coordinate goal,Coordinate current,struct direction directionVector);

int main() {
	int x,y;
	ifstream in("snakein.txt");
	ofstream out("snakeout.txt");
	in >> x >> y;
	struct coordinate goal = {x,y};
	struct coordinate current = {0,0};

	struct coordinate fr = {1,0};
	struct coordinate fl = {-1,0};
	struct coordinate rr = {0,-1};
	struct coordinate rl = {0,1};
	struct coordinate dr = {-1,0};
	struct coordinate dl = {1,0};
	struct coordinate lr = {0,1};
	struct coordinate ll = {0,-1};

	struct direction forward = {fl,fr};
	struct direction right = {rl,rr};
	struct direction down = {dl,dr};
	struct direction left = {ll,lr};

	struct direction directions[4] = {forward,right,down,left};
	int directionCounter = 0;
	vector <char> moves;
	moves = navigate(&goal,&current,directions,directionCounter,moves);
	vector <char>::iterator i = moves.begin();
	while(i != moves.end()) {
		out << *i;
		i ++;
	}
	in.close();
	out.close();
	return 1;
}

vector <char> navigate(Coordinate goal,Coordinate current,struct direction directions[4],int directionCounter,vector <char> moves) {
	// cout << current->x << current->y << endl;
	if (goal->x == current->x && goal->y == current->y) {
		return moves;
	}
	struct direction currentDirection = directions[directionCounter];
	int move = selectMove(goal,current,currentDirection);
	if (move == 0) { // Left
		// cout << "left" << endl;
		directionCounter --;
		if (directionCounter == -1) {
			directionCounter = 3;
		}
		current->x += currentDirection.left.x;
		current->y += currentDirection.left.y;
		moves.push_back('L');
		return navigate(goal,current,directions,directionCounter,moves);
	} else if (move == 1) { // Right
		// cout << "right" << endl;
		directionCounter ++;
		if (directionCounter == 4) {
			directionCounter = 0;
		}
		current->x += currentDirection.right.x;
		current->y += currentDirection.right.y;
		moves.push_back('R');
		return navigate(goal,current,directions,directionCounter,moves);
	}
}

int selectMove(Coordinate goal,Coordinate current,struct direction directionVector) {
	struct coordinate left = directionVector.left;
	struct coordinate right = directionVector.right;
	int distanceOne = pow((goal->x - (current->x + left.x)),2) + pow((goal->y - (current->y + left.y)),2);
	int distanceTwo = pow((goal->x - (current->x + right.x)),2) + pow((goal->y - (current->y + right.y)),2);

	// cout << distanceOne << " " << distanceTwo << endl;
	if (distanceOne < distanceTwo) {
		return 0; // Lest distance for left
	} else {
		return 1; // Lest distance for right
	}
}

