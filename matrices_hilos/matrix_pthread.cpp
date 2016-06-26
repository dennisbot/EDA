#include <bits/stdc++.h>
#include <pthread.h>
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
int nthreads = 4;
struct params {
    int rank;
    int total_size;
    int nthreads;
    int*** A;
    int*** B;
    int*** C;
};
pthread_mutex_t mtx;

void* thread_work(void* param) {

    params* thread_param = (params*)param;
    int rank             = thread_param->rank;
    int nthreads         = thread_param->nthreads;
    int total_size       = thread_param->total_size;
    int chunk_size       = total_size / nthreads;
    int start            = rank * chunk_size;
    int end              = (rank + 1) * chunk_size + ( (rank + 1 == nthreads) ? total_size % nthreads : 0 );
    int ***A              = thread_param->A;
    int ***B              = thread_param->B;
    int ***C              = thread_param->C;
    // pthread_mutex_lock(&mtx);
    // puts("======================================");
    // db2(rank, nthreads);
    // db2(total_size, chunk_size);
    // db2(start, end);
    // puts("======================================");
    // pthread_mutex_unlock(&mtx);
    for (int i = start; i < end; i++) {
        for (int j = 0; j < total_size; j++) {
            (*C)[i][j] = 0;
            for (int k = 0; k < total_size; k++) {
                (*C)[i][j] += (*A)[i][k] * (*B)[k][j];
            }
        }
    }
    return NULL;
}

int main(int argc, char** argv) {
    // #undef dennisbot
    #ifdef dennisbot
        freopen("matrix_pthread.in", "r", stdin);
        freopen("matrix_pthread.out", "w", stdout);
        clock_t _start = clock();
    #endif
    int n;
    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            if (i == 0)
                printf("%s", argv[i]);
            else
                printf(" %s", argv[i]);
        }
        puts("");
        nthreads = atoi(argv[argc - 1]);
    }
    while (scanf("%d", &n) != EOF) {
        int **A, **B, **C;
        /* se inicializa / reserva memoria para las matrices */
        matrix_init(&A, n, n);
        matrix_init(&B, n, n);
        matrix_init(&C, n, n);

        /* se hace lectura desde stdin de las matrices */
        matrix_read(&A, n, n);
        matrix_read(&B, n, n);

        /* se muestra en el stdout las matrices */
        // matrix_print(A, n, n);
        // matrix_print(B, n, n);

        // C = matrix_multiplication(A, B, n, n);
        // C = matrix_multiplication_omp(A, B, n, n);
        pthread_t* thread_handles;
        thread_handles = (pthread_t*)malloc(nthreads * sizeof(pthread_t));
        params *thread_params = (params*)malloc(nthreads * sizeof(params));
        pthread_mutex_init(&mtx, NULL);

        for (int i = 0; i < nthreads; i++) {
            thread_params[i].rank = i;
            thread_params[i].total_size = n;
            thread_params[i].nthreads = nthreads;
            thread_params[i].A = &A;
            thread_params[i].B = &B;
            thread_params[i].C = &C;
            pthread_create(&thread_handles[i], NULL, thread_work, (void *) &thread_params[i]);
        }
        for (int i = 0; i < nthreads; i++) {
            pthread_join(thread_handles[i], NULL);
        }
        free(thread_params);
        free(thread_handles);

        matrix_readable_print(C, n, n);
    }

    #ifdef dennisbot
        printf("\ntime=%.3fs\n", (clock() - _start) * 1. / CLOCKS_PER_SEC);
    #endif
    return 0;
}
