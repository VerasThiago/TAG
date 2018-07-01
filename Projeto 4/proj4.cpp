#include <bits/stdc++.h>
#define RED     "\x1b[31m"  
#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


using namespace std;

fstream file("../../../creditcard.csv");
vector<double> data[31];

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

vector<string> get_header(){
	
		vector<string> colum;
		string aux;
	
		getline(file,aux);
	
		colum = split(aux,',');

		for(int i = 0; i < colum.size(); i++)
			colum[i] = colum[i].substr(1, colum[i].size() - 2);
	
		return colum;
}


void create(string line){

	vector<string> inputs;

	inputs = split(line,',');

	inputs[30] = inputs[30].substr(1, inputs[30].size() - 2);

	for(int i = 0; i < 31; i++)
		data[i].push_back(stod(inputs[i]));

}


int main(){

	vector<string> header = get_header();

	string line;

	int n = 900;


	cout << "Uploading creditcard.csv to memory" << endl;



	while(getline(file,line)){
		create(line);
		if(!n--) break;
	}

	cout << GREEN << "success" << RESET << endl;

	//for(int k = 0; k < 30; k++){
		for(int i = 0 ; i < 31; i++)
			cout << setprecision(14) <<  data[i][0] << " ";
		puts("");
	//}

	map< pair<double,double>, pair<int,int> > id;
	map< pair<int,int> , pair<double,double> >id_rev;

	int idx = 1;

	cout << "data[0].size = " << data[0].size() << endl;

	

	for(int k = 0; k < data[0].size(); k++)
		for(int i = 1; i < 28; i+=2){
			pair<double, double> cord = make_pair(data[i][k],data[i+1][k]);
			if(id.count(cord))
				printf("A coordenada (%lf,%lf)[%d,%d]{%d}  já esteve na pos (%d,%d)\n",cord.first,cord.second,i,i+1,k,id[cord].first,id[cord].second);
			else{
				id_rev[make_pair(i,k)] = cord;
				id[cord] = make_pair(i,k); 
			}	
		}

	



}