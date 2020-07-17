#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File {
	string head;
	int number;
	string tail;
	int index;
};

bool cmp(File a, File b) {
	if(a.head == b.head) {
		if(a.number == b.number) return a.index < b.index;
		return a.number < b.number;
	}
	return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
	vector<File> temp;

	for(int i = 0; i < files.size(); i++) {
		string str = files[i];
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		string head = "";
		string number = "";
		string tail = "";
		int flag = 0;

		for(char c : str) {
			if(flag == 0) {
				if(c >= '0' && c <= '9') {
					flag = 1;
					number += c;
				} else {
					head += c;
				}
			} else if(flag == 1) {
				if(c >= '0' && c <= '9') {
					number += c;
				} else {
					flag = 2;
					tail += c;
				}
			} else {
				tail += c;
			}
		}

		temp.push_back({head, stoi(number), tail, i});
	}

	sort(temp.begin(), temp.end(), cmp);

	for(File f : temp) {
		answer.push_back(files[f.index]);
	}

    return answer;
}