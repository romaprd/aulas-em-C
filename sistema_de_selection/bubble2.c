#include <stdio.h>

void bubble_sort ( char vetor [], int tam){
   
//variavel auxiliar
char  proximo =' ';
//percorre todo o vetor externo
for (int i = 0;i < tam; i++){
    //trabalha com os proximos elementos
 for(int j = 0; j < (tam - 1); j++){
     //faz a troca
 if (vetor [j] > vetor [j + 1]){
    proximo = vetor [j];
    vetor [j] = vetor [j + 1];
    vetor [j + 1] = proximo;
    
 }
 }

}
}
int main (){

char vetor [10] = {'h', 'b', 'a', 'y', 'c', 'e', 'i'};
bubble_sort(vetor, 10);

for (int i = 0; i < 10; i++){
    printf(" |%c| ", vetor [i]);
    
}

    return 0;
}
