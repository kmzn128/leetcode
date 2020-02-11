def nCk(n, k, v, cur, elem, ans):
    if(len(elem) == k):
        ans.append(elem.copy())
    else:
        for i in range(cur, n):
             elem.append(v[i])
             nCk(n, k, v, i+1, elem, ans)
             elem.pop()
             



n = 6
k = 3
v = [i for i in range(1, n+1)]
elem = []
ans = []
nCk(n, k, v, 0, elem, ans)
print(ans)