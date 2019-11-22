#include <stdio.h>

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
        printf("[Vetor] -> {");
        for(int i = 0 ; i < 8 ; i++){
            printf("%d," , v[i]);
        }
        printf("\b} aux = %d\n" , aux);
        aux = (int) (aux / 2.0); 
    }
} 


int main(void){
    int input[8] = {1,1,2,1,9,0,7,1};
    printf("[Vetor Original] -> ");
    for(int i = 0 ; i < 8 ; i++){
        printf("%d," , input[i]);
    }
    printf("\b} size = 8\n");
    algoritmo(input,8);


    return 0;
}