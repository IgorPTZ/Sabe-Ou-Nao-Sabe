/*
*  Cabe�alho de fun��es implementados no m�dulo Pergunta.c
*/


/*
* Fun��o responsavel por apresentar as op��es disponiveis ao usuario.
* Apenas esta fun��o deve e tem acesso as fun��es criarPergunta,jogar e score.
* A chamada da fun��o criarPergunta � gerada automaticamente e ocorre apenas uma vez.
*/
void menu(void);


/*
* Fun��o responsavel por lan�ar indiretamente as perguntas ao usuario
* Apresenta os resultados ao final do jogo
* Fica responsavel pela chamada da fun��o que salva o score do jogador no banco de dados.
*/
void jogar(void);

/*
* Fun��o resposavel por criar as perguntas
* As informa��es da pergunta (Enunciado,alternativas e resposta) s�o armazenadas em um vetor de struct
* Essa fun��o � chamada apenas uma vez durante toda a execu��o do programa.
*/
void criarPergunta(void);

/*
* Fun��o responsavel por apresentar as informa��es das perguntas ao usu�rio
* Consulta um vetor de struct global que contem as informa��es das perguntas
*/
void apresentarPergunta(void);
