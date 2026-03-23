#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    int alpha[26] = {0};
    for (char ch : str) {
        alpha[ch - 'A']++;
    }

    int oddCount = 0;
    int midIdx = -1;
    std::string half = "";

    for (int i = 0; i < 26; ++i) {
        if (alpha[i] % 2 != 0) {
            oddCount++;
            midIdx = i; // 홀수 개수인 알파벳의 인덱스 저장
        }
        
        // 어떤 경우든 절반만큼은 결과 문자열의 앞부분에 배치
        for (int j = 0; j < alpha[i] / 2; ++j) {
            half += (char)(i + 'A');
        }
    }

    // 팰린드롬 불가능 조건 (홀수가 2개 이상이면 안 됨)
    if (oddCount > 1) {
        std::cout << "I'm Sorry Hansoo";
        return 0;
    }

    std::string result = half;
    if (midIdx != -1) result += (char)(midIdx + 'A'); // 가운데 글자 추가
    std::reverse(half.begin(), half.end());
    result += half; // 뒤집은 절반 추가

    std::cout << result;

    return 0;
}