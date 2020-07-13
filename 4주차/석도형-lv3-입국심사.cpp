#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = 100000000000000;

    while(left <= right) {
        long long sum = 0;
        long long mid = (left + right) / 2;

        for(int t : times) {
            sum += mid / t;
        }

        if(sum >= n) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}