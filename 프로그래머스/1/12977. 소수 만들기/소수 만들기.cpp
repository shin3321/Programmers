#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int prime)
{
    for(int i = 2; i *i <= prime; ++i)
    {
        if(prime % i == 0)
            return false;
    }
    return true;
}
    

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
     for(int i = 0 ; i < nums.size() -2; ++ i)
     {
         for(int j = i+1; j < nums.size() -1; ++j)
         {
             for(int k = j+1; k < nums.size(); ++k)
             {
                 sum = nums[i] + nums[j] + nums[k];
                     cout << sum << endl;
                 if(isPrime(sum))
                 {
                     ++answer;
                 }
             }
         }
     }
    return answer;
}