/*Bibliotecas para o programas*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#ifdef _WIN32 

#include <Windows.h>
// Outros includes 

#else

// Dá mensagem de erro informando que o sistemas não é suportado.
#error "Sistema nao suportado."

#endif

/*01 - Estrutura do endereço*/
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
	char descrição[100];
	char cnpj[14];
	address endereco;
}branch;

/*03 - Estrutura do usuário*/
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

/*Métodos do programa*/
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
char cad_elogiosereclamacoes();



/*MENU PRINCIPAL*/
char menu_principal()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
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

	printf("\nFavor selecionar alguma opção: \n\n");

	return _getch();
}

char menu_cadastros()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	system("cls");

	printf("	        ========   CLIMANAGER   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu de cadastros                |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Cadastros usuários                     |\n");
	printf("    |       [2] - Cadastrar pacientes                    |\n");
	printf("    |       [3] - Cadastrar médicos                      |\n");
	printf("    |       [4] - Cadastrar filial                       |\n");
	printf("    |       [5] - Cadastrar agendamentos                 |\n");
	printf("    |       [6] - Voltar ao menu principal               |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");

	printf("\nFavor selecionar alguma opção: \n\n");

	return getchar();
}

char menu_consultas()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	system("cls");

	printf("	        ========   CLIMANAGER   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu de consultas                |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Consultar usuários                     |\n");
	printf("    |       [2] - Consultar pacientes                    |\n");
	printf("    |       [3] - Consultar médicos                      |\n");
	printf("    |       [4] - Consultar filial                       |\n");
	printf("    |       [5] - Consultar agendamentos                 |\n");
	printf("    |       [6] - Voltar ao menu principal               |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");

	printf("\nFavor selecionar alguma opção: \n\n");

	return getchar();
}

/*MAIN COM SWITCH*/
void main()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	char str1[50] = "str";
	char str2[50] = "str2";
	int i, k, g, tam3 = 0;;
	char a[50];
	char crip_msg[50];
	int tam_msg;


volta:

	k = 0; g = 0;

	/* CADASTRO DO USUÁRIO PADRÃO*/
	char const* buscar = { NULL };
	buscar = "administrador";
	char buscar2[256] = { NULL };

	system("mkdir dados");
	puser = fopen("dados\\cad_funcionario.txt", "a+");

	if (puser == NULL) {
		perror("dados\\cad_funcionario.txt");
		return 1;
	}
	while (fscanf(puser, "%s", buscar2) != buscar)
	{
		if (strcmp(buscar, buscar2) != 0)
		{
			fprintf(puser, "Usuario: administrador");
			fprintf(puser, "\nSenha: firnsnxywfitw");
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

	user cusuario = { NULL };

	printf("\n============ PAINEL DE LOGIN ============\n\n");
	printf("\nFavor digitar o seu usuário e senha!\n");
	printf("\nLOGIN: ");
	gets(cusuario.usuario);
	printf("\nSENHA: ");

	char c;
	int pos = 0;


	do {
		c = _getch();

		if (isprint(c))
		{
			cusuario.senha[pos++] = c;
			printf("%c", '*');
		}
		else if (c == 8 && pos)
		{
			cusuario.senha[pos--] = '\0';
			printf("%s", "\b \b");
		}
	} while (c != 13);

	/*REALIZA A BUSCA NO ARQUIVO DO USUÁRIO E SENHA, A SENHA ELE COMPARA O VALOR DIGITADO CRIPTOGRAFADO
	COM O VALOR CRIPTOGRAFADO QUE ESTÁ NO ARQUIVO*/

	while (fscanf(puser, "%s", a) != EOF) {
		if (strcmp(a, cusuario.usuario) == 0) {
			g = 1;
			break;
		}
	}

	tam_msg = strlen(cusuario.senha);
	for (i = 0; i < tam_msg; i++)
	{
		crip_msg[i] = cusuario.senha[i] + 5;
	}
	crip_msg[tam_msg] = '\0';


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
		printf("\n\nUsuário ou senha inválido!\n\n");
		//setbuf(stdin(NULL);
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
	case '6': goto fim;
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
	case '6': goto fim;
		exit(0);
	}

	printf("\n\n");
	system("pause");
	goto inicio;
fim:
	;
}

/*SEÇÃO USUÁRIOS*/
void cad_usuario()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação

	system("mkdir dados");
	puser = fopen("dados\\cad_funcionario.txt", "a");
	user cfuncionario;
	int tam = 0, tam2 = 0, i;
	char crip_msg[100];
	int tam_msg;
	memset(cfuncionario.usuario, 0x00, sizeof(cfuncionario.usuario));
	memset(cfuncionario.senha, 0x00, sizeof(cfuncionario.senha));
	memset(cfuncionario.senha2, 0x00, sizeof(cfuncionario.senha2));

	/*Buscar último código cadastrado*/

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

	printf("\n\nUsuário para funcionario: \n");
	gets(cfuncionario.usuario);

	/* ---------- TRATAMENTO NO CAMPO SENHA ---------- */

inicio:

	tam = 0;
	tam2 = 0;

	printf("\n\nSenha do usuário: \n");
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
		printf("\nAs senhas não conferem!\n\n");
		goto inicio;
	}
	else
	{
		printf("\n\n--------- Localização --------- \n\n");

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

		printf("\n\nUsuário cadastrado com sucessso!");
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
	/*Incrementar mais um valor no código usuário*/
	fprintf(puser, "Codigo: %i \n", cfuncionario.codigo);
	fprintf(puser, "Nome: %s \n", cfuncionario.nome);
	fprintf(puser, "Telefone: %s \n", cfuncionario.telefone);
	fprintf(puser, "E-mail: %s \n", cfuncionario.email);
	fprintf(puser, "CPF: %s \n", cfuncionario.cpf);
	fprintf(puser, "Usuario: %s \n", cfuncionario.usuario);
	fprintf(puser, "Senha: %s \n\n", crip_msg);
	fprintf(puser, "-------- Endereço --------\n\n");
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
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	char texto[255];
	//user cpaciente;
	puser = fopen("dados\\cad_funcionario.txt", "r");

	if (puser == NULL) {
		perror("dados\\cad_funcionario.txt");
		return 1;
	}
	printf("Usuário:\n\n");

	while (!feof(puser))
	{
		//função gets lê string, pega do teclado, e fgets, pega do arquivo
		fgets(texto, 255, puser);
		printf("%s", texto);
	}

	fclose(puser);

	if (ferror(puser)) {
		printf("error: %s\n", strerror(errno));
	}
}

/*SEÇÃO PACIENTES*/
void cad_paciente()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação

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

	printf("\n\n--------- Localização --------- \n\n");

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

	/*Incrementar mais um valor no código usuário*/
	fprintf(ppatient, "Código: %i \n", cpaciente.codigo);
	fprintf(ppatient, "Nome: %s \n", cpaciente.nome);
	fprintf(ppatient, "Telefone: %s\n", cpaciente.telefone);
	fprintf(ppatient, "E-mail: %s\n", cpaciente.email);
	fprintf(ppatient, "CPF: %s\n\n", cpaciente.cpf);
	fprintf(ppatient, "-------- Endereço --------\n\n");
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
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	char texto[255];
	//user cpaciente;
	ppatient = fopen("dados\\cad_paciente.txt", "r");

	if (ppatient == NULL) {
		perror("dados\\cad_paciente.txt");
		return 1;
	}
	printf("Pacientes:\n\n");

	while (!feof(ppatient))
	{
		//função gets lê string, pega do teclado, e fgets, pega do arquivo
		fgets(texto, 255, ppatient);
		printf("%s", texto);
	}

	fclose(ppatient);

	if (ferror(ppatient)) {
		printf("error: %s\n", strerror(errno));
	}
}

/*SEÇÃO MEDICOS*/
void cad_medico()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação

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

	fprintf(pdoctor, "-------- Endereço --------\n\n");

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
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	char texto[255];
	//user cpaciente;
	pdoctor = fopen("dados\\cad_medico.txt", "r");

	if (puser == NULL) {
		perror("dados\\cad_medico.txt");
		return 1;
	}
	printf("Medico:\n\n");

	while (!feof(puser))
	{
		//função gets lê string, pega do teclado, e fgets, pega do arquivo
		fgets(texto, 255, puser);
		printf("%s", texto);
	}

	fclose(puser);

	if (ferror(puser)) {
		printf("error: %s\n", strerror(errno));
	}
}

/*SEÇÃO FILIAL*/

void cad_filial()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação

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

	printf("\n\nDescrição da filial: \n");
	gets(cfilial.descrição);

	printf("\n\n--------- Localização --------- \n\n");

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

	/*Incrementar mais um valor no código usuário*/
	fprintf(pfilial, "Codigo: %i \n", cfilial.codigo);
	fprintf(pfilial, "Nome: %s \n", cfilial.nome);
	fprintf(pfilial, "Cnpj: %s\n", cfilial.cnpj);
	fprintf(pfilial, "Descrição: %s\n\n", cfilial.descrição);

	fprintf(pfilial, "-------- Endereço --------\n\n");

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
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	char texto[255];
	//user cpaciente;
	pfilial = fopen("dados\\cad_filial.txt", "r");

	if (puser == NULL) {
		perror("dados\\cad_filial.txt");
		return 1;
	}
	printf("Filial:\n\n");

	while (!feof(puser))
	{
		//função gets lê string, pega do teclado, e fgets, pega do arquivo
		fgets(texto, 255, puser);
		printf("%s", texto);
	}

	fclose(puser);

	if (ferror(puser)) {
		printf("error: %s\n", strerror(errno));
	}
}

/*SEÇÃO AGENDAMENTOS*/

void cad_agendamentos()
{
	printf("teste");
}

void con_agendamentos()
{
	printf("teste");
}

/*RECLAMAÇÕES E ELOGIOS DOS CLIENTES*/

char cad_elogiosereclamacoes()
{
	setlocale(LC_ALL, "Portuguese"); //Para acentuação
	char elogios, reclamações, sugestões;
	int x = 1, y = 2, w = 3;


	system("cls");

	printf("\nSe deseja adicionar um elogio digite 1\n Se deseja adiciomar uma reclamação digite 2\n Se deseja adicionar uma sugestão digite 3\n");

	if (x == 1)
	{
		scanf("%c", &elogios);
		getchar();
	}
	if (y == 2)
	{
		scanf("%c", &reclamações);
		getchar();
	}
	if (w == 3)
	{
		scanf("%c", &sugestões);
		getchar();
	};

	getchar();
	return(0);
}
