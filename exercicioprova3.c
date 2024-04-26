/* Programa que recebe a idade, sexo e salario de N funcionários. Calcule e Mostre:
a) quantidade de pessoas com salário inferior a 2000.
b) a média da idade das pessoas que possuem salario acima de 4700.
c) total de homens e mulheres na empresa.
d) exibir o resultado no final do processamento. */

#include <stdio.h>

char nome[50][50];
char sexo[50];
int idade[50];
float salario[50];
int qtFuncionarios = 0;
int totalHomens = 0;
int totalMulheres = 0;
float menorSalario = 0;
float somaIdades = 0;
float qtSalarioM2000 = 0;
float qtSalarioM4700 = 0;
float mediaIdade = 0;

void coleta()
{
    printf("Digite o número de funcionarios:\n");
    scanf("%i", &qtFuncionarios);

    // loop para perguntar as informações
    for (int i = 0; i < qtFuncionarios; i++)
    {
        printf("Digite o nome do funcionario:\n");
        scanf("%s", nome[i]);
        printf("Digite o sexo do funcionario (M/F):\n");
        scanf("%c", &sexo[i]);
        printf("Digite a idade do funcionario:\n");
        scanf("%i", &idade[i]);
        printf("Digite o salario do funcionario: \n");
        scanf("%f", &salario[i]);
    }
}

void comparacao()
{
    menorSalario = salario[0];
    for (int i = 0; i < qtFuncionarios; i++)
    {
        // salario < 2000
        if (salario[i] < 2000)
        {
            qtSalarioM2000++;
        }
        // idades salario > 4700
        if (salario[i] > 4700)
        {
            somaIdades += idade[i];
            qtSalarioM4700++;
        }
        // total de homens e mulheres
        if (sexo[i] == 'M')
        {
            totalHomens++;
        }
        if (sexo[i] == 'F')
        {
            totalMulheres++;
        }
    }
    // media das idades dos funcionários com salário > 4700
    if (qtSalarioM4700 > 0)
    {
        mediaIdade = somaIdades / qtSalarioM4700;
    }
}

void resultados()
{
    // mostrando resultados
    printf("Quantidade de funcionarios com salario < 2000: %.0f\n", qtSalarioM2000);
    printf("A média da idade dos funcionarios com salario > 4700: %.2f\n", mediaIdade);
    printf("Total de Homens: %i, Total de Mulheres: %i\n", totalHomens, totalMulheres);
}

int main()
{
    // chamando funçoes
    coleta();
    comparacao();
    resultados();
    return 0;
}
