#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int scores[3];
vector<vector<int>> people;
int maxScore;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    people.resize(3);
    people[0] = {1, 2, 3, 4, 5};
    people[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    people[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++) {
    	if(answers[i] == people[0][i % 5]) scores[0]++;
    	if(answers[i] == people[1][i % 8]) scores[1]++;
    	if(answers[i] == people[2][i % 10]) scores[2]++;
	}
	
	maxScore = max(scores[0], max(scores[1], scores[2]));
	
	for(int i = 0; i < 3; i++) {
		if(scores[i] == maxScore) answer.push_back(i + 1);
	}
	
	sort(answer.begin(), answer.end());
    
    return answer;
}

int main() {
	vector<int> answer = solution({1, 2, 3, 4, 5});
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}

	cout << '\n';

	return 0;
}