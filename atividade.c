#include <stdio.h>
#include <string.h>

int main(){

int quantidade;
float valorProduto, valorProduto2, valorProduto3;
char nome [50];

printf("Bem Vindo ao Condor, por favor informe o seu nome: ");
fgets(nome, 50, stdin);
printf("entre com o valor do produto: ");
scanf("%f", &valorProduto);
printf("informe a quantidade de produtos: ");
scanf("%d", &quantidade);

if (quantidade < 10){
    valorProduto2 = valorProduto;
}
else if (quantidade > 10 && quantidade <= 99){
    valorProduto2 = quantidade * (valorProduto * 0.95);
}
else if (quantidade > 100 && quantidade <= 999){
    valorProduto2 = quantidade * (valorProduto * 0.9);
}
else {
    valorProduto2 = quantidade * (valorProduto * 0.85);
}
valorProduto3 = valorProduto * quantidade;

printf("%s, o valor total dos produtos foi: R$ %0.2f", nome, valorProduto2);
printf("\nvalor sem desconto: R$ %0.2f", valorProduto3);










    return 0;
}





