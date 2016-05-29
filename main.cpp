#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <cstdlib>
#define SIZE 10
#define STRING_SIZE 20
#define MAX 100
/*shortest path length between any two cities (All Pairs Shortest Paths)*/

using namespace std;

int** adjacency_matrix;
int ** length;


int main()
{
    char filename[] = "roadmap.txt";
    fstream file;
    int i,j,k;
    char input[STRING_SIZE];
    char* m;
    int a,b,w;
    file.open(filename,ios::in);

    adjacency_matrix = new int* [SIZE];
    length = new int* [SIZE];
    for( i = 0 ; i < SIZE ; i++){
        adjacency_matrix[i] = new int [SIZE];
        length[i] = new int [SIZE];
    }

    for( i = 0 ; i < SIZE ; i++){
        for( j = 0 ; j < SIZE ; j++){
            adjacency_matrix[i][j] = 0;
            if(i != j)
                length[i][j] = MAX;
            else
                length[i][j] = 0;
        }
    }


    while(file.getline(input,sizeof(input),'\n')){
        cout << input << endl;
        int count = 0 ;

        m = strtok(input,"(), ");
        a = atoi(m);

        m = strtok(NULL,"(), ");
        b = atoi(m);

        m = strtok(NULL,"(), ");
        w = atoi(m);

        if( a != b){
            adjacency_matrix[a][b] = w;
        }

    }

    for( i = 0 ; i < SIZE ; i++){
        for( j = 0 ; j < SIZE ; j++);
           // cout << adjacency_matrix[i][j] << ends;
     //   cout << endl;
    }

    for( i = 0 ; i < SIZE ; i++){
        for( j = 0 ; j < SIZE ; j++){
            if(adjacency_matrix[i][j] != 0)
                length[i][j] = adjacency_matrix[i][j];
            //cout << length[i][j] << ends;
        }
        cout <<endl;
    }

    for( k = 0 ; k < SIZE ; k++){
        for( i = 0 ; i < SIZE ; i++){
            for ( j = 0 ; j < SIZE ; j++){
                if(( length[i][k] + length[k][j] ) < length[i][j])
                    length[i][j] = length[i][k] + length[k][j];
            }
        }
    }


    for( i = 0 ; i < SIZE ; i++){
        for( j = 0 ; j < SIZE ; j++){
            if(length[i][j] == MAX){
                length[i][j] = 0;
            }
            cout << length[i][j] << '\t';
        }

        cout << endl;
    }




    file.close();
    return 0;
}
