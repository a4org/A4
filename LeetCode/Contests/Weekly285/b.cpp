#include <string>

using namespace::std;

class Solution {
public:
    int countCollisions(string directions) {
	int ret = 0;

	if (directions.length() == 1) return 0;
	string next = "";

	while (directions != next) {
	    next = directions;
	    for (int i = 1; i < directions.size(); i++) {
		char *dir = &directions[i];
		char *prv = &directions[i-1];
		if (*prv != *dir) {
		    // may cause a collision
		    if (*prv == 'R' && *dir == 'L') {
			ret += 2;
			*dir = 'S';
			*prv = 'S';
		    }
		    else if (*prv == 'S') {
			if (*dir == 'L') {
			    ret += 1;
			    *dir = 'S';
			    *prv = 'S';
			} 
		    } else if (*dir == 'S') {
			if (*prv == 'R') {
			    ret += 1;
			    *dir = 'S';
			    *prv = 'S';
			} 
		    }
		}
	    }
	}
	return ret;
    }
};

// "SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR"
