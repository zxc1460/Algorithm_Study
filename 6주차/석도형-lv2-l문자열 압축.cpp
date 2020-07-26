#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i <= (s.size() / 2); i++) {
    	vector<string> temp;
    	for(int j = 0; j < s.size(); j += i) {
    		if(j + i < s.size()) temp.push_back(s.substr(j, i));
    		else temp.push_back(s.substr(j));
    	}
    	
    	int cnt = 1;
    	string cur = temp.front();
    	string result = "";
    	
    	for(int j = 1; j < temp.size(); j++) {
    		if(temp[j] == cur) cnt++;
    		else {
    			if(cnt > 1) result += to_string(cnt);
    			result += cur;
    			cnt = 1;
    			cur = temp[j];
    		}
    	}
    	
    	if(cnt > 1) result += to_string(cnt);
    	result += cur;
		
		answer = min(answer, (int)result.size());    	
    	
	}
    
    return answer;
}
