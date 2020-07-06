#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int>nums(n + 1, 1);//인덱스를 학생번호로 사용하여 체육복 개수 저장(1로 초기화)
	for (int i = 1; i < nums.size(); i++) {//1번부터 n번까지 확인
		for (int j = 0; j < lost.size(); j++) {
			if (lost[j] == i)//i번학생이 도난당했다면
				nums[i]--;//i번학생의 체육복 수 감소
		}
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] == i) {
				nums[i]++;//도난당했던 애였으면 여분 덕에 다시 1개가 되었음
			}
		}
	}//도난과 여분 합쳐서 학생 체육복수 업데이트 완료

	//이제 0개인 애 해결해주기(주변 애가 2개인지 확인)
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == 0) {//내가 0개면 내 주변 확인
			if (i - 1 >= 1) {
				if (nums[i - 1] == 2) {//빌려오기
					nums[i - 1]--;
					nums[i]++;
				}
			}
			if (nums[i] == 0 && i + 1 <= n) {//아직 자기 앞한테 못 빌려 받았다면 자기 뒷번호 확인
				if (nums[i + 1] == 2) {
					nums[i + 1]--;
					nums[i]++;
				}
			}
		}
	}

	//최종
	for (int i = 1; i < nums.size(); i++) {//1번부터 n번까지
		if (nums[i] >= 1) {//체육복 1개 이상이면
			answer++;
		}
	}

	return answer;
}