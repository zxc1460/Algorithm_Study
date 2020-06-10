#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	bool flag = true;
	
	for(int i = 0; i < numbers.size(); i++) {
		if(numbers[i] > 0) {
			flag = false;
			break;
		}
	}
	if(flag) return "0";
	
    string answer = "";
    vector<string> v;
    
    for(int num : numbers) {
    	v.push_back(to_string(num));
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(string s : v) answer += s;
    
    return answer;
}
