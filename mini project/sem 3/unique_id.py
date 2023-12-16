import random
import string

U_ID = ''.join([random.choice(string.ascii_letters + string.digits) for n in range(16)])

print(U_ID)
