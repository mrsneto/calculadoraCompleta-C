#include <stdio.h>
#include <math.h> // para sqrt, pow e log

int opcoes() {
    printf("\nEscolha uma operacao:\n");
    printf("0 - Finalizar o programa\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Raiz Quadrada\n");
    printf("6 - Exponenciacao\n");
    printf("7 - Logaritmo\n");
    printf("8 - Calculos financeiros\n");
    printf("Digite a opcao desejada: ");
    return 0;
}

int main() {
    int opcao;
    int valor1, valor2;
    float num, base, expoente;
    float dividendo, divisor;
    char continuar = 's';

    printf("=== Seja bem-vindo(a) a nossa calculadora completa em C! ===\n");

    do {
        opcoes();
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Finalizando o programa...\n");
                return 0;

            case 1:
                printf("Digite o primeiro valor: ");
                scanf("%d", &valor1);
                printf("Digite o segundo valor: ");
                scanf("%d", &valor2);
                printf("Resultado da soma: %d\n", valor1 + valor2);
                break;

            case 2:
                printf("Digite o primeiro valor: ");
                scanf("%d", &valor1);
                printf("Digite o segundo valor: ");
                scanf("%d", &valor2);
                printf("Resultado da subtracao: %d\n", valor1 - valor2);
                break;

            case 3:
                printf("Digite o primeiro valor: ");
                scanf("%d", &valor1);
                printf("Digite o segundo valor: ");
                scanf("%d", &valor2);
                printf("Resultado da multiplicacao: %d\n", valor1 * valor2);
                break;

            case 4:
                printf("Digite o valor do dividendo: ");
                scanf("%f", &dividendo);
                printf("Digite o valor do divisor: ");
                scanf("%f", &divisor);

                if (divisor == 0) {
                    printf("Erro: divisao por zero nao permitida.\n");
                } else {
                    float resultado_divisao = dividendo / divisor;
                    printf("Resultado da divisao: %.2f\n", resultado_divisao);

                    if ((int)dividendo == dividendo && (int)divisor == divisor) {
                        int resto = (int)dividendo % (int)divisor;
                        printf("Resto da divisao: %d\n", resto);
                    } else {
                        printf("Nao e possivel calcular o resto da divisao com numeros reais.\n");
                    }
                }
                break;

            case 5:
                printf("Digite um numero para calcular a raiz quadrada: ");
                scanf("%f", &num);
                if (num < 0) {
                    printf("Nao existe raiz quadrada real de numero negativo.\n");
                } else {
                    printf("Raiz quadrada: %.2f\n", sqrt(num));
                }
                break;

            case 6:
                printf("Digite a base: ");
                scanf("%f", &base);
                printf("Digite o expoente: ");
                scanf("%f", &expoente);
                printf("Resultado da exponenciacao: %.2f\n", pow(base, expoente));
                break;

            case 7:
                printf("Digite um numero maior que 0 para calcular o logaritmo natural: ");
                scanf("%f", &num);
                if (num <= 0) {
                    printf("Nao e possivel calcular o log de numeros menores ou iguais a 0.\n");
                } else {
                    printf("Logaritmo natural (base e): %.4f\n", log(num));
                }
                break;

            case 8:
                printf("Selecione o tipo de calculo financeiro:\n");
                printf("1 - Juros simples\n");
                printf("2 - Desconto simples\n");
                printf("3 - Financiamento (prestacao fixa)\n");
                int tipo;
                float capital, taxa, tempo;
                scanf("%d", &tipo);
                switch (tipo) {
                    case 1:
                        printf("Digite o capital: ");
                        scanf("%f", &capital);
                        printf("Digite a taxa (em %%): ");
                        scanf("%f", &taxa);
                        printf("Digite o tempo (em meses): ");
                        scanf("%f", &tempo);
                        printf("Juros simples: %.2f\n", capital * (taxa/100) * tempo);
                        break;
                    case 2:
                        printf("Digite o valor bruto: ");
                        scanf("%f", &capital);
                        printf("Digite a taxa de desconto (em %%): ");
                        scanf("%f", &taxa);
                        printf("Desconto: %.2f\n", capital * (taxa/100));
                        break;
                    case 3:
                        printf("Digite o valor financiado: ");
                        scanf("%f", &capital);
                        printf("Digite a taxa (em %%): ");
                        scanf("%f", &taxa);
                        printf("Digite o tempo (em meses): ");
                        scanf("%f", &tempo);
                        float parcela = capital * (taxa/100) / (1 - pow(1 + (taxa/100), -tempo));
                        printf("Valor da prestacao mensal: %.2f\n", parcela);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

       
        printf("\nDeseja fazer outra operacao? (s/n): ");
        scanf(" %c", &continuar); 

    } while (continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
