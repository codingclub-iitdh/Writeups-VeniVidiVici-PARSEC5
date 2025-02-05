from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

def lcg(seed, a, c, m, count):
    values = []
    for _ in range(count):
        seed = (a * seed + c) % m
        values.append(seed)
    return values
# Params recieved from wireshark DNS tunnel 
current_time = 1737505180
a = 1103515245
c = 12345
m = 2**31

keys = lcg(current_time, a, c, m, 10)
decryption_key = keys[-1].to_bytes(16, 'big')  

print("Generated Decryption Key:", decryption_key.hex())

received_hex = "ced1a50b083a02b15caa632a8039799e4e9071779c60f5ab2f7afed590d1b828eede677610fb17009955094d5032e64e6195d8a2b93536cff75ba2c9dec33328"
encrypted_data = bytes.fromhex(received_hex)

# Extract IV and ciphertext
iv = encrypted_data[:16]  # First 16 bytes is IV
ciphertext = encrypted_data[16:]  # Remaining bytes are ciphertext

print("Extracted IV:", iv.hex())
print("Extracted Ciphertext:", ciphertext.hex())

def decrypt_message(iv, ciphertext, key):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted = cipher.decrypt(ciphertext)
    return unpad(decrypted, AES.block_size)

# Decrypt
try:
    decrypted_message = decrypt_message(iv, ciphertext, decryption_key)
    print("Decrypted Message:", decrypted_message.decode())
except Exception as e:
    print("[ERROR] Decryption failed:", e)