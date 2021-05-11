// 
// Created by Angold4 on 21-3-15
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int eval(int a, int b, char op){
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return -1;
}

int main(){
    map<int, string> ans;
    map<int, char> m;
    m[0] = '*';
    m[1] = '/';
    m[2] = '+';
    m[3] = '-';

    // Because there are three ops so there are i*j*k -- total 4*4*4 combinations to represent them
    // caculate all cases of this combinations
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                vector<int> nums = {4,4,4,4};
                vector<char> ops = {m[i],m[j],m[k]};
                for(size_t it = 0; it < ops.size(); ++it){        
                    if(ops[it] == '*' || ops[it] == '/'){               // First iterate through operands and execute * and /
                        nums[it] = eval(nums[it], nums[it+1], ops[it]); // That is because no matter what the sequence of three op; * and / are first to caculate
                        nums.erase(nums.begin()+it+1);                  // delete the used number and store the temp answer in nums[0]
                        ops.erase(ops.begin()+it);                      // delete the used op (combinations)
                        --it;                                           // key point
                    }
                }

                for(size_t it = 0; it < ops.size(); ++it){              // Then iterate through again and execute remaining operands (+ and -) (the remaining ops)
                    nums[it] = eval(nums[it], nums[it+1], ops[it]);     // same as before
                    nums.erase(nums.begin()+it+1);
                    ops.erase(ops.begin()+it);
                    --it;
                }
                ans[nums[0]] = "4 " + string(1,m[i]) + " 4 " + string(1,m[j]) + " 4 " + string(1,m[k]) + " 4 = " + to_string(nums[0]); //Answer string
            }
        }
    }

    int mm;
    cin >> mm;
    while(mm--){
        int nn;
        cin >> nn;
        if(ans.find(nn) != ans.end()){
            cout << ans[nn] << endl;
        } else {
            cout << "no solution" << endl;
        }
    }


    return 0;
}
