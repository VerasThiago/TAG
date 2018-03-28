#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[1000];
map<int,string> node;
map<string,int> nodes;



bool read(string file){
	// Variável para gerar os indices de cada vértice
	int idx = 1; 
	// Ler as linhas do arquivo e os dados para criar o grafo;
	string line, source, target;  
	fstream arquivo;
	// Abre o arquivo
	arquivo.open(file); 
	if(!arquivo){
		cout << "Falha ao abrir o arquivo" << endl;
		// Retorna falso caso nao tenha conseguido abrir o arquivo
		return false; 
	}
	//Percorre o arquivo
	while(arquivo >> line){ 
		// Quando chega em um nó
		if(line == "node"){ 
			//Vai pulando todos os dados até chegar no id
			while(arquivo >> line, line != "id"); 
			//Le o id
			arquivo >> line; 
			//Gera o numero para aquele id, que pode ser um nome, um numero, um simbolo ...
			node[idx] = line;
			// Gera o contrário para conseguir pegar acessar os dados do no depois
			nodes[line] = idx++; 
		}
		else if(line == "edge"){ //Quando chega em uma aresta
			//Pula todos os caracteres até chegar no source
			while(arquivo >> line, line != "source"); 
			//Le o source
			arquivo >> source;
			//Pula todos os caracteres até chegar no target
			while(arquivo >> line, line != "target");
			// Le o target
			arquivo >> target;
			//Insere no grafo não direcional 
			grafo[nodes[source]].push_back(nodes[target]); 
			grafo[nodes[target]].push_back(nodes[source]);
		}
	}
	// Retorna true caso tudo tenha ocorrido corretamente
	return true; 
}


void show(){// Mostra a estruturação do grafo (Ponto extra)

	cout << endl << endl <<  "grafo possui " << node.size() << " vertices" << endl;
	// Percorre todos os vertices
	for(int i = 1; i <= node.size(); i++){
		//Imprime o dado do vertice e seu grau
		cout << node[i] << " com " << grafo[i].size() << " vertices adjacentes : ";

		//Percorre todos os vertices adjacentes a ele
		//Imprime o valor do vertice passado pela hash node
		for(auto u : grafo[i]) cout << node[u] << ", ";
		puts("");
	}
}

void show_sorted(){
	// Vetor de pares para armazenar o grau e o vertice correspondente
	vector< pair<int, int> > graph;

	// Insere todos os vertices e seus respectivos grau
	for(int i = 1; i <= node.size(); i++) graph.push_back(make_pair(grafo[i].size(),i));

	// Ordena esses vertices por ordem decrescente do grau	
	sort(graph.begin(), graph.end(), greater< pair<int,int> >());

	printf("\n\n--------------------------------------------------\n\n");
	cout << "Imprimindo em ordem decrescente os vértices:" << endl;

	//Imprime os vertices e seu grau já ordenado, também passado pelo hash node
	for(auto x : graph) cout << "Vertice " << node[x.second] << " com grau " << x.first << endl;
}

void clique(){
	cout << endl << endl << "Clique in construction" << endl;
}



int main(){
	// Variavel para ler o nome do arquivo que contem o grafo
	string file;
	cout << "Input gml file name: ";
	// Le o nome do arquivo
	cin >> file;
	//Tenta ler o arquivo e caso nao exista, encerra o programa
	if (!read(file + ".gml")){
		cout << "System finished" << endl;
		return 0;
	}
	//Mostra o grafo (Ponto extra)
	show();
	//Mostra os vertices ordenados por grau
	show_sorted();
	//Encontra um clique de tamanho 5
	clique();


	return 0;
}
