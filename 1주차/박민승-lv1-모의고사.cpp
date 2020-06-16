#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
   vector<int> first = { 1,2,3,4,5 };
	vector<int> second = { 2,1,2,3,2,4,2,5 };
	vector<int> third = { 3,3,1,1,2,2,4,4,5,5 };
	int num_f = 0, num_s = 0, num_t = 0;
	vector<pair<int,int>> nums;
	int idx=0;
	for (int i = 0; i < answers.size(); i++) {
	
		if (first[idx] == answers[i]) {
			num_f++;
		}
		idx++;
		if (idx == first.size()) {
			idx = 0;
		}
		
	}
	idx = 0;
	for (int i = 0; i < answers.size(); i++) {

		if (second[idx] == answers[i]) {
			num_s++;
		}
		idx++;
		if (idx == second.size()) {
			idx = 0;
		}
	}
	idx = 0;
	for (int i = 0; i < answers.size(); i++) {

		if (third[idx] == answers[i]) {
			num_t++;
		}
		idx++;
		if (idx == third.size()) {
			idx = 0;
		}
	}
	nums.push_back(make_pair(num_f, 1));
	nums.push_back(make_pair(num_s,2));
	nums.push_back(make_pair(num_t,3));
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	
	bool ok = true;
	idx = 0;
	while (ok) {
		answer.push_back(nums[idx].second);
		if (idx + 1 == nums.size()) {
			break;
		}
		if (nums[idx].first != nums[idx + 1].first) {
			ok = false;
		}
		else {
			idx++;
			
		}
	} 
	sort(answer.begin(), answer.end());



    return answer;
}
