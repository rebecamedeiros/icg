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
  Figura 2 - Janela exibida durante a execução.
</p>

### Pipeline Gráfico

*Pipeline Gráfico* pode ser definido com uma sequência de estágios pelas quais uma cena 3D passa ao ser renderizada em uma tela 2D. Para que a imagem passe de um estágio para o outro transformações geométricas são aplicadas, essas transformações modificam o sistema de coordenadas de um espaço para o outro. A Figura [2] mostra todos os estágios do pipeline. Cada frame a ser exibido passa por todo o pipeline.

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/pipeline_g.png" /> <br />
  Figura 2 - Etapas do pipeline gráfico.
</p>

As transformações aplicadas aos objetos presentes em cena podem ser de: **escala**, **rotação**, **translação** e **shear**. 

Como mostra a Figura [2] o espaço do objeto é o primeiro estágio do pipeline. Neste espaço acontece a modelagem dos objetos no sistema de coordenadas do espaço. A matriz de modelagem (MModel) é usada para levar os objetos para o espaço do universo, a matriz contém todas as transformações necessárias, por exemplo, transformações de escala ou rotação. A passagem entre os espaços ocorre com a multiplicação dos vértices do objeto pela matrix MModel. 

A Figura [2] mostra que saindo do espaço do objeto o próximo estágio é o espaço do universo. Neste espaço ocorre a reunião de objetos para montagem da cena. E o posicionamento da câmera, para a transformação do espaço do universo para o da câmera é usada a matriz de visualização (MView).

Quando ocorre a passagem para o espaço da câmera é necessário transformar as coordenadas do espaço do universo para o da câmera, para as novas coordenadas é preciso saber: o vetor de posição da câmera, o vetor UP que aponta para a parte de cima da câmera e o vetor de direção que é para onde a câmera aponta.

Para transformação do espaço da câmera para o de recorte é usada a matriz de projeção (MProjection). 

### Exercício 1: Escala
O primeiro exercício é uma modificação na matriz MModel para mudar a escala dos dois triângulos. A transformação de escala pode mudar o tamanho do objeto, o deixar espelhado, mudar sua direção.

A modificação da matrix foi feita com os seguintes fatores de escala: (x, y, z) = (1/3, 3/2, 1). O trecho de código abaixo mostra como ficou a matrix: 

```
float model_array[16] = {0.33f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 1.5f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         0.0f, 0.0f, 0.0f, 1.0f};
```
A Figura [3] mostra a imagem gerada:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img2.png" /> <br />
  Figura 3 - Resultado da mudança de escala.
</p>


### Exercício 2: Translação
O segundo exercício é uma modificação na matriz Model para realizar uma translação. Esta transformação movimenta os vértices do objeto somando valores as suas coordenadas. 

Os fatores para a transformação foram os seguintes: (x, y, z) = (1, 0, 0). A matriz ficou da seguinte forma: 

```
float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 1.0f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         1.0f, 0.0f, 0.0f, 1.0f};
```
O resultado foi o seguinte:
<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img3.png" /> <br />
  Figura 4 - Resultado da translação.
</p>

### Exercício 3: Projeção Perspectiva
O terceiro exercício é uma modificação na matriz de Projeção, que cria uma distorção perspectiva. É a partir do valor do parâmetro ***d*** que é a distância entre o centro de projeção e o plano de visualização que a distorção é aplicada. Dependendo do valor os objetos mais próximos do centro de projeção podem parecer maiores e os mais distantes menores.

Com o parâmetro d = 1/8. A matrix ficou da seguinte forma:
```
float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                        0.0f, 1.0f, 0.0f, 0.0f, 
                        0.0f, 0.0f, 1.0f, -8.0f, 
                        0.0f, 0.0f, 0.125f, 0.0f};
```
O resultado foi o seguinte:
<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img4.png" /> <br />
  Figura 5 - Resultado da mudança na matrix.
</p>

### Exercício 4: Posição da Câmera
Para o quarto exercício a matrix View será modificada para obtenção do resultado presente na Figura [8] do documento desta atividade. Para isso, a matriz de Projeção utilizada será a do Exercício (3). Os parâmetros informados são os seguintes:

- Posição da câmera = (-1/10, 1/10, 1/10)
- Vetor UP da câmera = (0, 1, 0)
- Ponto para o qual a câmera está apontando = (0, 0 , -1)

O primeiro passo para a resolução foi criar os vetores acima, para isso foi usada a função **vec3()** do **glm** que cria vetores com três posições. O trecho de código abaixo mostra o vetor de posição:

```
glm::vec3 posicao = glm::vec3(-0.1f, 0.1f, 0.1f);
```
Como foi visto em aula para formar a base ortonormal da câmera é preciso calcular Xcâmera, Ycâmera e Zcâmera. Assim como diz na documentação o vetor de direção da câmera foi calculado subtraindo a posição da câmera do ponto para qual está apontando. Para realizar os cálculos foram utilizadas as seguintes funções: **normalize()** e **cross()**. O código abaixo mostra como o cálculo Xcâmera foi feito:

```
glm::vec3 xcam = glm::normalize(glm::cross(up, zcam));
```
O próximo passo foi a criação da matriz B transposta, para isso seguindo a dica do professor primeiro foi criado um array de 16 floats. Esse array foi montado seguindo o que foi visto em aula:

```
float matrixB_array[16] = {xcam.x, ycam.x, zcam.x, 0.0f,
                           xcam.y, ycam.y, zcam.y, 0.0f,
                           xcam.z, ycam.z, zcam.z, 0.0f,
                           0.0f, 0.0f, 0.0f, 1.0f};
```
Em seguida foi usada a função make_mat4() para criar a matriz:

```
glm::mat4 B_matrix = glm::make_mat4(matrixB_array);
```
A matrix T foi criada de forma parecida, com um array de 16 floats e a função make_mat4():

```
float matrixT_array[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                           0.0f, 1.0f, 0.0f, 0.0f,
                           0.0f, 0.0f, 1.0f, 0.0f,
                           -posicao.x, -posicao.y, -posicao.z, 1.0f};

glm::mat4 T_matrix = glm::make_mat4(matrixT_array);
```
E a matrix de visualização foi criada calculando o produto das matrizes BT e T. A figura gerada com a matriz foi:
<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img5.png" /> <br />
  Figura 6 - Resultado da mudança na matrix.
</p>


### Exercício 5: Transformações Livres


## Resultados
Foi possível chegar em todos os exercícios aos resultados presentes na documentação da atividade. Houve um pouco de dificuldade no ínicio para entender a organização das matrizes no **glm** e as funções utilizadas.

O exercício 4 apresentou a maior dificuldade, com o auxílio da documentação sobre as funções do **glm** foi possível entender como os vetores e matrizes poderiam ser criados. O resultado das primeiras execuções deste exercício apresentaram resultados diferentes da Figura [8] presente na documentação. Primeiro apareceu apenas uma linha azul inclinada, depois os dois triângulos apareceram de ponta-cobiça. Isto aconteceu por conta de erros nos valores dos vetores e falta da normalização de Xcam, Ycam e Zcam. 

## Referências
1 - [Erro GLSL](https://stackoverflow.com/questions/52592309/0110-error-glsl-3-30-is-not-supported-ubuntu-18-04-c) <br />
2 - [OpenGL Mathematics (GLM)](http://www.c-jump.com/bcc/common/Talk3/Math/GLM/GLM.html) <br />
3 - [Funções Geométricas](https://glm.g-truc.net/0.9.4/api/a00131.html) <br />
4 - [Matrizes](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/#the-projection-matrix) <br />
