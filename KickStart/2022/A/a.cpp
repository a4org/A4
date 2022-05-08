#include <string>
#include <iostream>

using namespace::std;

void run_case(int n) {
    string correct = "";
    string type = "";
    cin >> correct;
    cin >> type;


    if (type.size() < correct.size()) {
	cout << "Case #" << n << ": IMPOSSIBLE" << endl;
	return;
    }

    int ci = 0; // correct i
    int ret = 0;
    for (int i = 0; i < type.size(); i++) {
	if (type[i] == correct[ci]) {
	    // match
	    ci++;
	} else {
	    // delete
	    ret++;
	}
    }

    if (ci == correct.size()) {
	cout << "Case #" << n << ": " << ret << endl;
	return;
    }
    cout << "Case #" << n << ": IMPOSSIBLE" << endl;
}

int main() {
    int n;
    cin >> n;

    int t = 1;
    while (t <= n) {
	run_case(t);
	t++;
    }
}
