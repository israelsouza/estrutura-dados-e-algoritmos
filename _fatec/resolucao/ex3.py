class Stack:
    def __init__(self):
        self.items = []
    def push(self, item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def peek(self):
        return self.items[len(self.items) - 1]
    def isEmpty(self):
        return self.items == []
    def size(self):
        return len(self.items)

pilha = Stack()
res = True

print()
print(pilha.isEmpty())
print()

while(res == True):
    print("================== DIGITE A OPÇÃO DESEJADA ==================")
    print("1. Inserir tarefa na pilha")
    print("2. Obter a próxima tarefa da pilha")
    print("3. Sair")
    opcao = int(input())
    
    if(opcao == 1):
        print("Digite a tarefa que deseja inserir")
        tarefa = input()
        pilha.push(tarefa)
        print("A quantidade de tarefas é: ", pilha.size())
        print()
    elif (opcao == 2):
        if(pilha.size() < 2):
            print("Tamanho insuficiente, adicione mais itens primeiro!")
        else:
            ultimoItem = pilha.pop()
            print( "Tarefa ", ultimoItem, " concluida!!!" )
            print ("A proxima tarefa é: ", pilha.peek())
            print()
    elif ( opcao == 3 ):
        print("Entendido, saindo do programa...")
        res = False
    else:
        print("Opção inválida, insira uma opção válida (1 - 2 - 3)")

print()
print(pilha.isEmpty())
print()
