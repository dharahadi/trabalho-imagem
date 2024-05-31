#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int R;
    int G;
    int B;
} Pixel;

void imagemCinza(Pixel **matriz, int linhas, int colunas, int valormax) {
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            int valorCinza = (int)(matriz[j][i].R * 0.30 + matriz[j][i].G * 0.59 + matriz[j][i].B * 0.11);
            matriz[j][i].R = valorCinza;
            matriz[j][i].G = valorCinza;
            matriz[j][i].B = valorCinza;
        }
    }

    FILE* imgCinza = fopen("imagemCinza.ppm", "w");
    if (imgCinza == NULL) {
        printf("Erro ao criar o arquivo de imagem cinza.\n");
        exit(1);
    }

    fprintf(imgCinza, "P2\n");
    fprintf(imgCinza, "%d %d\n", colunas, linhas);
    fprintf(imgCinza, "%d\n", valormax);

    
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            fprintf(imgCinza, "%d ", matriz[j][i].R); 
        }
        fprintf(imgCinza, "\n");
    }
    fclose(imgCinza);
}

void imagemNegativa(Pixel **matriz, int linhas, int colunas, int valormax){
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            matriz[j][i].R = (255 - matriz[j][i].R);
            matriz[j][i].G = (255 - matriz[j][i].G);
            matriz[j][i].B = (255 - matriz[j][i].B);
        }
    }
    FILE *imgNegativa = fopen("imagemNegativa.ppm", "w");

    if (imgNegativa == NULL) {
        printf("Erro ao criar o arquivo de imagem negativa.\n");
        return;
    }

    fprintf(imgNegativa, "P3\n");
    fprintf(imgNegativa, "%d %d\n", colunas, linhas);
    fprintf(imgNegativa, "%d\n", valormax);

    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            fprintf(imgNegativa, "%d %d %d ", matriz[j][i].R, matriz[j][i].G, matriz[j][i].B);
        }
        fprintf(imgNegativa, "\n");
    }    
    fclose(imgNegativa);
}

void imagemAumentaBrilho(Pixel **matriz, int linhas, int colunas, int valormax){
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            matriz[j][i].R = matriz[j][i].R + 50;
            if (matriz[j][i].R > 255){
            matriz[j][i].R = 255;
            }
            matriz[j][i].G = matriz[j][i].G + 50;
            if (matriz[j][i].G > 255){
            matriz[j][i].G = 255;
            }
            matriz[j][i].B = matriz[j][i].B + 50;
            if (matriz[j][i].B > 255){
            matriz[j][i].B = 255;
            }
        }
    }
    

    FILE *imgMaisBrilho = fopen("imagemMaisBrilho.ppm", "w");

    if (imgMaisBrilho == NULL) {
        printf("Erro ao criar o arquivo de imagem com brilho aumentado.\n");
        return;
    }

    fprintf(imgMaisBrilho, "P3\n");
    fprintf(imgMaisBrilho, "%d %d\n", colunas, linhas);
    fprintf(imgMaisBrilho, "%d\n", valormax);

    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            fprintf(imgMaisBrilho, "%d %d %d ", matriz[j][i].R, matriz[j][i].G, matriz[j][i].B);
        }
        fprintf(imgMaisBrilho, "\n");
    }    
    fclose(imgMaisBrilho);

}


void imagemDiminuiBrilho(Pixel **matriz, int linhas, int colunas, int valormax){
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            matriz[j][i].R = matriz[j][i].R - 50;
            if (matriz[j][i].R < 0){
            matriz[j][i].R += 50;
            }
            matriz[j][i].G = matriz[j][i].G - 50;
            if (matriz[j][i].G < 0){
            matriz[j][i].G += 50;
            }
            matriz[j][i].B = matriz[j][i].B - 50;
            if (matriz[j][i].B < 0){
            matriz[j][i].B += 50;
            }
        }
    }
    

    FILE *imgMenosBrilho = fopen("imagemMenosBrilho.ppm", "w");

    if (imgMenosBrilho == NULL) {
        printf("Erro ao criar o arquivo de imagem com brilho diminuido.\n");
        return;
    }

    fprintf(imgMenosBrilho, "P3\n");
    fprintf(imgMenosBrilho, "%d %d\n", colunas, linhas);
    fprintf(imgMenosBrilho, "%d\n", valormax);

    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            fprintf(imgMenosBrilho, "%d %d %d ", matriz[j][i].R, matriz[j][i].G, matriz[j][i].B);
        }
        fprintf(imgMenosBrilho, "\n");
    }    
    fclose(imgMenosBrilho);

}

void rotacionarImagem(Pixel **matriz, int linhas, int colunas, int valormax) {
    Pixel **matrizRotacionada = (Pixel **)malloc(colunas * sizeof(Pixel *));
    for (int i = 0; i < colunas; i++) {
        matrizRotacionada[i] = (Pixel *)malloc(linhas * sizeof(Pixel));
    }

    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            matrizRotacionada[i][linhas - 1 - j] = matriz[j][i];
        }
    }

    FILE *imgRotacionada = fopen("imagemRotacionada.ppm", "w");
    if (imgRotacionada == NULL) {
        printf("Erro ao criar o arquivo de imagem rotacionada.\n");
        exit(1);
    }

    fprintf(imgRotacionada, "P3\n");
    fprintf(imgRotacionada, "%d %d\n", linhas, colunas);
    fprintf(imgRotacionada, "%d\n", valormax);

    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            fprintf(imgRotacionada, "%d %d %d ", matrizRotacionada[i][j].R, matrizRotacionada[i][j].G, matrizRotacionada[i][j].B);
        }
        fprintf(imgRotacionada, "\n");
    }

    for (int i = 0; i < colunas; i++) {
        free(matrizRotacionada[i]);
    }
    free(matrizRotacionada);
    fclose(imgRotacionada);
}

void imagemEnvelhecida(Pixel **matriz, int linhas, int colunas, int valormax) {
    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            //reduzir os valores de R, G, e B
            matriz[j][i].R = (int)(matriz[j][i].R * 0.8);
            matriz[j][i].G = (int)(matriz[j][i].G * 0.7);
            matriz[j][i].B = (int)(matriz[j][i].B * 0.5);
        }
    }

    FILE* imgEnvelhecida = fopen("imagemEnvelhecida.ppm", "w");
    if (imgEnvelhecida == NULL) {
        printf("Erro ao criar o arquivo de imagem envelhecida.\n");
        exit(1);
    }

    fprintf(imgEnvelhecida, "P3\n");
    fprintf(imgEnvelhecida, "%d %d\n", colunas, linhas);
    fprintf(imgEnvelhecida, "%d\n", valormax);

    for (int j = 0; j < linhas; j++) {
        for (int i = 0; i < colunas; i++) {
            fprintf(imgEnvelhecida, "%d %d %d ", matriz[j][i].R, matriz[j][i].G, matriz[j][i].B);
        }
        fprintf(imgEnvelhecida, "\n");
    }
    fclose(imgEnvelhecida);
}




int main() {
    char imagem[100];

    printf("TRABALHO 1 - PROGRAMAÇÃO DE BAIXO NÍVEL\n Desenvolvedores: Dhara Hadi, Renata Hess e Samuel Morales\n Professor: Anderson Terroso\n\n");
    printf("Insira o nome da imagem [modelo nome.ppm]: \n");
    scanf("%s", imagem);

    FILE *fp = fopen(imagem, "r");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; //erro
    }

    char formato[3];
    fscanf(fp, "%2s", formato); //le formato
    printf("Formato: %s", formato);
    

    int colunas, linhas;
    fscanf(fp, "%d %d", &colunas, &linhas); //le tamanho
    printf("O tamanho da imagem é de %dx%d\n", colunas, linhas);

    int valormax;
    fscanf(fp, "%d", &valormax); //le valor máximo por pixel
    printf("O valor máximo por pixel é: %d\n", valormax);

    // alocação da matriz de pixels
    Pixel **matriz = (Pixel **)malloc(linhas * sizeof(Pixel *));
        for (int i = 0; i < linhas; i++) {
        matriz[i] = (Pixel *)malloc(colunas * sizeof(Pixel));

    }

    // preenchimento da matriz com os valores RGB
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(fp, "%d %d %d", &matriz[i][j].R, &matriz[i][j].G, &matriz[i][j].B);
        }
    }

int opc;
printf("MENU: \n 1. Criar uma imagem tom de cinza;\n 2. Criar uma imagem negativa;\n 3. Aumentar o brilho;\n 4. Diminuir o brilho;\n 5. Rotacionar a imagem 90º;\n 6. Envelhecimento da imagem;\n 7. Encerrar o programa;\n\n Digite o número da opção desejada: \n");
scanf("%d", &opc);

if (opc < 1 || opc > 7) {
    printf("Insira um valor válido (1 a 7): \n");
    scanf("%d", &opc);
}

    switch(opc){
    case 1:
    //criar uma imagem tom de cinza 
    imagemCinza(matriz, linhas, colunas, valormax);
    break;
    
    case 2:
    //criar uma imagem negativa 
    imagemNegativa(matriz, linhas, colunas, valormax);
    break;

    case 3:
    //aumentar o brilho 
    imagemAumentaBrilho(matriz, linhas, colunas, valormax);
    break;
    
    case 4:
    //diminuir o brilho
    imagemDiminuiBrilho(matriz, linhas, colunas, valormax);

    break;

    case 5:
    //rotacionar a imagem 90º 
    rotacionarImagem(matriz, linhas, colunas, valormax);

    break;
    
    case 6:
    //envelhecimento da imagem 
    imagemEnvelhecida(matriz, linhas, colunas, valormax);

    break;

    case 7:
    printf("Programa encerrado.");
    break;
}

    fclose(fp); //fecha o arquivo

    return 0;
}