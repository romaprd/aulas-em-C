# include <stdio.h>

# define TAMFILA 10

int fila [TAMFILA] = {0,0,0,0,0,0,0,0,0,0};
int cabeca = 0;
int calda = 0;

void enfileirar (){
     int val;
      
      if(calda < TAMFILA){
        printf("informe o elemento para adicionar na fila: ");
        scanf("%d", &val);
        fila[calda] = val;
        calda ++;
        
      } else {
        printf("A fila esta cheia\n");
      }

}  void desinfileirar(){

    if (cabeca < calda ){
       fila [cabeca] = 0 ;
       cabeca ++;
      

    } else {


         printf("lista está vazia\n");

    }
       
    
} 
   void limpar (){

 for (int i = 0; i < TAMFILA; i ++){

    fila [i] = 0;
 }
 


   } void menu (){
    int opcao;
     
     do{

    printf("\nescolha um das opcoes abaixo");
    printf("\n");
    printf("\n1 - enfileirar\n2 - desinfileirar\n3 - listar\n4 - limpar\n5 - sair!\n:  ");
    scanf("%d", &opcao);

    switch (opcao){
     
     case 1:
     enfileirar();
     menu();
     break ;

     case 2: 
     desinfileirar();
     menu();
     break;

     case 3:
     listar();
     menu();
     break;

     case 4:
     limpar();
     menu();
     break;

     case 5:
     printf("programa encerrado, obrigado!");
     break;

     default:
       printf("valor inválido, tente novamente!");
       

    }

     } while (opcao < 1 || opcao> 5);

   } 
   void listar(){
       
      for(int i = 0; i < TAMFILA; i ++){
        printf(" - | %d | -", fila[i]);
      }

      printf("\nhead: %d\n",cabeca);
      printf("\ntail: %d\n", calda);


   } 
    int main (){
        menu();


   return 0;

    }