#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main (){
//cabe�alho
setlocale(LC_ALL, "Portuguese");
printf("\n\n");	
printf("		          P  /_\\  P                              	\n");
printf("		         /_\\_|_|_/_\\                             	\n");
printf("		     n_n | ||. .|| | n_n         Bem vindo ao    	\n");
printf("		     |_|_|nnnn nnnn|_|_|     Jogo de Adivinha��o!	\n");	
printf("		    |_____| ' _ ' |_____|                        	\n");
printf("		          \\__|_|__/								\n");
printf("\n\n");	




//aleatoriedade	
	int segundos = time(0);
	srand(segundos);
	int numerogrande = rand();
	int numerosecreto = numerogrande % 100;
//pontos 
	int chute = 0;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;
	
//Escolha do n�vel
	int numerodetentativas = 0;
	int nivel = 0;
	printf("(1)N�vel f�cil (2)N�vel m�dio (3)N�vel dif�cil\n\n");
	printf("Escolha seu n�vel: ");
	scanf("%d",&nivel);	

//Escolha do n�vel	
	switch(nivel){
		case 1:
			numerodetentativas =  15;
		break;
		case 2:
			numerodetentativas = 10;
		break;
		default:
			
			numerodetentativas = 6;
		break; 
	}
	
//Inicio do jogo 
		int i=0;
	for(i = 1; i <= numerodetentativas; i++){
		printf ("Tentativa %d\n", tentativas);
		printf ("Qual � o seu chute? ");
		scanf ("%d",&chute);
		
		if (chute < 0){
			printf("Voc� n�o pode chutar n�meros negativos!\n");
			continue; 
		}
	
		acertou = chute == numerosecreto;
		int maior = chute > numerosecreto;
		
		if (acertou){
			break;
		}
		else if (maior){
			printf ("Seu chute foi maior que o n�mero secreto\n");
		} else {
			printf ("Seu chute foi menor que o n�mero secreto\n ");
		}
		
		tentativas++;	
		
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}


//Vit�ria ou Derrota	
	printf ("Fim de jogo!\n");
	if(acertou){
		printf("Voc� ganhou!\n");
		printf ("Voc� acertou em %d tentativas!\n", tentativas);
		printf ("Total de pontos %.1f\n",pontos);
	}else {
		printf("Voc� perdeu!Tente novamente!");
	} 
	
}






