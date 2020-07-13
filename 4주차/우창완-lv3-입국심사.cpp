#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    long long answer = 0;
    long long max_time = (long long)times.back() * (long long)n, min_time = 1;

    while (min_time <= max_time)
    {
        long long mid = (min_time + max_time) / 2;
        long long sum = 0;
        //mid 시간을 돌릴수 있는 최대 인원 구하기
        for (auto a : times)
            sum += mid / a;
        if (sum >= n)
        {
            //최대 인원이 더 많을 경우 answer 초기화
            max_time = mid - 1;
            answer = mid;
        }
        //평균 걸리는 시간보다 더 적게 했을 경우
        else
            min_time = mid + 1;
    }
    return answer;
}