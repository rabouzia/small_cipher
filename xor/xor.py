mes = "Hello !"
key = "xor"

mes_len = len(mes)
key_len = len(key)

def xoring(message, key):
        key = key * (mes_len // key_len) + key[:mes_len % key_len]

        result= ''.join(chr(ord(m) ^ ord(k)) for m, k in zip(message, key))
        return result


print("[",mes, "]")
xor = xoring(mes, key)
unxor = xoring(xor, key)
print("\n\n")

print("[",xor, "]")
print("[",unxor, "]")



