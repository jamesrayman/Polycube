#include <bits/stdc++.h>

#include "format.h"
#include "exact_cover.h"

using namespace std;

bool uniq (string s) {
    sort(s.begin(), s.end());
    return unique(s.begin(), s.end()) == s.end();
}

vector<char> bv (const string& word) {
    vector<char> res (27);
    for (char c : word) {
        res[c - 'a'] = true;
    }
    return res;
}

int main () {
    ifstream f ("words_alpha.txt");
    string word;

    vector<string> words;
    vector<vector<char>> bitvs;

    while (f >> word) {
        if (word.size() == 5 && uniq(word)) {
            words.push_back(word);
            bitvs.push_back(bv(word));
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        bitvs.push_back(bv(string("{")+c));
    }

    auto ans = exact_cover::solve(bitvs, 1000, exact_cover::Method::dlx);

    cout << format::countable(ans.size(), "solution") << ".\n";

    for (auto& sol : ans) {
        cout << "--------\n";
        for (auto& w : sol) {
            if (w < words.size()) {
                cout << words[w] << "\n";
            }
        }
    }

    return 0;
}
