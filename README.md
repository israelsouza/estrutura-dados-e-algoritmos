Notas e sequência das aulas de [estrutura de dados](https://www.youtube.com/playlist?list=PLxI8Can9yAHf8k8LrUePyj0y3lLpigGcl)

Funções de gerenciamento (para quase todas as estruturas de dados)

- Inicializar a estrutura
- Retornar a quantidade de elementos válidos
- Exibir os elementos da estrutura
- Buscar por um elemento na estrutura
- Inserir elementos na estrutura
- Excluir elementos na estrutura
- Reinicializar a estrutura

---

## Indice

01 - Apresentação da disciplina

- [file](test.c)

02 - Criação de uma primeira estrutura

- comparação entre Java e C
  - modelar, instanciar, acessar, uso de memoria
- ponteiro e alocação de memoria

- [file](./primeira-estrutura.c)
- [file](./ponteiros.c)
- [file](./alocacao-memoria.c)
- [file](./primeira-estrutura-com-alocacao-memoria.c)

03 - Lista linear sequencial
lista linear: estrutura de dados com cada elemento tendo anterior e sucessor (exceto 1o e ultimo); elementos possuem uma dada sequencia (inclusão, ordenados...)

lista linear sequencial: lista linear cuja ordem logica vista pelo usuário (4, 8, 9,1) é a mesma ordem física, em memória (ou seja, se excluir o 8, não ficará espaço em branco/inválido, os após são movidos para preencher essa lacuna, o mesmo deve ser feito no código)

modelagem:

- usa um arranjo de registros
- registros possuem dados relevantes ao usuário
- arranjo possui tamanho fixo

![IMG01](./attach/image-pilha.png)

enquanto a primeira `cria uma cópia de uma lista` a segunda `faz referencia a lista definida` exibindo na img o endereço na memória na qual a lista esta sendo salva

- [file](./lista-linear-sequencial.c)

04 - Lista linear sequencial (continuação)

o que é visto?
- otimização da busca sequencial (busca com elemento sentinela)
- inserir elemento ordenado
- busca binaria

- [file](./lista-linear-continuacao.c)

05 - Lista ligada (implementação estática)

- [file](./lista-ligada.c)

06 - Lista ligada (implementação dinâmica)

Dinamico aqui significa qu pPara cada elemento que vai ser criado é alocado um espaço na memoria para armazena-lo (diferente de antes, onde o limite era estático) e quando se exclui a memoria é liberada.

- [file](./lista-ligada-dinamica.c)

07 - Lista ligada circular com nó cabeça

- [file](./lista-ligada-no-cabeca.c)

08 - Pilha (implementação estática)

Estrutura linear onde elementos a serem inseridos e excluidos sempre ficam no topo

- [file](./pilha-estatica.c)

09 - Pilha (implementação dinâmica)

Testei fazer diferente, após o prof falar o método, primeiro tentei implementar sem o vídeo. Consegui, pegar a lógica com mais facilidade pegando exemplo da [lista ligada dinâmica](./lista-ligada-dinamica.c) e adaptando para a pilha. O ultimo, depois de tentativas primeiro, consegui implementar com sucesso!!!

- [file](./pilha-dinamica.c)

10 - Deque

Espécie de fila com duas extremidades. Exemplos de uso:
- Histórico de navegador web
  - quando limite é atingido, a ponta antiga começa a 'deletar' registros e a ponta nova inclui os novos registros
- Agendamento de tarefas por prioridades
  - se for prioridade, vai pro inicio da fila, se não vai pro final
  - (pensei agr: no MC, checa se a pessoa é um diretor ou associado, se for é dado prioridade para essas pessoas, se não, vai pro fim da fila mesmo (só pensei, não acho que seja real))

- [file](./deque.c)


11 - Fila (imp. estática)

Assim como uma fila de mercado, banco... . Exemplos de casos de uso: 
- Saúde
- Alimentação
- Gov

- [file](./fila.c)

12 - Fila (imp. dinâmica)

- [file](./fila-dinamica.c)

13 - Pilha dupla

Feita para um problema mais específico, quando há um total fixo (30 alunos) mas precisam ser agrupados em sub grupos (aprovados e reprovados).

Feito assim para manter contexto e gerenciamento único. Cada topo cresce em direção a seu oposto.

Cenarios de caso de uso:
- Em um condomio, onde há numero total de casas, mas é preciso saber quais pagaram e quais não pagaram no mês recorrente.
- Em uma equipe, onde há um número total de integrantes, mas é preciso saber quais fizeram horas extras e quais não fizeram.

![IMG02](image-pilha-pilha.png)

- [file](./pilha-dupla.c)

14 - Matriz esparsa

Utilizada quando maior parte elementos tem valor padrão, e só alguns tem valores diferentes. Portanto, por so alocar memoria para esses valores diferentes do padrão, torna a estrutura eficiente em gasto de memoria e processamento.

Possivel usar para representar grafos (aula mais adiante).

Casos de uso:
- Imagem em preto e branco
- PLN
- Machine Learning
- Sistema de recomendação

![IMG03](./attach/image-matriz.png)

- [file](./matriz-esparsa.c)

