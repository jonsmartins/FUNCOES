#include <stdio.h>

float TabelaInss (float valor){
    float aux = 0;
    if (valor < 1693.73){
        aux = valor * 0.08;
    }
    else if ((valor < 2822.91) && (valor > 1693.72)){
        aux = valor * 0.09;
    }
    else if ((valor > 2822.91) && (valor < 5645.81)){
        aux = valor * 0.11;
    }
    else if (valor > 5645,80){
        aux = 621.03;
    }
    return aux;
    
}

float TabelaIrrf (float valor1, int dep){
    float aux = TabelaInss (valor1);
    float ir = 0;
    if ((((valor1 - aux)-(dep*189.59)) > 1903.99) && ((((valor1 - aux)-(dep*189.59)) < 2826.66))){
        ir = (((valor1 - aux)-(dep*189.590)) * 0.075) - 142.80;
    }
    else if ((((valor1 - aux)-(dep*189.59)) > 2826.65) && ((((valor1 - aux)-(dep*189.59)) < 3751.06))){
        ir = (((valor1 - aux)-(dep*189.59)) * 0.15) - 354.80;
    }
    else if ((((valor1 - aux)-(dep*189.59)) > 3751.05) && ((((valor1 - aux)-(dep*189.59)) < 4664.69))){
        ir = (((valor1 - aux)-(dep*189.59)) * 0.225) - 636.13;
    }
    else if (((valor1 - aux)-(dep*189.59)) > 4664.68){
        ir = (((valor1 - aux)-(dep*189.59)) * 0.275) - 869.36;
    }
    if(ir>10.00){
        return ir;
    }
}

float LiquidoSalario (float salario, int dep){
  float inss = 0, irrf = 0;
  inss = TabelaInss(salario);
  irrf = TabelaIrrf(salario, dep);
  salario = (salario - inss) - irrf;
  return salario;
}

int
main ()
{
  float salario = 0, liquido=0;
  int qdep=0;
  printf ("Informe o salario liquido:\n");
  scanf ("%f", &salario);
  printf ("Possui quantos dependentes ?\n");
  scanf("%d",&qdep);
  TabelaInss (salario);
  TabelaIrrf(salario,qdep);
  liquido = LiquidoSalario (salario, qdep);
  printf("...");
  printf ("\nSalario liquido a pagar %.2f", liquido);

}
