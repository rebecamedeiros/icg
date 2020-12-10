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
void PutPixel(Pontos p, Cores cor){
    
    int j = (IMAGE_WIDTH * p.y + p.x) * 4;
    fb_ptr[j]     = cor.red;
    fb_ptr[j + 1] = cor.green;
    fb_ptr[j + 2] = cor.blue;
    fb_ptr[j + 3] = cor.alpha;
}

Cores inter_cores(Cores c1, Cores c2, int dx){
    Cores cor;
    
    float cr = c2.red - c1.red;
    float cg = c2.green - c1.green;
    float cb = c2.blue - c1.blue;
    float ca = c2.alpha - c1.alpha;

    cor.red = cr/dx;
    cor.green = cg/dx;
    cor.blue = cb/dx; 
    cor.alpha = ca/dx;

    return cor;
}


void DrawLine(Pontos p1, Pontos p2, Cores cor1, Cores cor2){
    // Calculando deltas
    int dx = (p2.x - p1.x);
    int dy = (p2.y - p1.y);
    
    int x_incl, y_incl; // Inclinação das retas
    if (dx > 0){
       x_incl = 1;
    } else {
       x_incl = -1;
    }

    if (dy > 0){
        y_incl = 1;
    } else{
        y_incl = -1;
    }
    
    // Calculando incrementos
    int incremento_leste_1 = 2 * dy;    // Sinal positivo  
    int incremento_leste_2 = (-2) * dy; // Sinal negativo

    int incremento_ne1 = 2 * (dy - dx); // Sinal negativo
    int incremento_ne2 = 2 * (dy + dx); // Sinal positivo

    int d; // Variavel de decisão

    PutPixel(p1, cor1);

    if (dx < 0){
        DrawLine(p2, p1, cor2, cor1);
        return;
    } else {
        if (dx >= (y_incl * dy)){
            if (dy < 0){
                d = (2 * dy) - dx;
                while (p1.x < p2.x){
                    if (d < 0){
                        d += incremento_ne2;
                        p1.x++;
                        p1.y--;
                    } else {
                        d += incremento_leste_1;
                        p1.x++;
                    }   

                    Cores cor = inter_cores(cor1, cor2, dx);
                    cor1.red += cor.red;
                    cor1.blue += cor.blue;
                    cor1.green += cor.green;
                    cor1.alpha += cor.alpha;

                    PutPixel(p1, cor1);
                }
            } else {
                d = (2 * dy) - dx;
                while (p1.x < p2.x){
                    if (d < 0){
                        d += incremento_leste_1;
                        p1.x++;
                    } else {
                        d += incremento_ne1;
                        p1.x++;
                        p1.y++;
                    } 

                    Cores cor = inter_cores(cor1, cor2, dx);
                    cor1.red += cor.red;
                    cor1.blue += cor.blue;
                    cor1.green += cor.green;
                    cor1.alpha += cor.alpha;


                    PutPixel(p1, cor1);
                }
                
            }
        } else {
            if (dy < 0){
                d = (2 * dx) + dy;
                while (p1.y > p2.y){
                    if (d < 0){
                        d += incremento_leste_1;
                        p1.y--;
                    } else {
                        d += incremento_ne2;
                        p1.x++;
                        p1.y--;
                    }

                    Cores cor = inter_cores(cor1, cor2, dx);
                    cor1.red += cor.red;
                    cor1.blue += cor.blue;
                    cor1.green += cor.green;
                    cor1.alpha += cor.alpha;

                    PutPixel(p1, cor1);
                    
                }
                
            } else {
                d = dy - (2 * dx);
                while (p1.y < p2.y){
                    if(d < 0){
                        d += incremento_ne1;
                        p1.x++;
                        p1.y++;
                    } else {
                        d += incremento_leste_2;
                        p1.y++;
                    }

                    Cores cor = inter_cores(cor1, cor2, dx);
                    cor1.red += cor.red;
                    cor1.blue += cor.blue;
                    cor1.green += cor.green;
                    cor1.alpha += cor.alpha;

                    PutPixel(p1, cor1);
                }
                
            }
            
        }

        PutPixel(p2, cor2);

    }

}

void DrawTriangle(Pontos p1, Pontos p2, Pontos p3, Cores c1, Cores c2, Cores c3){
    DrawLine(p1, p2, c1, c2);
    DrawLine(p2, p3, c2, c3);
    DrawLine(p3, p1, c3, c1);
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

    Pontos p1 = {290, 150};
    Cores c1 = {64,224,208,255};

    Pontos p2 = {190, 100};
    Cores c2 = {144, 238, 144, 0};

    DrawLine(p1, p2, c1, c2);

    Pontos p3 = {75, 250};
    Cores c3 = {218, 165, 32, 0};

    Pontos p4 = {275, 120};
    Cores c4 = {128, 0, 128, 0};

    DrawLine(p3, p4, c3, c4);

    // Exemplo para a função DrawTriangle()
    /*
    Pontos p1 = {50, 200};
    Cores c1 = {47, 79, 0, 0};

    Pontos p2 = {80, 160};
    Cores c2 = {0, 255, 127, 255};

    Pontos p3 = {150, 250};
    Cores c3 = {46, 0, 87, 0};

    DrawTriangle(p1, p2, p3, c1, c2, c3);   
    */
}
