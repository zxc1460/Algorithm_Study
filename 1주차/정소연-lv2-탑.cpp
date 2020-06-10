#include <string>
#include <vector>

using namespace std; 

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    int max=0;
     for(int i=0; i<heights.size(); i++){ //가장 높은 탑 찾 기 
         if(heights[i]>max){
             max = heights[i];
         }
     }
    answer.push_back(0);
    for(int i=1; i<heights.size(); i++){
        for(int j=i; j>0; j--){
            if(heights[i]==max){ //탑이 최대라면 0 
                answer.push_back(0);
                break;
            }
            else if(heights[i] < heights[j-1]){ //전 탑이 더 크면 전탑의 index 넣기 
                answer.push_back(j);
                break;
            }
            else if(j-1 == 0 ){ //맨 앞수면 0 
                answer.push_back(0);
                break;
            }
            
        }
    }
    return answer;
}
