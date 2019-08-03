#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

extern vector<string> anagram(string);

void printAnagram(string word) {
    vector<string> res;

    cout << endl;
    cout << "Anagrams:" << endl;
    res = anagram(word);
    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    string input = "", c, line;
    ifstream infile("testCase.txt");

    if (argc == 1) {
        cout << "Running local test cases." << endl;
        while (getline(infile, line)) {
            cout << "word:" << endl;
            cout << line << endl;
            printAnagram(line);
        }
    } else if (argc == 2) {
        cout << "Testing manually." << endl;
        input = argv[1];
        do {
            if (input == "") {
                cout << "Enter a set characters, solve your anagrams." << endl;
                cin >> input;
            }
            printAnagram(input);
            input = "";
            do {
                cout << "Press C continue wordAnagram, press Q to quit." << endl;
                cin >> c;
                if (c.size() != 1) continue;
                c[0] = tolower(c[0]);
            } while (c!="c" && c!="q");
        } while (c == "c");
    }

    return 0;
}
