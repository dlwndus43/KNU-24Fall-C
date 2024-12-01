#include <iostream>
using namespace std;

int solution(int n) {
    int batteryUsage = 0; // ������ ��뷮�� ��Ÿ�� ����

    while (n > 0) {
        // ���� ��ġ�� ¦���� ��� �����̵�
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            // ���� ��ġ�� Ȧ���� ��� ����
            n -= 1;
            batteryUsage++;
        }
    }

    return batteryUsage;
}

int main() {
    // �׽�Ʈ�� ���� �Է� ����
    cout << "Hello Cpp" << endl;

    int N1 = 5, N2 = 6, N3 = 5000;
    cout << "Result for " << N1 << ": " << solution(N1) << endl;
    cout << "Result for " << N2 << ": " << solution(N2) << endl;
    cout << "Result for " << N3 << ": " << solution(N3) << endl;

    return 0;
}
