#include<bits/stdc++.h>

using namespace std;
vector<int> grafo[1000];
vector<int> habilitacoes(1000,0);
vector<pair<int,int>> escolas(1000);

void show(){
	for(int i = 1; i <= 100; i++){
		cout << "hab de " << i << " = " << habilitacoes[i] << " : ";
		for(auto x: grafo[i])
			cout << "E" << x << " ";
		
		puts("");
	}
	for(int i = 1; i <= 50; i++)
		cout << "Escola " << i << " : " << escolas[i].first << " " << escolas[i].second << endl;
}


// Faz o split da string de acordo com o parametro passado pelo char c
const vector<string> split(const string& s, const char& c){

	// String base
	string buff{""};

	// Vetor que irá salvar os splits
	vector<string> v;
	
	// Andando por cada carcter
	for(auto n:s){

		// Se nao for o char de quebra
		if(n != c)
			buff += n; 

		// Char que deve ser quabrado, logo adicionar a string ao vetor
		else if (n == c && buff != ""){
			// Adicionando no vetor
			v.push_back(buff);

			// Resetando a string buff
			buff = "";
		}
	}
	// Fazendo a ultima adição após o char de quebra
	if(buff != "")
		v.push_back(buff);
	
	// Retornando o vetor com os splits
	return v;
}


// Função que cria o grafo e armazena as ligações
void  read(string nome){

	// Variáveis para acessar e ler os dados do arquivo
	ifstream arquivo; string line;

	// Abrindo o arquivo
	arquivo.open(nome);

	// Se não conseguir abrir o arquivo, imprimir a mensagem de falha e encerrar o programa
	if(!arquivo) cout << "Falha ao abrir o arquivo " << nome << endl, exit(EXIT_FAILURE);

	// Ignorando as 3 primeiras linhas
	for(int i = 0; i < 3; i++)
		getline(arquivo,line);


	while(arquivo >> line, line[0] == '('){
			// Removendo os 2 primeiros e os 2 ultimos caracteres
			line = line.substr(2, line.size() - 3);

			// Pegando o numero do professor
			int professor = stoi(line);

			// Iterando pelos 6 dados de cada linha
			for(int i = 0; i < 6; i++){

				// Lendo uma string do arquivo
				arquivo >> line;

				// Verificando qual bloco lido se encontra
				switch(i){
					case 0:

						// Removendo o ultimo caracter
						line = line.substr(0, line.size() - 2);

						// Adicionando a quantidade de habilitações do professor
			    		habilitacoes[professor] = stoi(line);

			    		break;

			    	case 1:

			    		// Removendo os 2 primeiros e os 2 ultimos caractere
			    		line = line.substr(2, line.size() - 3);

			    		// Adicionando a escola de preferência do professor
			    		grafo[professor].push_back(stoi(line));

			    		break;

			    	default:

			    		// Removendo o pirmeiro e o ultimo caracter
			    		line = line.substr(1, line.size() - 2);

			    		// Adicionando a escola de preferência do professor
			    		grafo[professor].push_back(stoi(line));


			    		break;
				}
			}
	}

	// Ignorando as 2 primeiras linhas
	for(int i = 0; i < 2; i++)
		getline(arquivo,line);

	// Lendo as preferencias de cada escola
	while(arquivo >> line){

		// Dando split no input do arquivo, seprando em escola, habilitação e quantidade de vagas	
		vector<string> v{split(line, ':')};

		// Pegando o numero da escola
		string escola = v[0].substr(2, v[0].size() - 2);

		// Pegando a habilitação
		string hab = v[1].substr(1,v[1].size()-2);

		// Pegando a quantidade de vagas
		string vagas = v[2].substr(1,v[2].size()-2);

		// Salvando os dados na respectiva escola
		escolas[stoi(escola)] = make_pair(stoi(hab),stoi(vagas));
	}

	// Apenas mostrando tudo para debugar.
	show();


}