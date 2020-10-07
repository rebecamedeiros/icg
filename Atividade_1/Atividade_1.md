# Atividade Prática 1 - Compilando e executando um programa OpenGL moderno

Disciplina: GDSCO0051 - Introdução à Computação Gráfica - 2020.1 <br />
Professor: Christian Azambuja Pagot

Aluna: Rebeca Andrade Medeiros <br />
Matrícula: 11500782

## Sumário

1. [Introdução](https://github.com/rebecamedeiros/icg/blob/main/Atividade_1/Atividade_1.md#introdu%C3%A7%C3%A3o)
2. [Desenvolvimento](https://github.com/rebecamedeiros/icg/blob/main/Atividade_1/Atividade_1.md#desenvolvimento)
3. [Resultados](https://github.com/rebecamedeiros/icg/blob/main/Atividade_1/Atividade_1.md#resultados)
4. [Referências](https://github.com/rebecamedeiros/icg/blob/main/Atividade_1/Atividade_1.md#refer%C3%AAncias-bibliogr%C3%A1ficas)

## Introdução

Esta atividade é a primeira entre as atividades práticas para a disciplina de Introdução à Computação Gráfica. <br />

O objetivo é verificar a configuração correta do ambiente OpenGL 3.3, compilando e executando o programa disponível no reposítório da disciplina. <br />

## Desenvolvimento 

O sistema operacional utilizado para este trabalho foi o Linux Ubuntu 18.04. O primeiro passo para o desenvolvimento foi buscar como realizar a instalação do OpenGL 3.3 no sistema. <br/>

Depois que um tutorial foi encontrado e a instalação feita o próximo passo foi realizar o download do programa no repositório da disciplina. <br />

Durante a compilação alguns *warnings* apareceram. Os comandos para compilação e execução foram:

```
make
./moderngl_hello_world 
```

## Resultados

A figura abaixo apresenta o resultado obtido com a primeira execução:

<p align="center">
  <img src="https://raw.githubusercontent.com/rebecamedeiros/icg/main/Atividade_1/Figuras/figura1.png" /> <br />
  Figura 1 - Primeiro resultado.
</p>

Este triângulo branco é diferente do que era esperado, verificando algumas das mensagens do terminal foi possível perceber que a versão 3.3 do OpenGL não estava sendo suportada. A solução foi usar:
```
export MESA_GL_VERSION_OVERRIDE=3.3
```
O resultado de uma nova execução foi:

<p align="center">
  <img src="https://github.com/rebecamedeiros/icg/blob/main/Atividade_1/Figuras/figura2.png?raw=true" /> <br />
  Figura 2 - Triângulo colorido.
</p>

Apesar da solução ter funcionado o comando precisa ser executado cada vez que o terminal for fechado e aberto novamente, uma solução melhor seria algo mais definito para que assim sempre fosse obtido o triângulo da figura 2. 

## Referências bibliográficas
1. How to Install OpenGL on Ubuntu Linux. Disponível em: <http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/>.
