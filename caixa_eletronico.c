//criar um pequeno projeto de um caixa eletronico. O usurario tera um menu para
 //escolher entre saldo, extrato, saque, deposito e uma opcao para sair. o saque
// apenas podera ser realizado se o usuario tiver saldo em conta.(incluindo
 //limte) para ter acesso as opcoes do menu o usuario deve validar sua senha,
 //agencia e conta deposito devera acrescer na conta

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int nr_agencia = 1020, nr_conta = 1224, nr_senha = 1007;
float saldo = 0.0, limite = 500.00;
float operacao_credito[100], operacao_debito[100];
int total_credito = 0, total_debito = 0;
//funcao para consultar e o saldo e o limite de saque
void consultar_saldo() {

  printf("\nseu saldo eh de:    %.2f", saldo);
  printf("\nseu limite eh de:   %.2f", limite);
  printf("\nvalor disponivel:   %.2f", saldo + limite);
  printf("\n\npressione a tecla 5 caso queira encerrar o programa\n");
}
//funcao para realizar um deposito
//atualiza o saldo da conta e registra a operacao de credito
void realizar_deposito(float *saldo) {
  float num;

  printf("informe o valor que voce deseja depositar: ");
  scanf("%f", &num);
  *saldo += num;//atualiza o saldo com o valor do deposito
  if (total_credito < 100) {
    
    //registro da operacao de credito
    operacao_credito[total_credito++] = num;
  } else {
    printf("Histórico de crédito cheio.\n");
  }
}
//funcao para realizar um saque na conta
//atualiza o saldo da conta e registra uma operacao de debito
void realizar_saque(float *saldo) {
  float valor_saque;

  printf("entre com o valor que voce deseja sacar: ");
  scanf("%f", &valor_saque);
  
   if (valor_saque <= *saldo) {
     *saldo -= valor_saque;//atualiza o saldo com o valor do saque
     if (total_debito < 100) {

       //registro da operacao de debito
       operacao_debito[total_debito++] = valor_saque;
     } else {
       printf("Histórico de débito cheio.\n");
     }
     } else {
     printf("Saldo insuficiente para o saque.\n");
     }
    
}
//funcao para mostra o extrato bancario digital
//exibe todas as operacoes de credito e debito realizadas e o saldo final
void consultar_extrato(){
  int i;
  printf("\nExtrato Bancário Digital:\n");

  printf("\nOperações de Crédito:\n");
  for (int i = 0; i < total_credito; i++) {
      printf("Depósito: %.2f\n", operacao_credito[i]);
  }

  printf("\nOperações de Débito:\n");
  for (int i = 0; i < total_debito; i++) {
      printf("Saque: %.2f\n", operacao_debito[i]);
  }

  printf("\nSaldo Final: %.2f\n", saldo);

  
}
//funcao para inicializar os vetores de operacoes com valores nulos
// essa funcao eh redundante pois os vetores sao inicializados diretamente nas funcoes de operacao
void preenche_vetor() {
  for (int i = 0; i < 100; i++) {
    operacao_credito[i] = 0.0;
    operacao_debito[i] = 0.0;
  }
}
//funcao para exibir o menu com as opcoes disponiveis para o usuario
//chama a funcao correspondente a opcao escolhida pelo usuario
void chama_menu() {
  int opcao;

  do {
    printf("\nescolha uma opcao: ");
    printf(
        "\n1 - saldo\n2 - extrato\n3 - saque\n4 - deposito\n5 - sair\nopcao: ");
    scanf("%d", &opcao);
    system("cls");//limpa a tela

  } while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5);

  switch (opcao) {
  case 1:
    consultar_saldo();
    chama_menu();//volta ao menu apos exibir o saldo
    break;

  case 2:
    consultar_extrato ();//exibe o extrato bancario
    chama_menu();//volta ao menu apos exibir o extrato
    break;
  case 3:
    realizar_saque(&saldo);
      printf("saque realizado com sucesso");
      consultar_saldo();//mostra o saldo apos a realizacao do saque
      
       printf("\ncaso queira encerrar o programa, digite a opcao: 5\n sanao, escolha outra opcao!");
    chama_menu();//volta ao menu apos o saque
    break;
  case 4:
    realizar_deposito(&saldo);//como o nome ja diz, realiza um deposito
      printf("desposito realizado com sucesso!\n");
      printf("\npara consultar seu saldo, escolha a opcao: 1\ncaso queira encerrar o programa, digite a opcao: 5\n");
    chama_menu();//volta ao menu apos o deposito
    break;
  case 5:
    printf("\nprograma encerrado pelo usuario");
    break;
  default:
    printf("opcao invalida\n\ninforme uma opcao valida");
    chama_menu();
  }
}
int main() {

  int senha, conta, agencia;

  preenche_vetor(); // Inicializa os vetores de operacoes aqui

  //verifica a agencia, conta e senha informados pelo usuario
  do {
    printf("informe sua agencia: ");
    scanf("%d", &agencia);
    printf("informe sua conta: ");
    scanf("%d", &conta);
    printf("informe sua senha: ");
    scanf("%d", &senha);
    system("cls");
    //verifica de os dados informados pelo usuario sao validos
    if (nr_agencia != agencia || nr_conta != conta || nr_senha != senha) {
      printf("dados invalidos, tente novamente: \n\n");
    }
  } while (nr_agencia != agencia || nr_conta != conta || nr_senha != senha);
  printf("acesso liberado!\n\n");

  chama_menu();//exibe o menu principal apos a validacao das informacoes

  return 0;
}
