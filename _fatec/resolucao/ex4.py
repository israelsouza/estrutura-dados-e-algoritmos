
class Queue:
    def __init__(self):
        self.nome = []
        self.numero = []
    def enqueue(self, nome, numero):
        self.nome.insert(0, nome)
        self.numero.insert(0, numero)
    def dequeue(self):
        return [self.nome.pop(), self.numero.pop()]
    def isEmpty(self):
        return self.nome == [] 
    def size(self):
        return len(self.nome)
    
    def peek(self):
        return [ self.nome[len(self.nome) - 1] , self.numero[len(self.numero) - 1]] 
    
fila = Queue()
res = True

print()
print(fila.isEmpty())
print()


while(res == True):
    print("================== DIGITE A OPÇÃO DESEJADA ==================")
    print("1. Inserir Contato (nome e telefone)")
    print("2. Chamar próximo contato")
    print("3. Sair")
    opcao = int(input())
    
    if(opcao == 1):
        print("Digite o nome do contato que deseja inserir")
        nome = input()

        print("Digite o numero do ", nome)
        numero = int(input())

        fila.enqueue(nome, numero)

        print("Contato salvo!")
        print(f"Você possui {fila.size()} contatos")
        print()

    elif (opcao == 2):
        
        if fila.size() > 0:
            ultimoContato = fila.dequeue()
            print("contato ", ultimoContato[0], " atendido com sucesso!")
            print()

            if fila.size() > 1:
                proximoContato = fila.peek()
                print("O proximo contato da fila de ligações é: ")
                print("NOME: ", proximoContato[0] , "-- NUMERO: ", proximoContato[1])
            print()
        else:
            print("Não há mais contatos para ligar!")
            print()


    elif ( opcao == 3 ):
        print("Entendido, saindo do programa...")
        res = False
    else:
        print("Opção inválida, insira uma opção válida (1 - 2 - 3)")

print()
print(fila.isEmpty())
print()
