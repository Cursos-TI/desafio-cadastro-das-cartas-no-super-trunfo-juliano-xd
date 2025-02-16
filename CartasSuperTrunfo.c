// Feito por Juliano-xd

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

// Macro para printar uma string com uma quebra de linha, (apenas uma facilidade).
#define printl(x) printf("%s\n", x)

/* Esta struct representa uma carta do jogo Super Trunfo. */
struct Carta{
    char estado;
    int codigo; // 0, 1, 3, 4
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

int main(){
    struct Carta carta; // Declaração de uma carta.

    // Preenchimento da carta.
    printl("Digite o estado (A até H):");
    scanf("%c", &carta.estado); // Lê um caractere (o estado) , ainda nao foi implementado nenhuma verificação.

    printl("Digite o código da carta (1 até 4):");
    scanf("%u", &carta.codigo); // Lê um inteiro sem sinal (o codigo da carta), tambem sem verificação.

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

    /* Estas linhas apenas printam os valores da carta */
    printf("Estado: %c\n", carta.estado);
    printf("Código: %c0%u\n", carta.estado ,carta.codigo); // O código da carta é impresso com o estado.
    printf("Nome: %s\n", carta.nome);
    printf("População: %u\n", carta.populacao);
    printf("Área: %.2f Km²\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Pontos turísticos: %u\n", carta.pontos_turisticos);
    return 0;
}
