/*
*  Cabeçalho de funções implementados no módulo Pergunta.c
*/


/*
* Função responsavel por apresentar as opções disponiveis ao usuario.
* Apenas esta função deve e tem acesso as funções criarPergunta,jogar e score.
* A chamada da função criarPergunta é gerada automaticamente e ocorre apenas uma vez.
*/
void menu(void);


/*
* Função responsavel por lançar indiretamente as perguntas ao usuario
* Apresenta os resultados ao final do jogo
* Fica responsavel pela chamada da função que salva o score do jogador no banco de dados.
*/
void jogar(void);

/*
* Função resposavel por criar as perguntas
* As informações da pergunta (Enunciado,alternativas e resposta) são armazenadas em um vetor de struct
* Essa função é chamada apenas uma vez durante toda a execução do programa.
*/
void criarPergunta(void);

/*
* Função responsavel por apresentar as informações das perguntas ao usuário
* Consulta um vetor de struct global que contem as informações das perguntas
*/
void apresentarPergunta(void);
