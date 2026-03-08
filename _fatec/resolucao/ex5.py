umaLista = [1, 3, 5, 9, 11, 13, 15, 17, 19, 21, 23]

for item in umaLista:
    print( f"Elemento: {item} | Indice: {umaLista.index(item)} " )

print()
print(f"Três primeiros elementos: {umaLista[0:3]}") 
print(f'Do indice 4 até o nono elemento (10° indice - 1) : {umaLista[4:10]}') 
print(f'Cinco primeiros elementos: {umaLista[:5]}') 
print(f'Do 5° indice em diante: {umaLista[5:]}') 
print(f'Do incice 0 ao 8, saltando de 3 em 3: {umaLista[0:8:3]}') 
print(f'Toda lista, saltando de 4 em 4: {umaLista[::4]}') 
print()
