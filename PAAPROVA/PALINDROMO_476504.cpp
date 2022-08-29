#include <cstdio>
#include <iostream>
#include <fstream> 

//name e a string de entrada e size seu tamanho
int solve(char* str, int size){
    std::string myString;
    myString.assign(str, size);
    int maxLength = 1;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int flag = 1;
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (myString[i + k] != myString[j - k])
                    flag = 0;
            if (flag && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
            }
        }
    }
    return maxLength;
}
//NAO MODIFICAR!
int main(int argc, char **argv){
    //LEITURA DOS ARQUIVOS DE ENTRADA
    std::ifstream ifs (argv[1], std::ifstream::in);
    int n;
    char name[300];
    ifs >> n;
    ifs.getline(name, 300);
    printf("TAMANHO DA STRING: %d \n", n);
    printf("STRING: %s \n", name);
    int sol = solve(name, n);
    printf("SOLUÇÃO PROVIDA: %d", sol);
    return 0;   
}

//476504