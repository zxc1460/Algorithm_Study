#include <string>
#include <vector>
#include <stack>
using namespace std;

int findBar(vector<int> bar, int start, int end){
    int bar_num = 0;
    for(int i= start; i<=end; ++i){
        if(bar[i] == 1){
            bar_num++;
        }
    }
    return bar_num;
}

int solution(string arrangement) {
    int answer = 0;
    stack<int> st;
    int strsize = arrangement.size();
    vector<int> bar(strsize, 0);
    for(int i=0; i<strsize; ++i){
        if(arrangement[i] == '('){
            st.push(i);    
        }else{
            if((i-st.top())==1){
                bar[i] = 1;
                st.pop();
            }else{
                int bar_num = findBar(bar, st.top(), i);
                answer += bar_num+1;
                st.pop();
            
            }
          
        }
    }
    return answer;
}