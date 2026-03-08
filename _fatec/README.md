# Resolução exercícios

Esta pasta contém a resolução dos exercícios propostos em sala na matéria de Estrutura de Dados, todos implementados em python.

## Enunciados

1. Crie uma lista heterogênea em Python com pelo menos 5 elementos de tipos diferentes (int, float, string, bool). Em seguida:

(a) Imprima o tipo de cada elemento usando type()

(b) Acesse e imprima o primeiro e o último elemento pelo índice

(c) Altere o segundo elemento para o valor 99

(d) Exclua o terceiro elemento usando del

(e) Imprima a lista final

- [arquivo](./resolucao/ex1.py)

---

2. Crie 2 listas — uma com 5 nomes (João, Maria, Kleber, Caio, Sarah) e outra com 5 saldos em reais (2350.20, 540.50, 300.00, 830.15, 150.00). Usando laços de repetição, imprima os dados no formato: 

LISTA DE CLIENTES - BANCO XXXXXXXX NOME      SALDO nome0     saldo0 ... 

- [arquivo](./resolucao/ex2.py)

---

3. Usando uma classe (com métodos push, pop, peek, isEmpty, size), implemente o um gerenciador de pilha de tarefas. As tarefas são strings. O menu deve oferecer: 

Opção 1: Inserir tarefa na pilha 

Opção 2: Obter a próxima tarefa da pilha 

Opção 3: Sair 

- [arquivo](./resolucao/ex3.py)

---

4. Usando uma classe (com métodos enqueue, dequeue, isEmpty, size), implemente uma fila de contatos para call center. O menu deve oferecer: 

Opção 1: Inserir Contato (solicitar nome e telefone) 

Opção 2: Chamar próximo contato (dequeue e exibir dados) 

Opção 3: Sair 

- [arquivo](./resolucao/ex4.py)

---

5. Dada a lista L = [1, 3, 5, 9, 11, 13, 15, 17, 19, 21, 23] do documento, escreva um programa que demonstre todas as operações de fatiamento apresentadas: 

(a) Os 3 primeiros elementos — L[0:3] 

(b) Do índice 4 ao 9 — L[4:10] 

(c) Os 5 primeiros — L[:5] 

(d) Do índice 5 em diante — L[5:] 

(e) De 3 em 3, do índice 0 ao 8 — L[0:8:3] 

(f) De 4 em 4, do início ao fim — L[::4] 

- [arquivo](./resolucao/ex5.py)

---
6. Implemente em Python uma classe ListaEncadeada. A implementação deve conter: 

Classe Node com campos dado e proximo 

Referências inicio_lista e fim_lista 

Métodos: adicionar(dado), remover_inicio(), exibir(), esta_vazia() 

Demonstre com uma lista de contatos (nome, telefone): adicione 3 contatos, exiba, remova o primeiro e exiba novamente. 

- [arquivo](./resolucao/ex6.py)

> Aqui a dificuldade começou a elevar o nivel

---
7. Implemente em Python uma Fila de Prioridades. Cada item possui uma prioridade inteira (menor número = maior prioridade). Métodos obrigatórios: enqueue (item, prioridade), dequeue(), exibir(), isEmpty(). 

Demonstre com uma fila de atendimento médico: pacientes com prioridades 1 (urgente), 2 (moderado) e 3 (normal), chamando-os em ordem de prioridade. 

- [arquivo](./resolucao/ex7.py)

---
8. Usando uma classe, implemente um verificador de expressões com parênteses balanceados. O programa deve receber uma expressão matemática como string e verificar se os parênteses estão corretamente balanceados. Teste com pelo menos 4 expressões diferentes e explique o algoritmo com comentários. 

- [arquivo](./resolucao/ex8.py)

---
9. Implemente em Python uma Lista Duplamente Encadeada (campos: dado, proximo, anterior). A classe deve conter: 

Node com dado, proximo e anterior 

Métodos: adicionar_fim(), adicionar_inicio(), remover_fim(), remover_inicio(), exibir_frente_para_tras(), exibir_tras_para_frente(), tamanho() 

Demonstre com uma agenda de contatos (nome, telefone, email) realizando todas as operações. 

- [arquivo](./resolucao/ex9.py)
> Após resolver o ex. 6, esse daqui bastou adaptar alguns pontos para inserir a lógica do segundo ponteiro.

---

10. Implemente em Python um sistema integrado que combine as três estruturas do documento para simular um gerenciamento de pedidos de restaurante: 

FILA → pedidos chegam em ordem de chegada (FIFO) 

PILHA → pedidos prontos aguardam entrega (LIFO) 

LISTA Python → histórico completo com timestamp 

Menu: 1) Novo pedido | 2) Cozinhar próximo | 3) Entregar pedido pronto | 4) Ver histórico | 5) Ver status atual | 6) Sair 

- [arquivo](./resolucao/ex10.py)

> No meu entendimento, os pedidos para entrega deveriam ser uma fila também pois precisam ser entregues primeiro por conta do tempo de espera e de o pedido não esfriar. Mas creio que consegui ajustar conforme solicitado ao contexto.
