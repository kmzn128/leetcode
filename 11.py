heights = [1,1]
def solve(li):
    i = 0
    j = width = len(li)-1
    vol = 0
    while(i < j):
        if(li[i] > li[j]):
            vol = max(width * li[j], vol)
            width -= 1
            j -= 1
        elif(li[i] < li[j]):
            vol = max(width * li[i], vol)
            width -= 1
            i += 1
        elif(li[i] == li[j]):
            vol = max(width * li[i], vol)
            width -= 2
            i += 1
            j -= 1
    return vol
    
print(solve(heights))