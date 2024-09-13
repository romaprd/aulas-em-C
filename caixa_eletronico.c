#include <stdio.h>
#include <stdlib.h>

const int nr_agencia = 1020, nr_conta = 123, nr_senha = 1234;
float saldo = 0.0, limite = 500.00, total;
float operacao_credito [100], operacao_debito [100]; 
int total_credito = 0, total_debito = 0;

void consulta_extrato (){
    int i, rep;
    printf("Extrato Bancario Completo:\n\n");
    printf("Operacoes feitas com credito: \n");
    for (i = 0; i < total_credito; i++){
        printf("Deposito: R$ %.2f\n", operacao_credito[i]);
    }

    printf("\nOperacoes de debito: \n");
    for (i = 0; i < total_debito; i++){
        printf("Saque: R$ %.2f\n", operacao_debito[i]);
    }

    printf("\nSaldo final: %.2f\n", total);
     do{
        printf("\n");
        printf("\nPara voltar para o menu, digite 5: ");
        scanf("%d", &rep);
        system("cls");
        chama_menu();
    }while (rep != 5);
}


void consulta_saldo (){
    int rep;
    printf("Saldo:              R$ %.2f", saldo);
    printf("\nLimite:           R$ %.2f", limite);
    printf("\nDisponivel:       R$ %.2f", total = saldo + limite);
    do{
        printf("\n");
        printf("\nPara voltar para o menu, digite 5: ");
        scanf("%d", &rep);
        system("cls");
        chama_menu();
    }while (rep != 5);
}

void realizar_deposito (float *saldo){
    float num;
    printf("Entre com o valor que gostaria de depositar: ");
    scanf("%f", &num);
    *saldo = *saldo + num;
    
    if (cont1 < 100){
        
        operacao_credito[total_credito++] = + num;
    }
    else {
        printf("Credito cheio");
    }
    
}

void realizar_saque(float *saldo, float *limite){
    float num;
    total = *saldo + *limite;
    printf("Digite o valor que gostaria de sacar: ");
    scanf("%f", &num);
    
    if (total_debito < 100){

        operacao_debito[total_debito++] = - num;
    } 
    else {
        printf("Debito cheio");
    }

    if (total < num){
        printf("Numero acima do valor total");
    }
    else if (num > *saldo && (*saldo -num) < *limite){
        *limite = (*saldo - num) + *limite ;
        *saldo = (*saldo - num);
        if (*saldo < 0) {
            *saldo = 0;
        }
    }
    else {
        *saldo = *saldo - num;
    }  

}

void preenche_vetor (){
    for (int i = 0; i < 100; i++){
        operacao_credito [i] = 0.0;
        operacao_debito [i] = 0.0;
    }
}

void chama_menu (){
    int opcao;

    do {
        printf("\nEscolha uma opcao: ");
        printf("\n1 - Saldo\n2 - Extrato\n3 - Saque\n4 - Deposito\n5 - Sair\n Opcao: ");
        scanf("%d", &opcao);
        system("cls");
    }while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5);

    switch (opcao){
    
    case 1:
        consulta_saldo ();
        printf("\n\n");
        break;
    case 2:
        consulta_extrato ();
        break;
    case 3:
        realizar_saque (&saldo, &limite);
        chama_menu();
        break;
    case 4:
        realizar_deposito (&saldo);
        printf("\n\n");
        chama_menu();
        break;
    case 5: 
        printf("\nPrograma encerrado pelo usuario");
        break;
    default:
        printf("Opcao invalida\n\nInforme uma opcao valida: ");
        chama_menu();
        break;
    }
}


int main (){

    int senha, conta, agencia;

    preenche_vetor ();

    do{
        printf("Infome sua agencia: ");
        scanf("%d", &agencia);
        printf("Informe sua conta: ");
        scanf("%d", &conta);
        printf("Informe sua senha: ");
        scanf("%d", &senha);
        system("cls");
        if (nr_agencia != agencia || nr_conta != conta || nr_senha != senha){
            printf("Dados incorretos\n\n");
        }

    }while (nr_agencia != agencia || nr_conta != conta || nr_senha != senha);
            printf("Acesso liberado!\n\n");
            chama_menu();

    return 0;
}
