#include <stdio.h>
//parametro por ponteiro
void contadora(int* contador){//      essa funcao toda serve para alterar os dois valores tanto em baixo quanto em cima, como uma funcao com retorno


    printf("antes de incrementar\n");
    printf("o contador vale %d\n", *contador);
    printf("o endereco de memoria %d\n", contador);
    printf("endereco em hexadecimal %p\n", contador);//%p: tras os valores em hexadecimais

    printf("apos incrementar\n");

    printf("o contador vale %d\n", ++(*contador));
    printf("endereco de memoria eh %d\n", &contador);

}

int main(){
int contador = 10;

printf("variavel antes da referencia: %d\n\n", contador);
contadora (&contador);

printf("variavel no programa principal %d\n", contador);
printf("%p", &contador);





    return 0;
}