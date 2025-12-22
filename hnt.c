#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char from, char to, char aux, unsigned long long *step) {
    if (n <= 0) return;
    if (n == 1) {
        (*step)++;
        printf("%llu: %c->%c\n", *step, from, to);
        return;
    }
    hanoi(n-1, from, aux, to, step);
    (*step)++;
    printf("%llu: %c->%c\n", *step, from, to);
    hanoi(n-1, aux, to, from, step);
}

int main() {
    int n;
    scanf("%d",&n);
    unsigned long long steps = 0;
    hanoi(n, 'A', 'C', 'B', &steps);
    printf("Total: %llu\n", steps);
    return 0;
}