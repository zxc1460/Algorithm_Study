#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> parent;
int getParent(int x)
{
    if (x == parent[x])
        return x;
    else
    {
        parent[x] = getParent(parent[x]);
        return parent[x];
    }
}
void unionParent(int x, int y)
{
    x = getParent(x);
    y = getParent(y);
    if (x > y)
        parent[x] = y;
    else
        parent[y] = x;
}
int find(int x, int y)
{
    x = getParent(x);
    y = getParent(y);
    if (x == y)
        return 1;
    else
        return 0;
}
bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    sort(costs.begin(), costs.end(), compare); // 어떻게 비용기준으로 정렬되는지?

    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }

    for (int i = 0; i < costs.size(); i++)
    {
        if (!find(costs[i][0], costs[i][1]))
        {
            answer += costs[i][2];
            unionParent(costs[i][0], costs[i][1]);
        }
    }

    return answer;
}