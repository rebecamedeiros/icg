#include "mygl.h"
//#include <math.h>

unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

//
// >>> Caro aluno: defina aqui as funções que você implementar <<<
//

// 
void PutPixel(Pontos p, Cores cor){
    
    int j = (IMAGE_WIDTH * p.y + p.x) * 4;
    fb_ptr[j]     = cor.red;
    fb_ptr[j + 1] = cor.green;
    fb_ptr[j + 2] = cor.blue;
    fb_ptr[j + 3] = cor.alpha;
}


void DrawLine(Pontos p1, Pontos p2, Cores cor1, Cores cor2){
   
}

void DrawTriangle(Pontos p1, Pontos p2, Pontos p3, Cores c1, Cores c2, Cores c3){

    
}
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
   

    // Exemplo para a função PutPixel()
    Pontos p1 = {250, 250};
    Cores c1 = {64,224,208,255};

    PutPixel(p1, c1);
    
}
