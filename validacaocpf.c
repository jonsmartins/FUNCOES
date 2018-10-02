#include <stdio.h>

int main()
{
    int cpf[10];
    printf("Digite o CPF utilizando um espaço apos cada digito:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d",&cpf[0],&cpf[1],&cpf[2],&cpf[3],&cpf[4],&cpf[5],&cpf[6],&cpf[7],&cpf[8],&cpf[9],&cpf[10]);
    if((((cpf[0]*10)+(cpf[1]*9)+(cpf[2]*8)+(cpf[3]*7)+(cpf[4]*6)+(cpf[5]*5)+(cpf[6]*4)+(cpf[7]*3)+(cpf[8]*2))*10)%11==cpf[9]){
        if((((cpf[0]*11)+(cpf[1]*10)+(cpf[2]*9)+(cpf[3]*8)+(cpf[4]*7)+(cpf[5]*6)+(cpf[6]*5)+(cpf[7]*4)+(cpf[8]*3)+(cpf[9]*2))*10)%11==cpf[10]){
            printf("CPF valido");
        }
    }
    else
        printf("CPF invalido");
}
