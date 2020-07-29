m=[(a,b,c) for a in range(1,30) for b in range(a,30) for c in range(b,30) if a**2 + b**2 == c**2]
print(m)
