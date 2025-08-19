#include <stdio.h>
#include <stdlib.h>

struct UpperTriangularMatrix {
    int *A;
    int n;
};

void set(struct UpperTriangularMatrix *m, int i, int j, int x) {
    if (i <= j) {
        int index = (i * m->n) - (i * (i - 1) / 2) + (j - i);
        m->A[index] = x;
    }
}

int get(struct UpperTriangularMatrix m, int i, int j) {
    if (i <= j) {
        int index = (i * m.n) - (i * (i - 1) / 2) + (j - i);
        return m.A[index];
    }
    return 0;
}

void display(struct UpperTriangularMatrix m) {
    printf("Matrix:\n");
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            printf("%d ", get(m, i, j));
        }
        printf("\n");
    }
}

int main() {
    struct UpperTriangularMatrix m;
    m.n = 4;
    int size = m.n * (m.n + 1) / 2;
    m.A = (int *)malloc(size * sizeof(int));

    int val = 1;
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            if (i <= j) {
                set(&m, i, j, val++);
            }
        }
    }

    display(m);
    
    free(m.A);
    return 0;
}