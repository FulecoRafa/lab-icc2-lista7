#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void algoritmo(int *v , int n){ 
    int j;
    int aux = (int)(n / 2.0);
    while(aux > 0){ 
        for(j = aux; j < n; ++j){ 
            int k = *(v+j);
            int b = j;
            while ((b >= aux) && (v[b-aux] > k)){ 
                v[b] = v[b-aux];
                b -= aux;
            }
            v[b] = k;
        }
        aux = (int) (aux / 2.0); 
    }
} 

void algoritmoNovo(int *v , int n){ 
    int j;
    long int aux = 1;
    int prev;
    while(aux-1<n){
        prev = aux;
        if(aux == 1){
            aux = 2;
        }else{
            aux *= aux;
        }
    }

    aux = prev-1;
    while(aux > 0){ 
        for(j = aux; j < n; ++j){ 
            int k = *(v+j);
            int b = j;
            while ((b >= aux) && (v[b-aux] > k)){ 
                v[b] = v[b-aux];
                b -= aux;
            }
            v[b] = k;
        }
        
        aux = (sqrt((aux+1))-1); 
    }
} 


int main(void){
    srand(time(NULL));
    float times[4];
    float timesNew[4];
    float ini , fim;
    int size = 100;
for(int i = 0 ; i < 4 ; i++){
    int input[size];
    printf("[Vetor Original] -> {");
    for(int i = 0 ; i < size ; i++){
        input[i] = rand()%100;
        printf("%d," , input[i]);
    }
    printf("\b} size = %d\n" , size);
    ini = clock();
    algoritmo(input,size);
    fim = clock();
    times[i] = ((double)(fim-ini))/CLOCKS_PER_SEC;
    printf("[Vetor] -> {");
    for(int i = 0 ; i < size ; i++){
        printf("%d," , input[i]);
    }
    printf("\b}\n");
    ini = clock();
    algoritmoNovo(input,size);
    fim = clock();
    timesNew[i] = ((double)(fim-ini))/CLOCKS_PER_SEC;
    size *= 10;
}
    printf("Velho:\n");
    printf("Tempo 100 -> %f\nTempo 1000 -> %f\nTempo 10000 -> %f\nTempo 100000 -> %f\n", times[0] , times[1] , times[2] , times[3]);
    printf("Novo:\n");
    printf("Tempo 100 -> %f\nTempo 1000 -> %f\nTempo 10000 -> %f\nTempo 100000 -> %f\n", timesNew[0] , timesNew[1] , timesNew[2] , timesNew[3]);
    return 0;
}