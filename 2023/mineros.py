# La primera línea contiene un solo entero t entre 1 y 10, el número de casos de prueba.
#La primera líneas de cada caso contiene un solo entero n (1≤n≤105) — el número de mineros y diamantes.
#Cada una de las siguientes n líneas contiene 2 enteros separados por un espacio x (−108≤x≤108) e y (−108≤y≤108), que representan el punto (x,y) y describen la posición de un minero o un diamante.
#Es garantizado que no hay dos mineros o dos diamantes en la misma posición.
#La suma de n sobre todos los casos no excede 105.
#Salida
#Para cada caso, imprime un solo número real — la mínima suma de las energías que pueden gastar los mineros.
#Tu respuesta estará correcta si su error absoluto o relativo no excede 10−9.


import math

def calcular_energia_minima(mineros, diamantes):
    n = len(mineros)
    suma = 0.0
    for i in range(n):
        minero = mineros[i]
        diamante = diamantes[i]
        x_minero = minero[0]
        y_minero = minero[1]
        x_diamante = diamante[0]
        y_diamante = diamante[1]
        distancia = math.sqrt((x_minero - x_diamante)**2 + (y_minero - y_diamante)**2)
        suma += distancia

    return suma

t = int(input())

for _ in range(t):
    n = int(input())
    mineros = []
    diamantes = []

    for _ in range(n):
        x_minero, y_minero = map(int, input().split())
        mineros.append((x_minero, y_minero))

    for _ in range(n):
        x_diamante, y_diamante = map(int, input().split())
        diamantes.append((x_diamante, y_diamante))

    energia_minima = calcular_energia_minima(mineros, diamantes)
    print(energia_minima)
t = int(input())

for _ in range(t):
    n = int(input())
    mineros = []
    diamantes = []

    for _ in range(n):
        x_minero, y_minero = map(int, input().split())
        mineros.append((x_minero, y_minero))

    for _ in range(n):
        x_diamante, y_diamante = map(int, input().split())
        diamantes.append((x_diamante, y_diamante))


pares_optimos = encontrar_pares_optimos(mineros, diamantes)
suma = 0.0
for p1, p2 in pares_optimos:
    suma =+ calcular_distancia(p1, p2)

print(suma)