/*
 * 71A Way Too Long Words
 * Jiawei Wang
 * 15 May 2021
 */


#include <iostream>
#include <string>
#include <vector>

using namespace::std;

int main() {
    int number;

    cin >> number;
    vector<string> vWord;
    for (int i = 0; i < number; i++) {
	string word;
	cin >> word;
	if (word.length() > 10) {
	    char begin = word[0];
	    char end = word[word.length()-1];
	    string snum = to_string(word.length() - 2);
	    word = begin + snum + end;
	}
	vWord.push_back(word);
    }

    for (string s : vWord) {
	cout << s << endl;
    }

}
