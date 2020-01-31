s = 'abaaababb'
n = len(s)
R = [0 for _ in range(n)]
i = j = k = 0
while(i < n):
    while(i-j >= 0 and i+j < n and s[i-j] == s[i+j]):
        j += 1
    R[i] = j
    k = 1
    while(i-k >= 0 and i+k < n):
        x = k + R[i-k]
        if(x < j):
            R[i+k] = R[i-k]
            k += 1
        else:
            break
    i += k
    j -= k
print(R)