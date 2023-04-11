#include <stdio.h>
#include <stdlib.h>
#include "crivoInt.h"

int main(int argc, char const *argv[]) {
    int tamanho=atoi(argv[1]);
    
    CrivoInt* crivo=iniciaCrivo(tamanho);
    selecionaPrimos(crivo);
    printaPrimos(crivo);
    deletaCrivo(crivo);

    return 0;
}