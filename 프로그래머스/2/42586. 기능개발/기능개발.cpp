#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); ++i)
    {
        int p = 100 - progresses[i];
        int day = p / speeds[i];
        if( p % speeds[i] != 0)
        {
            ++day;
        }
        q.push(day);
    }
    int deployDay = 0;
  
    while(!q.empty())
    {
        int count = 1;
        deployDay = q.front();
        q.pop();
        while(q.front() <= deployDay && !q.empty())
        {
            q.pop();
            ++count;         
        }
        answer.emplace_back(count);        
    }   
    
    return answer;
}