#include <stdio.h>
#include <string.h>

void ponteiro(int* idade, char* nome, float* altura){
*nome = 'roma';
*idade += 1;
*altura += 1.50;


}
int main(){
int idade;
char nome;
float altura;

printf("informe sua idade: ");
scanf("%d", &idade);
fseek(stdin, 0, SEEK_END);
printf("informe sua altra: ");
scanf("%f", &altura);

printf("informe seu nome: ");
scanf("%c", &nome);

printf("variaveis antes da referencia: Ola sr.%c, sua idade eh %d e sua altura eh %f", nome, idade, altura);

ponteiro(&idade, &nome, &altura);
printf("valores apos ponteiro: Ola sr.%c, sua idade eh %d e sua altura eh %f", nome, idade, altura);








    return 0;
}