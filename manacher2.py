s = 'abaaababb'
n = len(s)
R = [0 for _ in range(n)]
i = j = k = 0
for i in range(n):
    l = k - (i - k)
    if(i + R[l] < k + R[k]):
        R[i] = R[l]
    else:
        j = k + R[k] - i
        while(i-j >= 0 and i+j < n and s[i-j] == s[i+j]):
            j += 1
        R[i] = j
        k = i
print(R)