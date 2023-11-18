#include<stdio.h> //bibioteca de comunição com o usuario
#include<stdlib.h> // biblioteca de alocação de espaço em memória 
#include<locale.h> // biblioteca de alocação de texto por região 
#include<string.h> // biblioteca responsavel por cuidar das string

int registrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das strings 
	
	FILE*file;// cria o arquivo
	file = fopen(arquivo,"w");//cria o arquivo, abre o arquivo e escreve no arquivo
	fprintf(file,cpf);//salvo o valor da variavel 
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");

}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
		
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{
		printf("\n Essas são as informações do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");

} 

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE* file;
	file=fopen(cpf,"r");
	
	if (file=NULL)
	{
		printf("Usuário não encontrado.\n");
		system("pause");
	}
 
}
 int main ()
 {
 	int opcao=0; // definindo variaveis 
	int laco=1;
 	
	for(laco=1;laco=1;)
 	{
 		system("cls");
 		
 		setlocale(LC_ALL,"Portuguese");
 		printf("###Arquivo da EBAC###\n\n"); //definindo a linguagem 
 		
 		printf("Escolha a opção desejada no menu:\n\n");
 		printf("\t1-Registrar alunos\n");
 		printf("\t2-Consultar cadastros\n");
 		printf("\t3-Deletar cadastros\n\n");
 		printf("\t4- Sair do sistema\n");
 		printf("Opção:");
 		
		scanf("%d",&opcao); // armazenando a escolha do usuário 
 		
 		system("cls");
 		
 		switch(opcao)
		 { 	
		    case 1 :
		 		registrar();
		 		break; // encerrar 

		 	case 2 :
		 		consultar();
		 		break; 

		 	case 3 :
		 		consultar();
		 		break;
		 		
		 	case 4 :
			 printf("Obrigado por utilizar o sistema\n");
			 return 0;
			 break;
			 	
			default :
		 		printf("Essa opção não está disponivel!\n");
		 		system("pause");
		 		break;
		  } 
	 }
 }
