#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    int qtd_dias_trabalhados;
    int *horas_trabalhadas;
}Funcionario;

int main(){
    int numFuncionarios;
    printf("Qauntidade de funcionarios:");
    scanf("%d", &numFuncionarios);

    Funcionario *funcionarios = malloc(numFuncionarios*sizeof(Funcionario));
    for(int i = 0; i < numFuncionarios; i++){
        printf("--- Funcionario %d ---\n", i+1);
        printf ("Codigo: ");
        scanf("%d", &funcionarios[i].codigo);
        printf("Quantidade de dias trabalhados: ");
        scanf("%d", &funcionarios[i].qtd_dias_trabalhados);

        funcionarios[i].horas_trabalhadas = malloc(funcionarios[i].qtd_dias_trabalhados*sizeof(int));

        for(int j = 0; j < funcionarios[i].qtd_dias_trabalhados; j++){
            scanf("%d", &funcionarios[i].horas_trabalhadas[j]);
        }
        printf("\n");
    }

    printf("--- Relatorio Final ---\n");

    printf("Funcionario - Horas Trabalhadas - Salario\n");
    double somaSalarios = 0;
    for(int i = 0; i < numFuncionarios; i++){
        int somaHoras = 0;
        for(int j = 0; j < funcionarios[i].qtd_dias_trabalhados; j++){
            somaHoras += funcionarios[i].horas_trabalhadas[j];
        }
        printf("    %d    -      %d           -  R$%.2lf\n", funcionarios[i].codigo, somaHoras, 25.0 * somaHoras);
        somaSalarios += (25*somaHoras);        
    }
    printf("\nTotal pago aos Funcionarios: R$%.2lf\n", somaSalarios);

    for(int i = 0; i < numFuncionarios; i++){
        free(funcionarios[i].horas_trabalhadas);
    }
    free(funcionarios);

}