#include <string>

using namespace::std;


class Solution {
public:
    int minimumBuckets(string street) {
	string ts = street;
	int ret = (street[0] == 'H') ? 1 : 0;
	bool cth = false; // all H?
	bool sst = false; // save a st?
	int n = street.size();
	if (n == 1) return (street == "H") ? -1 : 0;

	if (ret && street[1] == 'H') return -1;

	for (auto c : street) {
	    if (c == '.') {
		cth = true;
		break;
	    }
	}

	if (!cth) return -1; // all H

	for (int i = 1; i < n; i++) {
	    if (street[i] == 'H') {
		if (street[i-1] == 'H' && (i == n-1 || street[i+1] == 'H')) return -1; // 3 adjacent H

		if (sst) ts[i] = '.';
		sst = false;
		ret++;   // assume put a buckets

	    } else {
		if (ts[i-1] == 'H' && i < n-1 && ts[i+1] == 'H') {
		    // can save a bucket
		    sst = true;
		    ret--;
		}
	    }
	}

	return ret;
    }
};


/*
 * H..H
 * H.H.
 * H..H.H.H.
 * .H..H..H
 */
