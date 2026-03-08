class Node:
    def __init__(self, dado):
        self.dado = dado
        self.proximo = None

class ListaEncadeada:
    def __init__(self):
        self.inicio_lista = None
        self.fim_lista = None
    def esta_vazia(self):
        return self.inicio_lista is None
    def adicionar(self, dado):
        novo_no = Node(dado)
        if self.esta_vazia():
            self.inicio_lista = novo_no
            self.fim_lista = novo_no
        else:
            self.fim_lista.proximo = novo_no # type: ignore
            self.fim_lista = novo_no
    def remover_inicio(self):
        if self.esta_vazia():
            print("A lista já esta vazia")
            return
        self.inicio_lista = self.inicio_lista.proximo # type: ignore

        if self.inicio_lista is None:
            self.fim_lista = None
    def exibir(self):
        if self.esta_vazia():
            print("A lista esta vazia, não há o que exibir")
            return
        atual = self.inicio_lista
        while atual:
            c = atual.dado
            print(f"Nome: {c['nome']} | Telefone: {c['telefone']}")
            atual = atual.proximo
        print(f'=='*30)

lista_contatos_simples = ListaEncadeada()

lista_contatos_simples.exibir()
lista_contatos_simples.remover_inicio()

print()

lista_contatos_simples.adicionar({'nome': 'joao', 'telefone': '1234'})
lista_contatos_simples.adicionar({'nome': 'mariana', 'telefone': '5678'})
lista_contatos_simples.adicionar({'nome': 'neusa', 'telefone': '1234-1234'})
lista_contatos_simples.adicionar({'nome': 'pedro', 'telefone': '1234-5678'})
lista_contatos_simples.adicionar({'nome': 'lucas', 'telefone': '5678-1234'})

lista_contatos_simples.exibir()
print()
lista_contatos_simples.remover_inicio()
print()
lista_contatos_simples.exibir()
