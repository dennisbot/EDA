#include <bits/stdc++.h>
#include "matrix_helper.h"
#define db(a) \
cout << #a << " = "<< a << endl;
#define db2(a,b) \
cout << #a << " = " <<  a << " " << #b << " = " << b << endl;
#define db3(a,b,c) \
cout << #a << " = " <<  a << " " << #b << " = " << b \
<< " " << #c << " = " << c << endl;

#define dbl(i, a) cout << "[" << i << "]" << " = "<< a << ", ";
#define foreach(mapa, it) \
 for (typeof(mapa.begin()) it = mapa.begin(); it != mapa.end(); it++)
#define listar(lista) \
    for(int i = 0; i < lista.size(); i++) \
        { dbl(i, lista[i]);} cout << endl;

using namespace std;

int main() {
    #ifdef dennisbot
        freopen("matrix_gen.in", "r", stdin);
        freopen("matrix_gen.out", "w", stdout);
        clock_t _start = clock();
    #endif
    srand(time(0));
    int n, **M, **I;
    scanf("%d", &n);
    printf("%d\n", n);
    M = (int**) malloc(n * sizeof(int*));
    I = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        M[i] = (int*)malloc(n * sizeof(int));
        I[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            M[i][j] = rand() % 10;
            if (i == j) I[i][j] = 1;
            else I[i][j] = 0;
        }
    }
    matrix_readable_print(M, n, n);
    matrix_readable_print(I, n, n);


    #ifdef dennisbot
        // printf("\ntime=%.3fs\n", (clock() - _start) * 1. / CLOCKS_PER_SEC);
    #endif
    return 0;
}