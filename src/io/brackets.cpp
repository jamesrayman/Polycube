#include <bits/stdc++.h>

#include "format.h"
#include "exact_cover.h"

using namespace std;

int h = 7, w = 7;

// first element is the set of black squares
vector<vector<char>> brackets;

vector<vector<char>> display;

void print_display() {
    for (auto& r : display) {
        for (auto c : r) {
            cout << format::cube(c, true);
        }
        cout << "\n";
    }
}

void add_to_display(const vector<char>& bv, char c) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (bv[i*w + j]) {
                display[i][j] = c;
            }
        }
    }
}

void display_solution(const vector<int>& solution) {
    display = vector<vector<char>>(h, vector<char>(w, 30));

    char c = 0;
    if (solution[0] != 0) {
        c++;
    }
    for (auto& i : solution) {
        add_to_display(brackets[i], c);
        c++;
    }

    print_display();
}

void init_brackets() {
    brackets.push_back(vector<char>(h*w, false));

    for (int i = 0; i < h; i++) {
        for (int I = i+1; I < h; I++) {
            for (int j = 0; j < w; j++) {
                for (int J = j+1; J < w; J++) {
                    // vertical left spine
                    if (I-i >= 2) {
                        vector<char> bracket (h*w, false);
                        for (int k = i; k <= I; k++) {
                            bracket[k*w + j] = true;
                        }
                        for (int k = j; k <= J; k++) {
                            bracket[i*w + k] = true;
                            bracket[I*w + k] = true;
                        }
                        brackets.push_back(bracket);
                    }
                    // vertical right spine
                    if (I-i >= 2) {
                        vector<char> bracket (h*w, false);
                        for (int k = i; k <= I; k++) {
                            bracket[k*w + J] = true;
                        }
                        for (int k = j; k <= J; k++) {
                            bracket[i*w + k] = true;
                            bracket[I*w + k] = true;
                        }
                        brackets.push_back(bracket);
                    }
                    // horizontal top spine
                    if (J-j >= 2) {
                        vector<char> bracket (h*w, false);
                        for (int k = j; k <= J; k++) {
                            bracket[i*w + k] = true;
                        }
                        for (int k = i; k <= I; k++) {
                            bracket[k*w + j] = true;
                            bracket[k*w + J] = true;
                        }
                        brackets.push_back(bracket);
                    }
                    // horizontal bottom spine
                    if (J-j >= 2) {
                        vector<char> bracket (h*w, false);
                        for (int k = j; k <= J; k++) {
                            bracket[I*w + k] = true;
                        }
                        for (int k = i; k <= I; k++) {
                            bracket[k*w + j] = true;
                            bracket[k*w + J] = true;
                        }
                        brackets.push_back(bracket);
                    }
                }
            }
        }
    }
}

void add_black_square(int p) {
    brackets[0][p] = true;

    for (int i = 1; i < brackets.size(); i++) {
        if (brackets[i][p]) {
            brackets[i] = vector<char>(h*w, false);
        }
    }
}

int main() {
    init_brackets();
    add_black_square(27);
    add_black_square(48);

    auto solutions = exact_cover::solve(brackets, 2, exact_cover::Method::dlx);

    cout << format::countable(solutions.size(), "solution") << ".\n";

    for (auto& solution : solutions) {
        cout << "\n";
        display_solution(solution);
    }

    return 0;
}
