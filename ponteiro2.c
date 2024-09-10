#include <stdio.h>

void contadora(int *num1, int *num2){

*num1 += 10;
*num2 *= 2;

}
int main(){
    int num1, num2;

printf("informe um valor inteiro: ");
scanf("%d", &num1);

printf("informe o seundo numero: ");
scanf("%d", &num2);

    printf("variavel antes da rferencia:\n%d\n%d\n ", num1, num2);

    contadora (&num1, &num2);
printf("valores apos ponteiro: \n%d\n%d", num1, num2);





    return 0;
}
