myticket = [157,101,107,179,181,163,191,109,97,103,89,113,167,127,151,53,83,61,59,173]
output = [16,3,11,17,4,5]
ans = 1
for i in output:
    print(i)
    ans *= myticket[int(i)]
print(ans)