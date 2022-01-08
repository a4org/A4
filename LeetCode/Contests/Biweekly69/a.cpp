#include <string>

using namespace::std;

class Solution {
public:
    string capitalizeTitle(string title) {
	int size = title.size();
	title += ' ';
	int ct = 0;
	string ret = "";
	string temp = "";

	for (auto c : title) {
	    if (c == ' ') {
		// divide
		if (ct <= 2 && ct > 0) {
		    for (auto sc : temp) ret += tolower(sc);
		} else if (ct > 2){
		    ret += toupper(temp[0]);
		    for (int i = 1; i < temp.size(); i++) {
			ret += tolower(temp[i]);
		    }
		}
		ret += ' ';
		temp = "";
		ct = 0;

	    } else {
		temp += c;
		ct++;
	    }
	}
	ret.pop_back();
	return ret;
    }

private:
    char tolower(char c) {
	if (c > 91) {
	    return c;
	} 
	return c + 32;
    }

    char toupper(char c) {
	if (c > 91) {
	    return c - 32;
	} 
	return c;
    }
};
