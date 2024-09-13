#include <stdio.h>
#include <stdlib.h>

const int nr_agencia = 1020, nr_conta = 123, nr_senha = 1234;
float saldo = 0.0, limite = 500.00, total;
float operacao_credito [100], operacao_debito [100]; 
int total_credito = 0, total_debito = 0, op;
//funcao para mostrar o extrato bancario digital
//exibe todas as operacoes de credito e debito realizadas e o saldo final
void consulta_extrato (){
    int i, op;
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
        scanf("%d", &op);
        system("clear");
        chama_menu();
    }while (op != 5);
}

//exibe o saldo e o limite disponivel
void consulta_saldo (){
    int op;
    printf("Saldo:              R$ %.2f", saldo);
    printf("\nLimite:           R$ %.2f", limite);
    printf("\nDisponivel:       R$ %.2f", total = saldo + limite);
    do{
        printf("\n");
        printf("\nPara voltar para o menu, digite 5: ");
        scanf("%d", &op);
        system("clear");
        chama_menu();
    }while (op != 5);
}
//funcao para realizar deposito 
//atualiza o saldo da conta e registra a operacao de credito
void realizar_deposito (float *saldo){
    float num;
    int op;
    printf("Entre com o valor que gostaria de depositar: ");
    scanf("%f", &num);
    *saldo = *saldo + num;//atualiza o saldo com o velor do deposito

    if (total_credito < 100){

        operacao_credito[total_credito++] = + num;//registro da operaca de credito
    }
    else {
        printf("Credito cheio");
    }
    do{
        printf("\n");
        printf("\nPara voltar para o menu, digite 5: ");
        scanf("%d", &op);
        system("clear");
        chama_menu();
    }while (op != 5);

}
//funcao para realizar um saque na conta
//atualiza o saldo da conta e registra uma operacao de debito
void realizar_saque(float *saldo, float *limite){
    float num;
    int op;
    
    total = *saldo + *limite;//atualiza o saldo com o valor do saque
    printf("Digite o valor que gostaria de sacar: ");
    scanf("%f", &num);

    if (total_debito < 100){

        operacao_debito[total_debito++] = - num;//registro da operacao de debito
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
    }  do{
        printf("\n");
        printf("\nPara voltar para o menu, digite 5: ");
        scanf("%d", &op);
        system("clear");
        chama_menu();
    }while (op != 5);

}
//funcao para preencher vetores de operacoes com valores nulos
//essa funcao eh redundate pois os vetores sao inicializados diretamente nas funcoes
void preenche_vetor (){
    for (int i = 0; i < 100; i++){
        operacao_credito [i] = 0.0;
        operacao_debito [i] = 0.0;
    }
}

void chama_menu(){
    int opcao;

    do {
        printf("\nEscolha uma opcao: ");
        printf("\n1 - Saldo\n2 - Extrato\n3 - Saque\n4 - Deposito\n5 - Sair\n Opcao: ");
        scanf("%d", &opcao);
        system("cls");//limpa a tela
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
        
        break;
    case 4:
        realizar_deposito (&saldo);
        printf("\n\n");
        
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
