#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
	char nome[20];
	char tipo[20];
	int integrantes;
}Bandas;

int op;
double areaTriangulo(double base, double altura);
double mediaAritmetica(double nota1, double nota2, double nota3);
double mediaPonderada(double nota1, double nota2, double nota3);
int parImpar(int num);
int primo(int p);
int valor(int num);
int somarMaioresQ50(int vet[], int qty);
float somaDosNumeros(float vet[], int qty);
int mediaValores(int vet[], int qty);
int menorValor(int vet[], int qty);
int maiorValor(int vet[], int qty);
void preecher(Bandas vet[]);
void ranking(Bandas vet[], int pos);
void tipoMusica(Bandas vet[], char tipo[]);
int bandaFav(char nome[], Bandas vet[]);
int bandaPos(char nome[], Bandas vet[]);


int main() {
	
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	do{
		printf("[?] Insira o número do exercício \n");
		scanf("%d", &op);
		system("cls");
		
		//feito
		if(op == 1){
			
			int op2;
			double base, altura;
			
			do{
				printf("[?] Insira o valor da base\n");
				scanf("%lf", &base);
				printf("[?] Insira o valor da altura\n");
				scanf("%lf", &altura);
				system("cls");
				
				printf("[!] Area do Triângulo: %f\n", areaTriangulo(base, altura));
				system("pause");
				system("cls");
				
				printf("[1] Calcular área\n");
				printf("[0] Terminar o programa\n");
				scanf("%d", &op2);
				
				system("cls");
			}while(op2 != 0);
			
		}
		//feito
		else if(op == 2){
			double nota1, nota2, nota3;
			char op2;
			
			printf("[?] Insira as 3 notas separadas por espaço\n");
			scanf("%lf %lf %lf", &nota1, &nota2, &nota3);
			system("cls");
			
			printf("[A] Media aritmética\n");
			printf("[P] Media ponderada\n");
			scanf(" %c", &op2);
			system("cls");
			
			if(tolower(op2) == 'a'){
				printf("[!] Média aritmética: %.2f\n", mediaAritmetica(nota1, nota2, nota3));
			}else if(tolower(op2) == 'p'){
				printf("[!] Média ponderada: %.2f\n", mediaPonderada(nota1, nota2, nota3));
			}else{
				printf("[!] Opção inválida\n");
			}	
		}
		//feito
		else if(op == 3){
			int num;
			
			printf("[?] Insira um número inteiro\n");
			scanf("%d", &num);
			system("cls");
			
			if(parImpar(num)){
				printf("[!] Par\n");
			}else{
				printf("[!] Impar\n");
			}
			
		}
		//feito
		else if(op == 4){
			int qty, num, soma = 0;

		    printf("[!] Insira a quantidade de números\n");
		    scanf("%d", &qty);
		    system("cls");
		
		    for (int i=0; i<qty; i++) {
		    	printf("[?] Insira o %dº número\n", i+1);
		        scanf("%d", &num);
		        system("cls");
		        
		        if (primo(num)) {
		            soma += num;
		        }
		    }
		    printf("[!] Soma: %d\n", soma);
		}
		//feito
		else if(op == 5){
			int num;
			
			printf("[!] Insira um valor inteiro\n");
			scanf("%d", &num);
			system("cls");
			
			printf("%d\n", valor(num));
		}
		//feito
		else if(op == 6){
			int qty;
		
		    printf("[?] Insira a quantidade de números\n");
			scanf("%d", &qty);
			system("cls");
			
			int vet[qty];
			
			for(int i=0; i<qty; i++){
				printf("[?] Insira o %dº numero\n", i+1);
				scanf("%d", &vet[i]);
				system("cls");
			}
		    printf("[!] Soma: %d\n", somarMaioresQ50(vet, qty));
		}
		//feito
		else if(op == 7){
			int qty;
		
		    printf("[?] Insira a quantidade de números\n");
			scanf("%d", &qty);
			system("cls");
			
			float vet[qty];
			
			for(int i=0; i<qty; i++){
				printf("[?] Insira o %dº numero\n", i+1);
				scanf("%f", &vet[i]);
				system("cls");
			}
			
			printf("[!] Soma dos numeros: %.2f\n", somaDosNumeros(vet, qty));
		}
		//feito
		else if(op == 8){
			int qty;
		
		    printf("[?] Insira a quantidade de números\n");
			scanf("%d", &qty);
			system("cls");
			
			int vet[qty];
			
			for(int i=0; i<qty; i++){
				printf("[?] Insira o %dº numero\n", i+1);
				scanf("%d", &vet[i]);
				system("cls");
			}
			
			printf("[!] A média dos valores do vector: %d\n", mediaValores(vet, qty));
			printf("[!] O menor valor do vector (sem considerar o último): %d\n", menorValor(vet, qty));
			printf("[!] O maior valor do vector: %d\n", maiorValor(vet, qty));
		}
		//feito
		else if(op == 9){
			int op2;
			Bandas vet[5];
			do{
				printf("[1] Inserir bandas\n");
				printf("[2] Pesquisa de banda por ranking\n");
				printf("[3] Pesquisa de banda por tipo de música\n");
				printf("[4] Pesquisa banda na lista dos favoritos\n");
				printf("[5] Pesquisa de posição da banda pelo nome\n");
				printf("[0] Sair\n");
				scanf("%d", &op2);
				
				switch(op2){
					case 1:
						preecher(vet);
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 0:
						break;
					default:
						printf("[!] Opção inválida\n");
				}
				
				system("pause");
				system("cls");
				
			}while(op2 != 0);
			
		}
		system("pause");
		system("cls");
	}while(op != 0);
}

// FUNÇÕES

//----------> 1 EXERCÍCIO <-------------
double areaTriangulo(double base, double altura){
	return (base * altura) / 2;
}

//----------> 2 EXERCÍCIO <-------------
double mediaAritmetica(double nota1, double nota2, double nota3){
    return (nota1 + nota2 + nota3) / 3;
}

double mediaPonderada(double nota1, double nota2, double nota3){
    return (nota1 * 5 + nota2 * 3 + nota3 * 2) / 10;
}

//----------> 3 EXERCÍCIO <-------------
int parImpar(int num){
	if(num % 2 == 0){
		return 1;
	}
	return 0;
}

//----------> 4 EXERCÍCIO <-------------
int primo(int p) {
    if (p == 1) {
        return 0;
    }

    for (int i = 2; i < p; i++) {
        if (p % i == 0) {
            return 0;
        }
    }
    return 1;
}

//----------> 5 EXERCÍCIO <-------------
int valor(int num){
	if(num > 0){
		return 1;
	}else if(num == 0){
		return 0;
	}else{
		return -1;
	}
}

//----------> 6 EXERCÍCIO <-------------
int somarMaioresQ50(int vet[], int qty) {
    int soma = 0;

    for (int i = 0; i < qty; i++) {
        if (vet[i] > 50) {
            soma += vet[i];
        }
    }

    return soma;
}

//----------> 7 EXERCÍCIO <-------------
float somaDosNumeros(float vet[], int qty){
	float soma = 0;
	for(int i=0; i<qty; i++){
		soma += vet[i];
	}
	
	return soma;
}

//----------> 8 EXERCÍCIO <-------------
int mediaValores(int vet[], int qty){
	int media = 0;
	
	for(int i=0; i<qty; i++){
		media += vet[i];
	}
	
	return media/qty;
}

int menorValor(int vet[], int qty){
	int menorValor = vet[0];
	
	for(int i=0; i<qty-1; i++){
		if(vet[i] < menorValor){
			menorValor = vet[i];
		}
	}
	
	return menorValor;
}

int maiorValor(int vet[], int qty){
	int maiorValor = vet[0];
	
	for(int i=0; i<qty; i++){
		if(vet[i] > maiorValor){
			maiorValor = vet[i];
		}
	}
	
	return maiorValor;
}

//----------> 9 EXERCÍCIO <-------------
void preecher(Bandas vet[]){
	
	for(int i=0; i<5; i++){
		printf("[?] Insira as informações da banda na %dº pos do RANKING\n\n", i+1);
		
		printf("[?] Insira o nome da banda\n");
		fflush(stdin);
		gets(vet[i].nome);
		printf("[?] Insira o tipo de música da banda\n");
		fflush(stdin);
		gets(vet[i].tipo);
		printf("[?] Insira o número de integrantes da banda\n");
		scanf("%d", &vet[i].integrantes);
		
		system("cls");
	}
	
	printf("[!] Banda preenchida com sucesso\n");
	
	
}

void ranking(Bandas vet[], int pos){
	printf("[?] Insira o Nº do Ranking\n");
	scanf("%d", &pos);
	
	if(pos > 0 && pos <=5){
		printf("[Nome da Banda]: %s\n", vet[pos-1].nome);
		printf("[Tipo de Música]: %s\n", vet[pos-1].tipo);
		printf("[Nº de Integrantes]: %d\n\n", vet[pos-1].integrantes);
	}else{
		printf("[!] Número de Ranking inválido\n");
	}
}

void tipoMusica(Bandas vet[], char tipo[]){
	int aux=0;
	for(int i=0; i<5; i++){
		if(vet[i].tipo == tipo){
			printf("[Nome da Banda]: %s\n", vet[i].nome);
			printf("[Tipo de Música]: %s\n", vet[i].tipo);
			printf("[Nº de Integrantes]: %d\n\n", vet[i].integrantes);
			aux++;
		}
	}
	if(aux == 0){
		printf("[!] Nada enontrado\n");
	}
}

int bandaFav(char nome[], Bandas vet[]){
	printf("[?] Insira o nome da banda\n");
	fflush(stdin);
	gets(nome);
	
	
	
	for(int i=0; i<5; i++){
		if(vet[i].nome == nome){
			return 1;
		}
	}
	return 0;
}

int bandaPos(char nome[], Bandas vet[]){
	printf("[?] Insira o nome da banda\n");
	fflush(stdin);
	gets(nome);
	
	
	
	for(int i=0; i<5; i++){
		int aux;
		if(vet[i].nome == nome){
			return i+1;
		}
	}
	return 0;
}

//----------> 10 EXERCÍCIO <------------

//----------> 11 EXERCÍCIO <------------

