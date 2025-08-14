#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

#define TAM_HAB 5 // tamanho fixo das matrizes de habilidade (5x5)

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona um navio com direção (dLinha, dColuna)
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                     int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;
        if (l >= 0 && l < TAM_TABULEIRO && c >= 0 && c < TAM_TABULEIRO) {
            tabuleiro[l][c] = NAVIO;
        }
    }
}

// Cria matriz de habilidade CONE apontando para baixo
void criarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = 0;
            // Preenche um cone: cada linha aumenta a largura
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i)) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Cria matriz de habilidade CRUZ
void criarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade OCTAEDRO (losango)
void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Distância de Manhattan em relação ao centro
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HAB][TAM_HAB],
                       int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int l = origemLinha + (i - centro);
                int c = origemColuna + (j - centro);
                // Valida limites
                if (l >= 0 && l < TAM_TABULEIRO && c >= 0 && c < TAM_TABULEIRO) {
                    if (tabuleiro[l][c] == AGUA) { // não sobrescreve navio
                        tabuleiro[l][c] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Posiciona navios
    posicionarNavio(tabuleiro, 2, 4, 0, 1); // horizontal
    posicionarNavio(tabuleiro, 5, 7, 1, 0); // vertical
    posicionarNavio(tabuleiro, 0, 0, 1, 1); // diagonal ↘
    posicionarNavio(tabuleiro, 0, 9, 1, -1); // diagonal ↙

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // centro no (4,4)
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      // centro no (7,2)
    aplicarHabilidade(tabuleiro, octaedro, 6, 7);  // centro no (6,7)

    // Exibe resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}