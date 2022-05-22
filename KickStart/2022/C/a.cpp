#include <iostream>
#include <string>

using namespace::std;

void test_case(int no) {
  bool r1, r2, r3, r4, r5;
  r1 = r2 = r3 = r4 = r5 = false;
  int n; cin >> n;

  if (n >= 7) {
    r1 = true;
  }
  
  string old_pass;
  cin >> old_pass;

  for (char c : old_pass) {
    if (c == '#' || c == '@' || c == '*' || c == '&') r5 = true;
    else if ( 65 <= c && c <= 90) {
      r2 = true;
    } else if (97 <= c && c <= 122) {
      r3 = true;
    } else if ('0' <= c &&  c <= '9') {
      r4 = true;
    }
  }

  string new_pass = old_pass;
  if (r1 && r2 && r3 && r4 && r5);
  else {
    if (!r2) new_pass.push_back('A');
    if (!r3) new_pass.push_back('a');
    if (!r4) new_pass.push_back('1');
    if (!r5) new_pass.push_back('#');

    if (!r1) {
      int diff = 7 - new_pass.length();
      if (diff > 0) {
	for (int i = 0; i < diff; i++) {
	  new_pass.push_back('C');
	}
      }
    }
  }
  cout << "Case #" << no << ": " << new_pass << '\n';
}

int main() {
  // brute force
  int N;
  cin >> N;

  int i = 1;
  while (i <= N) {
    test_case(i);
    i++;
  }
}
