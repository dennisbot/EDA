#include <bits/stdc++.h>
#include <pthread.h>
#define db(a) cout << #a << " = " << a << endl
#define db2(a, b) cout << #a << " = " << a << " " << #b << " = " << b << endl
#define MAX_THREADS 4

using namespace std;

void mostrar_lista(int rank);

struct lista {
    int long long value;
    int depth;
    lista* pointer;
};

lista* mi_lista;
pthread_mutex_t mi_mutex;
pthread_t* arr_pthreads;

void* run(void* rank) {
    int long long mi_rank = (int long long) rank;
    printf("mi_rank = %d\n", mi_rank);
    int opt = rand() % 2;
    opt = 0;
    if (opt == 0) { // inserción
        pthread_mutex_lock(&mi_mutex);
        lista* head = new lista;
        // db(head->value);
        head->value = rand() % 100;
        head->value = mi_rank;
        // printf("head->value : %d\n", head->value);
        head->depth = mi_lista == NULL ? 0 : mi_lista->depth + 1;
        // db2(head->depth, mi_lista->depth);
        head->pointer = mi_lista;
        mi_lista = head;
        // mostrar_lista(mi_rank);
        pthread_mutex_unlock(&mi_mutex);
    } else { // eliminación
        pthread_mutex_lock(&mi_mutex);
        pthread_mutex_unlock(&mi_mutex);
    }
    return NULL;
}

void mostrar_lista(int rank) {
    lista* tmp = mi_lista;
    while (tmp != NULL) {
        printf("tmp->value : %lld \ttmp->depth : %d\n", tmp->value, tmp->depth);
        tmp = tmp->pointer;
    }
    puts("=====================");
}

int main() {
    srand(time(0));
    arr_pthreads = (pthread_t*) malloc(MAX_THREADS * sizeof(pthread_t));
    // mi_lista = new lista;
    // mi_lista->value = 12;
    // mi_lista->depth = 0;
    // mi_lista->pointer = NULL;
    mi_lista = NULL;
    pthread_mutex_init(&mi_mutex, NULL);
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&arr_pthreads[i], NULL, run, (void*) i);
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(arr_pthreads[i], NULL);
    }
    mostrar_lista(4);
    printf("mi_lista->value = %d\n", mi_lista->value);
    printf("hola mundo! :)\n");
    return 0;
}