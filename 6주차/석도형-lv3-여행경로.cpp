#include <string>
#include <vector>

using namespace std;

void dfs(string cur, vector<string> temp, vector<string> &answer, vector<vector<string>> &tickets) {
	if(temp.size() == tickets.size() + 1) {
		if(answer.empty() || temp < answer) answer = temp;
		return;
	}
	
	for(int i = 0; i < tickets.size(); i++) {
		if(tickets[i][0] == cur) {
			tickets[i][0] = "done";
			temp.push_back(tickets[i][1]);
			
			dfs(tickets[i][1], temp, answer, tickets);
			
			temp.pop_back();
			tickets[i][0] = cur;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    dfs("ICN", {"ICN"}, answer, tickets);
    
    return answer;
}
