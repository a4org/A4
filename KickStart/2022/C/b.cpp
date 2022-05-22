#include <vector>
#include <iostream>

using namespace::std;

vector<int> ret = {};

bool isSubsetSum(int num, int sum, vector<int> rets) {
  // Termination Condition
  if (sum == 0) {
    // assign to this global variable
    ret = rets;
    return true;
  }
  if (num == 0)
    // we cannot find the answer
    return false;
  
  if (num > sum) {
    // do not pick that
    return isSubsetSum(num-1, sum, rets);
  }

  // else check if sum can be obtained by any of the following:
  // (1) including current element
  // (2) excluding current element
  vector<int> ret1 = rets; ret1.push_back(num);
  vector<int> ret2 = rets;

  return isSubsetSum(num-1, sum-num, ret1) || isSubsetSum(num-1, sum, ret2);
}

void test_case(int no) {
  double n;
  cin >> n; 

  double sum = ((1 + n) * n) / 2;
  ret = {};

  int X, Y;
  cin >> X >> Y;

  // math problem
  double di = sum * X / (X + Y);

  int id = (int) di;

  if (di != id) {
    cout << "Case #" << no << ": IMPOSSIBLE" << '\n';
    return;
  }
  
  // possible then we want to find the id (partition)
  // recursion
  
  if (isSubsetSum(n, id, ret)) {
    cout << "Case #" << no << ": POSSIBLE" << '\n';
    cout << ret.size() << '\n';
    for (int i : ret) {
      cout << i << " ";
    }
    cout << '\n';
    return;
  } else {
    cout << "Case #" << no << ": IMPOSSIBLE" << '\n';
    return;
  }
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
