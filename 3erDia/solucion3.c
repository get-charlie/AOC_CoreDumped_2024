#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define N 1000 

int char_to_int(char ch)
{
    return ch - '0';
}

int buscar_minas(int matriz[N][N], int posi, int posj)
{
    int veci[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int vecj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int suma = 0;
    for(int k = 0; k < 8; k++){
        int newi = posi + veci[k];
        int newj = posj + vecj[k];
        if(newi < N && newi >= 0 && newj < N && newj >= 0){
            suma += matriz[newi][newj];
        }
    }
    return suma;
}

int contar_minas(int matriz[N][N])
{
    int suma = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int vecinos = buscar_minas(matriz, i, j);
            printf("%d_%d_%d, ", i, j, vecinos);
            if(vecinos > 42){
                suma += matriz[i][j];
            }
        }
        printf("\n");
    }
    return suma;
}

int main(int argc, char **argv)
{
    FILE* f = fopen(argv[1], "r");
    if(f == NULL){
        fprintf(stderr, "No se pudo abrir el archivo\n");
        exit(1);
    }
    int matriz[N][N];
    char line[N + 2];
    int i = 0;
    while(fgets(line, N + 2, f)){
        for(int j = 0; j < N; j++){
            matriz[i][j] = char_to_int(line[j]);
            printf("%d, ", matriz[i][j]);
        }
        i++;
        printf("\n");
    }
    printf("Matriz cargada\n");
    for(i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Total: %d\n", contar_minas(matriz));
    return 0;
}













