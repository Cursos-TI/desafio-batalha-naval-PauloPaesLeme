#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Inicializa com água
        }
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

void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = -i; j <= i; j++) {
            int linha = origemLinha + i;
            int coluna = origemColuna + j;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                tabuleiro[linha][coluna] = 5; // Marca como área afetada
            }
        }
    }
}

void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    for (int i = -TAMANHO_HABILIDADE / 2; i <= TAMANHO_HABILIDADE / 2; i++) {
        int linha = origemLinha + i;
        int coluna = origemColuna + i;

        // Marca a coluna central da cruz
        if (linha >= 0 && linha < TAMANHO_TABULEIRO)
            tabuleiro[linha][origemColuna] = 5;

        // Marca a linha central da cruz
        if (coluna >= 0 && coluna < TAMANHO_TABULEIRO)
            tabuleiro[origemLinha][coluna] = 5;
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    for (int i = 0; i <= TAMANHO_HABILIDADE / 2; i++) {
        for (int j = -i; j <= i; j++) {
            int linhaCima = origemLinha - i;
            int linhaBaixo = origemLinha + i;
            int coluna = origemColuna + j;

            // Marca as linhas superior e inferior do losango
            if (linhaCima >= 0 && linhaCima < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO)
                tabuleiro[linhaCima][coluna] = 5;

            if (linhaBaixo >= 0 && linhaBaixo < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO)
                tabuleiro[linhaBaixo][coluna] = 5;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais das habilidades
    int origemConeLinha = 1, origemConeColuna = 4;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 3;

    aplicarHabilidadeCone(tabuleiro, origemConeLinha, origemConeColuna);
    aplicarHabilidadeCruz(tabuleiro, origemCruzLinha, origemCruzColuna);
    aplicarHabilidadeOctaedro(tabuleiro, origemOctaedroLinha, origemOctaedroColuna);

    printf("Tabuleiro com habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}