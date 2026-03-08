import random
from datetime import datetime

class Queue:
    def __init__(self):
        self.nome = []
        self.endereco = []
        self.pedido = []
        self.pagamento = []
        self.valor_conta = []
    def enqueue(self, nome, endereco, pedido, pagamento, valor_conta):
        self.nome.insert(0, nome)
        self.endereco.insert(0, endereco)
        self.pedido.insert(0, pedido)
        self.pagamento.insert(0, pagamento)
        self.valor_conta.insert(0, valor_conta)
    def dequeue(self):
        dados = {
            "nome": self.nome.pop(),
            "endereco": self.endereco.pop(),
            "pedido": self.pedido.pop(),
            "pagamento": self.pagamento.pop(),
            "valor_conta": self.valor_conta.pop()
        }
        return dados
    def isEmpty(self):
        return self.nome == []
    def size(self):
        return len(self.nome)
    def peek(self):
        return [ self.nome[len(self.nome) - 1] , self.endereco[len(self.endereco) - 1], self.pedido[len(self.pedido) - 1], self.pagamento[len(self.pagamento) - 1], self.valor_conta[len(self.valor_conta) - 1] ] 

class Stack:
    def __init__(self):
        self.nome = []
        self.endereco = []
        self.pedido = []
        self.pagamento = []
        self.valor_conta = []
    def push(self, nome, endereco, pedido, pagamento, valor_conta):
        self.nome.append(nome)
        self.endereco.append(endereco)
        self.pedido.append(pedido)
        self.pagamento.append(pagamento)
        self.valor_conta.append(valor_conta)
    def pop(self):
        dados = {
            "nome": self.nome.pop(),
            "endereco": self.endereco.pop(),
            "pedido": self.pedido.pop(),
            "pagamento": self.pagamento.pop(),
            "valor_conta": self.valor_conta.pop()
        }
        return dados
    def peek(self):
        return self.pedido[len(self.pedido) - 1]
    def isEmpty(self):
        return self.pedido == []
    def size(self):
        return len(self.pedido)

filaChegadaPedidos = Queue()
pedidosCozinhar = Stack()
pedidosEntregar = Stack()
historicoPedidos = []

res = True

def apresentarMenu():
    print()
    print()
    print("================== PIZZARIA IRIS ==================")
    print("Escolha a opção desejada")
    print("1. Novo pedido") 
    print("2. Cozinhar próximo")
    print("3. Entregar pedido pronto")
    print("4. Ver histórico")
    print("5. Ver status atual")
    print("6. Sair")
    print("====================================================")
    print()

def realizarNovoPedido():
    print("Insira as informações para realizar o pedido.")
    nome = input("Nome: ")
    endereco = input("Endereco: ")
    pedido = input("Pedido: ")
    pagamento = input("Pagamento (cartão, pix, dinheiro): ")

    valorDaConta = random.randint(50, 290)
    print("O valor da conta foi: ", valorDaConta)
    confirmarPedido = input("Deseja efetuar a compra? (n/s)")

    if(confirmarPedido == 'n'):
        print("Certo, pedido cancelado...")
        print("Reiniciando o programa...")
    elif (confirmarPedido == 's' ):
        filaChegadaPedidos.enqueue(nome, endereco, pedido, pagamento, valorDaConta)
        pedidoFeito = { "nome": nome, "endereco": endereco, "pedido": pedido, "pagamento": pagamento, "valorDaConta": valorDaConta, "data_hora": datetime.now(), "status": "pedido_aprovado" }
        historicoPedidos.append(pedidoFeito)
        print()
        print("Pedido realizado!")
    else:
        print("Comando não definido, reiniciando o programa...")

def cozinharPedidoFeito():
    pedido = filaChegadaPedidos.dequeue()
    print("Iniciando o preparo do pedido", pedido["pedido"], " da pessoa ", pedido["nome"])
    pedidosCozinhar.push(pedido["nome"], pedido["endereco"], pedido["pedido"], pedido['pagamento'], pedido['valor_conta'])
    preparandoPedido = { "nome": pedido["nome"], 
                   "endereco": pedido["endereco"], 
                   "pedido": pedido["pedido"], 
                   "pagamento": pedido['pagamento'], 
                   "valorDaConta": pedido['valor_conta'], 
                   "data_hora": datetime.now(), 
                   "status": "preparando" }
    historicoPedidos.append(preparandoPedido)
    
def entregarPedidoPronto():
    pedido = pedidosCozinhar.pop()
    print("O pedido", pedido["pedido"], " foi finalizado, aguardando o entregador... ")
    pedidosEntregar.push(pedido["nome"], pedido["endereco"], pedido["pedido"], pedido['pagamento'], pedido['valor_conta'])
    pedidoParaEntregar = { "nome": pedido["nome"], 
                   "endereco": pedido["endereco"], 
                   "pedido": pedido["pedido"], 
                   "pagamento": pedido['pagamento'], 
                   "valorDaConta": pedido['valor_conta'], 
                   "data_hora": datetime.now(), 
                   "status": "aguardando_entregador" }
    historicoPedidos.append(pedidoParaEntregar)

def verHistoricoCompleto():
    print(" ========= HISTÓRICO COMPLETO DE PEDIDOS ======== ")
    print()
    id = 0
    for registro in historicoPedidos:
        id = id + 1
        cliente  = registro["nome"]
        local    = registro["endereco"]
        item     = registro["pedido"]
        forma    = registro["pagamento"]
        total    = registro["valorDaConta"]
        momento  = registro["data_hora"]
        situacao = registro["status"]
        print("-" * 40)
        print(f"• Id: {id}")
        print(f"• Cliente: {cliente.title()}")
        print(f"• Pedido:  {item}")
        print(f"• Endereço: {local}")
        print(f"• Total:   R$ {total:.2f} ({forma.upper()})")
        print(f"• Horário: {momento.strftime('%d/%m/%Y | %H:%M:%S')}")
        print(f"• Status:  [{situacao.upper()}]")
        print()

def verStatusDosPedidos():
    print("1. Pedido aprovado")
    print("2. Preparando")
    print("3. Aguardando o motorista para entrega")
    print("4. Todos")
    verStatus = int(input("Qual status deseja verificar? "))

    status_alvo = ''
    match verStatus:
        case 1: status_alvo = 'pedido_aprovado'
        case 2: status_alvo = 'preparando'
        case 3: status_alvo = 'aguardando_entregador'
        case 4: status_alvo = 'todos'
        case _: 
            print("Opção inválida! Retornando ao menu inicial")
            return

    print(f"\n--- LISTANDO: {status_alvo.upper()} ---")

    for pedido in historicoPedidos:
        if status_alvo == "todos" or pedido["status"] == status_alvo:
            print(f"Cliente: {pedido['nome']} | Status: {pedido['status']} | pedido: {pedido['pedido']}")


while(res == True):
    apresentarMenu()
    opcao = int(input())

    if(opcao == 1):
        realizarNovoPedido()
    elif(opcao == 2):
        cozinharPedidoFeito()
    elif(opcao == 3):
        entregarPedidoPronto()
    elif(opcao == 4):
        verHistoricoCompleto()
    elif(opcao == 5):
        verStatusDosPedidos()
    elif ( opcao == 6 ):
        print("Entendido, saindo do programa...")
        res = False
    else:
        print("Opção inválida, insira uma opção válida (1 - 2 - 3 - 4 - 5 - 6)")

