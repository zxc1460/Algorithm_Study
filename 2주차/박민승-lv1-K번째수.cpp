#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); ++i) {
		vector<int> tmp;
		for (int j = 0; j < array.size(); ++j) {
			if (j >= commands[i][0] - 1 && j <= commands[i][1] - 1) {
				tmp.push_back(array[j]);
			}
		}
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[commands[i][2] - 1]);
	}


    return answer;
}
