#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M)
{
    int answer = 0;
    sort(budgets.begin(), budgets.end());
    int left = 1, right = budgets.back();

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int sum = 0;
        for (auto a : budgets)
        {
            if (a < mid)
                sum = sum + a;
            else if (a >= mid)
                sum = sum + mid;
        }
        if (M >= sum)
        {
            //상한가 보다 작을 때
            left = mid + 1;
            answer = max(answer, mid);
        }
        else if (M < sum)
        {
            right = mid - 1;
        }
    }
    return answer;
}