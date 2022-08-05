/*
 * 1A Theatre Square
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    unsigned long long n,m,a;
    cin >> n >> m >> a;
    unsigned long long value=ceil((double)m/a)*ceil((double)n/a);

    cout<<value;
    return 0;
}
