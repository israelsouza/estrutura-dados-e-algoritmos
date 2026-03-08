umaLista = [ 7789, 123, 3.22, 'ola, mundo', True]

for item in umaLista:
    print( f"Elemento: {item} | Tipo: {type(item)} " )
    
print()
print("primeiro elemento: ", umaLista[0], ". Ultimo elemento: ", umaLista[-1])
print()

umaLista[1] = 99
del umaLista[2]

for item in umaLista:
    print( f"Elemento: {item} | Tipo: {type(item)} " )

print()
