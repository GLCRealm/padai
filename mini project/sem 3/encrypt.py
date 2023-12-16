import encrypt

random_number = secrets.randbelow(134)
print(random_number)

random_bits = secrets.randbits(64)
print(random_bits)

random_bytes = secrets.token_bytes(8)
print(random_bytes)

random_hex = secrets.token_hex(10)
print(random_hex)

random_urlsafe = secrets.token_urlsafe(12)
print(random_urlsafe)