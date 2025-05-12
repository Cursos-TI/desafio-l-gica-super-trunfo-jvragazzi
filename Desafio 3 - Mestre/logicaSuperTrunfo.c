#include <stdio.h>

int main() {
    // Dados fixos das cartas
    char nome1[50] = "São Paulo", estado1[] = "SP";
    int populacao1 = 12300000, pontos1 = 50;
    float area1 = 1521.11, pib1 = 699.28;

    char nome2[50] = "Rio de Janeiro", estado2[] = "RJ";
    int populacao2 = 6748000, pontos2 = 30;
    float area2 = 1200.25, pib2 = 300.50;

    // Cálculo dos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // Exibir opções
    int opcao1, opcao2;

    printf("--- MENU DE ATRIBUTOS ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    // Escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação: ");
    scanf("%d", &opcao1);

    // Menu dinâmico para o segundo atributo
    printf("\nAgora escolha o segundo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }

    printf("Escolha: ");
    scanf("%d", &opcao2);

    // Função auxiliar: retorna o valor numérico de um atributo
    float valor1_a = 0, valor2_a = 0, valor1_b = 0, valor2_b = 0;

    // Primeiro atributo
    switch (opcao1) {
        case 1: valor1_a = populacao1; valor2_a = populacao2; break;
        case 2: valor1_a = area1;       valor2_a = area2;       break;
        case 3: valor1_a = pib1;        valor2_a = pib2;        break;
        case 4: valor1_a = pontos1;     valor2_a = pontos2;     break;
        case 5: valor1_a = densidade1;  valor2_a = densidade2;  break;
        default: printf("Opção inválida.\n"); return 1;
    }

    // Segundo atributo
    switch (opcao2) {
        case 1: valor1_b = populacao1; valor2_b = populacao2; break;
        case 2: valor1_b = area1;       valor2_b = area2;       break;
        case 3: valor1_b = pib1;        valor2_b = pib2;        break;
        case 4: valor1_b = pontos1;     valor2_b = pontos2;     break;
        case 5: valor1_b = densidade1;  valor2_b = densidade2;  break;
        default: printf("Opção inválida.\n"); return 1;
    }

    // Regra: maior vence, exceto para densidade (menor vence)
    int v1_a = (opcao1 == 5) ? (valor1_a < valor2_a) : (valor1_a > valor2_a);
    int v1_b = (opcao2 == 5) ? (valor1_b < valor2_b) : (valor1_b > valor2_b);

    float soma1 = valor1_a + valor1_b;
    float soma2 = valor2_a + valor2_b;

    // Exibição
    printf("\n--- COMPARAÇÃO DAS CARTAS ---\n");
    printf("Carta 1: %s (%s)\n", nome1, estado1);
    printf("Carta 2: %s (%s)\n", nome2, estado2);

    // Atributo 1
    printf("\nAtributo 1: ");
    switch (opcao1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", nome1, valor1_a, nome2, valor2_a);
    printf("Vencedor: %s\n", v1_a ? nome1 : (valor1_a == valor2_a ? "Empate" : nome2));

    // Atributo 2
    printf("\nAtributo 2: ");
    switch (opcao2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", nome1, valor1_b, nome2, valor2_b);
    printf("Vencedor: %s\n", v1_b ? nome1 : (valor1_b == valor2_b ? "Empate" : nome2));

    // Comparação final
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Soma dos Atributos:\n");
    printf("%s: %.2f\n", nome1, soma1);
    printf("%s: %.2f\n", nome2, soma2);

    (soma1 > soma2) 
        ? printf("Resultado Final: %s venceu a rodada!\n", nome1)
        : (soma2 > soma1)
            ? printf("Resultado Final: %s venceu a rodada!\n", nome2)
            : printf("Resultado Final: Empate!\n");

    return 0;
}
