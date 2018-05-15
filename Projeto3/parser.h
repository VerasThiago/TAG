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

const vector<string> explode(const string& s, const char& c){
	string buff{""};
	vector<string> v;
	
	for(auto n:s){
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}


// Função que cria o grafo e armazena as ligações
void  read(string nome){

	// Variáveis para pegar o nome, acessar e ler os dados do arquivo
	ifstream arquivo; string line;

	// Abrindo o arquivo
	arquivo.open(nome);

	// Se não conseguir abrir o arquivo, imprimir a mensagem de falha e encerrar o programa
	if(!arquivo) cout << "Falha ao abrir o arquivo " << nome << endl, exit(EXIT_FAILURE);

	for(int i = 0; i < 3; i++)
		getline(arquivo,line);


	while(arquivo >> line, line[0] == '('){
			line = line.substr(2, line.size() - 3);
			cout << line << " ";
			int pai = stoi(line);

			for(int i = 0; i < 6; i++){
				string line;
				arquivo >> line;
				switch(i){
					case 0:
						line = line.substr(0, line.size() - 2);
			    		habilitacoes[pai] = stoi(line);
			    		break;
			    	case 1:
			    		line = line.substr(2, line.size() - 3);
			    		grafo[pai].push_back(stoi(line));
			    		break;
			    	default:
			    		line = line.substr(1, line.size() - 2);
			    		grafo[pai].push_back(stoi(line));
			    		break;
				}

				cout << line << " ";
			}
			puts("");
	}
	getline(arquivo,line);
	getline(arquivo,line);

	while(arquivo >> line){
			vector<string> v{explode(line, ':')};
			string escola = v[0].substr(2, v[0].size() - 2);
			string hab = v[1].substr(1,v[1].size()-2);
			string vagas = v[2].substr(1,v[2].size()-2);
			escolas[stoi(escola)] = make_pair(stoi(hab),stoi(vagas));
	}
	show();


}