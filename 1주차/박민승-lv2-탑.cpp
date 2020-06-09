#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    stack<int> st;
    for(int i=heights.size()-1; i>=0; --i){
        while(!st.empty() && heights[st.top()] < heights[i]){
            answer[st.top()] = i+1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        answer[st.top()] = 0;
        st.pop();
    }
    return answer;
}