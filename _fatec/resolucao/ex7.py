
class FilaComPrioridade:
    def __init__(self):
        self.nome = []
        self.idade = []
        self.prioridade = []
        self.indiceElementoPrioritario = 0
    def enqueue(self, nome, idade, prioridade):
        self.nome.append(nome)
        self.idade.append(idade)
        self.prioridade.append(prioridade)
    def getFirstOcorrencia(self, prioridade):
        return self.prioridade.index(prioridade, 0)
    def setFirstOcorrencia(self, indiceEncontrado):
        self.indiceElementoPrioritario = indiceEncontrado
    def dequeue(self):
        i = self.indiceElementoPrioritario
        return [self.nome.pop(i), self.idade.pop(i), self.prioridade.pop(i)]
    def isEmpty(self):
        return self.nome == []
    def size(self):
        return len(self.nome)
    def peek(self):
        return [ self.nome[len(self.nome) - 1] , self.idade[len(self.idade) - 1], self.prioridade[len(self.prioridade) - 1]] 
    def exibir(self):
        if self.isEmpty():
            print("Não há o que exibir. Adicione algo primeiro.")
            return
        for i in range(0, int(len(self.nome))):
            print(f"Nome: {self.nome[i]} | Idade: {self.idade[i]} | Prioridade: {self.prioridade[i]}")
            


    
fila = FilaComPrioridade()

print()
print("Exibindo a lista de pacientes: ")
print()
fila.exibir()
print()

res = True
while(res == True):
    print()
    print("insira alguém na fila: ")
    nome = input("Nome: ")
    idade = int(input("Idade: "))

    if(idade >= 60):
        prioridade = 1
    elif (idade > 50):
        prioridade = 2
    else:
        prioridade = 3
    
    fila.enqueue(nome, idade, prioridade)
    print()
    print(f"Adicionado: {fila.peek()}")
    print()

    opc = input("deseja continuar? (s/n)")
    if(opc == 's'):
        res = True
    elif (opc == 'n'):
        res = False

print()
print("Exibindo a lista de pacientes: ")
print()
fila.exibir()
print()


nivelPrioridade = 1
pimeiroIndiceEncontrado = ''
while (nivelPrioridade < 4):
    print()
    if nivelPrioridade in fila.prioridade:
        pimeiroIndiceEncontrado = fila.getFirstOcorrencia(nivelPrioridade)
        fila.setFirstOcorrencia(pimeiroIndiceEncontrado)
        itemExcluido = fila.dequeue()
        print(f"Item excluido com sucesso!")
        print(f"Nome: {itemExcluido[0]} - Idade {itemExcluido[1]} - prioridade {itemExcluido[2]}")
        print()
        nivelPrioridade = 1
    else:
        nivelPrioridade = nivelPrioridade + 1

print()
print("Exibindo a lista de pacientes: ")
print()
fila.exibir()
print()
