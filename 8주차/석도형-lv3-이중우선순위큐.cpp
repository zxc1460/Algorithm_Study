#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(string str : operations) {
        char op = str[0];
        int num = stoi(str.substr(2));

        if(op == 'I') {
            min_heap.push(num);
            max_heap.push(num);
        } else {
            if(num == 1) {
                if(max_heap.empty()) continue;
                if(!min_heap.empty() && min_heap.top() == max_heap.top()) min_heap.pop();
                max_heap.pop();
            } else {
                if(min_heap.empty()) continue;
                if(!max_heap.empty() && max_heap.top() == min_heap.top()) max_heap.pop();
                min_heap.pop();
            }
        }

        
        if(min_heap.empty() || max_heap.empty()) {
            while(!max_heap.empty()) max_heap.pop();
            while(!min_heap.empty()) min_heap.pop();
        }
    }

    if(max_heap.empty()) answer = {0, 0};
    else answer = {max_heap.top(), min_heap.top()};

    return answer;
}