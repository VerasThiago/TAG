#include <bits/stdc++.h>

using namespace std;

struct Professor;

// Struct que representa uma escola
struct Escola{

	// Código da escola
	int code;

	// Quatidade de habilidades da preferencia da escola
	int pref;


	// Quantidade de vagas
	int jobs;

	// Professores ligados a escola	
	vector<Professor*> match;

	// Construtor da escola
	Escola(int code, int pref, int jobs){
		this->code = code;
        this->pref = pref;
        this->jobs = jobs;
        this->match.clear();
	}

	// Método que retorna a quantidade de vagas disponíveis
	int free(){
		return jobs - match.size();
	}

};


// Struct que representa um professor
struct Professor {

	// Código do professor
    int code;

    // Quantidade de habilidades que possui
    int hab;

    // Lista de códigos das escolas de sua preferencia
   	vector<int> pref;

   	// Variável booleana para saber se o professor está livre
   	bool matched;
   	
   	// Escola que o professor está ligado
   	Escola* match;
	
	// Construtor do professor 
    Professor(int code, int hab, vector<int> pref){
        this->code = code;
        this->hab = hab;
        this->pref = pref;
        this->matched = true;
        this->match = NULL;
    }

    // Método para saber se o professor está livre
    bool free(){
        return matched;
    }
  
};

// Lista de professores
vector<Professor*> prof;

// Lista de escolas
vector<Escola*> esc;

// Mostra os dados das listas, apenas para debugar
void show(){
	puts("Andando pelps professores");
	for(auto x: prof){
		cout << "hab de " << x->code << " = " << x->hab << " : ";
		for(auto y : x->pref) cout << y << " ";
		puts("");
	}

	puts("Andando pelas escolas");
	for(auto x: esc)
		cout << "escola " << x->code << " prefere " << x->pref << " e tem " << x->jobs << " vagas " << endl;
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

			// Quantidade de habilidade do professor
			int hab;

			// Códigos das escolas de preferencia do professor
			vector<int> pref;

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
			    		hab = stoi(line);

			    		break;

			    	case 1:

			    		// Removendo os 2 primeiros e os 2 ultimos caractere
			    		line = line.substr(2, line.size() - 3);

			    		// Adicionando a escola de preferência do professor
			    		pref.push_back(stoi(line));

			    		break;

			    	default:

			    		// Removendo o pirmeiro e o ultimo caracter
			    		line = line.substr(1, line.size() - 2);

			    		// Adicionando a escola de preferência do professor
			    		pref.push_back(stoi(line));


			    		break;
				}
			}

			// Criando uma estruct do professor
			Professor* p = new Professor(professor, hab, pref);

			// Inserindo professor na lista de professores
			prof.push_back(p);
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
		Escola* e = new Escola(stoi(escola),stoi(hab),stoi(vagas));
		esc.push_back(e);
	}

	// Apenas mostrando tudo para debugar, descomente a função show para conseguir ver.
	//show();


}