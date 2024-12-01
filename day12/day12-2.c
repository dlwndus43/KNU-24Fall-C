#include <iostream>
using namespace std;

int solution(int n) {
    int batteryUsage = 0; // 건전지 사용량을 나타낼 변수

    while (n > 0) {
        // 현재 위치가 짝수인 경우 순간이동
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            // 현재 위치가 홀수인 경우 점프
            n -= 1;
            batteryUsage++;
        }
    }

    return batteryUsage;
}

int main() {
    // 테스트를 위한 입력 예시
    cout << "Hello Cpp" << endl;

    int N1 = 5, N2 = 6, N3 = 5000;
    cout << "Result for " << N1 << ": " << solution(N1) << endl;
    cout << "Result for " << N2 << ": " << solution(N2) << endl;
    cout << "Result for " << N3 << ": " << solution(N3) << endl;

    return 0;
}
