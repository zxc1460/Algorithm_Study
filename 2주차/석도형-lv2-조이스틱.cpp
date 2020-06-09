#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    //레버를 위아래로만 움직였을 때 최솟값 
    for (auto ch : name) {
        answer += min(ch - 'A', 'Z' - ch + 1);
   }
    
    // 왼쪽오른쪽으로 움직이는 것의 최솟값. 
   int len = name.size();
    
   int horizontal_move = len - 1;
    
    //i는 오른쪽으로 움직이는 횟수
   //i번쨰 위치까지 오른쪽으로 움직이고 i번쨰부터 다시 왼쪽으로 움직임.
   //last_idx는 왼쪽으로 움직였을 때 마지막으로 확인해야할 위치값.
   // 즉 중간에 연속된 A가 껴있는 경우 그 연속된 A를 제외하고 나머지 위치들에서만 움직이는 것이다.
   // 
    for (int i = 0; i < len; ++i) {
        int last_index = i + 1;
        while (last_index < len && name[last_index] == 'A') {   
            last_index++;
       }
       //last_index가 문자열과 같아지면 결국 왼쪽으로 꺾지 않고 오른쪽으로 i까지만 움직이면 된다는 소리.
      //그게 아니라면 i만큼 오른쪽으로 움직이고 다시 i만큼 왼쪽으로 움직이고 len-last_index만큼 끝에서 last_index까지 움직여줘야 한다. 
        if(last_index == len) {
            horizontal_move = min(horizontal_move, i);
        } else {
            horizontal_move = min(horizontal_move, (i * 2) + (len - last_index));
        }
       
    }
    answer += horizontal_move;
    
    return answer;
}
