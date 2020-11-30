# Atividade Prática 3 - Implementação do Pipeline Gráfico

Disciplina: GDSCO0051 - Introdução à Computação Gráfica - 2020.1 <br />
Professor: Christian Azambuja Pagot

Aluna: Rebeca Andrade Medeiros <br />
Matrícula: 11500782

## Sumário

1. [Introdução](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#introdu%C3%A7%C3%A3o)
2. [Desenvolvimento](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#desenvolvimento) <br />
   * [Exercício 1](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-1)<br />
   * [Exercício 2](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-2) <br />
   * [Exercício 3](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-3) <br />
   * [Exercício 4](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-4)<br />
   * [Exercício 5](https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Atividade_3.md#exerc%C3%ADcio-5)<br />
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
Alguns *warnings* apareceram na tela durante a compilação, mesmo assim o código compilou sem problemas. A primeira dificuldade apareceu durante a execução, com a janela de exibição abrindo e fechando rapidamente sem exibir as imagens esperadas. Observando as mensagens de erro foi observado que o erro era relacionado ao GLSL, com o comando abaixo foi possível executar o código, porém não é a melhor solução já que a cada execução o comando deve ser usado.

```
$ export MESA_GL_VERSION_OVERRIDE=3.3
```
A figura abaixo mostra o resultado da execução:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img1.png" /> <br />
  Figura 1 - Janela exibida durante a execução.
</p>

#### Pipeline Gráfico


### Exercício 1
O primeiro exercício é uma modificação na matriz Model para mudar a escala dos dois triângulos. Com os fatores de escala: (x,y,z) = (1/3, 3/2, 1) a matriz ficou da seguinte forma:

```
float model_array[16] = {0.333f, 0.0f, 0.0f, 0.0f, 
                         0.0f, 1.5f, 0.0f, 0.0f, 
                         0.0f, 0.0f, 1.0f, 0.0f, 
                         0.0f, 0.0f, 0.0f, 1.0f};
```

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_3/Figuras/img2.png" /> <br />
  Figura 2 - Resultado da mudança de escala.
</p>

### Exercício 2 

### Exercício 3 

### Exercício 4

### Exercício 5


## Resultados

## Referências
