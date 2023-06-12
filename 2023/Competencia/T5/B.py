# Leer el número de casos de prueba
t = int(input())

# Iterar sobre cada caso de prueba
for _ in range(t):
    # Leer la longitud de la permutación
    n = int(input())
    
    # Leer la permutación desordenada
    permutation = list(map(int, input().split()))
    
    # Encontrar el máximo valor de k que permite ordenar la permutación
    max_k = 0
    i = n - 1
    while i > 0 and permutation[i - 1] < permutation[i]:
        i -= 1
    j = i
    while j > 0 and permutation[j - 1] > permutation[j]:
        j -= 1

    max_k = max(max_k, i - j + 2)
    
    # Imprimir el resultado para el caso de prueba actual
    print(max_k)
