#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;

	vector<bool> era = vector<bool>(n + 1, true);
	for (int i = 2; i <= n; ++i) {
	
		if (era[i] == true) {
	
			answer++;
			for (int j = i+i; j <= n; j = j + i) {
				era[j] = false;
			}
		}
	}


    return answer;
}
