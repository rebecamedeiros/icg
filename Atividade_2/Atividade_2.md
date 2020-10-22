# Atividade Prática 2 - Rasterizando linhas

Disciplina: GDSCO0051 - Introdução à Computação Gráfica - 2020.1 <br />
Professor: Christian Azambuja Pagot

Aluna: Rebeca Andrade Medeiros <br />
Matrícula: 11500782

## Sumário

1. [Introdução](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#introdu%C3%A7%C3%A3o)
2. [Desenvolvimento](https://github.com/rebecamedeiros/icg/blob/main/Atividade_2/Atividade_2.md#desenvolvimento)
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

Para esta primeira função o objetivo é rasterizar um ponto na memória de vídeo, recebendo como parâmetros: as coordenadas e as cores. Para descrever os pixels e cores foram utilizadas *structs*. A função fica da seguinte forma:

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
<p>
<img src="https://raw.githubusercontent.com/rebecamedeiros/icg/main/Atividade_2/Figuras/figura1.png" /> <br /> </p>

**Figura 1 - Ponto obtido com a função**.

## Resultados


## Referências
1.[Cores](https://celke.com.br/artigo/tabela-de-cores-html-nome-hexadecimal-rgb)
