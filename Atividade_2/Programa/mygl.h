#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

unsigned char *fb_ptr;

// Structs 
typedef struct {
    int red, green, blue, alpha;
} Cores;

typedef struct {
    int x, y;
} Pontos;

// Fim das structs

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Caro aluno: declare aqui as funções que você implementar <<<
//

void PutPixel(Pontos v, Cores cor);
void DrawLine(Pontos p1, Pontos p2, Cores cor1, Cores cor2);
void DrawTriangle(void);

#endif  // MYGL_H
