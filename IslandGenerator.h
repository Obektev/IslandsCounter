#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

class IslandGenerator
{
public:
	template<typename T>
	vector<vector<T>> generateIslands(int x_size, int y_size, T empty_, T full_) {
		srand(time(NULL));
		vector<vector<T>> res(x_size, vector<T>(y_size, empty_));
		for (int i = 0; i < x_size; i++) {
			for (int j = 0; j < y_size; j++) {
				if (rand() % 2 == 0)
					res[i][j] = empty_;
				else
					res[i][j] = full_;
			}
		}
		return res;
	}
};
