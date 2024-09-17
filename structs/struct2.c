#include <stdio.h>
#include <string.h>

struct aluno1
{
    char nome [100];
    int n_matricula;
    char curso [100];

}aluno1 [5];

int main(){
 int i;
    for(i = 0; i < 5; i++){
        printf("informe seu nome: ");
        fgets(aluno1[i].nome, 100, stdin);
        printf("informe sua matricula: ");
        scanf("%d", &aluno1[i].n_matricula);
        getchar();
        printf("informe seu curso: ");
        fgets(aluno1[i].curso, 100, stdin);

        printf("seu nome eh: %s\no numero da sua matricula eh: %d\nseu endereco eh: %s", strtok(aluno1[i].nome, "\n"),aluno1[i].n_matricula, aluno1[i].curso);
    }
    return 0;
}

