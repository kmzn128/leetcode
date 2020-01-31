s = "PAYPALISHIRING"
numRows = 4
n = len(s)
col_size = n//(numRows-1)+1
M = [[" " for _ in range(col_size)] for _ in range(numRows)]
for i, c in enumerate(s):
    d = i // (numRows-1)
    m = i % (numRows-1)
    row = col = 0
    if(d % 2 == 0):
        row = m
        col = d
    elif(d % 2 == 1 and m == 0):
        row = numRows-1
        col = d-1
    else:
        row = numRows-1-m
        col = d
    M[row][col] = c
print("".join("".join(M[i]).replace(" ","") for i in range(numRows)))
    
        