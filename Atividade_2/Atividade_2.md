# Atividade Prática 2 - Rasterizando linhas

Disciplina: GDSCO0051 - Introdução à Computação Gráfica - 2020.1 <br />
Professor: Christian Azambuja Pagot

Aluna: Rebeca Andrade Medeiros <br />
Matrícula: 11500782

**Atualizado em: 09 de Dezembro de 2020** <br />
Atualizações: adicionada função DrawLine() e DrawTriangle().


## Sumário

1. [Introdução](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#introdu%C3%A7%C3%A3o)
2. [Desenvolvimento](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#desenvolvimento)
    * [PutPixel()](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#putpixel)
    * [DrawLine()](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#drawline)
    * [DrawTriangle()](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#drawtriangle)
3. [Resultados](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#resultados)
4. [Referências](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#refer%C3%AAncias)

## Introdução

Esta atividade é a segunda atividade prática para a disciplina de Introdução à Computação Gráfica. O objetivo é a implementação de algoritmos para rasterização de pontos e linhas. E atráves dessas implementações realizar o desenho de um triângulo.

Como foi visto durante as aulas o sistema operacional não permite o acesso direto a memória de vídeo. Assim, para realização da atividade foi utilizado um *framework* fornecido pelo professor. Entre os arquivos do *framework* os únicos modificados foram: *mygl.h* e *mygl.c*.

## Desenvolvimento

Para esta atividades três funções foram desenvolvidas: PutPixel(), DrawLine() e DrawTriangle.

O sistema operacional utilizado foi: Linux Ubuntu 18.04 LTS.

### PutPixel()

Pixels são os menores elementos de um frame, cada pixel possui uma coordenada e três componentes de cores: vermelho(R), verde(G) e azul(B). E um canal Alpha(A) que não interfere com a cor.

Para esta primeira função o objetivo é rasterizar um ponto na memória de vídeo, recebendo como parâmetros: as coordenadas e as cores. Para descrever os pixels e cores foram utilizadas *structs*. Seguindo um dos exemplos apresentados na especificação do trabalho, a função ficou da seguinte forma:

```
void PutPixel(Pontos p, Cores cor){
    
    int j = (IMAGE_WIDTH * p.y + p.x) * 4;
    fb_ptr[j]     = cor.red;
    fb_ptr[j + 1] = cor.green;
    fb_ptr[j + 2] = cor.blue;
    fb_ptr[j + 3] = cor.alpha;
}
```
A figura abaixo apresenta o resultado:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Figuras/figura1.png" /> <br />
  Figura 1 - Ponto exibido durante a execução.
</p>

### DrawLine()

Para esta função o esperado é que recebendo como parâmetro as coordenadas dos vértices iniciais e final. Para o desenvolvimento desta função foi usado o **Algoritmo do Ponto Médio**, este algoritmo foi estudado em aula e foi visto que para atuar além do primeiro octante algumas modificações deveriam ser feitas. O algoritmo permite que após a realização de alguns cálculos o próximo ponto escolhido seja o mais próximo do atual. 

A função ficou definida com os seguintes parâmetros:

```
void DrawLine(Pontos p1, Pontos p2, Cores cor1, Cores cor2)
```
Os valores para os vértices e cores foram definidos dentro da função **MyGlDraw()**. A execução da função gerou as retas que aparecem abaixo:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Figuras/figura2.png" /> <br />
  Figura 2 - Janela exibida durante a execução.
</p>


### DrawTriangle()

Esta função deve receber as posições de três vértices para realizar o desenho de um triângulo na tela. Os valores dos vértices e cores foram estabelidos dentro da função **MyGlDraw()**. A função **DrawTriangle** ficou da seguinte forma:

```
void DrawTriangle(Pontos p1, Pontos p2, Pontos p3, Cores c1, Cores c2, Cores c3){
    DrawLine(p1, p2, c1, c2);
    DrawLine(p2, p3, c2, c3);
    DrawLine(p3, p1, c3, c1);
}
```
Com a execução o resultado foi o seguinte:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Figuras/figura3.png" /> <br />
  Figura 3 - Resultado exibido na janela.
</p>

Como é possível obsevar o resultado não foi o esperado, pois não foi possível formar o triângulo.

## Resultados

A primeira função apresentou a solução mais rápida, com o resultado esperado. As dificuldades surgiram durante o desenvolvimento da função DrawLine(), com a implementação do Algoritmo do Ponto Médio. A função não apresentou o resultado correto durante os testes, por exemplo, ao colocar para desenhar duas retas apenas uma reta aparecia com erros de coordenadas e de tamanho, no lugar de uma segunda reta aparecia apenas um pixel.

**Resultados da atualização de 09/12/2020** <br />
A função **DrawLine()** foi implementada e apresentou o resultado esperado, com duas linhas exibidas na janela. A função **DrawTriangle()** apresentou um resultado errado, pois não formou o triângulo e este erro deve ter acontecido por algo na função **DrawLine()**.

## Referências
1. [Cores](https://celke.com.br/artigo/tabela-de-cores-html-nome-hexadecimal-rgb)
2. Aulas da disciplina de Introdução à Computação Gráfica
