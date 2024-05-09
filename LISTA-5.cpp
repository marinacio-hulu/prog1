#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    char letra;
    int quantidade;
}TipoLetra;

typedef struct{
    char nome[20];
    float altura;
    float peso;
    char bi[14];
    char sexo;
} Pessoa;

typedef struct{
	int numero_conta;
	char titular[20];
	float saldo;
} Conta;

typedef struct {
	char nome[50];
	float c;
	float f;
} TipoCidade;

int main(){
	int op;
	
	do{
		
		printf("------> Insira o numero do exercicio: ");
		scanf("%d", &op);
		system("cls");
		
		if(op==1){
			TipoLetra v_letras[26];
			char frase[20];
			
			for(int i=0; i<26; i++) {
		        v_letras[i].letra = 'a' + i;
		        v_letras[i].quantidade = 0;
		    }
		    
		    printf("Insira uma frase: ");
		    fflush(stdin);
		    gets(frase);
		    
		    int qty = strlen(frase);
		    
		    for(int i=0; i<26; i++){
		    	for(int j=0; j<qty; j++){
		    		if(isalpha(frase[j])){
		    			if(v_letras[i].letra == frase[j]){
		    				v_letras[i].quantidade = v_letras[i].quantidade + 1;
						}
					}
				}
			}
			
			for (int i=0; i<26; i++) {
		        printf("Letra %c: %d\n", v_letras[i].letra, v_letras[i].quantidade);
		    }
		}
		else if(op==2){
			int i;
			Pessoa pessoas[3];
			int op2, cadastros=0;
			
			do{
				printf("1- Inserir Registro \n2- Localizar Registro\n3- Sair\n");
				scanf("%d", &op2);
				
				system("cls");
				
				if(op2==1){
					if(cadastros < 3){
						printf("Nome: ");
	                    fflush(stdin);
		    			gets(pessoas[cadastros].nome);
	                    printf("Altura: ");
	                    scanf("%f", &pessoas[cadastros].altura);
	                    printf("Peso: ");
	                    scanf("%f", &pessoas[cadastros].peso);
	                    printf("BI: ");
	                    fflush(stdin);
		    			gets(pessoas[cadastros].bi);
	                    printf("Sexo M ou F: ");
	                    scanf("%c", &pessoas[cadastros].sexo);
	                    cadastros++;
						
					}else{
						printf("Máximo de registros alcançados\n");
					}
				}else if(op2==2){
					char bi[14];
					
					printf("Insira o Nº do BI: ");
					fflush(stdin);
					gets(bi);
					
					for(i=0; i<cadastros; i++){
						if(strcmp(bi, pessoas[i].bi) == 0){
							printf("Cadastro encontrado: \n\n");
							printf("Nome: %s \n", pessoas[i].nome);
	                        printf("Altura: %.2f\n", pessoas[i].altura);
	                        printf("Peso: %.2f\n", pessoas[i].peso);
	                        printf("BI: %d\n", pessoas[i].bi);
	                        printf("Sexo: %c\n", pessoas[i].sexo);
	                        break;
						}
					}
					
					if(i == cadastros){
						printf("Cadastro nao encontrado\n");
					}
					
				}else if(op2==3){
					printf("Saindo...\n");
				}
				system("pause");
				system("cls");
				
			}while(op2!=3);
			
		}
		else if(op==3){
			Conta contas[3];
			
			
			printf("+-----------------------------+\n");
			printf("| M A R I N A C I O - B A N K |\n");
			printf("+-----------------------------+\n");
			printf("\n\n");
			printf("+-----------------------------------+\n");
			printf("| A B E R T U R A   D E   C O N T A |\n");
			printf("+-----------------------------------+\n");
			printf("\n");
			for(int i=0; i<3; i++){
				printf("Nome: ");
				fflush(stdin);
				gets(contas[i].titular);
				printf("N de Conta: ");
				scanf("%d", &contas[i].numero_conta);
				printf("Deposito Inicial: ");
				scanf("%f", &contas[i].saldo);
				
				system("cls");
			}
			
			
			int numero_conta, login=0;
			int j=0;
			do{
				printf("+-----------+-----------------------------+\n");
				printf("| L O G I N | N U M E R O  D E  C O N T A |\n");
				printf("+-----------+-----------------------------+\n");
				printf("\n\n");
				
				scanf("%d", &numero_conta);
				
				
				
				for(j=0; j<3; j++){
					if(contas[j].numero_conta == numero_conta){
						printf("Seja bem vindo(a), %s\n", contas[j].titular);
						login=1;
					}
				}
				system("cls");
			}while(login != 1);
			
			login = j;
			
			int op2;
			float valor;
			
			do{
				printf("+-----------------------------+\n");
				printf("| M A R I N A C I O - B A N K |\n");
				printf("+-----------------------------+\n");
				printf("| 1 - D E P O S I T O         |\n");
				printf("+-----------------------------+\n");
				printf("| 2 - L E V A N T A M E N T O |\n");
				printf("+-----------------------------+\n");
				printf("| 0 - L O G O U T             |\n");
				printf("+-----------------------------+\n");
				
				scanf("%d", &op2);
				system("cls");
				
				if(op2==1){
					printf("Insira o valor a ser depositado: ");
					scanf("%f", &valor);
					
					contas[login].saldo += valor;
				}else if(op2==2){
					printf("Insira o valor a ser levantado: ");
					scanf("%f", &valor);
					
					contas[login].saldo -= valor;
				}
				printf("N Conta: %d\n", contas[login].numero_conta);
				printf("Titular: %s\n", contas[login].titular);
				printf("Saldo: %.2f\n", contas[login].saldo);
				
				system("pause");
				system("cls");
				
			}while(op2!=0);
		}
		else if(op==4){
			TipoCidade cidades[2];
		    float media = 0;
		    int t_max = 0;
		    int t_min = 0;
		
		    for(int i=0; i<2; i++){
		        printf("Insira o nome da cidade: ");
		        fflush(stdin);
		        gets(cidades[i].nome);
		
		        printf("Insira a temperatura em ºC: ");
		        scanf("%f", &cidades[i].c);
		
		        
		        cidades[i].f = (float) (cidades[i].c * 1.8) + 32;
		    }
		    
		    t_max = cidades[0].c;
		    t_min = cidades[0].c;
		    
		    for(int i=0; i<2; i++){
		        if (cidades[i].c > t_max) {
		            t_max = cidades[i].c;
		        }
		
		        if (cidades[i].c < t_min) {
		        	t_min = cidades[i].c;
		        }
		
		        media += cidades[i].c;
			}
		
		    media /= (float) 2;
		
		    printf("As cidades e suas temperaturas:\n");
		    for(int i=0; i<2; i++){
		        printf("Cidade: %s \nTemperatura em graus: %.2f ºC \nTemperatura em fahrenheit: %.2f ºF\n", cidades[i].nome, cidades[i].c, cidades[i].f);
		        printf("\n\n");
		    }
		
		    printf("Temperatura média: %.2f ºC\n", media);
		    printf("Temperatura máxima: %d ºC\n", t_max);
		    printf("Temperatura mínima: %d ºC\n", t_min);
		}
		else if(caso==5){
			
		}
		system("pause");
		system("cls");
		
	}while(op!=0);
	
    
}
