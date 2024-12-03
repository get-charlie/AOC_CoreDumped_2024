#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int get_num_pos(char* str, int pos)
{
    while(str[pos]){
        if(isdigit(str[pos])){
            return pos;
        }
        pos++;
    }
    fprintf(stderr, "Error en get_num_pos\n");
    exit(1);
}

int char_to_int(char ch)
{
    return ch - '0';
}

char get_letra(char* str, int pos)
{
    int len = strlen(str);
    while(!isalpha(str[pos]) && pos < len){
        pos = char_to_int(str[pos]) + pos;
    }
    return str[pos];
}

int letra_a_num(char ch)
{
    char* vec = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; vec[i]; i++){
        if(vec[i] == ch){
            return i + 1;
        }
    }
    fprintf(stderr, "Error en letra_a_num\n");
    exit(1);
}

int main(int argc, char **argv)
{
    FILE* f = fopen(argv[1], "r");
    if(f == NULL){
        fprintf(stderr, "Error: no se pudo abrir el fichero\n");
        exit(1);
    }
    int sum = 0;
    char buff[200];
    while(fgets(buff, sizeof(buff), f)){
        char letra = get_letra(buff, get_num_pos(buff, 0));
        sum += letra_a_num(letra);
    }
    printf("Total: %d\n", sum);
    return 0;
}













