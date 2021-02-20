import hashlib

def mine(prefix,target):
    i = 0
    while True:
        cur = prefix + str(i)
        cur = cur.encode("ascii")
        m = hashlib.md5(cur)
        if m.hexdigest().startswith('0'*target):
            print(m.hexdigest())
            return i
        i += 1

print(mine('yzbqklnj',5))
