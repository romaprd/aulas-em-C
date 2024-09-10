//criar um pequeno projeto de um caixa eletronico. O usurario tera um menu para escolher entre saldo, extrato, saque, deposito e uma opcao para sair.
//o saque apenas podera ser realizado se o usuario tiver saldo em conta.(incluindo limte)
//para ter acesso as opcoes do menu o usuario deve validar sua senha, agencia e conta
//deposito devera acrescer na conta

#include <stdio.h>
#include <stdlib.h>

const int nr_agencia = 1020, nr_conta = 1224, nr_senha = 1007;
float saldo = 0.0; limite = 500.00;
float operacao_credito [100], operacao_debito [100];

void consultar_saldo(){
    
    printf("\n*************************");
    printf("seu saldo eh de:    %.2f", saldo);
    printf("seu limite eh de:   %.2f", limite);
    printf("valor disponivel:   %.2f", saldo + limite);
    printf("\n*************************")
    
}
void realizar_deposito(float *saldo){
float num;

printf("entre com o valor que voce deseja depositar: ");
scanf("%f", num);
*saldo += num;

}

void preenche_vetor(){
for (int i = 0; i < 100; i++){
operacao_credito [i] = 0.0;
operacao_debito [i] = 0.0;


}

}
void chama_menu(){
int opcao;

do{
    printf("\nescolha uma opcao: ");
    printf("\n1 - saldo\n2 - extrato\n3 - saque\n4 - deposito\n5 - sair\nopcao: ");
    scanf("%d", &opcao);
    system("cls");


}while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5);

switch (opcao)
{
case 1:
    consulta_saldo ();
    chama_menu();
break;

case 2:
    consultar_extrato ();
    chama_menu();
break;
case 3:
    realizar_saque ();
    chama_menu();
break;
case 4:
    realizar_deposito();
    chama_menu();
break;
case 5:
    printf("\nprograma encerrado pelo usuario");
break;
default:
    printf("opcao invalida\n\ninforme uma opcao valida");
    chama_menu ();

}
}
int main(){

int senha, conta, agencia;

    preenche_vetor ();

do{
    printf("informe sua agencia: ");
    scanf("%d", &agencia);
     printf("informe sua conta: ");
    scanf("%d", &conta);
     printf("informe sua senha: ");
    scanf("%d", &senha);
    system ("cls");

if (nr_agencia != agencia || nr_conta != conta || nr_senha != senha){
    printf("agencia ou conta ou senha invlidos\n\n");


}
}while ( nr_agencia != agencia || nr_conta != conta || nr_senha != senha);
    printf("acesso liberado!\n\n");

    chama_menu();





    return 0;


}




