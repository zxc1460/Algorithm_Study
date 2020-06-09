#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.resize(heights.size());

    for(int i = heights.size() - 1; i >= 0; i--) {
        int loc = -1;

        for(int j = i - 1; j >= 0; j--) {
            if(heights[j] > heights[i]) {
                loc = j + 1;
                break;
            }
        }

        answer[i] = loc != -1 ? loc : 0;
    }


    return answer;
}

int main() {
    vector<int> answer = solution({3, 9, 9, 3, 5, 7, 2});

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}