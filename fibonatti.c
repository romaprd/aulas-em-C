#include <stdio.h>
// Função recursiva para calcular o n-ésimo número de Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
 // Caso base: se n for 0 ou 1, retorna n (porque Fibonacci(0) = 0 e Fibonacci(1) = 1)
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("O valor de n deve ser não-negativo.\n");
    } else {
        printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    }

    return 0;
}
