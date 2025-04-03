#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Inicializa com água
        }
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // Marca as posições como parte do navio
    }
}

void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // Marca as posições como parte do navio
    }
}

void posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3; // Marca as posições na diagonal principal
    }
}

void posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3; // Marca as posições na diagonal secundária
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 3;
    int linhaVertical = 5, colunaVertical = 7;
    int linhaDiagonalPrincipal = 0, colunaDiagonalPrincipal = 0;
    int linhaDiagonalSecundaria = 6, colunaDiagonalSecundaria = 9;

    // Validação simplificada: garantindo que os navios fiquem dentro dos limites
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaDiagonalPrincipal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonalPrincipal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaDiagonalSecundaria + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonalSecundaria - TAMANHO_NAVIO >= -1) {
        
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
        posicionarNavioDiagonalPrincipal(tabuleiro, linhaDiagonalPrincipal, colunaDiagonalPrincipal);
        posicionarNavioDiagonalSecundaria(tabuleiro, linhaDiagonalSecundaria, colunaDiagonalSecundaria);
    } else {
        printf("Erro: As coordenadas dos navios estão fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("Tabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}