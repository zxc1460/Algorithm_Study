#include <string>
#include <vector>
bool check[201];
using namespace std;
vector<vector<int>> net(201);
//먼저 공간을 할당해주지 않으면 할당되지 않은 배열을 참조하기 때문에 오류가난다!
void dfs(int start){
    check[start]=true;
    for(int i=0; i<net[start].size(); i++){
        int y=net[start][i];
        if(check[y]==false){
            dfs(y);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j]==1&&i!=j){
                net[i].push_back(j);
                net[j].push_back(i);
            }
        }
    }

   for(int i=0; i<n; i++){
        if(check[i]==false){
            dfs(i);
            answer++;
        }
    }
    return answer;
}