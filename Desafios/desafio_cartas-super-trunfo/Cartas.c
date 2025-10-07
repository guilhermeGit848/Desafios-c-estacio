
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
	char estado[50];
	char codigo[50];
	char cidade[50];
	int populacao;
	float area;
	float pib;
	int pontos_turisticos;
	float densidade_populacional;
	float pib_per_capita;
} Carta;


// Função para cadastrar uma carta
void cadastrar_carta(Carta *carta, int numero) {
	char pontos[50];
	printf("Digite os dados da carta %d:\n", numero);
	printf("Estado: ");
	scanf("%s", carta->estado);
	printf("Codigo: ");
	scanf("%s", carta->codigo);
	printf("Cidade: ");
	scanf("%s", carta->cidade);
	printf("População: ");
	scanf("%d", &carta->populacao);
	printf("Área: ");
	scanf("%f", &carta->area);
	printf("PIB: ");
	scanf("%f", &carta->pib);
	printf("Número de Pontos Turísticos: ");
	scanf("%s", pontos);
	carta->pontos_turisticos = atoi(pontos);
	// Calcula indicadores
	carta->densidade_populacional = carta->populacao / carta->area;
	carta->pib_per_capita = carta->pib / carta->populacao;
	printf("\n");
}

// Função para exibir uma carta
void exibir_carta(Carta carta, int numero) {
	printf("Carta %d - %s (%s):\n", numero, carta.cidade, carta.estado);
	printf("  População: %d\n", carta.populacao);
	printf("  Área: %.2f km2\n", carta.area);
	printf("  PIB: %.2f\n", carta.pib);
	printf("  Pontos Turísticos: %d\n", carta.pontos_turisticos);
	printf("  Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
	printf("  PIB per capita: %.2f\n", carta.pib_per_capita);
	printf("\n");
}

int main() {
	Carta carta1, carta2;

	// Cadastro das cartas
	cadastrar_carta(&carta1, 1);
	cadastrar_carta(&carta2, 2);

	// Exibe as cartas
	printf("=== Cartas do Super Trunfo ===\n\n");
	exibir_carta(carta1, 1);
	exibir_carta(carta2, 2);

	// Escolha do atributo para comparação (População)
	printf("Comparação de cartas (Atributo: População):\n\n");
	printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
	printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

	// Lógica de comparação
	if (carta1.populacao > carta2.populacao) {
		printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
	} else if (carta2.populacao > carta1.populacao) {
		printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
	} else {
		printf("Resultado: Empate!\n");
	}

	return 0;   
}                                                                                                                    