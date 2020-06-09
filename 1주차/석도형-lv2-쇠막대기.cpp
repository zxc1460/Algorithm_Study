#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> st;

    for(int i = 0; i < arrangement.size(); i++) {
        if(arrangement[i] == '(') {
            st.push(1);
        } else {
            if(arrangement[i - 1] == '(') {
                st.pop();
                answer += st.size();
            } else {
                answer++;
                st.pop();
            }
        }
    }

    return answer;
}

int main() {
    cout << solution("()(((()())(())()))(())") << '\n';

    return 0;
}