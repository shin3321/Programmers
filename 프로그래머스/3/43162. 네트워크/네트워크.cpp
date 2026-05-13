#include <string>
#include <vector>
#include <queue>

using namespace std;

void dfs(int current, int n, vector<vector<int>>& computers, vector<bool>& visited)
{
    visited[current] = true;
    for(int next = 0; next < n; ++next)
    {
        if(next != current && computers[current][next] == 1 && !visited[next])
        {
            dfs(next, n, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; ++i)
    {
        if(!visited[i])
        {
            ++answer;
            dfs(i, n, computers, visited);
        }
    }
    return answer;
}