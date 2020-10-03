/*Bibliotecas para o programas*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>

/*01 - Estrutura do endere�o*/
typedef struct
{
	char logradouro[15];
	char complemento[50];
	char bairro[30];
	char cidade[20];
	char estado[3];
	char cep[10];
}address;

/*02 - Estrutura da filial*/
typedef struct
{
	int codigo;
	char nome[50];
	char descri��o[100];
	char cnpj[14];
	address endereco;
}branch;

/*03 - Estrutura do usu�rio*/
typedef struct
{
	int codigo;
	char nome[50];
	char telefone[12];
	char email[100];
	char cpf[11];
	char usuario[50];
	char senha[50];
	char senha2[20];
	address endereco;
}user;

/*04 - Estrutura do paciente*/
typedef struct
{
	int codigo;
	char nome[50];
	char telefone[12];
	char email[100];
	char cpf[11];
	address endereco;
}patient;

/*05 - Estrutura do medico*/
typedef struct
{
	int codigo;
	char nome[50];
	char telefone[12];
	char email[100];
	char cpf[11];
	char especialidade[50];
	branch filial;
	address endereco;

}doctor;

/*06 - Estrutura do agendamento*/
typedef struct
{
	int codigo;
	char servico[30];
	patient paciente;
	doctor medico;
	char data;
	char horario;
	char periodo[20];
	char status;
}scheduling;

FILE* puser, * ppatient, * pdoctor, * pfilial, * pendereco, * plogin;

/*M�todos do programa*/
char menu_principal();
char menu_cadastros();
char menu_consultas();
void main_cadastro();
void main_consulta();
void cad_usuario();
void con_usuario();
void cad_paciente();
void con_paciente();
void cad_medico();
void con_medico();
void cad_filial();
void con_filial();
void cad_agendamentos();
void con_agendamentos();
void limpabuffer(void);


/*MENU PRINCIPAL*/
char menu_principal()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o
	system("cls");

	printf("	        ========   CLIMANAGER   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu principal                   |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Menu de cadastros                      |\n");
	printf("    |       [2] - Menu de consultas                      |\n");
	printf("    |       [3] - Sair do Programa                       |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");

	printf("\nFavor selecionar alguma op��o: \n\n");

	return _getch();
}

char menu_cadastros()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o
	system("cls");

	printf("	        ========   CLIMANAGER   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu de cadastros                |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Cadastros usu�rios                     |\n");
	printf("    |       [2] - Cadastrar pacientes                    |\n");
	printf("    |       [3] - Cadastrar m�dicos                      |\n");
	printf("    |       [4] - Cadastrar filial                       |\n");
	printf("    |       [5] - Cadastrar agendamentos                 |\n");
	printf("    |       [6] - Voltar ao menu principal               |\n");
	printf("    |       [7] - Sair do Programa                       |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");

	printf("\nFavor selecionar alguma op��o: \n\n");

	return getchar();
}

char menu_consultas()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o
	system("cls");

	printf("	        ========   CLIMANAGER   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu de consultas                |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Consultar usu�rios                     |\n");
	printf("    |       [2] - Consultar pacientes                    |\n");
	printf("    |       [3] - Consultar m�dicos                      |\n");
	printf("    |       [4] - Consultar filial                       |\n");
	printf("    |       [5] - Consultar agendamentos                 |\n");
	printf("    |       [6] - Voltar ao menu principal               |\n");
	printf("    |       [7] - Sair do Programa                       |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");

	printf("\nFavor selecionar alguma op��o: \n\n");

	return getchar();
}

/*MAIN COM SWITCH*/
void main()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o
	char str1[50] = "str";
	char str2[50] = "str2";
	int i, k, g, tam3 = 0;;
	char a[50];
	char crip_msg[50];
	int tam_msg;
	user cususario;

volta:

	k = 0; g = 0;

	/* CADASTRO DO USU�RIO PADR�O*/
	char const* buscar = "adminstrador";
	char buscar2[50];

	system("mkdir dados");
	puser = fopen("dados\\cad_funcionario.txt", "a+");

	if (puser == NULL) {
		perror("dados\\cad_funcionario.txt");
		return 1;
	}
	while (fscanf(puser, "%s", buscar2) || (fscanf(puser, "%s", buscar2) != buscar))
	{
		if (strcmp(buscar, buscar2) != 0)
		{
			fprintf(puser, "\n --- U: administrador S: firnsnxywfitw ---     \n\n");
			fclose(puser);
			break;
		}
	}
	if (ferror(puser)) {
		printf("error: %s\n", strerror(errno));
	}

	/*PAINEL DE LOGIN*/

	puser = fopen("dados\\cad_funcionario.txt", "r");
	system("cls");

	printf("\n============ PAINEL DE LOGIN ============\n\n");

	printf("\nFavor digitar o seu usu�rio e senha!\n");
	printf("\nLOGIN: ");
	gets(cususario.usuario);
	printf("\nSENHA: ");


	/*ADICIONANDO MASCARA NA SENHA*/
	//do
	//{
	//	cususario.senha[tam3] = _getch();
	//	if (cususario.senha[tam3] == 0x08 && tam3 > 0)  //Backspace
	//	{
	//		printf("\b \b");
	//		cususario.senha[tam3] = 0x00;
	//		tam3--;

	//	}
	//	else if (cususario.senha[tam3] == 13) // Enter
	//	{
	//		cususario.senha[tam3] = 0x00;
	//		break;
	//	}
	//	else if (cususario.senha[tam3] != 0x08)
	//	{
	//		putchar('*');
	//		tam3++;
	//	}
	//} while (tam3 < 13);

	char buffer[256] = { 0 };
	char c;
	int pos = 0;

	do {
		c = _getch();

		if (isprint(c))
		{
			cususario.senha[pos++] = c;
			printf("%c", '*');
		}
		else if (c == 8 && pos)
		{
			cususario.senha[pos--] = '\0';
			printf("%s", "\b \b");
		}
	} while (c != 13);

	/*REALIZA A BUSCA NO ARQUIVO DO USU�RIO E SENHA, A SENHA ELE COMPARA O VALOR DIGITADO CRIPTOGRAFADO
	COM O VALOR CRIPTOGRAFADO QUE EST� NO ARQUIVO*/

	while (fscanf(puser, "%s", a) != EOF) {
		if (strcmp(a, cususario.usuario) == 0) {

			g = 1;
			break;
		}
	}

	tam_msg = strlen(cususario.senha);
	for (i = 0; i < tam_msg; i++)
	{
		crip_msg[i] = cususario.senha[i] + 5;
	}

	while (fscanf(puser, "%s", a) != EOF) {
		if (strcmp(a, crip_msg) == 0) {
			k = 1;
			break;
		}
	}
	fclose(puser);
	if (k == 1 && g == 1) {
		printf("\n\nLOGADO");
	}
	else {
		printf("\n\nUsu�rio ou senha inv�lido!\n\n");
		//(void)getchar();
		//(void)getchar();
		goto volta;
	}
	printf("\n\n\n");
	(void)getchar();

	/*ACESSO AO MENU*/
inicio:
	switch (menu_principal())
	{
	case '1': main_cadastro();	break;
	case '2': main_consulta();	break;
	case '3': goto fim;
		exit(0);
	}

	printf("\n\n");
	system("pause");
	goto inicio;
fim:
	;

}

void main_cadastro()
{
inicio:
	switch (menu_cadastros())
	{
	case '1': cad_usuario();		break;
	case '2': cad_paciente();		break;
	case '3': cad_medico(); 		break;
	case '4': cad_filial(); 		break;
	case '5': cad_agendamentos(); 	break;
	case '6': menu_principal();		break;
	case '7': goto fim;
		exit(0);
	}

	printf("\n\n");
	system("pause");
	goto inicio;
fim:
	;
}

void main_consulta()
{

inicio:
	switch (menu_consultas())
	{
	case '1': con_usuario();		break;
	case '2': con_paciente();		break;
	case '3': con_medico(); 		break;
	case '4': con_filial(); 		break;
	case '5': con_agendamentos(); 	break;
	case '6': menu_principal();		break;
	case '7': goto fim;
		exit(0);
	}

	printf("\n\n");
	system("pause");
	goto inicio;
fim:
	;
}

/*SE��O USU�RIOS*/
void cad_usuario()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o

	system("mkdir dados");
	puser = fopen("dados\\cad_funcionario.txt", "a");
	user cfuncionario;
	int tam = 0, tam2 = 0, i;
	char crip_msg[100];
	int tam_msg;
	memset(cfuncionario.usuario, 0x00, sizeof(cfuncionario.usuario));
	memset(cfuncionario.senha, 0x00, sizeof(cfuncionario.senha));
	memset(cfuncionario.senha2, 0x00, sizeof(cfuncionario.senha2));

	/*Buscar �ltimo c�digo cadastrado*/

	/*Cadastro dos dados*/
	printf("\033[2J\033[1;1H");
	printf("CADASTRO DE FUNCIONARIOS\n\n");

	printf("\n\nCodigo do funcionario: \n");
	scanf_s("%d", &cfuncionario.codigo);
	(void)getchar();

	printf("\n\nNome do funcionario: \n");
	gets(cfuncionario.nome);

	printf("\n\nTelefone do funcionario: \n");
	gets(cfuncionario.telefone);

	printf("\n\nE-mail do funcionario: \n");
	gets(cfuncionario.email);

	printf("\n\nCPF do funcionario: \n");
	gets(cfuncionario.cpf);

	printf("\n\nUsu�rio para funcionario: \n");
	gets(cfuncionario.usuario);

	/* ---------- TRATAMENTO NO CAMPO SENHA ---------- */

inicio:

	tam = 0;
	tam2 = 0;

	printf("\n\nSenha do usu�rio: \n");
	fflush(stdin);

	do
	{
		cfuncionario.senha[tam] = _getch();
		if (cfuncionario.senha[tam] == 0x08 && tam > 0)  //Backspace
		{
			printf("\b \b");
			cfuncionario.senha[tam] = 0x00;
			tam--;

		}
		else if (cfuncionario.senha[tam] == 13) // Enter
		{
			cfuncionario.senha[tam] = 0x00;
			break;
		}
		else if (cfuncionario.senha[tam] != 0x08)
		{
			putchar('*');
			tam++;
		}
	} while (tam < 50);


	printf("\n\nDigite a senha novamente: \n");

	fflush(stdin);

	do
	{
		cfuncionario.senha2[tam2] = _getch();
		if (cfuncionario.senha2[tam2] == 0x08 && tam > 0)  //Backspace
		{
			printf("\b \b");
			cfuncionario.senha2[tam2] = 0x00;
			tam2--;

		}
		else if (cfuncionario.senha2[tam2] == 13) // Enter
		{
			cfuncionario.senha2[tam2] = 0x00;
			break;
		}
		else if (cfuncionario.senha2[tam2] != 0x08)
		{
			putchar('*');
			tam2++;
		}
	} while (tam2 < 50);


	if (strcmp(cfuncionario.senha, cfuncionario.senha2) != 0)
	{
		printf("\nAs senhas n�o conferem!\n\n");
		goto inicio;
	}
	else
	{
		printf("\n\n--------- Localiza��o --------- \n\n");

		printf("\n\nEstado da Usuario: \n");
		gets(cfuncionario.endereco.estado);

		printf("\n\nCidade da Usuario: \n");
		gets(cfuncionario.endereco.cidade);

		printf("\n\nBairro da Usuario: \n");
		gets(cfuncionario.endereco.bairro);

		printf("\n\nLogradouro da Usuario: \n");
		gets(cfuncionario.endereco.logradouro);

		printf("\n\nComplemento da Usuario: \n");
		gets(cfuncionario.endereco.complemento);

		printf("\n\nCEP da Usuario: \n");
		gets(cfuncionario.endereco.cep);

		printf("\n\nUsu�rio cadastrado com sucessso!");
		goto fim;
	}

fim:


	/*GRAVAR OS DADOS NO ARQUIVO DE TEXTO*/
	fprintf(puser, "%s\n\n", "\n ==============  Funcionario Cadastrado  ============== ");
	//hora
	time_t mytime;
	char dataehora[100];
	mytime = time(NULL);
	strftime(dataehora, sizeof(dataehora), "%d.%m.%Y - %H:%M:%S", localtime(&mytime));
	fprintf(puser, "Data/Hora: %s\n", dataehora);
	fprintf(puser, "\n");


	tam_msg = strlen(cfuncionario.senha);
	for (i = 0; i < tam_msg; i++)
	{
		crip_msg[i] = cfuncionario.senha[i] + 5;
	}
	crip_msg[tam_msg] = '\0';
	/*Incrementar mais um valor no c�digo usu�rio*/
	fprintf(puser, "Codigo: %i \n", cfuncionario.codigo);
	fprintf(puser, "Nome: %s \n", cfuncionario.nome);
	fprintf(puser, "Telefone: %s \n", cfuncionario.telefone);
	fprintf(puser, "E-mail: %s \n", cfuncionario.email);
	fprintf(puser, "CPF: %s \n", cfuncionario.cpf);
	fprintf(puser, "Usuario: %s \n", cfuncionario.usuario);
	fprintf(puser, "Senha: %s \n\n", crip_msg);
	fprintf(puser, "-------- Endere�o --------\n\n");
	fprintf(puser, "Estado: %s\n", cfuncionario.endereco.estado);
	fprintf(puser, "Cidade: %s\n", cfuncionario.endereco.cidade);
	fprintf(puser, "Bairro: %s\n", cfuncionario.endereco.bairro);
	fprintf(puser, "Logradouro: %s\n", cfuncionario.endereco.logradouro);
	fprintf(puser, "Complemento: %s\n", cfuncionario.endereco.complemento);
	fprintf(puser, "CEP: %s\n", cfuncionario.endereco.cep);
	fprintf(puser, "\n");

	fclose(puser);
}

void con_usuario()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o

	int i;
	char tsaida[50], car;

	user cusuario;
	puser = fopen("dados\\cad_funcionario.txt", "r");

	if (puser == NULL) {
		perror("dados\\cad_funcionario.txt");
		return 1;
	}
	printf("Usu�rios:\n\n");

	i = 0;
	car = fgetc(puser);
	while (car != EOF)
	{
		tsaida[i] = car;
		printf("%c", tsaida[i]);
		i++;
		car = fgetc(puser);
	}

	fclose(puser);

	if (ferror(puser)) {
		printf("error: %s\n", strerror(errno));
	}

}

/*SE��O PACIENTES*/
void cad_paciente()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o

	/*Ponteiros do metodo*/
	system("mkdir dados");
	ppatient = fopen("dados\\cad_paciente.txt", "a");
	patient cpaciente;

	/*Cadastro dos dados*/
	printf("\033[2J\033[1;1H");
	printf("CADASTRO DE PACIENTES\n\n");

	printf("\n\nCodigo do paciente: \n");
	scanf_s("%d", &cpaciente.codigo);
	(void)getchar();

	printf("\n\nNome do paciente: \n");
	gets(cpaciente.nome);

	printf("\n\nTelefone do paciente: \n");
	gets(cpaciente.telefone);

	printf("\n\nE-mail do paciente: \n");
	gets(cpaciente.email);

	printf("\n\nCPF do paciente: \n");
	gets(cpaciente.cpf);

	printf("\n\n--------- Localiza��o --------- \n\n");

	printf("\n\nEstado do paciente: \n");
	gets(cpaciente.endereco.estado);

	printf("\n\nCidade do paciente: \n");
	gets(cpaciente.endereco.cidade);

	printf("\n\nBairro do pacientel: \n");
	gets(cpaciente.endereco.bairro);

	printf("\n\nLogradouro do paciente: \n");
	gets(cpaciente.endereco.logradouro);

	printf("\n\nComplemento do paciente: \n");
	gets(cpaciente.endereco.complemento);

	printf("\n\nCEP do paciente: \n");
	gets(cpaciente.endereco.cep);

	/*GRAVAR OS DADOS NO ARQUIVO DE TEXTO*/
	fprintf(ppatient, "%s\n\n", "\n ==============  Paciente Cadastrado  ============== ");
	//hora
	time_t mytime;
	char dataehora[100];
	mytime = time(NULL);
	strftime(dataehora, sizeof(dataehora), "%d.%m.%Y - %H:%M:%S", localtime(&mytime));
	fprintf(ppatient, "Data/Hora: %s\n", dataehora);
	fprintf(ppatient, "\n");

	/*Incrementar mais um valor no c�digo usu�rio*/
	fprintf(ppatient, "C�digo: %i \n", cpaciente.codigo);
	fprintf(ppatient, "Nome: %s \n", cpaciente.nome);
	fprintf(ppatient, "Telefone: %s\n", cpaciente.telefone);
	fprintf(ppatient, "E-mail: %s\n", cpaciente.email);
	fprintf(ppatient, "CPF: %s\n\n", cpaciente.cpf);
	fprintf(ppatient, "-------- Endere�o --------\n\n");
	fprintf(ppatient, "Estado: %s\n", cpaciente.endereco.estado);
	fprintf(ppatient, "Cidade: %s\n", cpaciente.endereco.cidade);
	fprintf(ppatient, "Bairro: %s\n", cpaciente.endereco.bairro);
	fprintf(ppatient, "Logradouro: %s\n", cpaciente.endereco.logradouro);
	fprintf(ppatient, "Complemento: %s\n", cpaciente.endereco.complemento);
	fprintf(ppatient, "CEP: %s\n", cpaciente.endereco.cep);
	fprintf(ppatient, "\n");

	fclose(ppatient);
}

void con_paciente()
{
	printf("teste");
}

/*SE��O MEDICOS*/
void cad_medico()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o

	/*Ponteiros do metodo*/
	system("mkdir dados");
	pdoctor = fopen("dados\\cad_medico.txt", "a");
	doctor cmedico;

	/*Cadastro dos dados*/
	printf("\033[2J\033[1;1H");
	printf("CADASTRO DE MEDICOS\n\n");

	printf("\n\nCodigo do medico: \n");
	scanf_s("%d", &cmedico.codigo);
	(void)getchar();

	printf("\n\nNome do medico: \n");
	gets(cmedico.nome);

	printf("\n\nTelefone do medico: \n");
	gets(cmedico.telefone);

	printf("\n\nE-mail do medico: \n");
	gets(cmedico.email);

	printf("\n\nCPF do medico: \n");
	gets(cmedico.cpf);

	printf("\n\nEspecialidade do medico: \n");
	gets(cmedico.especialidade);

	/*GRAVAR OS DADOS NO ARQUIVO DE TEXTO*/
	fprintf(pdoctor, "%s\n\n", "\n ==============  Medico Cadastrado  ============== ");
	//hora
	time_t mytime;
	char dataehora[100];
	mytime = time(NULL);
	strftime(dataehora, sizeof(dataehora), "%d.%m.%Y - %H:%M:%S", localtime(&mytime));
	fprintf(pdoctor, "Data/Hora: %s\n", dataehora);
	fprintf(pdoctor, "\n");

	fprintf(pdoctor, "Codigo: %i \n", cmedico.codigo);
	fprintf(pdoctor, "Nome: %s \n", cmedico.nome);
	fprintf(pdoctor, "Telefone: %s\n", cmedico.telefone);
	fprintf(pdoctor, "E-mail: %s\n", cmedico.email);
	fprintf(pdoctor, "CPF: %s\n", cmedico.cpf);
	fprintf(pdoctor, "Especialidade: %s\n\n", cmedico.especialidade);

	fprintf(pdoctor, "-------- Endere�o --------\n\n");

	fprintf(pdoctor, "Estado: %s\n", cmedico.endereco.estado);
	fprintf(pdoctor, "Cidade: %s\n", cmedico.endereco.cidade);
	fprintf(pdoctor, "Bairro: %s\n", cmedico.endereco.bairro);
	fprintf(pdoctor, "Logradouro: %s\n", cmedico.endereco.logradouro);
	fprintf(pdoctor, "Complemento: %s\n", cmedico.endereco.complemento);
	fprintf(pdoctor, "CEP: %s\n", cmedico.endereco.cep);
	fprintf(pdoctor, "\n");

	fclose(pdoctor);
}

void con_medico()
{
	printf("teste");
}

/*SE��O FILIAL*/

void cad_filial()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentua��o

	/*Ponteiros do metodo*/
	system("mkdir dados");
	pfilial = fopen("dados\\cad_filial.txt", "a");
	branch cfilial;

	/*Cadastro dos dados*/
	printf("\033[2J\033[1;1H");
	printf("CADASTRO DE FILIAIS\n\n");

	printf("\n\nCodigo da filial: \n");
	scanf_s("%d", &cfilial.codigo);
	(void)getchar();

	printf("\n\nNome da filial: \n");
	gets(cfilial.nome);

	printf("\n\nCNPJ da filial: \n");
	gets(cfilial.cnpj);

	printf("\n\nDescri��o da filial: \n");
	gets(cfilial.descri��o);

	printf("\n\n--------- Localiza��o --------- \n\n");

	printf("\n\nEstado da filial: \n");
	gets(cfilial.endereco.estado);

	printf("\n\nCidade da filial: \n");
	gets(cfilial.endereco.cidade);

	printf("\n\nBairro da filial: \n");
	gets(cfilial.endereco.bairro);

	printf("\n\nLogradouro da filial: \n");
	gets(cfilial.endereco.logradouro);

	printf("\n\nComplemento da filial: \n");
	gets(cfilial.endereco.complemento);

	printf("\n\nCEP da filial: \n");
	gets(cfilial.endereco.cep);

	/*GRAVAR OS DADOS NO ARQUIVO DE TEXTO*/
	fprintf(pfilial, "%s\n\n", "\n ==============  Filial Cadastrado  ============== ");
	//hora
	time_t mytime;
	char dataehora[100];
	mytime = time(NULL);
	strftime(dataehora, sizeof(dataehora), "%d.%m.%Y - %H:%M:%S", localtime(&mytime));
	fprintf(pfilial, "Data/Hora: %s\n", dataehora);
	fprintf(pfilial, "\n");

	/*Incrementar mais um valor no c�digo usu�rio*/
	fprintf(pfilial, "Codigo: %i \n", cfilial.codigo);
	fprintf(pfilial, "Nome: %s \n", cfilial.nome);
	fprintf(pfilial, "Cnpj: %s\n", cfilial.cnpj);
	fprintf(pfilial, "Descri��o: %s\n\n", cfilial.descri��o);

	fprintf(pfilial, "-------- Endere�o --------\n\n");

	fprintf(pfilial, "Estado: %s\n", cfilial.endereco.estado);
	fprintf(pfilial, "Cidade: %s\n", cfilial.endereco.cidade);
	fprintf(pfilial, "Bairro: %s\n", cfilial.endereco.bairro);
	fprintf(pfilial, "Logradouro: %s\n", cfilial.endereco.logradouro);
	fprintf(pfilial, "Complemento: %s\n", cfilial.endereco.complemento);
	fprintf(pfilial, "CEP: %s\n", cfilial.endereco.cep);
	fprintf(pfilial, "\n");

	fclose(pfilial);
}

void con_filial()
{
	printf("teste");
}

/*SE��O AGENDAMENTOS*/

void cad_agendamentos()
{
	printf("teste");
}

void con_agendamentos()
{
	printf("teste");
}

void limpabuffer(void) // Fun�ao utilit�ria para limpar o buffer do teclado
{
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) {}
	return;
}
