import hashlib
import random
import string
import date


class block:
    def __init__(self, U_ID, index, previous_hash, data_name, data_car_number, data_DS_detail, data_DOP, data_licence_no, data_DOB, data_DOR, data_add, current_hash):
        self.index = index
        self.previous_hash = previous_hash
        self.data_name = data_name
        self.data_car_number = data_car_number
        self.data_DS_detail = data_DS_detail
        self.data_DOP = data_DOP
        self.data_licence_no = data_licence_no
        self.data_DOB = data_DOB
        self.data_DOR = data_DOR
        self.data_add = data_add
        self.current_hash = current_hash
        self.U_ID=U_ID

def calculate_hash(U_ID,index,previous_hash,data_name,data_car_number,data_DS_detail,data_DOP,data_licence_no,data_DOB,data_DOR,data_add):
    value=str(U_ID)+str(index)+str(previous_hash)+str(data_name)+str(data_car_number)+str(data_DS_detail)+str(data_DOP)+str(data_licence_no)+str(data_DOB)+str(data_DOR)+str(data_add)
    return hashlib.sha256(value.encode()).hexdigest()

def create_first_block():
    return block(0, 0, "NULL", "this is a empty block", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", calculate_hash(0, 0, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"))

def create_main_block(U_ID, previous_block, data_name, data_car_number, data_DS_detail, data_DOP, data_licence_no, data_DOB, data_DOR, data_add):
    index=previous_block.index+1
    current_hash=calculate_hash(U_ID,index,previous_block.current_hash,data_name,data_car_number,data_DS_detail,data_DOP,data_licence_no,data_DOB,data_DOR,data_add)
    return block(U_ID, index, previous_block.current_hash, data_name, data_car_number, data_DS_detail, data_DOP, data_licence_no, data_DOB,data_DOR,data_add,current_hash)

def print_data(blockchain):
    for block in blockchain:
        print("\n")
        print(f"UNIQUE ID: {block.U_ID}")
        print("\n")
        print(f"INDEX: {block.index}")
        print(f"PREVIOUS HASH: {block.previous_hash}")
        print(f"CURRENT HASH: {block.current_hash}")
        print("\n\n")
        print(f"NAME: {block.data_name}")
        print(f"CAR NUMBER: {block.data_car_number}")
        print(f"DETAIL OF DELEARSHIP: {block.data_DS_detail}")
        print(f"DATE OF PURCHASE: {block.data_DOP.date()}")
        print(f"LICENCE NUMBER: {block.data_licence_no}")
        print(f"DATE OF BIRTH: {block.data_DOB.date()}")
        print(f"DATE OF REGISTRATION: {block.data_DOR.date()}")
        print(f"ADDRESS: {block.data_add}")
        print("\n"+"-"*40+"\n")

blockchain=[create_first_block()]

def add_block():
    format='%d/%m/%Y'

    block1_data_name = input("Enter the name of customer: ")

    block1_data_car_number = input("Enter th vehicle number: ")

    block1_data_DS_detail = input("Enter the detail of dealership: ")

    a = input("Enter the date of purchase(DD/MM/YYYY): ")
    block1_data_DOP = datetime.datetime.strptime(a, format)

    block1_data_licence_no = input("Enter the licence number of customer: ")

    b = input("Enter the date of birth of the customer(DD/MM/YYYY): ")
    block1_data_DOB = datetime.datetime.strptime(b, format)

    c= input("Enter the date of registration(DD/MM/YYYY): ")
    block1_data_DOR =datetime.datetime.strptime(c, format)


    block1_data_add = input("Enter the address of the customer: ")
    block1_U_ID = ''.join([random.choice(string.ascii_letters + string.digits) for n in range(10)])

    block1 = create_main_block(block1_U_ID, blockchain[-1], block1_data_name, block1_data_car_number,block1_data_DS_detail, block1_data_DOP, block1_data_licence_no, block1_data_DOB,block1_data_DOR, block1_data_add)
    blockchain.append(block1)
    print(f"YOUR DATA IS UPLOADED\nYour unique ID is: {block1_U_ID}")

def search_uid():
    unique=str(input("Enter your unique ID: "))
    flag=0
    for block in blockchain:
        if block.U_ID == unique:
            print("\n" + "-" * 40 + "\n")
            print(f"UNIQUE ID: {block.U_ID}")
            print("\n")
            print(f"INDEX: {block.index}")
            print(f"PREVIOUS HASH: {block.previous_hash}")
            print(f"CURRENT HASH: {block.current_hash}")
            print("\n\n")
            print(f"NAME: {block.data_name}")
            print(f"CAR NUMBER: {block.data_car_number}")
            print(f"DETAIL OF DELEARSHIP: {block.data_DS_detail}")
            print(f"DATE OF PURCHASE: {block.data_DOP.date()}")
            print(f"LICENCE NUMBER: {block.data_licence_no}")
            print(f"DATE OF BIRTH: {block.data_DOB.date()}")
            print(f"DATE OF REGISTRATION: {block.data_DOR.date()}")
            print(f"ADDRESS: {block.data_add}")
            print("\n" + "-" * 40 + "\n")
            flag=1
            break
    if flag == 0:
        print("invalid unique id")





#menu driven

def op1():
    add_block()

def op2():
    print("1.Print all \n2.Print data by Unique ID")
    a=int(input("ENTER YOUR CHOICE: "))

    if a == 1:
        print_data(blockchain)
    elif a == 2:
        search_uid()
    else:
        print("Invalid selection")

def op_default():
    print("Invalid selection")

options={1:op1,2:op2}

while True:
    print("1.Add a new registration\n2.Print the data\n3.EXIT")
    a=int(input("ENTER YOU YOUR OPERATION: "))

    if a in options:
        options[a]()
    elif a==3:
        print("ENDING THE PROGRAM")
        break
    else:op_default()
