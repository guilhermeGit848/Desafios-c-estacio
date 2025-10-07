#include <stdio.h>

// Tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
	// Matriz do tabuleiro: 0 = água, 3 = navio
	int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

	// Inicializa o tabuleiro com água
	for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
		for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
			tabuleiro[linha][coluna] = 0;
		}
	}

	// Vetores para os navios (valores não são usados, só o tamanho)
	int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
	int navio_vertical[TAM_NAVIO] = {3, 3, 3};

	// Coordenadas iniciais dos navios (definidas no código)
	int linhaHorizontal = 2, colunaHorizontal = 4; // Navio horizontal começa na linha 2, coluna 4
	int linhaVertical = 5, colunaVertical = 7; // Navio vertical começa na linha 5, coluna 7

	// Validação simples: garantir que os navios cabem e não se sobrepõem
	int sobreposicao = 0;
	// Verifica se o navio horizontal cabe
	if (colunaHorizontal + TAM_NAVIO > TAM_TABULEIRO) {
		printf("Navio horizontal fora do tabuleiro!\n");
		return 1;
	}
	// Verifica se o navio vertical cabe
	if (linhaVertical + TAM_NAVIO > TAM_TABULEIRO) {
		printf("Navio vertical fora do tabuleiro!\n");
		return 1;
	}
	// Verifica sobreposição
	for (int deslocamento = 0; deslocamento < TAM_NAVIO; deslocamento++) {
		if (linhaHorizontal == linhaVertical + deslocamento && colunaHorizontal + deslocamento == colunaVertical) {
			sobreposicao = 1;
		}
	}
	if (sobreposicao) {
		printf("Navios sobrepostos!\n");
		return 1;
	}

	// Posiciona navio horizontal
	for (int deslocamento = 0; deslocamento < TAM_NAVIO; deslocamento++) {
		tabuleiro[linhaHorizontal][colunaHorizontal + deslocamento] = navio_horizontal[deslocamento];
	}
	// Posiciona navio vertical
	for (int deslocamento = 0; deslocamento < TAM_NAVIO; deslocamento++) {
		tabuleiro[linhaVertical + deslocamento][colunaVertical] = navio_vertical[deslocamento];
	}

	// Exibe o tabuleiro
	printf("Tabuleiro de Batalha Naval:\n");
	for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
		for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
			printf("%d ", tabuleiro[linha][coluna]);
		}
		printf("\n");
	}

	return 0;
}
