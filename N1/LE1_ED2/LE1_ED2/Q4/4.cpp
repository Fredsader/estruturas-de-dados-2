#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define MAX_BLOCO 100
#define TAM_MAX_LINHA 100

void intercalar(char *nomeArquivoSaida, char **nomesArquivosEntrada, int numBlocos) {
    FILE *arquivosEntrada[numBlocos];
    FILE *arquivoSaida;
    char linha[TAM_MAX_LINHA];

    for (int i = 0; i < numBlocos; i++) {
        arquivosEntrada[i] = fopen(nomesArquivosEntrada[i], "r");
        if (!arquivosEntrada[i]) {
            perror("Erro ao abrir arquivo de entrada");
            exit(1);
        }
    }

    arquivoSaida = fopen(nomeArquivoSaida, "w");
    if (!arquivoSaida) {
        perror("Erro ao abrir arquivo de saída");
        exit(1);
    }

    char **buffers = (char **)malloc(numBlocos * sizeof(char *));
    for (int i = 0; i < numBlocos; i++) {
        buffers[i] = (char *)malloc(TAM_MAX_LINHA * sizeof(char));
    }

    for (int i = 0; i < numBlocos; i++) {
        if (fgets(buffers[i], TAM_MAX_LINHA, arquivosEntrada[i]) == NULL) {
            buffers[i] = NULL;
        }
    }

    while (1) {
        int menorIndice = -1;
        for (int i = 0; i < numBlocos; i++) {
            if (buffers[i] != NULL) {
                if (menorIndice == -1 || strcmp(buffers[i], buffers[menorIndice]) < 0) {
                    menorIndice = i;
                }
            }
        }

        if (menorIndice == -1) {
            break;
        }

        fputs(buffers[menorIndice], arquivoSaida);

        if (fgets(buffers[menorIndice], TAM_MAX_LINHA, arquivosEntrada[menorIndice]) == NULL) {
            buffers[menorIndice] = NULL;
        }
    }

    for (int i = 0; i < numBlocos; i++) {
        fclose(arquivosEntrada[i]);
        free(buffers[i]);
    }
    fclose(arquivoSaida);
    free(buffers);
}

int compararLinhas(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void quicksort(char *nomeArquivoEntrada, char *nomeArquivoSaida, int numBlocos) {
    FILE *arquivoEntrada;
    char **blocos = (char **)malloc(numBlocos * sizeof(char *));
    
    arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    if (!arquivoEntrada) {
        perror("Erro ao abrir arquivo de entrada");
        exit(1);
    }
    
    for (int i = 0; i < numBlocos; i++) {
        blocos[i] = (char *)malloc(MAX_BLOCO * sizeof(char));
        if (!fgets(blocos[i], MAX_BLOCO, arquivoEntrada)) {
            break;
        }
    }
    
    fclose(arquivoEntrada);
    
    qsort(blocos, numBlocos, sizeof(char *), compararLinhas);
    
    char **nomesArquivosSaida = (char **)malloc(numBlocos * sizeof(char *));
    for (int i = 0; i < numBlocos; i++) {
        nomesArquivosSaida[i] = (char *)malloc(30 * sizeof(char));
        sprintf(nomesArquivosSaida[i], "bloco_%d.txt", i);
    }
    
    for (int i = 0; i < numBlocos; i++) {
        FILE *arquivoSaida = fopen(nomesArquivosSaida[i], "w");
        if (!arquivoSaida) {
            perror("Erro ao abrir arquivo de saída");
            exit(1);
        }
        fputs(blocos[i], arquivoSaida);
        fclose(arquivoSaida);
        free(blocos[i]);
    }
    
    intercalar(nomeArquivoSaida, nomesArquivosSaida, numBlocos);
    
    for (int i = 0; i < numBlocos; i++) {
        remove(nomesArquivosSaida[i]);
        free(nomesArquivosSaida[i]);
    }
    
    free(blocos);
    free(nomesArquivosSaida);
}


int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
    char *nomeArquivoEntrada = "dados.txt";
    char *nomeArquivoSaida = "saida.txt";
    int numBlocos = 22;

    quicksort(nomeArquivoEntrada, nomeArquivoSaida, numBlocos);

    printf("Ordenação externa concluída. Resultado em %s\n", nomeArquivoSaida);

    getch();
    return 0;
}
