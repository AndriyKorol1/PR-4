#include <stdio.h>

#define MOD 12345

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int n;
    printf("Введіть довжину послідовності n: ");
    scanf("%d", &n);

    if (n < 2 || n >= 10000) {
        printf("Некоректне значення n\n");
        return 1;
    }

    int dp[n+1][3];

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1];
    }

    int result = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2]) % MOD;

    printf("Кількість шуканих послідовностей: %d\n", result);

    return 0;
}
