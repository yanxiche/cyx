#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

string strlower(string word) {
    for (int i=0; i<word.size(); i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

vector<string> anagram(string word) {
    if (word == "") return {};
    ifstream infile("words.txt");
    string line, tmp;
    int ws = word.size();
    vector<string> res;

    word = strlower(word);
    sort(word.begin(), word.end());

    while (getline(infile, line)) {
        if (line.size() != ws) continue;
        tmp = line;
        tmp = strlower(tmp);
        sort(tmp.begin(), tmp.end());
        if (tmp == word) {
            res.push_back(line);
        }
    }

    return res;
}
