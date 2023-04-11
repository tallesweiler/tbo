#include <stdio.h>
#include <stdlib.h>
#include "crivoInt.h"

struct crivoint{
    int tamanho;
    int* crivo;
};

CrivoInt* iniciaCrivo(int tamanho) {
    CrivoInt* crivo = malloc(sizeof(CrivoInt));
    crivo->tamanho=tamanho;
    crivo->crivo=malloc(sizeof(int)*tamanho);

    for (int i=0;i<tamanho;i++) {
        crivo->crivo[i]=i;
    }

    return crivo;
}

void selecionaPrimos(CrivoInt * crivo) {
    for (int i=2;i<crivo->tamanho;i++) {
        if (crivo->crivo[i]) {
            for (int j=2;i*j<crivo->tamanho;j++) {
                crivo->crivo[i*j]=0;
            }
        }
    }
}

void printaPrimos(CrivoInt* crivo) {
    for (int i=0;i<crivo->tamanho;i++) {
        if (crivo->crivo[i]) {
            printf("%d ", crivo->crivo[i]);
        }
    }
    printf("\n");
}

void deletaCrivo(CrivoInt* crivo) {
    if (crivo) {
        if (crivo->crivo) {
            free(crivo->crivo);
        }
        free(crivo);
    }
}