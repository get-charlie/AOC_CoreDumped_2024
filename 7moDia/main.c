#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define PSIZE   1000

int prog[PSIZE];
int vals[PSIZE];
int exec[PSIZE];
int pc;
int accum;

typedef enum {
    NOP, ACC, JMP,
} Inst;

static bool is_int(char* word)
{
    if(word == NULL || word[0] == '\0'){
        return false;
    }
    int i = 0;
    if(word[i] == '-' || word[i] == '+'){
        i++;
    }
    while(word[i]) {
        if(!isdigit(word[i])){
            return false;
        }
        i++;
    }
    return true;
}

#define DELIM       " \n\t"
#define MAX_LINE    100

static int load_prog(FILE* file)
{
    char line[MAX_LINE];
    int  cur_dir = 0;
    while(fgets(line, MAX_LINE, file)){
        char* tok = strtok(line, DELIM);
        while(tok != NULL){
            if(!strcmp(tok, "nop")){
                prog[cur_dir] = NOP;
            }
            else if(!strcmp(tok, "acc")){
                prog[cur_dir] = ACC;
                tok = strtok(NULL, DELIM);
                vals[cur_dir] = atoi(tok);
            }
            else if(!strcmp(tok, "jmp")){
                prog[cur_dir] = JMP;
                tok = strtok(NULL, DELIM);
                vals[cur_dir] = atoi(tok);
            }
            tok = strtok(NULL, DELIM);
            cur_dir++;
        }
    }
    return cur_dir;
}

int main (int argc, char **argv)
{
    FILE* file = fopen(argv[1], "r");
    if(file == NULL){
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }
    int max_dir = load_prog(file);
    fclose(file);

    while(pc < max_dir){
        exec[pc]++;
        if(exec[pc] == 2){
            break;
        }
        printf("pc: %4d val: %4d ", pc, vals[pc]);
        if(prog[pc] == NOP){
            printf("NOP");
            pc++;
        }
        else if(prog[pc] == ACC){
            printf("ACC");
            accum += vals[pc];
            pc++;
        }
        else if(prog[pc] == JMP){
            printf("JMP");
            pc += vals[pc];
        }
        printf(" acc: %4d \n", accum);
    }
    return 0;
}













