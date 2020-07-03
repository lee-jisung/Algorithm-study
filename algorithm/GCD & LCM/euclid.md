### 최대 공약수 / 최소 공배수

``` c++
#include <stdio.h>

int A, B;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    scanf("%d %d", &A, &B);
    printf("gcd : %d\n", gcd(A, B));
    printf("lcm : %d", lcm(A, B));
    return 0;
}

```
