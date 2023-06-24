// C program to compute the FIRST of given grammar.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

typedef struct {
    char lhs;
    char rhs[MAX_SYMBOLS];
} Production;

int isTerminal(char symbol) {
    return (symbol >= 'a' && symbol <= 'z');
}

int isNonTerminal(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

void computeFirstSet(Production* productions, int numProductions, char symbol, char* firstSet) {
    int i;
    for (i = 0; i < numProductions; i++) {
        if (productions[i].lhs == symbol) {
            char firstSymbol = productions[i].rhs[0];
            if (isTerminal(firstSymbol)) {
                firstSet[firstSymbol - 'a'] = 1;
            } else if (isNonTerminal(firstSymbol)) {
                computeFirstSet(productions, numProductions, firstSymbol, firstSet);
            }
        }
    }
}

int main() {
    Production productions[MAX_PRODUCTIONS];
    int numProductions;
    char symbol;
    char firstSet[MAX_SYMBOLS] = {0};

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter the productions in the form 'A->alpha' (without spaces):\n");
    for (int i = 0; i < numProductions; i++) {
        scanf(" %c->%s", &productions[i].lhs, productions[i].rhs);
    }

    printf("Enter the symbol to compute its FIRST set: ");
    scanf(" %c", &symbol);

    computeFirstSet(productions, numProductions, symbol, firstSet);

    printf("FIRST(%c) = {", symbol);
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (firstSet[i] == 1) {
            printf("%c ", i + 'a');
        }
    }
    printf("}\n");

    return 0;
}
