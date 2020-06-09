#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int open=0;
    int close=0;
    for(int i=0; i<arrangement.size(); i++){
        if(arrangement[i]== '('){
            ++open;
            cout<<open<< " ";
        }
        else{
            if(arrangement[i-1]=='('){ //만약 바로 앞이 ( 면 레이저
                --open; //레이저의 ( 개수는 빼주기
                answer+=open;
                cout<<"a : "<<answer<<endl;
                open-=close;
                close=0;
            }
            else{
                ++close; //닫은거 count
            }
        }
    }
    return answer;
}
