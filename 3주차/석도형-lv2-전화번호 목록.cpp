#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

bool solution(vector<string> phone_book) {
    // 해쉬맵으로 문제 풀이
    // 전화번호를 key값으로 하여 전화번호부에 있는 모든 전화번호 해쉬맵에 value값을 1로 저장
    // 각 전화번호의 크기보다 작은 부분문자열이 해쉬맵에 존재하면 접두어인 것
    unordered_map<string, int> dict;

    for(string number : phone_book) dict[number] = 1;

    for(string number : phone_book) {
        for(int i = 1; i < number.size(); i++) {
            if(dict[number.substr(0, i)] == 1) {
                return false;
            }
        }
    }

    return true;
}