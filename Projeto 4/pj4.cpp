#include <bits/stdc++.h>
#include "fileStructure.hpp"
# define ESC 0x1b

using namespace std;

#define RED     "\x1b[31m"  
#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


typedef struct {
    int size[28];
    int frauds[28];
    vector<int> group[28];
} community;



vector<community> raw_split(vector<transacoes*> G){
    // Groups are LOW and HIGH
    vector<community> groups(2);
    // sizes start as 0
    memset(groups[0].size, 0, sizeof(int)*28);
    memset(groups[1].size, 0, sizeof(int)*28);
    for(transacoes* t : G){
        vector<double> stats = t->getEstatisticas();
        for(int i = 0; i < 28; i++){
            double k = stats[i];
            if(k > 0){
                groups[1].size[i]++;
                groups[1].group[i].push_back(t->getIdx());
                if( t->getFraude())
                    groups[1].frauds[i]++;
            }
            else{
                groups[0].size[i]++;
                groups[0].group[i].push_back(t->getIdx());
                if( t->getFraude())
                    groups[0].frauds[i]++;
            }
        }
    }

    return groups;
}

bool cmp(int i,int j) { return (i<j); }

vector<int> intersection(vector<int> a, vector<int> b){
    vector<int> answer;
    if(a.size() <= b.size()){
        for(int k : a){
            if( binary_search(b.begin(), b.end(), k, cmp)){
                answer.push_back(k);
            }
        }
    }
    else{
        for(int k : b){
            if( binary_search(a.begin(), a.end(), k, cmp)){
                answer.push_back(k);
            }
        }
    }
    return answer;
}

void countFrauds(vector<int> OUT, vector<transacoes*> G){
    int r = 0;
    for(int i : OUT){
        if(G[i]->getFraude())
            r++;
    }
    cout << CYAN << "Tamanho da comunidade : " << RESET << OUT.size() << endl;
    cout << RED << "Quantidade de fraudes : " << RESET << r << endl;
}

vector<int> makeCommunity(vector<community> C){
    vector<int> out;
    // initial assignment
    int l = 28, i;
    cout << CYAN << "DADOS REFERENTE A COMUNIDADE MAIS ANÔMALA:\n" << RESET;
    vector<int> high,low;
    for(i = 0; i < l; i++){
        if(C[0].frauds[i]*4 <= C[1].frauds[i]){
            high.push_back(i);
            out = C[1].group[i];
            break;
        }
        else if (C[0].frauds[i] >= C[1].frauds[i]*4){
            low.push_back(i);
            out = C[0].group[i];
            break;
        }
    }
    i++;
    while(i < l){
        if(C[0].frauds[i]*4 <= C[1].frauds[i]){
            out = intersection(out, C[1].group[i]);
            high.push_back(i);
        }
        else if (C[0].frauds[i] >= C[1].frauds[i]*4){
            out = intersection(out, C[0].group[i]);
            low.push_back(i);
        }
        i++;
    }

    cout << BLUE << "ALTO " << RESET << " - Representa propriedades que possuem valores" << GREEN << " positivos" << RESET << endl;
    cout << YELLOW <<"BAIXO "  << RESET << " - Representa propriedades que possuem valores" << RED << " negativos" << RESET << endl;
    cout << BLUE << "<--------- 'ALTO' --------->" << RESET << endl;
    for(auto x : high){
        cout << "Propriedade V" << x << endl;
    }
    cout << YELLOW  << "<--------- 'BAIXO' --------->" << RESET << endl;
    for(auto x : low){
        cout << "Propriedade V" << x << endl;
    }
    return out;
}

int main(){
   
    
    // Leitura e estruturação dos dados
    readFile();
    
    // STATISTICS
    vector<community> raw_data = raw_split(graph);
    vector<int> out = makeCommunity(raw_data);


    // Função para contar a quantidade de fraudes
    countFrauds(out, graph);


    
    cout << GREEN << "Membros da comunidade mais anômala gerado em um arquivo 'Membros.txt'.\n";
    fstream saida("Membros.txt", ios::out);
    for(int i : out){
        saida << i << " ";
    }
    return 0;
}   