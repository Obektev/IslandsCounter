
#include <bits/stdc++.h>
#include <chrono>
#include <Windows.h>

using namespace std;

#include "IslandGenerator.h"

class Solution {
public:
    vector<vector<char>> m;
    vector<vector<int>> used;

    bool isValidCord(int x, int y) {
        return x >= 0 && x < m.size() && y >= 0 && y < m[0].size();
    }

    bool isValid(int x, int y) {
        return isValidCord(x, y) && !used[x][y] && m[x][y] == '1';
    }

    long perimeter = 0;

    void goMatrix(int x, int y) {
        if (used[x][y])
            return;
        used[x][y] = 1;


        if (isValid(x - 1, y))
            goMatrix(x - 1, y);
        if (isValid(x + 1, y))
            goMatrix(x + 1, y);
        if (isValid(x, y - 1))
            goMatrix(x, y - 1);
        if (isValid(x, y + 1))
            goMatrix(x, y + 1);
    }

    void printMatrix(int x, int y) {
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if (i == x && y == j) {
                    printf("\033[46m \033[m", i, i);
                    continue;
                }
                if (m[i][j] == '1' && !used[i][j])
                    printf("\033[47m \033[m", i, i);
                else
                    if (m[i][j] == '1')
                        printf("\033[42m \033[m", i, i);
                    else
                        printf("\033[41m \033[m", i, i);
            }
            cout << endl;
        }
        Sleep(200); // Change it to speed up code
        system("cls");
    }

    int numIslands(vector<vector<char>>& m) {
        this->m = m;

        this->used = vector<vector<int>>(m.size(), vector<int>(m[0].size(), 0));

        //printMatrix();
        //return 1;
       
        int res = 0;

        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if (m[i][j] == '1' && !used[i][j]) {
                    goMatrix(i, j);
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution A;
    IslandGenerator Generator;
    vector<vector<char>> test = Generator.generateIslands(30, 20, '0', '1');
    cout << endl << ' ' << A.numIslands(test);
    return 0;
}
