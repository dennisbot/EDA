#include <bits/stdc++.h>
#include <pthread.h>
#define db(a) cout << #a << " = " << a << endl
#define MAX_THREADS 4

using namespace std;

struct lista {
    int value;
    int depth;
    lista* pointer;
};
lista* p;

void mostrar() {
    int i = 0;
    lista* temp = p;
    while (p != NULL) {
        printf("el[%d] = %d\n", i, p->value);
        p = p->pointer;
    }
    p = temp;
}

int main() {
    int n;
    while (scanf("%d", &n)) {
        lista* pp = new lista;
        pp->value = n;
        pp->pointer = p;
        p = pp;
        mostrar();
    }
    return 0;
}