#include <stdio.h>
#include <string.h>

struct st_aluno
{
    char nome[100];
    char endereco [100];
    int idade;

}aluno1;

int main(){

printf("informe seu nome completo: ");
fgets(aluno1.nome, 100, stdin);
printf("informe sua idade: ");
scanf("%d", &aluno1.idade);
getchar();
printf("informe seu endereco: ");
fgets(aluno1.endereco, 100, stdin);

printf("seu nome eh: %s\nsua idade eh: %d\nseu endereco eh: %s",strtok(aluno1.nome, "\n"), aluno1.idade, aluno1.endereco);

return 0;
}
