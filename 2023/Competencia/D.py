n = int(input())
for i in range(n):
    mymax = 0
    largo = input()
    mystrig=input()
    left_map = {}
    right_map = {}
    for c in mystrig:
        if c in right_map:
            right_map[c] += 1
        else:
            right_map[c] = 1
    
    for c in mystrig:
        right_map[c] -= 1
        if c in left_map:
            left_map[c] += 1
        else:
            left_map[c] = 1
        if right_map[c] == 0:
            del right_map[c]
        if mymax < len(left_map) + len(right_map):
            mymax = len(left_map) + len(right_map)
            
    print(mymax)