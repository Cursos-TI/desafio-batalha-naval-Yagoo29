#include <stdio.h>

#define TAM_TABULEIRO 10   // Tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3        // Tamanho fixo dos navios
#define AGUA 0             // Valor que representa água
#define NAVIO 3            // Valor que representa parte de navio

// Função auxiliar para verificar se é possível posicionar o navio
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;

        // Verifica se está dentro dos limites
        if (l < 0 || l >= TAM_TABULEIRO || c < 0 || c >= TAM_TABULEIRO) {
            return 0; // Fora do tabuleiro
        }

        // Verifica se a posição já está ocupada
        if (tabuleiro[l][c] != AGUA) {
            return 0; // Sobreposição detectada
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i * dLinha][coluna + i * dColuna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas e direções: (linha inicial, coluna inicial, variação de linha, variação de coluna)
    // Horizontal → (0, 1)
    // Vertical   → (1, 0)
    // Diagonal ↘ → (1, 1)
    // Diagonal ↙ → (1, -1)

    // Navio horizontal
    if (podePosicionar(tabuleiro, 2, 4, 0, 1))
        posicionarNavio(tabuleiro, 2, 4, 0, 1);

    // Navio vertical
    if (podePosicionar(tabuleiro, 5, 7, 1, 0))
        posicionarNavio(tabuleiro, 5, 7, 1, 0);

    // Navio diagonal ↘
    if (podePosicionar(tabuleiro, 0, 0, 1, 1))
        posicionarNavio(tabuleiro, 0, 0, 1, 1);

    // Navio diagonal ↙
    if (podePosicionar(tabuleiro, 0, 9, 1, -1))
        posicionarNavio(tabuleiro, 0, 9, 1, -1);

    // Exibe o tabuleiro
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}