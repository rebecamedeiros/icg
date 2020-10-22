#include "mygl.h"
#include <math.h>

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
    
    int pos = (IMAGE_WIDTH*p.y + p.x) * 4;
    fb_ptr[pos]     = cor.red;
    fb_ptr[pos + 1] = cor.green;
    fb_ptr[pos + 2] = cor.blue;
    fb_ptr[pos + 3] = cor.alpha;
}

// Funções para calcular interpolação e distância
Cores InterpolacaoDeCores(float a, Cores cor1, Cores cor2){
    Cores c;

    c.red = cor1.red + ((1 - a) * cor2.red);
    c.green = cor1.green + ((1 - a) * cor2.green);
    c.blue = cor1.blue + ((1 - a) * cor2.blue);
    c.alpha = cor1.alpha + ((1 - a) * cor2.alpha);

    return c;
}

float DistanciaEntrePontos(Pontos p1, Pontos p2){

    //float r = ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
 
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));

    //return pow(((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)), 0.5);

}

// 

void DrawLine(Pontos p1, Pontos p2, Cores cor1, Cores cor2){
   
    // cálculo de dx e dy
    int dx = p2.x - p1.x;
    int dy = p2.y - p2.y;

    int d; // variável de decisão

    // variáveis de incremento da variável de decisão
    int inc_L1, inc_L2;
    int inc_NE1, inc_NE2;

    inc_NE1 = 2 * (dy - dx); // sinal negativo
    inc_NE2 = 2 * (dy + dx); // sinal positivo

    inc_L1 = 2 * dy; // sinal positivo
    inc_L2 = -2 * dy; // sinal negativo

    int InclinacaoReta;

    float Distancia; // distância parcial de p1 até p2

    float Comprimento = DistanciaEntrePontos(p1, p2);

    if (dx < 0){

        DrawLine(p2, p1, cor2, cor1);
        return;

    } 


    if (dy < 0){

        InclinacaoReta = -1;

    } else {

        InclinacaoReta = 1;

    }

    Pontos ponto = p1;
    Cores c = cor1;
    PutPixel(ponto, c);

    if(dx >= InclinacaoReta * dy){

        if(dy < 0){
            
            d = 2 * dy + dx; // decisão para o primeiro pixel 

            while(ponto.x < p2.x){

                if (d < 0){
                    d += inc_NE2;
                    ponto.x++;
                    ponto.y--;
                } else {
                    d += inc_L1;
                    ponto.x++;
                }

                Distancia = DistanciaEntrePontos(ponto, p2);
                c = InterpolacaoDeCores(Distancia/Comprimento, cor1, cor2);
                PutPixel(ponto, c);

            }
        } else {

            d = 2 * dy - dx;

            while (ponto.x < p2.x) {
                
                if (d < 0){
                    d += inc_L1;
                    ponto.x++;
                } else {
                    d += inc_NE1;
                    ponto.x++;
                    ponto.y++;
                } 

                Distancia = DistanciaEntrePontos(ponto, p2);
                c = InterpolacaoDeCores(Distancia/Comprimento, cor1, cor2);
                PutPixel(ponto, c);

            }
            
        }
    } else {

        if (dy < 0){

            d = dy + 2 * dx;

            while (ponto.y > p2.y) {
                
                if(d < 0){
                    d += inc_L1;
                    ponto.y--;
                } else {
                    d += inc_NE2;
                    ponto.x++;
                    ponto.y--;
                }

                Distancia = DistanciaEntrePontos(ponto, p2);
                c = InterpolacaoDeCores(Distancia/Comprimento, cor1, cor2);
                PutPixel(ponto, c);

            }

        } else {

            d = dy - 2 * dx;

            while (ponto.y < p2.y) {
                if (d < 0){
                    d += inc_NE1;
                    ponto.x++;
                    ponto.y++;
                } else {
                    d += inc_L2;
                    ponto.y++;
                }
                // Adicionar interpolação das cores
                // E PutPixel()

                Distancia = DistanciaEntrePontos(ponto, p2);
                c = InterpolacaoDeCores(Distancia/Comprimento, cor1, cor2);
                PutPixel(ponto, c);

            }
        }
    }

    PutPixel(p2, cor2);

}

void DrawTriangle(Pontos p1, Pontos p2, Pontos p3, Cores c1, Cores c2, Cores c3){

    DrawLine(p1,p2,c1,c2);
    DrawLine(p2,p3,c2,c3);
    DrawLine(p3,p1,c3,c1);

    
}
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
    

    // Exemplo para a função PutPixel()
    /*
    Pontos p1 = {250, 250};
    Cores c1 = {64,224,208,255};

    PutPixel(p1, c1);
    */
    // Exemplo para a função DrawLine()


    Pontos p1 = {250, 50};
    Cores c1 = {0,0,255,255};
    
    Pontos p2 = {170, 400};
    Cores c2 = {0,0,255,255};

    DrawLine(p1, p2, c1, c2);
    
    //DrawTriangle(p1, p2,p3,c1,c2,c3);

}
