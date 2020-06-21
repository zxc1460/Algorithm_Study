#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0; 
    string tmp;
    for(int i=0; i<name.size(); ++i){
        tmp += 'A';
    }
    vector<int> visited(name.size(), 0);
    int standard = 0;

    visited[standard] = 1;
    if(name[standard] != 'A'){
  
        tmp[standard] = name[standard];
        if(name[standard] - 'A' > 13){
            answer += 26-(name[standard]- 'A');
        }else{ answer += (name[standard]-'A');}
    }
    while(name != tmp){
        int howMany = 0;
  
        int staLeft = standard-1, staRight = standard+1;
        howMany++;
        if(staLeft <0) staLeft= name.size()-1;
        if(staRight >= name.size()) staRight = 0;
      
        while((visited[staLeft]!=0||name[staLeft]=='A')&&(visited[staRight]!=0 || name[staRight] == 'A')){
            howMany++;
            staLeft--; staRight++; 
            if(staLeft <0) staLeft= name.size()-1;
            if(staRight >= name.size()) staRight = 0;        
        }
        if(visited[staLeft] ==0 && name[staLeft] != 'A') standard = staLeft;
        if(visited[staRight] == 0 && name[staRight] != 'A') standard = staRight;
        
        tmp[standard] = name[standard];
        visited[standard] = 1;
        if(name[standard] - 'A' > 13){
            answer += 26-(name[standard]- 'A');
        }else{ answer += name[standard]-'A';}
        answer+= howMany;

              
    }
        
        
        
     
    
    return answer;
}
