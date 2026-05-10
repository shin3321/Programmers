#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> ootd;
    string type;
    
    for(int i = 0; i < clothes.size(); ++i)
    {      
        type = clothes[i][1];
        ++ootd[type];
    }
    
    int count = 0;
    for(auto& o : ootd)
    {
        count = o.second;
        answer *= count + 1;
    }
    
    
    return answer - 1;
}