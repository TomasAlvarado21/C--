import math

a = int(input())
contador = 0

for i in range(1, math.isqrt(a) + 1):
    if a % i == 0:
        contador += 2
        if i * i == a:
            contador -= 1

print(contador)