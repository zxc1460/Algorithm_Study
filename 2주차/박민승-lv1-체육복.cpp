#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
	int escape_num = 0;
	int idx = 0;
	queue<int> q1;
	queue<int> q2;

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int i = 0; i < lost.size();++i) {
		for (int j = 0; j < reserve.size(); ++j) {
			if (lost[i] == reserve[j]) {
				lost[i] = -1;
				reserve[j] = -1;
				escape_num++;
				break;
			}
		}
	} 
	
	for (int i = 0; i < lost.size(); ++i) {
		if (lost[i] != -1) {
			q1.push(lost[i]);
		}
	}
	for (int j = 0; j < reserve.size(); ++j) {
		if (reserve[j] != -1) {
			q2.push(reserve[j]);
		}
	}

	while (!q1.empty() && !q2.empty()) {
		if (q1.front() == q2.front() - 1 || q1.front() == q2.front() + 1) {

			q1.pop(); q2.pop(); escape_num++;
		}
		else {
			if (q1.front() > q2.front()) {
				q2.pop();
			}
			else {
				q1.pop();
			}
		}
	}

	answer = n - (lost.size() - escape_num);
    return answer;
}
