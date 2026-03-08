listaNomes = ["João", "Maria", "Kleber", "Caio", "Sarah"]
listaSaldos = [2350.20, 540.50, 300.00, 830.15, 150.00]

print("LISTA DE CLIENTES - BANCO XXXXXXXX")
print()
print( f"NOME         SALDO" )

for item in range(0, 5):
    print( f"{listaNomes[item]}         {listaSaldos[item]}" )

print()
