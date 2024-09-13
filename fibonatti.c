#include <stdio.h>

// Função recursiva para calcular o n-ésimo número de Fibonacci
int fibonacci(int n) {
    // Caso base: se n é 0 ou 1, retorne n diretamente
    if (n <= 1) {
        return n;
    } else {
        // Caso geral: calcula o n-ésimo número de Fibonacci chamando a função recursivamente
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Solicita ao usuário a posição desejada na sequência de Fibonacci
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Verifica se o valor de n é um número inteiro não negativo
    if (n < 0) {
        printf("O valor de n deve ser um número inteiro não negativo.\n");
    } else {
        // Chama a função fibonacci e exibe o resultado
        printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    }

    return 0;
}
