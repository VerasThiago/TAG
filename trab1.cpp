#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[1000];
map<int,string> node;
map<string,int> nodes;
vector< vector<int> > cliques;


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

void bron_kerbosh(vector<int> r, vector<int> p, vector<int> e){
	// r = vertices escolhidos para o clique atual
	// p = possiveis vertices para expandir o clique atual
	// e = vertices que nao podem fazer parte do clique atual

	// Caso nao seja possivel adicionar nenhum vertice ao clique atual, "p" esta vazio,
	// e o conjunto de vertices atualmente considerados nao possua nenhum vertice excluido, "e" esta vazio.
	// O clique encontrado eh armazenado no vetor "cliques"
	if(p.empty() && e.empty()) cliques.push_back(r);
	
	// Vetores para marcar os elementos dos vetores "p" e "e" que estao sendo considerados ativos
	bool mark[(int)node.size() + 1], mark2[(int)node.size() + 1];
	memset(mark,0,sizeof mark);
	memset(mark2,0,sizeof mark2);
	
	for(int i = 0; i < p.size(); i++)
		mark[p[i]] = 1;
	for(int i = 0; i < e.size(); i++)
		mark2[e[i]] = 1;
	
	for(int i = 0; i < p.size(); i++){
		// Adiciona um novo vertice, "p[i]" ao clique que se pretende expandir
		r.push_back(p[i]);

		// Vetores "p2" e "e2" representam a intercessao entre os vetores "p" e "e", respectivamente
		// e o conjunto de vizinhos do vertice "p[i]"
		vector<int> p2, e2;
		for(int j = 0; j < grafo[p[i]].size(); j++){
			if(mark[grafo[p[i]][j]])
				p2.push_back(grafo[p[i]][j]);
			if(mark2[grafo[p[i]][j]])
				e2.push_back(grafo[p[i]][j]);
		}

		// Realiza uma chamada recursiva para tentar expandir o conjunto de vertices de "r"
		// com os vertices de "p2"
		bron_kerbosh(r,p2,e2);

		// Remove o vertice "p[i]" do vetor "r" para procurar cliques em outros conjuntos
		// de vertices nas proximas iteracoes
		r.pop_back();

		// Remove o vertice "p[i]" do vetor "p" e o adiciona ao vetor "e"
		mark[p[i]] = 0;
		mark2[p[i]] = 1;
	}
}


void show(){// Mostra a estruturação do grafo (Ponto extra)

	cout << endl << endl <<  "grafo possui " << node.size() << " vertices" << endl;
	// Percorre todos os vertices
	for(int i = 1; i <= node.size(); i++){
		//Imprime o dado do vertice e seu grau
		cout << node[i] << " com " << grafo[i].size() << " vertices : ";

		//Percorre todos os vertices grafoacentes a ele
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

	// Declaracao dos tres vetores que serao usados no algoritmo de Bron & Kerbosh para encontrar os cliques maximais
	vector<int> r,p,e;
	// Coloca no v
	for(int i = 1; i <= node.size(); i++)
		p.push_back(i);

	bron_kerbosh(r,p,e);

	// Ordena o vetor "cliques" em ordem decrescente com relacao ao tamanho dos cliques encontrados
	sort(cliques.begin(), cliques.end(), greater< vector<int> >() );

	// Mostra o maior clique maximal
	printf("Clique Maximo\n");
	printf("Tamanho: %d\n",cliques[0].size());
	printf("Alunos:\n");
	for(int i = 0; i < cliques[0].size(); i++){
		printf("%d %s\n",cliques[0][i],node[cliques[0][i]].c_str());
	}

	printf("------------------------------------------------------------------------\n");
	printf("\n");

	// Mostra um outro clique maximal, de tamanho menor ou igual ao primeiro
	printf("Clique maximal\n");
	printf("Tamanho: %d\n",cliques[1].size());
	printf("Alunos:\n");
	for(int i = 0; i < cliques[1].size(); i++){
		printf("%d %s\n",cliques[1][i],node[cliques[1][i]].c_str());
	}
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
