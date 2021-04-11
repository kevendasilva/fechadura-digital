# **Fechadura Digital**

Projeto Final da Disciplina de Sistemas Microprocessados - TI0144.

### **Equipe**
Antonio Felype Ferreira Maciel - 472118
Keven da Silva Gonçalves - 473982
Vitor Mateus Costa Alves - 470879

## Sobre
Esse projeto trata-se de uma fechadura com senha. Ao digitar a senha correta no teclado numérico, a porta é destrancada.

## Introdução
A segurança é um dos assuntos de destaque de nosso dia a dia, geralmente de forma negativa. Assim, visando desenvolver um elemento que fosse capaz de aumentar a segurança do lar, surgiu a ideia da Fechadura Digital. O projeto trata-se de uma tranca que só é liberada após a inserção da senha correta, definida pelo usuário.

## Objetivos
- Destrancar uma porta ao ser inserida uma senha correta;
- Permitir que o usuário troque a senha do dispositivo;
- Permitir que o usuário cheque o registro do sistema, acessando informações de uso do dispositivo.

## Desenvolvimento
Devido às adversidades da pandemia e da distância entre os componentes da equipe, o projeto foi totalmente desenvolvido de forma virtual. O código do programa foi escrito no STM32CubeIDE e a montagem dos componentes foi realizada no Proteus.
Para a interação entre o sistema e o usuário, foi utilizado um teclado matricial, que serve para navegar entre as funcionalidades oferecidas e digitar a senha. Um LCD 20x4 (LM044L) serviu para exibir as informações necessárias para o usuário. Já para simbolizar o atuador do projetos, LEDs foram usados.

## Conclusão

## **Lista de componentes**

1 x STM32F103C6 Série ARM Cortex M3 Núcleo LQFP-48  
1 x St-link V2 Stm8&Stm32  
n x Jumpers/Fios  
3 x Led (Azul, Verde, Vermelho)  
3 x Resistor 330 Ohm 1/16W 5%  
1 x Display LCD 20x4 LM044L  
1 x Teclado de membrana matricial 4x4  
1 x Fonte de alimentação  

Componentes do simulador (exclusivos do ambiente virtual):

1 x Terminal virtual

### Apresentação do projeto no YouTube: 


## Arquivos

* [Divisão do trabalho](Divisão%20do%20trabalho/divisao.txt)
* [Projeto Proteus](https://github.com/kevensilvag/fechadura_digital-sm/tree/main/Projeto%20Proteus)
* [Projeto STM32CubeIDE](https://github.com/kevensilvag/fechadura_digital-sm/tree/main/Projeto%20STM32CubeIDE/fechadura%20-%20funcional%20-%20menu)
* [Proposta](https://github.com/kevensilvag/fechadura_digital-sm/tree/main/Proposta)
* [Diagrama de blocos](diagrama.jpg)


## **Referências**

https://www.theengineeringprojects.com/2013/05/how-to-use-virtual-terminal-in-proteus.html
https://github.com/delpitec/STM32


