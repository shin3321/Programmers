#include <string>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    for(int i = 0; i < progresses.size(); ++i)
    {
        int progress = 100 - progresses[i];
        int day = progress/speeds[i];
        if(progress%speeds[i]!=0)
        {
            ++day;
        }
        days.push(day);
    }
    
    int deployDay = 0;
    while(!days.empty())
    {
        int count = 1;
        deployDay = days.front();
        days.pop();
        while(deployDay >= days.front() && !days.empty())
        {
            days.pop();
            ++count;
        }
        answer.emplace_back(count);
    }
         
    return answer;
}