#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 1001;
    int cnt, loc;
    for (int i = 1; i < s.length(); i++) {  //i는 반복되는 길이
        string comp = "";
        bool isIter = false;
        for (int j = 0; j < s.length(); j = j + loc) {
            string temp = s.substr(j, i);
            cnt = 1;
            loc = cnt * i;
            for (int k = j + i; k < s.length(); k = k + i) {
                if (temp == s.substr(k, i)) {
                    cnt++;
                    loc = cnt * i;
                    isIter = true;
                    //반복되면 반복되지 않는 숫자까지 +자리 설정
                    continue;
                } else {
                    break;
                }
            }
            if (cnt != 1)
                comp += to_string(cnt) + s.substr(j, i);
            else
                comp += s.substr(j, i);
            cout << comp << endl;
        }
        cout << comp << endl;
        int leng = comp.length();
        answer = min(answer, leng);
    }
    return answer;
}