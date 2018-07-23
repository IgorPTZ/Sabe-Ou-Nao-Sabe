#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <string.h>

#define SIZE 5
#define SIZE_Q 50

MYSQL conexao;
int statusConexao;


void salvarScore(int score){

    char nome[SIZE];
    char query[SIZE_Q];

    setbuf(stdin,NULL);
    mysql_init(&conexao);

    system("cls");
    printf("Armazenamento de score\n\n");
    printf("Digite um apelido (três digitos):");
    fgets(nome,SIZE,stdin);
    nome[strcspn(nome,"\n")] = 0;

        if(mysql_real_connect(&conexao, "localhost", "root", "", "score", 3306, NULL, 0)){

            sprintf(query,"INSERT INTO jogador values('%s','%d');",nome,score);

            if(!mysql_query(&conexao,query)){
                printf("\nScore salvo com sucesso!\n");
            }
            else{
                printf("\nFalha na conexão, tente novamente\n");
            }
            system("PAUSE");
            mysql_close(&conexao);

        }
        else{
            printf("Falha na conexão,tente novamente\n");
            system("PAUSE");
        }


}


void obterScore(void){

    mysql_init(&conexao);
    MYSQL_RES * resp;
    MYSQL_ROW linhas;
    MYSQL_FIELD * campos;
    int contador;
    char query [] = "SELECT * FROM jogador ORDER BY acertos DESC;";

        system("cls");
        printf("Melhores scores\n\n");
        if(mysql_real_connect(&conexao, "localhost", "root", "", "score", 3306, NULL, 0)){

            if(mysql_query(&conexao,query)){
                printf("Falha na conexão,tente novamente\n");
                system("PAUSE");
            }else{

                resp = mysql_store_result(&conexao);

                if(resp){

                    campos = mysql_fetch_field(resp);

                    for(contador = 0; contador < mysql_num_fields(resp); contador++){
                        printf("%s",(campos[contador].name));

                        if(mysql_num_fields(resp) > 1){
                            printf("\t");
                        }
                    }

                    printf("\n\n");

                    while((linhas = mysql_fetch_row(resp)) != NULL){

                        for(contador = 0; contador < mysql_num_fields(resp); contador++){
                            printf("%s\t",linhas[contador]);
                        }

                        printf("\n");

                    }

                }

                printf("\n");
                system("PAUSE");
                mysql_free_result(resp);
                mysql_close(&conexao);

            }

        }
        else{
            printf("\nFalha na conexão\n");
            system("PAUSE");
        }

}
