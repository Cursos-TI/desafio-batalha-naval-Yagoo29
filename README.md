🛳️ Batalha Naval – Posicionando Navios
📌 Descrição

Este projeto é a primeira etapa da construção de um jogo de Batalha Naval em C.
O objetivo deste nível é criar um tabuleiro 10x10 e posicionar dois navios de tamanho fixo (3 posições cada), um na horizontal e outro na vertical, sem sobreposição e dentro dos limites.

🎯 Objetivos

Representar o tabuleiro com uma matriz bidimensional (10x10).

Inicializar todas as posições com o valor 0 (água).

Posicionar:

Navio horizontal (valor 3) em coordenadas fixas.

Navio vertical (valor 3) em coordenadas fixas.

Validar:

Que o navio cabe no tabuleiro.

Que não há sobreposição de navios.

Exibir o tabuleiro no console.

🛠️ Tecnologias utilizadas

Linguagem: C

Estruturas utilizadas:

Matrizes (int tabuleiro[10][10])

Loops for aninhados

Constantes com #define

Validações condicionais com if

📂 Estrutura do Código

Definição de constantes

TAM_TABULEIRO → tamanho do tabuleiro (10)

TAM_NAVIO → tamanho fixo dos navios (3)

AGUA e NAVIO → valores que representam água (0) e navio (3)

Inicialização do tabuleiro

Preenche toda a matriz com 0 (água).

Posicionamento dos navios

Coordenadas iniciais fixas definidas no código.

Validação de limites e sobreposição.

Marcação das posições com 3.

Exibição no console

Impressão formatada da matriz.