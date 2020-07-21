#include <string>
#include <vector>
#include<iostream>
using namespace std;
int col[13];
int answer = 0;
bool check(int n, int row){
    for(int i=1; i<row; i++){
        if(col[row]==col[i]) return false;
        if(abs(i-row)==abs(col[i]-col[row])) return false;
    }
    return true;
}
void backtracking(int n,int row){
    if(row>n){
        ++answer;
    }else{
        for(int i=1; i<=n; i++){
            col[row]=i;
            if(check(n,row)){
                backtracking(n,row+1);
            }else{
                col[row]=0;
            }
        }
    }
}
int solution(int n) {

    backtracking(n,1);
    
    return answer;
}