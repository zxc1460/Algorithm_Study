#include <bits/stdc++.h>
using namespace std;

int result1[]={1,2,3,4,5};
int result2[]={2,1,2,3,2,4,2,5};
int result3[]={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3]={0,0,0}; //1,2,3번 사람들의 정답개수 카운트
    int maxScore=0;
    for(int i= 0; i<answers.size(); i++){
        if(answers[i] == result1[i%5]) score[0]++;
        if(answers[i] == result2[i%8]) score[1]++;
        if(answers[i] == result3[i%10]) score[2]++;
    }
    
    maxScore = max(max(score[0],score[1]),score[2]);
    
    for(int i= 0; i<3; i++){
        if(maxScore == score[i]) answer.push_back(i+1);
    }
     
    return answer;
}
