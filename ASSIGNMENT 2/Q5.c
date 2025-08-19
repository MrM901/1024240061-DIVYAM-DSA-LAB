#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int numRows;
    int numCols;
    int numElements; 
    Element *elements;
} SparseMatrix;

void create(SparseMatrix *s) {
    printf("Enter matrix dimensions (rows columns): ");
    scanf("%d %d", &s->numRows, &s->numCols);
    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->numElements);

    s->elements = (Element *)malloc(s->numElements * sizeof(Element));

    printf("Enter the non-zero elements (row col value) in sorted row-major order:\n");
    for (int i = 0; i < s->numElements; i++) {
        scanf("%d %d %d", &s->elements[i].row, &s->elements[i].col, &s->elements[i].value);
    }
}

void display(SparseMatrix s) {
    printf("\nRows: %d, Cols: %d, Non-zero Elements: %d\n", s.numRows, s.numCols, s.numElements);
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < s.numElements; i++) {
        printf("%d\t%d\t%d\n", s.elements[i].row, s.elements[i].col, s.elements[i].value);
    }
}

SparseMatrix add(SparseMatrix s1, SparseMatrix s2) {
    SparseMatrix sum;
    int i = 0, j = 0, k = 0;

    if (s1.numRows != s2.numRows || s1.numCols != s2.numCols) {
        printf("\nError: Matrices dimensions are not compatible for addition.\n");
        sum.numElements = 0;
        sum.elements = NULL;
        return sum;
    }

    sum.numRows = s1.numRows;
    sum.numCols = s1.numCols;
    sum.elements = (Element *)malloc((s1.numElements + s2.numElements) * sizeof(Element));

    while (i < s1.numElements && j < s2.numElements) {
        if (s1.elements[i].row < s2.elements[j].row) {
            sum.elements[k++] = s1.elements[i++];
        } else if (s1.elements[i].row > s2.elements[j].row) {
            sum.elements[k++] = s2.elements[j++];
        } else { 
            if (s1.elements[i].col < s2.elements[j].col) {
                sum.elements[k++] = s1.elements[i++];
            } else if (s1.elements[i].col > s2.elements[j].col) {
                sum.elements[k++] = s2.elements[j++];
            } else { 
                sum.elements[k] = s1.elements[i];
                sum.elements[k++].value = s1.elements[i++].value + s2.elements[j++].value;
            }
        }
    }

    for (; i < s1.numElements; i++) sum.elements[k++] = s1.elements[i];
    for (; j < s2.numElements; j++) sum.elements[k++] = s2.elements[j];

    sum.numElements = k;
    sum.elements = (Element *)realloc(sum.elements, k * sizeof(Element));

    return sum;
}

int main() {
    SparseMatrix s1, s2, s3;

    printf("--- Create First Matrix ---\n");
    create(&s1);
    printf("\n--- Create Second Matrix ---\n");
    create(&s2);

    printf("\n--- First Matrix ---");
    display(s1);
    printf("\n--- Second Matrix ---");
    display(s2);

    s3 = add(s1, s2);
    if (s3.elements != NULL) {
        printf("\n--- Resultant Matrix (Addition) ---");
        display(s3);
        free(s3.elements);
    }

    free(s1.elements);
    free(s2.elements);

    return 0;
}