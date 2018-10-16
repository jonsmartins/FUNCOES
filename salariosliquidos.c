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
    if(ir<10.00){
        ir=0;
        return ir;
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

float abs(float valor){
    return valor > 0 ? valor : -valor;
}

float bissecao(float salarioLiquido, int dep){
    float a = salarioLiquido;
    float b = salarioLiquido * 1.5;
    float delta = 0.001;
    
    float c = (a + b)/2;
    
    float fa = LiquidoSalario(a, dep);
    float fb = LiquidoSalario(b, dep);
    float fc = LiquidoSalario(c, dep);
    
    int i = 0;
    int max_iterations = 1000;
    while( abs(fc - salarioLiquido) > delta && i < max_iterations){
        
        c = (a + b)/2;
        
        fa = LiquidoSalario(a, dep);
        fb = LiquidoSalario(b, dep);
        fc = LiquidoSalario(c, dep);
        
        if(fc > salarioLiquido){
            b = c;
        }
        else {
            a = c;
        }
        
        i++;
    }
    
    printf("iteracoes realizadas %d\n", i);
    printf("SALARIO BRUTO %.2f", c);
    
    return c;
    
    
}


int main ()
{
  float salario = 0, liquido=0;
  int qdep=0;
  printf ("Informe o salario liquido desejado:\n");
  scanf ("%f", &salario);
  printf ("Possui quantos dependentes, caso nao possua digite 0 ?\n");
  scanf("%d",&qdep);
  
  
  //passando um salario liquido para calcular o bruto
  float salarioBruto = bissecao(salario, qdep);
  
  
  
  liquido = LiquidoSalario (salarioBruto, qdep);
  printf(" ...");
  printf ("\nSalario liquido a pagar %.2f\n", liquido);

}
