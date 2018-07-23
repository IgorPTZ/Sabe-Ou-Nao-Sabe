#include "Conexao.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

# define TAM 20


typedef struct{
    char * enunciado;
    char * alternativaA;
    char * alternativaB;
    char * alternativaC;
    char * alternativaD;
    char resposta;
}Pergunta;


Pergunta pergunta[TAM];
int acertos = 0;
int erros = 0;


void menu(void);


void menu(void){

    void criarPergunta(void);
    void jogar(void);

    int opcao;
    criarPergunta();

    while(opcao != 3){

        system("cls");
        printf("Sabe ou N�o Sabe! - Linguagem C\n\n1-Jogar\n2-Score\n3-Sair\n\nOp��o desejada:");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:
                jogar();
                break;

            case 2:
                obterScore();
                break;

            case 3:
                break;

            default:
                printf("\nOp��o inv�lida\n");
                system("PAUSE");
                break;

        } // fim do switch

    } // fim do while

}

void jogar(void){

    void apresentarPergunta(void);

    setbuf(stdin,"NULL");

    do{
        system("cls");
        setbuf(stdin,"NULL");
        apresentarPergunta();
    }while(erros < 3 && acertos < 10);

    if(acertos == 10){
        system("cls");
        printf("Parab�ns ! Voc� alcan�ou 10 acertos!\nVoc� realmente sabe muito sobre a linguagem C!\n\n");
        printf("Acertos(%d/10)\nErros(%d/3)",acertos,erros);
        system("PAUSE");

        salvarScore(acertos);
        acertos = 0;
        erros = 0;
        return;
    }

    if(erros == 3){
        system("cls");
        printf("GAME OVER!\n\nVoc� errou muitas perguntas!\n\nAcertos(%d/10)\n\n",acertos);
        system("PAUSE");

        if(acertos >= 5){
            salvarScore(acertos);
        }
        acertos = 0;
        erros = 0;
        return;
    }

}


void apresentarPergunta(void){


    srand(time(NULL));
    int escolhida = rand() % 19;
    char resposta;

    printf("%s\n",pergunta[escolhida].enunciado);
    printf("%s\n",pergunta[escolhida].alternativaA);
    printf("%s\n",pergunta[escolhida].alternativaB);
    printf("%s\n",pergunta[escolhida].alternativaC);
    printf("%s\n",pergunta[escolhida].alternativaD);
    printf("\n\nDigite a letra correspondente a alternativa");
    resposta = getch();

    if(resposta == pergunta[escolhida].resposta){
        acertos++;
        printf("\n\nVoc� acertou!\n");
        system("PAUSE");
    }else{
        erros++;
        printf("\n\nVoc� errou!\n");
        system("PAUSE");
    }

}


void criarPergunta(void){

setlocale(LC_ALL,"portuguese");

pergunta[0].enunciado = "Qual o nome do tipo de dados para valores de ponto flutuante?";
pergunta[0].alternativaA = "a) int";
pergunta[0].alternativaB = "b) inteiro";
pergunta[0].alternativaC = "c) doub";
pergunta[0].alternativaD = "d) float";
pergunta[0].resposta = 'd';

pergunta[1].enunciado = "Qual o nome da fun��o utilizada para gerar valores pseudo-aleat�rios?";
pergunta[1].alternativaA = "a) rand";
pergunta[1].alternativaB = "b) srand";
pergunta[1].alternativaC = "c) aleatory";
pergunta[1].alternativaD = "d) time";
pergunta[1].resposta = 'a';

pergunta[2].enunciado = "Uma variavel declarada dentro de uma fun��o tem escopo...";
pergunta[2].alternativaA = "a) global";
pergunta[2].alternativaB = "b) local";
pergunta[2].alternativaC = "c) aleatorio";
pergunta[2].alternativaD = "d) modular";
pergunta[2].resposta = 'b';


pergunta[3].enunciado = "Um...cont�m um endere�o de outra variavel que contem um valor.";
pergunta[3].alternativaA = "a) variavel estatica";
pergunta[3].alternativaB = "b) vetor";
pergunta[3].alternativaC = "c) struct";
pergunta[3].alternativaD = "d) ponteiro";
pergunta[3].resposta = 'd';


pergunta[4].enunciado = "C � uma linguagem de programa��o...";
pergunta[4].alternativaA = "a) Improvisada";
pergunta[4].alternativaB = "b) Procedural";
pergunta[4].alternativaC = "c) Orientada a objetos";
pergunta[4].alternativaD = "d) Funcional";
pergunta[4].resposta = 'b';

pergunta[5].enunciado = "O operador ... � utilizado para retornar o endere�o de seu operando";
pergunta[5].alternativaA = "a) &";
pergunta[5].alternativaB = "b) **";
pergunta[5].alternativaC = "c) NULL";
pergunta[5].alternativaD = "d) if";
pergunta[5].resposta = 'a';

pergunta[6].enunciado = "Uma String representa um vetor de...";
pergunta[6].alternativaA = "a) int";
pergunta[6].alternativaB = "b) char";
pergunta[6].alternativaC = "c) double";
pergunta[6].alternativaD = "d) string";
pergunta[6].resposta = 'b';

pergunta[7].enunciado = "O unico inteiro que pode ser atribuido a um ponteiro � o...";
pergunta[7].alternativaA = "a) 1";
pergunta[7].alternativaB = "b) 10";
pergunta[7].alternativaC = "c) -1";
pergunta[7].alternativaD = "d) 0";
pergunta[7].resposta = 'd';

pergunta[8].enunciado = "C armazena lista de valores em...";
pergunta[8].alternativaA = "a) inteiros";
pergunta[8].alternativaB = "b) arrylists";
pergunta[8].alternativaC = "c) vetores";
pergunta[8].alternativaD = "d) tabelas";
pergunta[8].resposta = 'c';

pergunta[9].enunciado = "Tipo de ponteiro que nao pode ser desreferenciado";
pergunta[9].alternativaA = "a) * int";
pergunta[9].alternativaB = "b) * char";
pergunta[9].alternativaC = "c) * string";
pergunta[9].alternativaD = "d) * void";
pergunta[9].resposta = 'd';

pergunta[10].enunciado = "A biblioteca string.h realiza o tratamento de...";
pergunta[10].alternativaA = "a) inteiros";
pergunta[10].alternativaB = "b) frases";
pergunta[10].alternativaC = "c) nomes";
pergunta[10].alternativaD = "d) strings";
pergunta[10].resposta = 'd';

pergunta[11].enunciado = "Caso as strings sejam iguais,a funcao strcmp retornar� o valor...";
pergunta[11].alternativaA = "a) 1";
pergunta[11].alternativaB = "b) 0";
pergunta[11].alternativaC = "c) -1";
pergunta[11].alternativaD = "d) 5";
pergunta[11].resposta = 'b';

pergunta[12].enunciado = "A funcao memcpy retorna um ponteiro do tipo...";
pergunta[12].alternativaA = "a) * int";
pergunta[12].alternativaB = "b) int";
pergunta[12].alternativaC = "c) * void";
pergunta[12].alternativaD = "d) * string";
pergunta[12].resposta = 'c';

pergunta[13].enunciado = "Como � chamado o caractere adicionado ao final das strings?";
pergunta[13].alternativaA = "a) nulo";
pergunta[13].alternativaB = "b) final";
pergunta[13].alternativaC = "c) void";
pergunta[13].alternativaD = "d) null";
pergunta[13].resposta = 'a';

pergunta[14].enunciado = "Como � chamada a fun��o utilizada para concatenar strings?";
pergunta[14].alternativaA = "a) cont";
pergunta[14].alternativaB = "b) strcat";
pergunta[14].alternativaC = "c) cat";
pergunta[14].alternativaD = "d) concat";
pergunta[14].resposta = 'b';

pergunta[15].enunciado = "... � uma diretiva de pr�-processador utilizada para incluir bibliotecas";
pergunta[15].alternativaA = "a) #null";
pergunta[15].alternativaB = "b) #typedef";
pergunta[15].alternativaC = "c) #define";
pergunta[15].alternativaD = "d) #include";
pergunta[15].resposta = 'd';

pergunta[16].enunciado = "... � uma diretiva de pr�-processador utilizada para definir constantes";
pergunta[16].alternativaA = "a) #null";
pergunta[16].alternativaB = "b) #typedef";
pergunta[16].alternativaC = "c) #define";
pergunta[16].alternativaD = "d) #include";
pergunta[16].resposta = 'c';

pergunta[17].enunciado = "... � uma fun��o que transforma um caractere min�sculo em mai�sculo";
pergunta[17].alternativaA = "a) upper";
pergunta[17].alternativaB = "b) toupper";
pergunta[17].alternativaC = "c) upWord";
pergunta[17].alternativaD = "d) isdigit";
pergunta[17].resposta = 'b';

pergunta[18].enunciado = "... � uma fun��o que transforma um caractere mai�sculo em min�sculo";
pergunta[18].alternativaA = "a) upper";
pergunta[18].alternativaB = "b) toupper";
pergunta[18].alternativaC = "c) tolower";
pergunta[18].alternativaD = "d) isxdigit";
pergunta[18].resposta = 'c';

pergunta[19].enunciado = "A biblioteca ctype.h realiza o tratamento de...";
pergunta[19].alternativaA = "a) inteiros";
pergunta[19].alternativaB = "b) caracteres";
pergunta[19].alternativaC = "c) strings";
pergunta[19].alternativaD = "d) letras";
pergunta[19].resposta = 'b';

}


