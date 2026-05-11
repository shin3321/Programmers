#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int index, int sum)
{
    if(index == numbers.size())
    {
        if(sum == target) return 1;
        else return 0;
    }
    int add = dfs(numbers, target, index + 1, sum + numbers[index]);
    int sub = dfs(numbers, target, index + 1, sum - numbers[index]);
    
    return add + sub;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int index = 0;
    int sum = 0;
    int count = 0;
    return dfs(numbers, target, index, sum);
}