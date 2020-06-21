#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> strs;
bool cmp(string a, string b){
    string c=  a+b;
    string d=  b+a;
    int Ic = std::stoi(c);
    int Id = std::stoi(d);
    return Ic < Id;
        
    
}

string solution(vector<int> numbers) {
    string answer = "";
    for(int i=0; i<numbers.size(); ++i){
        strs.push_back(to_string(numbers[i]));
    }
    sort(strs.begin(), strs.end(), cmp);
    for(int i=0; i< strs.size(); ++i){
        answer = strs[i] + answer;
    }
    if(answer[0] =='0'){
        return "0";
    }
    return answer;
}
