#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

// Macro para printar uma string com uma quebra de linha.
#define printl(x) printf("%s\n", x)

// Esta struct representa uma carta do jogo Super Trunfo.
struct Carta{
    uint8_t estado, pontuacao;
    uint8_t nome[50];
    uint32_t codigo, populacao, pontos_turisticos;
    float area, pib, densidade_populacional, pib_per_capita;
};// uma struct serve para agrupar variáveis de tipos diferentes

void loadCard(struct Carta *carta); // carrega os dados da carta
void showCard(struct Carta *carta); // exibe os dados da carta

int main(){
    struct Carta cartas[2]; // Declaração das duas cartas.

    printl("Carta 1");
    loadCard(&cartas[0]); // carrega os dados da carta 1
    showCard(&cartas[0]); // exibe os dados da carta 1

    while (getchar() != '\n'); // apenas limpa o buffer do stdin

    printl("Carta 2");
    loadCard(&cartas[1]); // carrega os dados da carta 2
    showCard(&cartas[1]); // exibe os dados da carta 2

    // Compara os atributos das cartas e atribui pontos.
    if (cartas[0].populacao > cartas[1].populacao)
        cartas[0].pontuacao++;
    else if (cartas[0].populacao < cartas[1].populacao)
        cartas[1].pontuacao++;

    if (cartas[0].area > cartas[1].area)
        cartas[0].pontuacao++;
    else if (cartas[0].area < cartas[1].area)
        cartas[1].pontuacao++;

    if (cartas[0].pib_per_capita > cartas[1].pib_per_capita)
        cartas[0].pontuacao++;
    else if (cartas[0].pib_per_capita < cartas[1].pib_per_capita)
        cartas[1].pontuacao++;

    if (cartas[0].pib > cartas[1].pib)
        cartas[0].pontuacao++;
    else if (cartas[0].pib < cartas[1].pib)
        cartas[1].pontuacao++;

    if (cartas[0].densidade_populacional < cartas[1].densidade_populacional)
        cartas[0].pontuacao++;
    else if (cartas[0].densidade_populacional > cartas[1].densidade_populacional)
        cartas[1].pontuacao++;

    if (cartas[0].pontos_turisticos > cartas[1].pontos_turisticos)
        cartas[0].pontuacao++;
    else if (cartas[0].pontos_turisticos < cartas[1].pontos_turisticos)
        cartas[1].pontuacao++;

    if (cartas[0].pontuacao > cartas[1].pontuacao) {
        printf("Carta 1 Ganhou!, Poder: %d\n", cartas[0].pontuacao);
    }else if (cartas[0].pontuacao < cartas[1].pontuacao) {
        printf("Carta 2 Ganhou!, Poder: %d\n", cartas[1].pontuacao);
    }

    return 0;
}

// Função para exibir os detalhes de uma carta.
void showCard(struct Carta *carta) {
    printf("\n--- Detalhes da Carta ---\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %c0%d\n", carta->estado, carta->codigo);
    printf("Nome: %s\n", carta->nome);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f Km²\n", carta->area);
    printf("Densidade populacional: %.2f hab/Km²\n", carta->densidade_populacional);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("PIB per capita: %.2f reais\n", carta->pib_per_capita);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("-------------------------\n");
}

void loadCard(struct Carta *carta){
    printf("Digite o estado (A até H): ");
    carta->estado = getchar();
    // scanf(" %c", &carta->estado); // Lê um caractere (o estado).

    printf("Digite o código da carta (1 até 4): ");
    scanf(" %u", &carta->codigo); // Lê um inteiro sem sinal (o codigo).

    printf("Digite o nome do estado: ");
    scanf(" %[^\n]", carta->nome); // Lê uma string (o nome da cidade).

    printf("Digite a população: ");
    scanf(" %u", &carta->populacao); // Lê um inteiro sem sinal (a quantidade da população).

    printf("Digite a área: ");
    scanf(" %f", &carta->area); // Lê um float (a área).

    printf("Digite o PIB: ");
    scanf(" %f", &carta->pib); // Lê um float (o PIB).

    printf("Digite a quantidade de pontos turísticos: ");
    scanf(" %u", &carta->pontos_turisticos); // Lê um inteiro sem sinal (a quantidade de pontos turísticos).

    // Calcula a densidade populacional.
    // carta.densidade_populacional = carta.populacao / carta.area;
    carta->densidade_populacional = (float)carta->populacao / carta->area;

    // Calcula o PIB per capita.
    // carta->pib_per_capita = carta->pib / carta->populacao;
    carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao;
}
