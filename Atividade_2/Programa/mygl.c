#include "mygl.h"

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
void PutPixel(Vertices v, Cores cor){
    
    int pos = (IMAGE_WIDTH*v.y + v.x) * 4;
    fb_ptr[pos]     = cor.red;
    fb_ptr[pos + 1] = cor.green;
    fb_ptr[pos + 2] = cor.blue;
    fb_ptr[pos + 3] = cor.alpha;
}


void DrawLine(Vertices vert1, Vertices vert2, Cores cor1, Cores cor2){
    
   
    // cálculo de dx e dy
    int dx = vert2.x - vert1.x;
    int dy = vert2.y - vert2.y;

    int d; // variável de decisão

    // variáveis de incremento da variável de decisão
    int inc_L1, inc_L2;
    int inc_NE1, inc_NE2;

    inc_NE1 = 2 * (dy - dx); // sinal negativo
    inc_NE2 = 2 * (dy + dx); // sinal positivo

    inc_L1 = 2 * dy; // sinal positivo
    inc_L2 = -2 * dy; // sinal negativo

    int InclinacaoReta;

    if (dx < 0){

        DrawLine(vert2, vert1, cor2, cor1);
        return;

    } 


    if (dy < 0){

        InclinacaoReta = -1;

    } else {

        InclinacaoReta = 1;

    }

    PutPixel(vert1, cor1);

    if(dx >= InclinacaoReta * dy){

        if(dy < 0){
            
            d = 2 * dy + dx; // decisão para o primeiro pixel 

            while(vert1.x < vert2.x){

                if (d <= 0){
                    d += inc_NE2;
                    vert1.x++;
                    vert1.y++;
                } else {
                    d += inc_L1;
                    vert1.x++;
                }
                // Adicionar interpolação das cores
                // E PutPixel()
            }
        } else {

            d = 2 * dy - dx;

            while (vert1.x < vert2.x) {
                
                if (d < 0){
                    d += inc_L1;
                    vert1.x++;
                } else {
                    d += inc_NE1;
                    vert1.x++;
                    vert1.y++;
                } 
                // Adicionar interpolação das cores
                // E PutPixel()
            }
            
        }
    } else {

        if (dy < 0){

            d = dy + 2 * dx;

            while (vert1.y > vert2.y) {
                
                if(d < 0){
                    d += inc_L1;
                    vert1.y--;
                } else {
                    d += inc_NE2;
                    vert1.x++;
                    vert1.y--;
                }
                // Adicionar interpolação das cores
                // E PutPixel()
            }

        } else {

            d = dy - 2 * dx;

            while (vert1.y < vert2.y) {
                if (d < 0){
                    d += inc_NE1;
                    vert1.x++;
                    vert1.y++;
                } else {
                    d += inc_L2;
                    vert1.y++;
                }
                // Adicionar interpolação das cores
                // E PutPixel()
            }
        }
    }

    //PutPixel();

}

void DrawTriangle(void){
    
}
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
    

    // Exemplo para a função PutPixel()
    /*
    Vertices p1 = {250, 250};
    Cores c1 = {64,224,208,255};

    PutPixel(p1, c1); */ 
}
