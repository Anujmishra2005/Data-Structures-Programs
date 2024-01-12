#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

void displayPoly(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int coef2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sumCoefficient = coef1 + coef2;
        int sumExponent = (exp1 > exp2) ? exp1 : exp2;

        insertTerm(&result, sumCoefficient, sumExponent);

        if (poly1 != NULL) {
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }

    return result;
}

struct Term* subtractPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int coef2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int diffCoefficient = coef1 - coef2;
        int diffExponent = (exp1 > exp2) ? exp1 : exp2;

        insertTerm(&result, diffCoefficient, diffExponent);

        if (poly1 != NULL) {
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }

    return result;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    int n1, n2, coefficient, exponent;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; ++i) {
        printf("Enter the coefficient and exponent for term %d (separated by space): ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; ++i) {
        printf("Enter the coefficient and exponent for term %d (separated by space): ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    struct Term* sumResult = addPolynomials(poly1, poly2);

    printf("Result of addition: ");
    displayPoly(sumResult);

    struct Term* diffResult = subtractPolynomials(poly1, poly2);

    printf("Result of subtraction: ");
    displayPoly(diffResult);

    while (poly1 != NULL) {
        struct Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    while (poly2 != NULL) {
        struct Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    while (sumResult != NULL) {
        struct Term* temp = sumResult;
        sumResult = sumResult->next;
        free(temp);
    }

    while (diffResult != NULL) {
        struct Term* temp = diffResult;
        diffResult = diffResult->next;
        free(temp);
    }

    return 0;
}
