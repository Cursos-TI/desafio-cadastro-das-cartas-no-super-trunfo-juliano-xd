#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

// Macro para printar uma string com uma quebra de linha.
#define printl(x) printf("%s\n", x)

/* Esta struct representa uma carta do jogo Super Trunfo.
*/
struct Carta{
    char estado;
    int codigo; // 0, 1, 3, 4
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

int main(){
    struct Carta carta; // Declaração de uma carta.

    // Preenchimento da carta.
    printl("Digite o estado (A até H):");
    scanf("%c", &carta.estado); // Lê um caractere (o estado).

    printl("Digite o código da carta (1 até 4):");
    scanf("%u", &carta.codigo); // Lê um inteiro sem sinal (o codigo).

    printl("Digite o nome do estado (Sem espaços):");
    scanf("%s", carta.nome); // Lê uma string (o nome da cidade).

    printl("Digite a população:");
    scanf("%u", &carta.populacao); // Lê um inteiro sem sinal (a quantidade da população).

    printl("Digite a área:");
    scanf("%f", &carta.area); // Lê um float (a área).

    printl("Digite o PIB");
    scanf("%f", &carta.pib); // Lê um float (o PIB).

    printl("Digite a quantidade de pontos turísticos:");
    scanf("%u", &carta.pontos_turisticos); // Lê um inteiro sem sinal (a quantidade de pontos turísticos).

    /* Estas linhas apenas printam os valores da carta.
    */
    printf("Estado: %c\n", carta.estado);
    printf("Código: %c0%u\n", carta.estado ,carta.codigo); // O código da carta é impresso com o estado.
    printf("Nome: %s\n", carta.nome);
    printf("População: %u\n", carta.populacao);
    printf("Área: %.2f Km²\n", carta.area);

    // Calcula a densidade populacional.
    // carta.densidade_populacional = carta.populacao / carta.area;
    carta.densidade_populacional = (float)carta.populacao / carta.area;
    printf("Densidade populacional: %.2f hab/Km²\n", carta.densidade_populacional);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);

    // Calcula o PIB per capita.
    // carta.pib_per_capita = carta.pib / carta.populacao;
    carta.pib_per_capita = (carta.pib * 1000000000) / carta.populacao;
    printf("PIB per capita: %.2f reais\n", carta.pib_per_capita);

    printf("Pontos turísticos: %u\n", carta.pontos_turisticos);

    return 0;
}
