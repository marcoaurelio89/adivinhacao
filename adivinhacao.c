#include <stdio.h>
#include <stdlib.h> // Biblioteca necessária para usar o comando system, comando abs
#include <time.h>

//#define NUMERO_DE_TENTATIVAS 5 // diretiva é o nome do termo que acompanha o #, neste caso, diretiva define.(não estamos mais utilizando no jogo)

// Imprime cabeçalho do nosso jogo
int main() {
	
	system("chcp 65001 > nul"); // Define o código de página do cmd para UTF-8
		
		printf ("***************************************************\n");
		printf ("*                                                 *\n");
		printf ("*  W   W  EEEEE  L      CCCC   OOO  M   M  EEEEE  *\n"); 
		printf ("*  W   W  E      L     C      O   O MM MM  E      *\n");
		printf ("*  W W W  EEEE   L     C      O   O M M M  EEEE   *\n"); 
		printf ("*  W W W  E      L     C      O   O M   M  E      *\n");
		printf ("*  W   W  EEEEE  LLLLL  CCCC   OOO  M   M  EEEEE  *\n");
		printf ("*                                                 *\n");
		printf ("***************************************************\n");
		printf ("\n\n");

	int segundos = time(0);
	srand(segundos);

	int numeroGrande = rand();
			
	int numeroSecreto = numeroGrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;

	int acertou = 0;

	int nivel;
	
	printf ("Qual o nível de dificuldade?\n");
	printf ("(1)Fácil (2)Médio (3)Difícil\n\n");
	printf ("Escolha: ");
	scanf ("%d", &nivel);

	int numeroTentativas;
	
	switch (nivel) {
		case 1:
			numeroTentativas = 20;
			break;
			
		case 2:
			numeroTentativas = 10;
			break;
			
		default:
			numeroTentativas = 4;
			break;
	}
		
	for (int i = 1; i <= numeroTentativas; i++) {

		printf ("Tentativa %d\n", tentativas);
		printf ("Qual é o seu chute? ");
		scanf  ("%d", &chute);
		printf ("O seu chute foi %d\n", chute);
			
		if(chute < 0) {
			printf ("Você não pode chutar números negativos!\n");
			continue;
		}
			
		acertou = (chute == numeroSecreto);	
		int maior = chute > numeroSecreto;
			
		if(acertou) {
			break;
		}
			
		else if(maior) {
			printf ("Seu chute foi maior que o numero secreto.\n");
			printf ("Tente novamente.\n");
		}
		else { 
			printf ("Seu chute foi menor que o número secreto.\n");
			printf ("Tente novamente.\n");
		}
		tentativas++;
			
		double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
		pontos = pontos - pontosPerdidos;
	}	
	printf ("Fim de jogo!\n\n");	
			
	if(acertou){
		printf ("        Você ganhou!\n");
		printf ("	▒▒▒▒▒▒▒▒▒▒▒▒     \n"); 
		printf ("	▒▒▒▒▓▒▒▓▒▒▒▒     \n");
		printf ("	▒▒▒▒▓▒▒▓▒▒▒▒     \n");
		printf ("	▒▒▒▒▒▒▒▒▒▒▒▒     \n");
		printf ("	▒▓▒▒▒▒▒▒▒▒▓▒     \n");
		printf ("	▒▒▓▓▓▓▓▓▓▓▒▒     \n");
		printf ("	▒▒▒▒▒▒▒▒▒▒▒▒     \n");
		printf ("\n");
		
		printf ("Você acertou em %d tentativas\n", tentativas);
		printf ("Total de pontos: %.1f\n", pontos);
	} else {
		printf ("        Você perdeu! Tente de novo!            \n\n");					
		printf ("    GGGGGG      AA     MMM   MMM EEEEEE          \n");
		printf ("    GG         AAAA    MM M M MM EE              \n");  
		printf ("    GG GGG    AA  AA   MM  M  MM EEEE            \n");
		printf ("    GG  GG   AAAAAAAA  MM     MM EE              \n");
		printf ("    GGGGGG  AA      AA MM     MM EEEEEE        \n\n");
		
		printf ("     OOOO   VV      VV EEEEEE RRRRR              \n");
	    printf ("   OO    OO  VV    VV  EE     RR  RR             \n");
		printf ("   OO    OO   VV  VV   EEEEEE RR RR              \n");
		printf ("   OO    OO    VVVV    EE     RR  RR             \n");
		printf ("     OOOO       VV     EEEEEE RR   RR            \n");
	}
}