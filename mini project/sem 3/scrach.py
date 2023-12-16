import hashlib
import random
import string
import date



class block:
    def __init__(self,U_ID,index,previous_hash,data_name,data_car_number,data_DS_detail,data_DOP,data_licence_no,data_DOB,data_DOR,data_add,current_hash):
        self.index=index
        self.previous_hash=previous_hash
        self.data_name = data_name
        self.data_car_number=data_car_number
        self.data_DS_detail=data_DS_detail
        self.data_DOP=data_DOP
        self.data_licence_no=data_licence_no
        self.data_DOB=data_DOB
        self.data_DOR=data_DOR
        self.data_add=data_add
        self.current_hash = current_hash
        self.U_ID=U_ID

def calculate_hash(U_ID,index,previous_hash,data_name,data_car_number,data_DS_detail,data_DOP,data_licence_no,data_DOB,data_DOR,data_add):
    value=str(U_ID)+str(index)+str(previous_hash)+str(data_name)+str(data_car_number)+str(data_DS_detail)+str(data_DOP)+str(data_licence_no)+str(data_DOB)+str(data_DOR)+str(data_add)
    return hashlib.sha256(value.encode()).hexdigest()

def create_first_block():
    return block(0,0,"NULL","this is a empty block","NULL","NULL","NULL","NULL","NULL","NULL","NULL",calculate_hash(0,0,"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"))

def create_main_block(U_ID,previous_block,data_name,data_car_number,data_DS_detail,data_DOP,data_licence_no,data_DOB,data_DOR,data_add):
    index=previous_block.index+1
    current_hash=calculate_hash(U_ID,index,previous_block.current_hash,data_name,data_car_number,data_DS_detail,data_DOP,data_licence_no,data_DOB,data_DOR,data_add)
    return block(U_ID,index,previous_block.current_hash,data_name,data_car_number,data_DS_detail,data_DOP,data_licence_no,data_DOB,data_DOR,data_add,current_hash)

def print_data(blockchain):
    for block in blockchain:
        print(f"UNIQUE ID: {block.U_ID}")
        print("\n")
        print(f"INDEX: {block.index}")
        print(f"PREVIOUS HASH: {block.previous_hash}")
        print(f"CURRENT HASH: {block.current_hash}")
        print("\n\n")
        print(f"NAME: {block.data_name}")
        print(f"CAR NUMBER: {block.data_car_number}")
        print(f"DETAIL OF DELEARSHIP: {block.data_DS_detail}")
        print(f"DATE OF PURCHASE: {block.data_DOP}")
        print(f"LICENCE NUMBER: {block.data_licence_no}")
        print(f"DATE OF BIRTH: {block.data_DOB}")
        print(f"DATE OF REGISTRATION: {block.data_DOR}")
        print(f"ADDRESS: {block.data_add}")
        print("\n"+"-"*40+"\n")

blockchain=[create_first_block()]






block1_data_name="ANSHDEEP RAWAT"
block1_data_car_number="UK 07 AF 5612"
block1_data_DS_detail="Honda delelarship of dehradun"
block1_data_DOP="27 JAN 2015"
block1_data_licence_no="DER23AU5"
block1_data_DOB="24 JAN 2004"
block1_data_DOR="27 JAN 2015"
block1_data_add="house no 9, pream pur maffi, kaulagarh, dehradun"
block1_U_ID=''.join([random.choice(string.ascii_letters + string.digits) for n in range(16)])

block1=create_main_block(block1_U_ID,blockchain[-1],block1_data_name,block1_data_car_number,block1_data_DS_detail,block1_data_DOP,block1_data_licence_no,block1_data_DOB,block1_data_DOR,block1_data_add)
blockchain.append(block1)




block2_data_name="AKASH BHATT"
block2_data_car_number="UK 17 TF 5782"
block2_data_DS_detail="Honda delelarship of roorkee"
block2_data_DOP="17 AUG 2018"
block2_data_licence_no="DKJ78F5"
block2_data_DOB="17 APR 2004"
block2_data_DOR="17 AUG 2018"
block2_data_add="53 A Ashok nagar post office milap nagar,roorkee"
block2_U_ID=''.join([random.choice(string.ascii_letters + string.digits) for n in range(16)])

block2=create_main_block(block2_U_ID,blockchain[-1],block2_data_name,block2_data_car_number,block2_data_DS_detail,block2_data_DOP,block2_data_licence_no,block2_data_DOB,block2_data_DOR,block2_data_add)
blockchain.append(block2)




block3_data_name="AKASH BHATT"
block3_data_car_number="UK 17 TF 5782"
block3_data_DS_detail="Honda delelarship of roorkee"
block3_data_DOP="17 AUG 2018"
block3_data_licence_no="DKJ78F5"
block3_data_DOB="17 APR 2004"
block3_data_DOR="17 AUG 2018"
block3_data_add="53 A Ashok nagar post office milap nagar,roorkee"
block3_U_ID=''.join([random.choice(string.ascii_letters + string.digits) for n in range(16)])

block3=create_main_block(block3_U_ID,blockchain[-1],block3_data_name,block3_data_car_number,block3_data_DS_detail,block3_data_DOP,block3_data_licence_no,block3_data_DOB,block3_data_DOR,block3_data_add)
blockchain.append(block3)
print_data(blockchain)