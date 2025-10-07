#include <stdio.h>

int main() {
	// Torre: 5 casas para a direita (for)
	printf("Movimento da Torre (5 casas para a Direita):\n");
	for (int torre = 1; torre <= 5; torre++) {
		printf("Direita\n");
	}
	printf("\n");

	// Bispo: 5 casas na diagonal para cima e direita (while)
	printf("Movimento do Bispo (5 casas na Diagonal Cima Direita):\n");
	int bispo = 1;
	while (bispo <= 5) {
		printf("Cima, Direita\n");
		bispo++;
	}
	printf("\n");

	// Rainha: 8 casas para a esquerda (do-while)
	printf("Movimento da Rainha (8 casas para a Esquerda):\n");
	int rainha = 1;
	do {
		printf("Esquerda\n");
		rainha++;
	} while (rainha <= 8);

	return 0;
}