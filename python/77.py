def nCk(n, k, v):
    ans = []
    if(k == 1):
        for e in v:
            ans.append([e])
        return ans
    else:
        top = v.pop(0)
        vv = nCk(n-1, k-1, v)
        for e in vv:
            ans.append([top]+e)
        return ans


n = 6
k = 3
v = [i for i in range(1, n+1)]
print(nCk(n, k, v))