# include <stdio.h>

# define TAMFILA 10 

int pilha [TAMFILA] = {0,0,0,0,0,0,0,0,0,0};

int topo = 0; 


void push (){

int val;
printf("informe um valor: ");
scanf("%d", &val);

if (topo < TAMFILA){
    pilha[topo] = val;
    topo ++;
 
} else {
    printf("pilha esta cheia!\n");


}

}

void pop (){
    if(topo >= 0 ){
        pilha[topo - 1] = 0;
        topo --;
        

    } else {
        printf("pilha esta vazia!");
    }

}

void limpar (){

    for(int i = 0; i < TAMFILA; i ++){
    pilha [i] = 0;
    }
}

void pilha_elemento(){
    for(int i = 0; i < TAMFILA; i ++){
        printf("| %d |", pilha [i]);
    }
}

void menu (){
int opcao;

do{

printf("\nescolha uma das opcoes abaixo!\n");
printf("\n1 - empilhar\n2 - desempilhar\n3 - listar\n4 - limpar\n5 - sair\n:");
scanf("%d", &opcao);

switch (opcao){
    case 1 :
    push();
    menu();
    break;

    case 2 : 
    pop();
    menu();
    break;

    case 3 :
    pilha_elemento();
    menu();
    break;

    case 4 :
    limpar();
    menu();
    break;

    case 5 :
      printf("programa encerrado, até a próxima!");

      default : 
      printf("opcao invalida, tente novamente");
}
} while (opcao < 1 || opcao > 5);

} 

int main (){

    menu();

    return 0;
}