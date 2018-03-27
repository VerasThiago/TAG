#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[1000];
map<int,string> node;
map<string,int> nodes;

void read(string file){
	int idx = 1;
	string line,source, target;
	fstream arquivo;
	arquivo.open(file);
	if(!arquivo){
		cout << "Falha ao abrir o arquivo" << endl;
		return;
	}
	while(arquivo >> line){
		if(line == "edge"){
			while(arquivo >> line, line != "source");
			arquivo >> source;
			while(arquivo >> line, line != "target");
			arquivo >> target;
			grafo[nodes[source]].push_back(nodes[target]);
		}
		else if(line == "node"){
			while(arquivo >> line, line != "id");
			arquivo >> line;
			node[idx] = line;
			nodes[line] = idx++;
		}
	}
	cout << "grafo possui " << node.size() << " vertices" << endl;
	for(int i = 1; i <= node.size(); i++){
		cout << "grafo " << node[i] << " com " << grafo[i].size() << " filhos : ";
		for(auto u : grafo[i]) cout << node[u] << ", ";
		puts("");
	}
}



int main(){
	string file;
	cout << "Input gml file name: ";
	cin >> file;
	read(file + ".gml");
}
