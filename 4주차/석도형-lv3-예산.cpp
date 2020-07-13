#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    int left = 1;
    int right = 100000;
    long long sum = 0;
    int result = 0;
    for(int num : budgets) {
        sum += num;
        result = max(result, num);
    }

    if(sum <= M) return result;

    while(left <= right) {
        int mid = (left + right) / 2;
        sum = 0;

        for(int num : budgets) {
            if(num > mid) sum += mid;
            else sum += num;
        }

        if(sum > M) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}