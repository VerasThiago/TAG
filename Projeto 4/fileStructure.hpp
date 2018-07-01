#include <bits/stdc++.h>

using namespace std;
# define ESC 0x1b

char YELLOW[] = { ESC, '[', '1', ';', '3', '3', 'm', 0 };
char BLUE[] = { ESC, '[', '1', ';', '3', '4', 'm', 0 };

#define RED     "\x1b[31m"  
#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif


// Arquivo para abrir os dados dos cartoes de crédito
ifstream fd ("creditcard.csv");


// O( str.size() )

// Struct que representa as transações
struct transacoes{

    // Variáveis que representam os dados das transações
    int idx;

    int tempo;

    double montante;

    bool fraude;

    vector<double> estatisticas;

    double montanteEntropia;

    double tempoEntropia;
    
    // Construtor das transações
    transacoes(int idx, int tempo, double montante, bool fraude, vector<double> estatisticas){
        this->idx = idx;
        this->tempo = tempo;
        this->montante = montante;
        this->fraude = fraude;
        this->estatisticas = estatisticas;
    }

    int getTempo(){
        return tempo;
    }

    double getMontante(){
        return montante;
    }

    vector<double> getEstatisticas(){
        return estatisticas;
    }

    int getIdx(){
        return idx;
    }

    void setMontanteEntropia(double montante){
        this->montanteEntropia = montante;
    }

    void setTimeEntropia(double tempo){
        this->tempoEntropia = tempo;
    }

    double getMontanteEntropia(){
        return this->montanteEntropia;
    }

    double getTempoEntropia(){
        return this->tempoEntropia;
    }

    bool getFraude(){
        return this->fraude;
    }

};
// Total de transações
vector<transacoes*> graph(284807); 

vector<string> split(string str){
    stringstream ss (str);
    vector<string> result;
    while( ss.good() ){
        string substr;
        getline( ss, substr, ',' );
        result.push_back( substr );
    }
    return result;
}

void readFile(){

    int i = 0;
    int zeros = 0, f_zero = 0;
    if (!fd){
        cout << RED << "Erro na abertura do arquivo. O arquivo 'creditcard.csv' existe no seu diretório atual?" << RESET << endl;
        exit(EXIT_FAILURE);
    }
    // String para ler as linhas
    string line;

    getline(fd, line); // first line is for headers, not data

    double ant = 0;

    while(getline(fd, line)){
        vector<string> parts = split(line);
        

        double agora = ((i/284807.0)*100);

        if(agora > ant + 2){
            // Limpa a tela 
            system(CLEAR);
            cout << GREEN  << "Carregando o arquivo : ";
            printf("%.0lf",agora);
            cout << '%' << RESET << endl;
            ant = agora;
        }

        // safety check
        if (parts.size() != 31){
            cout << YELLOW << "Warning: " << RESET << "Parts doesn't have correct number of items. Line" << i << " Ignored.\n";
            continue;
        }
        // extracting parts
        int t = stoi(parts[0]);
        vector<double> s;
        for(int i = 0; i < 28; i++){
            double stat = stod(parts[1+i]);
            s.push_back(stat);
        }
        double am = stod(parts[29]); 

        if (am == 0)
            zeros++;
        bool f = stoi(parts[30].substr(1,1)); // last column has double quotes in it

        if (f == true && am == 0)
            f_zero++;
        // add transaction to graph
        graph[i] = new transacoes(i, t, am, f, s);
        i++;
    }

    system(CLEAR);
    cout << GREEN  << "Carregando o arquivo : 100" << '%' << RESET << endl;

    // safety check
    if (i != 284807)
        cout << RED << "Operação de leitura completada com erros." << RESET << endl;
    else
        cout << GREEN << "SUCCESS" << RESET <<  endl << i << " transações encontradas" << endl;
}