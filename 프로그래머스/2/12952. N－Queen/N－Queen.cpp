#include <string>
#include <vector>

using namespace std;

bool isSafe(int col, int row, vector<int>& board)
{
    for(int i = 0; i < row; ++i)
    {
        if(board[i] == col)
        {
            return false;
        }
        if(abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void dfs(int n, int row, int& answer, vector<int>& board)
{
    // 열이 최대 행까지 돌았으면 완성된 것임
    if(row == n)
    { ++answer;
     return;
    }
    
    for(int col = 0; col < n; ++col)
    {
        board[row] = col;
        // row에 퀸을 놓을 수 있는지 확인
        if(isSafe( col, row, board))
        {
            // 퀸을 놓았으면 row 한 줄 추가해서 돌리기
            dfs(n, row + 1, answer, board);
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> board(n, -1);
    // 보드판을 돌면서
    // 보드 행에 퀸이 들어간 열 자리를 확인
    dfs(n, 0, answer,board);
    
    return answer;
}