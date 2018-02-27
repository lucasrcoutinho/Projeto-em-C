#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_materia //Armazena o nome de uma materia
{
char materia[50];
};

struct tipo_aluno //Armazena o nome de um aluno e todas as materia que está matriculado
{
char nome[50];//Um nome de aluno   		
tipo_materia materias[50];//Até 50 materias podem ser cadastradas
};


int cadastro(int opcao, tipo_aluno aluno[], int qtd_alunos);
void menu(tipo_aluno aluno[],int qtd_alunos);

void main()
{
tipo_aluno aluno[100];
int qtd_alunos=0;
menu(aluno, qtd_alunos);
system ("pause");
}

void menu(tipo_aluno aluno[],int qtd_alunos)
{
int opc;
printf("Digite o numero da opcao desejada:\n");
printf("1-Cadastrar um aluno\n");
printf("2-Matricular um aluno em uma materia\n");
printf("3-Cadastrar um gupo de alunos\n");
printf("4-Matricular um gupo de alunos em uma materia\n");
printf("5-Matricular um gupo de alunos em um gupo de materias\n");
scanf("%i", &opc);
cadastro(opc, aluno, qtd_alunos);
}


int cadastro(int opcao, tipo_aluno aluno[], int qtd_alunos)
{
int i=0, i_aluno_cadastrado;
char nomeAluno[50],materia[50];//Usados para busca na struct
switch(opcao)
{
case 1:
	system ("cls");
	printf("Digite o nome do aluno\n");
	scanf("%i");//Limpa lixo (fflush não funciona)
	gets_s(aluno[qtd_alunos].nome);
	qtd_alunos++;
	menu(aluno, qtd_alunos);
	break;

case 2:
	system ("cls");
	printf("Digite o nome do aluno que deseja matricular\n");
	scanf("%i");//Limpa lixo (fflush não funciona)
	gets_s(nomeAluno);
	for (i=0;i<=qtd_alunos;i++)//Busca e verifica se o aluno está cadastrado
		{
		if(strcmp(nomeAluno,aluno[i].nome)==0)
			{
			i_aluno_cadastrado=i;
			printf("Aluno encontrado\n");
			}		
		}
	
	printf("Digite o nome da materia\n");
	scanf("%i");
	gets_s(materia);
		while((aluno[i_aluno_cadastrado].materias[i].materia)!=NULL)//Busca materia na grade do aluno, caso não encotre cadastra como nova
		{
		if(strcmp(materia,aluno[i_aluno_cadastrado].materias[i].materia)==0)
			{
			printf("Materia ja cadastrada na grade\n");
			menu(aluno, qtd_alunos);
			return(0);
			}			
		i++;		
		}
	printf("Materia cadastrada com sucesso\n");
	menu(aluno, qtd_alunos);
	break;

		 
default:
	break;
	return(0);

}


/*do 	{
	scanf("%c", &aluno[0].nome[i]);
	i++;
	}while (aluno[0].nome[i-1]!=';');	

while(j<i-1)
	{
	printf("%c",aluno[0].nome[j]);
	j++;
	}
*/


}