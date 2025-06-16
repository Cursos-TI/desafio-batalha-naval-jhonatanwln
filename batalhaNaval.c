#include <stdio.h>

#define TAM 5

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com 0
    int linha, coluna;
    int valido = 0;

    printf("=== JOGO DE BATALHA NAVAL ===\n");
    printf("Tabuleiro: 5 linhas x 5 colunas (coordenadas vão de 0 até 4)\n");
    printf("Você irá posicionar 2 navios de 3 espaços cada:\n");
    printf("- Um navio HORIZONTAL (ocupa 3 colunas na mesma linha)\n");
    printf("- Um navio VERTICAL (ocupa 3 linhas na mesma coluna)\n\n");

    // POSICIONAR NAVIO HORIZONTAL
    while (!valido) {
        printf("Digite a coordenada INICIAL do navio HORIZONTAL (3 posições)\n");
        printf("Exemplo válido: linha = 2, coluna = 1\n");
        printf("Linha (0 a 4): ");
        scanf("%d", &linha);
        printf("Coluna (0 a 2): ");
        scanf("%d", &coluna);

        if (linha >= 0 && linha < TAM && coluna >= 0 && coluna <= TAM - 3) {
            valido = 1;
        } else {
            printf("⚠️  Coordenadas inválidas! Tente novamente.\n\n");
        }
    }

    // Marca o navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 1;
    }

    // POSICIONAR NAVIO VERTICAL
    valido = 0;
    while (!valido) {
        printf("\nDigite a coordenada INICIAL do navio VERTICAL (3 posições)\n");
        printf("Exemplo válido: linha = 0, coluna = 3\n");
        printf("Linha (0 a 2): ");
        scanf("%d", &linha);
        printf("Coluna (0 a 4): ");
        scanf("%d", &coluna);

        if (linha >= 0 && linha <= TAM - 3 && coluna >= 0 && coluna < TAM) {
            // Verifica se tem colisão
            int colisao = 0;
            for (int i = 0; i < 3; i++) {
                if (tabuleiro[linha + i][coluna] == 1) {
                    colisao = 1;
                    break;
                }
            }

            if (!colisao) {
                valido = 1;
            } else {
                printf("⚠️  Colisão com o navio horizontal! Escolha outra posição.\n");
            }
        } else {
            printf("⚠️  Coordenadas inválidas! Tente novamente.\n");
        }
    }

    // Marca o navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 1;
    }

    // MOSTRAR O TABULEIRO
    printf("\n✅ Navios posicionados com sucesso!\n");
    printf("\nTabuleiro final (1 = parte do navio, 0 = água):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
