class ContarParenteses: # inicializa a estrutura com 3 variaveis internas para o calculo
    def __init__(self):
        self.aberto = 0
        self.fechado = 0
        self.abertoEFechado = 0
    def reiniciarEstrutura(self):
        self.aberto = 0
        self.fechado = 0
        self.abertoEFechado = 0
    def converterParaLista(self, string): # transforma a string em uma lista para facilitar a contagem
        return list(string)
    def somarAberto(self, numero): # funções auxiliares para somar o valor das variaveis
        self.aberto = self.aberto + numero
        return self.aberto
    def somarFechado(self, numero):
        self.fechado = self.fechado + numero
        return self.fechado
    def somarAbertoEFechado(self, numero):
        self.abertoEFechado = self.abertoEFechado + numero
        return self.abertoEFechado
    def subtrairAberto(self, numero): # funções auxiliares para subtrair o valor das variaveis
        self.aberto = self.aberto - numero
        return self.aberto
    def subtrairFechado(self, numero):
        self.fechado = self.fechado - numero
        return self.fechado
    def subtrairAbertoEFechado(self, numero):
        self.abertoEFechado = self.abertoEFechado - numero
        return self.abertoEFechado
    def verResultadoSoma(self): # função auxiliar para ver o valor de cada variavel interna da estrutura
        return [self.aberto, self.fechado, self.abertoEFechado]

def procuraESomaParenteses():
    # para cada posição da lista verifica se tem abertura ou fechamento de parenteses
    # se tiver, chama o respectivo metodo da estrutura para somar a variavel interna
    for item in string_original:
        if (item == '('):
            estrutura.somarAberto(1)
        elif (item == ')'):
            estrutura.somarFechado(1)
        else: # pula posições que não são parenteses
            continue

def verificaSeExisteBalanceamento():        
    # no meu entender, o balancear do enunciado se refere a saber se tem abertura e fechamento na string, independente da distancia
    # ex: )(()(( ->  abre 4 e fecha 2 -> portanto, 2 balanceados, pois abre e fecha, e apenas 2 que abre restantes
    # então esse laço verifica isso e ajusta as variaveis caso encontre
    aberto = estrutura.aberto
    fechado = estrutura.fechado
    while (aberto >= 1 and fechado >= 1):
        aberto = estrutura.subtrairAberto(1)
        fechado = estrutura.subtrairFechado(1)
        estrutura.somarAbertoEFechado(1)

def printarBalanceamento():
    # printa o resultado
    res = estrutura.verResultadoSoma() 
    print()
    print(f"aberto: {res[0]} - fechado: {res[1]} aberto e fechado (balanceado): {res[2]}")
    print()

estrutura = ContarParenteses()

# variaveis auxiliares
aberto = ''
fechado = ''
 
string_original = '(((((-))asdasd)(4(4(dd(a))' # 9-5-0 - aberto, fechado, abertoEFechado, respectivamente
string_original = estrutura.converterParaLista(string_original)

# funções
procuraESomaParenteses()


print(" ============================ PRIMEIRA VEZ ============================ ")

verificaSeExisteBalanceamento()
printarBalanceamento() # 4 - 0 - 5  - aberto, fechado, abertoEFechado, respectivamente



# zera os valores internos da estrutura para novos testes
estrutura.reiniciarEstrutura()
aberto = ''
fechado = ''


string_original = '(##2(((-)asdasd))3)t)a))4-(dda))' # 5-9-0  - aberto, fechado, abertoEFechado, respectivamente
string_original = estrutura.converterParaLista(string_original)


procuraESomaParenteses()

print(" ============================ SEGUNDA VEZ ============================ ")

verificaSeExisteBalanceamento()
printarBalanceamento() #  0 - 4 - 5 - aberto, fechado, abertoEFechado, respectivamente

# zera os valores internos da estrutura para novos testes
estrutura.reiniciarEstrutura()
aberto = ''
fechado = ''


string_original = ')2))4)#(((-)a5d)()(()4-(dda))' # 10-7-0 - aberto, fechado, abertoEFechado, respectivamente
string_original = estrutura.converterParaLista(string_original)

# funções
procuraESomaParenteses()

print(" ============================ TERCEIRA VEZ ============================ ")

verificaSeExisteBalanceamento()
printarBalanceamento() # 0 - 3 - 7 - aberto, fechado, abertoEFechado, respectivamente

