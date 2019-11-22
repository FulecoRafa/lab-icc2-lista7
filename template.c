void algoritmo(int *v , int n){ 
    int j;
    int aux = (int)(n / 2.0);
    while(aux > 0){ 
        for(j = aux; j < n; ++j){ 
            int k = *(v+j);
            int b = j;
            while ((b >= aux) && (v[b−aux] > k)){ 
                v[b] = v[b−aux];
                b −= aux;
            }
            v[b] = k;
        }
        aux = (int) (aux / 2.0); 
    }
} 