//
// Created by Angold4 on 21-3-17
//
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

/*
double tran3(double d) {
    double b = floor((d * pow(10, 5) + 0.5)) / pow(10, 5);
    return b;
}
*/

int main() {
    cout << endl;
    int i = 0; int j = 0; int t = 0; int cls = 0; int avg = 0;
    cin >> i;

    vector<double> asv;
    for (int k=0; k<i; k++) {
        cin >> t;   // number of student

        // init
        cls = 0;    // total grade(class)
        vector<int> vcls = {};

        for (int l=0; l<t; l++) {
            cin >> j;
            cls += j;
            vcls.push_back(j);
        }
        avg = cls / t;

        double count = 0;
        for (int g : vcls) {
            if(g > avg) count++;
        }
        double s = count / vcls.size();

        asv.push_back(s);
    }

    for (double av : asv) {
        cout << fixed << setprecision(3) << av*100 << "%" << '\n';
    }
}
