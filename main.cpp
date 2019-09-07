#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*
Author: André Rodrigues Rocha.
Remember to delete this if you copy :P
Language program: C++/C

I'm Brazilian so every variable is in Portuguese because yes.
*/
using namespace std;


int main()
{

    FILE *arquivo;
      arquivo = fopen("Dimacs.txt", "wt"); //create the document

    int n=4;//this variable you can put a size of chessboard
    int tabuleiro[n][n]; //tabuleiro = chessboard
    int linha; //linha = line
    int coluna;//coluna = column
    int auxilio;//auxilio = aux obvious :p
    int m=1;

    //rule: At least one queen on line
    for(linha=1;linha<=n;linha++){
        for(coluna=1;coluna<=n;coluna++){
            tabuleiro[linha][coluna]=m;
            fprintf(arquivo,"%d ", m);
            m++;
        }
        fprintf(arquivo,"0\n");
    }fprintf(arquivo,"\n");

//rule of queens
    for(linha=1;linha<=n;linha++){
        for(coluna=1;coluna<=n;coluna++){
            fprintf(arquivo,"%d 0\n",tabuleiro[linha][coluna]);
        }
    }


//rule: At least one queen on column
    for(linha=1;linha<=n;linha++){
        for(coluna=1;coluna<=n;coluna++){
        fprintf(arquivo,"%d ",tabuleiro[coluna][linha]);

        }
        fprintf(arquivo,"0\n");
    }

// rule of lines
    for(linha=1; linha<=n;linha++){
            fprintf(arquivo,"c linha %d: \n",linha);
        for(coluna=1;coluna<=n;coluna++){
            for(auxilio=1;auxilio<=n;auxilio++){
                if(auxilio!=coluna){
                 fprintf(arquivo,"-%d%",tabuleiro[linha][coluna]);
                 fprintf(arquivo,"-%d% ",tabuleiro[linha][auxilio]);
                 fprintf(arquivo,"0\n");
              }
            }
        }fprintf(arquivo,"\n");
       fprintf(arquivo,"\n");
    }

//rule of columns
    for(coluna=1; coluna<=n;coluna++){
            fprintf(arquivo,"c coluna %d: \n",coluna);
        for(linha=1;linha<=n;linha++){
            for(auxilio=1;auxilio<=n;auxilio++){
              if(auxilio!=linha){
                  fprintf(arquivo,"-%d%",tabuleiro[linha][coluna]);
                  fprintf(arquivo," -%d 0",tabuleiro[auxilio][coluna]);
                  fprintf(arquivo,"\n");
              }
            }
        }
        fprintf(arquivo,"\n");
    }



//rule of diagonal
        for(linha=1;linha<=n;linha++){
            for(coluna=1;coluna<=n;coluna++){
                if(linha!=n&&coluna!=n){
                    int k=linha+1;
                    int m=coluna+1;
                    while( k<=n && m<=n ){
                        fprintf(arquivo,"-%d", tabuleiro[linha][coluna]);
                        fprintf(arquivo," -%d 0\n" , tabuleiro[k++][m++]);
                    }fprintf(arquivo,"\n");
                }
            }
        }
    fclose(arquivo);
}


