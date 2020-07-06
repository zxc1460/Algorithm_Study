#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());//사전순서(숫자크기순x)
	int l;
	for (int i = 0; i < phone_book.size() - 1; i++) {
		string str1 = phone_book[i];
		string str2 = phone_book[i + 1];
		string st;
		if (str1.length() <= str2.length())
			l = str1.length();
		else
			l = str2.length();
		bool same = true;//다른 문자가 하나라도 있으면 false될거야
		for (int j = 0; j < l; j++) {
			if (str1[j] - '0' != str2[j] - '0') {//하나라도 다르면
				same = false;
				break;
			}
		}
		if (same) {//접두어 같은문자가 있다면
			answer = false;
			break;
		}
	}

	return answer;
}