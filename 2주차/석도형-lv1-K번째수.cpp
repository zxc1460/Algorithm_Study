#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int num : numbers) {
    	v.push_back(to_string(num));
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(string s : v) answer += s;
	
	if(answer.front() == '0') answer = "0";
    
    return answer;
}
