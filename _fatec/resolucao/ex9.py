
class Node:
    def __init__(self, dado):
        self.dado = dado
        self.anterior = None
        self.proximo = None

class ListaDuplamenteEncadeada:
    def __init__(self):
        self.inicio_lista = None
        self.fim_lista = None
    def esta_vazia(self):
        return self.inicio_lista is None
    def adicionar_fim(self, dado):
        novo_no = Node(dado)
        if self.esta_vazia():
            self.inicio_lista = novo_no
            self.fim_lista = novo_no
        else:
            novo_no.anterior = self.fim_lista # type: ignore
            self.fim_lista.proximo = novo_no # type: ignore
            self.fim_lista = novo_no
    def adicionar_inicio(self, dado):
        novo_no = Node(dado)
        if self.esta_vazia():
            self.inicio_lista = novo_no
            self.fim_lista = novo_no
        else:
            novo_no.proximo = self.inicio_lista # type: ignore
            self.inicio_lista.anterior = novo_no # type: ignore
            self.inicio_lista = novo_no
    def remover_inicio(self):
        if self.esta_vazia():
            print("A lista já esta vazia")
            return
        self.inicio_lista = self.inicio_lista.proximo # type: ignore
        if self.inicio_lista is not None:
            self.inicio_lista.anterior = None
        else: 
            self.fim_lista = None
    def remover_final(self):
        if self.esta_vazia():
            print("A lista já esta vazia")
            return
        self.fim_lista = self.fim_lista.anterior # type: ignore
        if self.fim_lista is not None:
            self.fim_lista.proximo = None
        else: 
            self.inicio_lista = None
    def exibir_inicioParaFim(self):
        if self.esta_vazia():
            print("A lista esta vazia, não há o que exibir")
            return
        atual = self.inicio_lista
        while atual:
            c = atual.dado
            print(f"Nome: {c['nome']} | Telefone: {c['telefone']} | E-mail: {c['email']}")
            atual = atual.proximo
        print(f'=='*30)   
    def exibir_fimParaInicio(self):
        if self.esta_vazia():
            print("A lista esta vazia, não há o que exibir")
            return
        atual = self.fim_lista
        while atual:
            c = atual.dado
            print(f"Nome: {c['nome']} | Telefone: {c['telefone']} | E-mail: {c['email']}")
            atual = atual.anterior
        print(f'=='*30)
    def tamanho(self):
        if self.esta_vazia():
            print("A lista esta vazia, não há o que contar")
            return
        atual = self.inicio_lista
        contador = 0
        while atual:
            contador = contador + 1
            atual = atual.proximo
        print(f"A Lista possui {contador} elementos.")   


lista = ListaDuplamenteEncadeada()

lista.tamanho()

lista.adicionar_inicio({"nome": "Ana", "telefone": "111", "email": "ana@email.com"})
lista.adicionar_fim({"nome": "Carla Soares", "telefone": "444", "email": "carla.soares@email.com"})
lista.adicionar_inicio({"nome": "Bruno", "telefone": "222", "email": "bruno@email.com"})
lista.adicionar_inicio({"nome": "Carla", "telefone": "333", "email": "carla@email.com"})

print()
lista.tamanho()
print()

lista.exibir_inicioParaFim()
print()
print()
lista.exibir_fimParaInicio()

lista.remover_final()

print()
lista.tamanho()
print()

lista.remover_inicio()

print()
lista.tamanho()
print()

lista.exibir_inicioParaFim()