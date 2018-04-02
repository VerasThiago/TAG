#include <bits/stdc++.h>
#include "graphParser.h"
#include "svg.h"
using namespace std;

// Para ordenar os clicks em ordem de tamanho decrescente
bool cmp(vector<int> a, vector<int> b){
	return (int)a.size() > (int)b.size();
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
	bool marcador_p[(int)node.size() + 1], marcador_e[(int)node.size() + 1];
	memset(marcador_p,0,sizeof marcador_p);
	memset(marcador_e,0,sizeof marcador_e);
	
	for(int i = 0; i < p.size(); i++)
		marcador_p[p[i]] = 1;
	for(int i = 0; i < e.size(); i++)
		marcador_e[e[i]] = 1;
	
	for(int i = 0; i < p.size(); i++){

		// Adiciona um novo vertice, "p[i]" ao clique que se pretende expandir
		r.push_back(p[i]);

		// Vetores "p2" e "e2" representam a intercessao entre os vetores "p" e "e", respectivamente
		// e o conjunto de vizinhos do vertice "p[i]"
		vector<int> p2, e2;
		for(int j = 0; j < grafo[p[i]].size(); j++){

			if(marcador_p[grafo[p[i]][j]])
				p2.push_back(grafo[p[i]][j]);
			
			if(marcador_e[grafo[p[i]][j]])
				e2.push_back(grafo[p[i]][j]);
		}

		// Realiza uma chamada recursiva para tentar expandir o conjunto de vertices de "r"
		// com os vertices de "p2"
		bron_kerbosh(r,p2,e2);

		// Remove o vertice "p[i]" do vetor "r" para procurar cliques em outros conjuntos
		// de vertices nas proximas iteracoes
		r.pop_back();

		// Remove o vertice "p[i]" do vetor "p" e o adiciona ao vetor "e"
		marcador_p[p[i]] = 0;
		marcador_e[p[i]] = 1;
	}
}



void show_sorted(){
	// Vetor de pares para armazenar o grau e o vertice correspondente
	vector< pair<int, int> > graph;

	// Insere todos os vertices e seus respectivos grau
	for(int i = 1; i <= node.size(); i++)
		graph.push_back(make_pair(grafo[i].size(),i));

	// Ordena esses vertices por ordem decrescente do grau	
	sort(graph.begin(), graph.end(), greater< pair<int,int> >());

	printf("\n\n--------------------------------------------------\n\n");
	cout << "Imprimindo em ordem decrescente os vértices:" << endl << endl;

	// Imprime os vertices e seu grau já ordenado, também passado pelo hash node
	for(auto x : graph)
		cout << "Grau : " << x.first << endl << "Vertice : " << node[x.second] << endl << endl;

	printf("\n\n--------------------------------------------------\n\n");	
}

void clique(){
	// Declaracao dos tres vetores que serao usados no algoritmo de Bron & Kerbosh para encontrar os cliques maximais
	vector<int> r,p,e;
	// Coloca no v
	for(int i = 1; i <= node.size(); i++)
		p.push_back(i);

	bron_kerbosh(r,p,e);

	// Ordena o vetor "cliques" em ordem decrescente com relacao ao tamanho dos cliques encontrados
	sort(cliques.begin(), cliques.end(), cmp);

	// Mostra o maior clique maximal
	printf("Clique Maximo\n");
	printf("Tamanho: %d\n", (int)cliques[0].size());
	for(auto x : cliques[0])
		cout << node[x] << endl;
	

	printf("------------------------------------------------------------------------\n");
	printf("\n");

	// Mostra um outro clique maximal, de tamanho menor ou igual ao primeiro
	printf("Clique maximal\n");
	printf("Tamanho: %d\n",(int)cliques[1].size());
	for(auto x : cliques[1])
		cout << node[x] << endl;
}

void all_cliques(){
	printf("------------------------------------------------------------------------\n");
	printf("Printando  todos os cliques\n");

	// Percorre a lista de todos os cliques já ordenado
	for(int i = 0; i < cliques.size(); i++){
		for(auto x : cliques[i])
			cout << node[x] << " ";
		puts("");
	}

}


int main(){
	// Variavel para ler o nome do arquivo que contem o grafo
	string file;

	cout << "Input gml file name (ex : friends, friends2, karate) : ";

	// Le o nome do arquivo
	cin >> file;

	//Tenta ler o arquivo e caso nao exista, encerra o programa
	if (!read(file + ".gml")){
		cout << "System finished" << endl;
		return 0;
	}
	// Mostra o grafo no terminal (testes)
	// show();

	// Mostra os vertices ordenados por grau
	show_sorted();

	// Encontra um clique de tamanho 5
	clique();

	// Descomentar a função all_cliques para imprimir todos os cliques
	// all_cliques();

	// Imprime o grafo (Ponto Extra)
	printGraph(grafo);

	return 0;
}
