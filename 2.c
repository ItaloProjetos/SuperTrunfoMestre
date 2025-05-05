#include <stdio.h>

int main() {
    // Cadastro da carta 1
    int populacao1, ponto_turisticos1;
    char nome_cidade1[20], nome_estado1[20], codigo1[10];
    float area1, PIB1;

    printf("----CADASTRO DE CARTA 1----\n");
    printf("Digite o estado: ");
    scanf("%s", nome_estado1);
    printf("Digite o código da carta: ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade: ");
    scanf("%s", nome_cidade1);
    printf("Digite a população: ");
    scanf("%d", &populacao1);
    printf("Digite a área em km²: ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &PIB1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &ponto_turisticos1);

    PIB1 *= 1000000000;
    float densidade1 = populacao1 / area1;

    // Cadastro da carta 2
    int populacao2, ponto_turisticos2;
    char nome_cidade2[20], nome_estado2[20], codigo2[10];
    float area2, PIB2;

    printf("\n----CADASTRO DE CARTA 2----\n");
    printf("Digite o estado: ");
    scanf("%s", nome_estado2);
    printf("Digite o código da carta: ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade: ");
    scanf("%s", nome_cidade2);
    printf("Digite a população: ");
    scanf("%d", &populacao2);
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &PIB2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &ponto_turisticos2);

    PIB2 *= 1000000000;
    float densidade2 = populacao2 / area2;

    int op1, op2;
    float valor1_c1 = 0, valor2_c1 = 0;
    float valor1_c2 = 0, valor2_c2 = 0;

    // Menu dinâmico: escolha do primeiro atributo
    printf("\n--- Escolha o PRIMEIRO atributo para comparar ---\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Escolha a opção: ");
    scanf("%d", &op1);

    // Menu dinâmico: escolha do segundo atributo (sem repetir)
    printf("\n--- Escolha o SEGUNDO atributo (diferente do primeiro) ---\n");
    if (op1 != 1) printf("1 - População\n");
    if (op1 != 2) printf("2 - Área\n");
    if (op1 != 3) printf("3 - PIB\n");
    if (op1 != 4) printf("4 - Pontos Turísticos\n");
    if (op1 != 5) printf("5 - Densidade Demográfica\n");
    printf("Escolha a opção: ");
    scanf("%d", &op2);

    // Primeiro atributo
    printf("\n--- Comparando %s x %s ---\n", nome_cidade1, nome_cidade2);
    switch (op1) {
        case 1:
            printf("População: %s = %d | %s = %d\n", nome_cidade1, populacao1, nome_cidade2, populacao2);
            valor1_c1 = populacao1;
            valor1_c2 = populacao2;
            break;
        case 2:
            printf("Área: %s = %.2f | %s = %.2f\n", nome_cidade1, area1, nome_cidade2, area2);
            valor1_c1 = area1;
            valor1_c2 = area2;
            break;
        case 3:
            printf("PIB: %s = %.2f | %s = %.2f\n", nome_cidade1, PIB1, nome_cidade2, PIB2);
            valor1_c1 = PIB1;
            valor1_c2 = PIB2;
            break;
        case 4:
            printf("Pontos Turísticos: %s = %d | %s = %d\n", nome_cidade1, ponto_turisticos1, nome_cidade2, ponto_turisticos2);
            valor1_c1 = ponto_turisticos1;
            valor1_c2 = ponto_turisticos2;
            break;
        case 5:
            printf("Densidade Demográfica: %s = %.2f | %s = %.2f\n", nome_cidade1, densidade1, nome_cidade2, densidade2);
            valor1_c1 = densidade1;
            valor1_c2 = densidade2;
            break;
        default:
            printf("Opção inválida.\n");
    }

    // Segundo atributo
    switch (op2) {
        case 1:
            printf("População: %s = %d | %s = %d\n", nome_cidade1, populacao1, nome_cidade2, populacao2);
            valor2_c1 = populacao1;
            valor2_c2 = populacao2;
            break;
        case 2:
            printf("Área: %s = %.2f | %s = %.2f\n", nome_cidade1, area1, nome_cidade2, area2);
            valor2_c1 = area1;
            valor2_c2 = area2;
            break;
        case 3:
            printf("PIB: %s = %.2f | %s = %.2f\n", nome_cidade1, PIB1, nome_cidade2, PIB2);
            valor2_c1 = PIB1;
            valor2_c2 = PIB2;
            break;
        case 4:
            printf("Pontos Turísticos: %s = %d | %s = %d\n", nome_cidade1, ponto_turisticos1, nome_cidade2, ponto_turisticos2);
            valor2_c1 = ponto_turisticos1;
            valor2_c2 = ponto_turisticos2;
            break;
        case 5:
            printf("Densidade Demográfica: %s = %.2f | %s = %.2f\n", nome_cidade1, densidade1, nome_cidade2, densidade2);
            valor2_c1 = densidade1;
            valor2_c2 = densidade2;
            break;
        default:
            printf("Opção inválida.\n");
    }

    // Regra especial: se atributo é densidade, menor é melhor
    float soma1 = (op1 == 5 ? -valor1_c1 : valor1_c1) + (op2 == 5 ? -valor2_c1 : valor2_c1);
    float soma2 = (op1 == 5 ? -valor1_c2 : valor1_c2) + (op2 == 5 ? -valor2_c2 : valor2_c2);

    printf("\nSoma dos atributos:\n");
    printf("%s = %.2f | %s = %.2f\n", nome_cidade1, soma1, nome_cidade2, soma2);

    printf("\nResultado Final: ");
    soma1 > soma2 ? printf("%s venceu!\n", nome_cidade1) :
    soma2 > soma1 ? printf("%s venceu!\n", nome_cidade2) :
    printf("Empate!\n");

    return 0;
}
