# Atividade Prática 3 - Implementação do Pipeline Gráfico

Disciplina: GDSCO0051 - Introdução à Computação Gráfica - 2020.1 <br />
Professor: Christian Azambuja Pagot

Aluna: Rebeca Andrade Medeiros <br />
Matrícula: 11500782

## Sumário

1. [Introdução](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#introdu%C3%A7%C3%A3o)
2. [Desenvolvimento](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#desenvolvimento) <br />
   * [Exercício 1](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-1-escala)<br />
   * [Exercício 2](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-2-transla%C3%A7%C3%A3o) <br />
   * [Exercício 3](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-3-proje%C3%A7%C3%A3o-perspectiva) <br />
   * [Exercício 4](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-4-posi%C3%A7%C3%A3o-da-c%C3%A2mera)<br />
   * [Exercício 5](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-5-transforma%C3%A7%C3%B5es-livres)<br />
3. [Resultados](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#resultados)
4. [Referências](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#refer%C3%AAncias)

## Introdução
Esta atividade é a terceira atividade prática para a disciplina de Introdução á Computação Gráfica. O objetivo da atividade é a implementação das transformações geométricas que compõem o pipeline gráfico. Como foi descrito pelo professor a implementação ocorre com auxílio da bibiloteca **glm** e a execução ocorre nos *shaders* do OpenGL.

A atividade consiste em modificar no programa template (fornecido pelo professor) as matrizes MModel, MView e MProjection para gerar as imagens presentes na documentação da atividade. 

## Desenvolvimento
O sistema operional utilizado para atividade foi o Linux Ubuntu 18.04 LTS.

O primeiro passo para o desenvolvimento da atividade foi o *download* do código fornecido pelo professor e a instalação das dependências. O código foi compilado utilizando o **MakeFile** disponibilizado, com o comando: 

```
$ make
```
Alguns *warnings* apareceram na tela durante a compilação, mesmo assim o código compilou sem problemas. A primeira dificuldade apareceu durante a execução, com a janela de exibição abrindo e fechando rapidamente sem exibir as imagens esperadas. Observando as mensagens de erro foi observado que o erro era relacionado ao GLSL, com o comando abaixo [1] foi possível executar o código, porém não é a melhor solução já que a cada execução o comando deve ser usado.

```
$ export MESA_GL_VERSION_OVERRIDE=3.3
```
A figura abaixo mostra o resultado da execução:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img1.png" /> <br />
  Figura 1 - Janela exibida durante a execução.
</p>

#### Pipeline Gráfico


### Exercício 1: Escala
O primeiro exercício é uma modificação na matriz Model para mudar a escala dos dois triângulos. Com os fatores de escala: (x,y,z) = (1/3, 3/2, 1) a matriz ficou da seguinte forma:

```
float model_array[16] = {0.33f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 1.5f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         0.0f, 0.0f, 0.0f, 1.0f};
```
O resultado foi o seguinte:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img2.png" /> <br />
  Figura 2 - Resultado da mudança de escala.
</p>

### Exercício 2: Translação
O segundo exercício é uma modificação na matriz Model para realizar uma translação. Os fatores para a transformação foram os seguintes: (x, y, z) = (1, 0, 0). A matriz ficou da seguinte forma: 

```
float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 1.0f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         1.0f, 0.0f, 0.0f, 1.0f};
```
O resultado foi o seguinte:
<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img3.png" /> <br />
  Figura 3 - Resultado da translação.
</p>

### Exercício 3: Projeção Perspectiva
O terceiro exercício é uma modificação na matriz de Projeção. Com o parâmetro d = 1/2. A matrix ficou da seguinte forma:

```
float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                        0.0f, 1.0f, 0.0f, 0.0f, 
                        0.0f, 0.0f, 1.0f, -2.0f, 
                        0.0f, 0.0f, 0.5f, 1.0f};
```
O resultado foi o seguinte:
<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img4.png" /> <br />
  Figura 4 - Resultado da modificação.
</p>

### Exercício 4: Posição da Câmera
Para o quarto exercício a matrix View será modificada para obtenção do resultado presente na Figura (8) do documento desta atividade. Para isso, a matriz de Projeção utilizada será a do Exercício (3). Os parâmetros informados são os seguintes:

- Posição da câmera = (-1/10, 1/10, 1/4)
- Vetor UP da câmera = (0, 1, 0)
- Ponto para o qual a câmera está apontando = (0, 0 , 0)

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img5.png" /> <br />
  Figura 5 - Resultado da nova matrix View.
</p>



### Exercício 5: Transformações Livres


## Resultados
Foi possível chegar em todos os exercícios aos resultados presentes na documentação da atividade. Houve um pouco de dificuldade no ínicio para entender a organização das matrizes no **glm** e as funções utilizadas.

O exercício 4 apresentou a maior dificuldade, com o auxílio da documentação sobre as funções do **glm** foi possível entender como os vetores e matrizes poderiam ser criados. O resultado das primeiras execuções deste exercício apresentaram resultados diferentes da Figura [8] presente na documentação. Primeiro apareceu apenas uma linha azul inclinada, depois os dois triângulos apareceram de ponta-cobiça. Isto aconteceu por conta de erros nos valores dos vetores e falta da normalização de Xcam, Ycam e Zcam. 

## Referências
1 - [Erro GLSL](https://stackoverflow.com/questions/52592309/0110-error-glsl-3-30-is-not-supported-ubuntu-18-04-c) <br />
2 - [OpenGL Mathematics (GLM)](http://www.c-jump.com/bcc/common/Talk3/Math/GLM/GLM.html) <br />
3 - [Funções Geométricas](https://glm.g-truc.net/0.9.4/api/a00131.html#ga68b931c228750eeba844c273c54ca43d) <br />
