#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<string> temp = {"ICN", "ATL", "SFO", "ATL", "ICN", "SFO"};
	vector<string> answer = {"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"};
	
	if(temp < answer) answer = temp;
	
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	
	cout << '\n';
	
}
