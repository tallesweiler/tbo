#ifndef crivo_int
#define crivo_int

typedef struct crivoint CrivoInt;

CrivoInt* iniciaCrivo(int size);
void selecionaPrimos(CrivoInt* crivo);
void printaPrimos(CrivoInt* crivo);
void deletaCrivo(CrivoInt* crivo);

#endif