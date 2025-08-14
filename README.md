⚓ Batalha Naval – Versão Avançada com Habilidades Especiais
📌 Descrição

Este projeto é a etapa final da evolução do jogo Batalha Naval em C.
Agora, além do posicionamento de navios horizontais, verticais e diagonais, adicionamos habilidades especiais com áreas de efeito distintas (Cone, Cruz e Octaedro), que podem ser aplicadas em qualquer posição do tabuleiro.

🎯 Objetivos

Criar um tabuleiro 10x10 com navios já posicionados.

Criar três matrizes de habilidades (Cone, Cruz e Octaedro).

Sobrepor essas habilidades ao tabuleiro, sem apagar navios.

Representar:

Água → 0

Navio → 3

Área de habilidade → 5

🛠️ Tecnologias utilizadas

C (ANSI C)

Matrizes bidimensionais

Estruturas de repetição aninhadas

Condicionais para validação de limites e formas

Distância de Manhattan para formar o Octaedro

📂 Estrutura do Código

Inicialização

Função inicializarTabuleiro() preenche tudo com 0 (água).

Posicionamento de navios

Função posicionarNavio() insere navios horizontais, verticais ou diagonais.

Construção das habilidades

criarCone() → Forma de cone apontando para baixo.

criarCruz() → Forma de cruz com centro no meio.

criarOctaedro() → Forma de losango (vista frontal de um octaedro).

Aplicação no tabuleiro

aplicarHabilidade() sobrepõe a matriz da habilidade no ponto central especificado.

Exibição final

Função exibirTabuleiro() mostra o resultado com números (0, 3, 5).