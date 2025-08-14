#include <stdio.h>

#define TAM_TABULEIRO 10   // Tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3        // Tamanho fixo dos navios
#define AGUA 0             // Valor que representa água
#define NAVIO 3            // Valor que representa parte de navio

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int i, j;

    // Inicializa todas as posições do tabuleiro com água (0)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais fixas (linha, coluna)
    // Navio horizontal: começa na linha 2, coluna 4
    int linhaH = 2, colunaH = 4;
    // Navio vertical: começa na linha 5, coluna 7
    int linhaV = 5, colunaV = 7;

    // Validação simples para garantir que cabem no tabuleiro
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO &&
        linhaV + TAM_NAVIO <= TAM_TABULEIRO) {

        // Posiciona navio horizontal
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }

        // Posiciona navio vertical
        for (i = 0; i < TAM_NAVIO; i++) {
            // Garante que não sobrepõe o navio horizontal
            if (tabuleiro[linhaV + i][colunaV] == AGUA) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            } else {
                printf("Erro: Sobreposição de navios detectada!\n");
                return 1; // Encerra o programa se houver sobreposição
            }
        }

    } else {
        printf("Erro: Coordenadas inválidas para o tamanho do navio.\n");
        return 1;
    }

    // Exibe o tabuleiro no console
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
