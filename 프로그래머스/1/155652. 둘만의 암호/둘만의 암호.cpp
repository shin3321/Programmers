#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(char c: s)
    {
        for(int i = 0; i < index;)
        {
            ++c;
            if(c > 'z')
            {
                c = 'a';
            }
            if(skip.find(c)!= string::npos)
            {
                // skip에 포함된 문자  
           }            
            else 
            {
                ++i;
            }          
          
        }
        answer += c;
    }
    return answer;
}