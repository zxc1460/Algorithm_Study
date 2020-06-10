#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define MAX 9999999999
using namespace std;
bool isPrime(int number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    bool isPrime = true; //소수인지 아닌지 판별
// 몫,나누는 수 둘중 하나는 반드시 N제곱근 이하이기 때문.제곱근까지만 해보면 소수판별 가능
    for (int i = 2; i <= sqrt(number); i++) {
        if (number% i == 0)
            return false;
    }
    return isPrime;
}
bool compare(char a, char b)
{
    return a > b; //내림차순
}
int solution(string numbers) {
    int answer = 0;
    string temp;
    temp = numbers;
    sort(temp.begin(), temp.end(),compare); //ex)temp가 string "1234"면 한 후엔 "4321"됨
    vector<bool> prime(std::stoi(temp)+1); 
    cout << "stoi(temp) : "<<stoi(temp) << endl;
    prime[0] = false; 
    for (long long i = 1; i < prime.size(); i++)
    {
        prime[i] = isPrime(i);
    }
    //cout << "chk1" << endl;
    //int num = std::stoi(numbers);
    string s, sub;
    s = numbers;
    sort(s.begin(), s.end());
    set<int> primes;
    int l = s.size();
    do {
        for (int i = 1; i <= l; i++)
        {
            sub = s.substr(0, i);
        //  cout << "chk2" <<  " " << sub<<  endl;
            if (prime[std::stoi(sub)])
            {
                primes.insert(std::stoi(sub));
            }
        }
    } while (next_permutation(s.begin(), s.end()));
    //cout << primes.size();
    answer = primes.size();
    return answer;
}
