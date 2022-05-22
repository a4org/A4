#include <iostream>
#include <unordered_map>
#include <vector>

using namespace::std;

int all = 0;

void move(unordered_map<int, pair<int, int>>& pd, unordered_map<int, int> pa, int ant, int L) {
  pair<int, int> *antp = &pd[ant];
  // Handle the first situation
  if (antp->second == -1) return; // falls off

  int curr = antp->first;
  if (antp->second == 1) {
    // right
    if (pa.find(curr+1) != pa.end() && pd[pa[curr+1]].second == 0) {
      antp->second = 0;
      pd[pa[curr]].second = 1;
    } else { 
      antp->first++; 
      if (antp->first > L) {
	antp->second = -1;
	cout << ant << " ";
	all++;
      }
    }
  } else {
    // left
    if (pa.find(curr-1) != pa.end() && pd[pa[curr-1]].second == 1) {
      antp->second = 1;
      pd[pa[curr]].second = 0;
    } else { 
      antp->first--; 
      if (antp->first < 1) {
	antp->second = -1;
	cout << ant << " ";
	all++;
      }
    }
  }
}

void test_case(int no) {
  int N, L;
  cin >> N >> L;

  all = 0;

  unordered_map<int, pair<int, int>> posDir;

  for (int i = 1; i <= N; i++) {
    int pos, dir;
    cin >> pos >> dir;
    posDir[i] = {pos, dir};
    // distinct pos
  }

  cout << "Case #" << no << ": ";

  while (true) {
    // time simulation:
    unordered_map<int, int> posAnt = {}; // which ant at position i?

    for (int i = 1; i <= N; i++) {
      int pos = posDir[i].first;
      if (posAnt.find(pos) != posAnt.end()) {
	cout << "Error! Not distinct!" << endl;
	break;
      }
      posAnt[pos] = i;
    }

    for (int i = 1; i <= N; i++) {
      move(posDir, posAnt, i, L);
    }

    if (all == N) break;
  }

  cout << '\n';
}

int main() {
  int N;
  cin >> N;

  int i = 1;
  while (i <= N) {
    test_case(i);
    i++;
  }
}
