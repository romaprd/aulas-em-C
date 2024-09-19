#include <stdio.h>

void merge (int vetor [], int inicio, int fim, int inicio2, int fim2){

    int temp [50];
    int i, j, k;
    i = inicio;
    j = inicio2;
    k = 0;
//enquanto tiver elementos em ambos os grupos 
    while (i <= fim && j <= fim2)
    {
   if(vetor [i] < vetor [j]){
    temp [k++] = vetor [i++];

   } else{
        temp [k++] = vetor [j++];
    }
    
    }
    //copia os elementos restantes do primeiro grupo
    while (i <=  fim)
    {
        temp[k++] = vetor [i++];

    }//copia os elementos restantes do segundo gurpo
    while (j <= fim2)
    {
        temp [k++] = vetor [j++];
    }//copioa os elementos do vetor temporario 
    for(int i = inicio, j = 0; i<= fim2; i++, j++ ){
        vetor [i] = temp [j];
    }
    
    
    

}
void merge_sort(int vetor[], int inicio, int tam){
    //calcula os grupos (meio do vetor )
    if (inicio < tam){
        int meio = (inicio + tam) / 2;
        //recursao esquerdo
        merge_sort(vetor, inicio, meio);
        merge_sort (vetor, meio + 1, tam);
        merge (vetor, inicio, meio, meio + 1, tam);

    }
}
int main(){
    int vetor [10] = {10, 9, 8 , 7, 6, 5, 4, 3, 2, 1};
merge_sort(vetor, 0, 9);

for (int i = 0; i < 10; i++){
    printf(" |%d| ", vetor [i]);
    
}

    return 0;
}