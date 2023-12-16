import hashlib
import time

class block:
    def __init__(self,index,previous_hash,timestamp,data,current_hash):
        self.index=index
        self.previous_hash=previous_hash
        self.timestamp=timestamp
        self.data=data
        self.current_hash=current_hash

def calculate_hash(index,previous_hash,timestamp,data):
    value= str(index)+str(previous_hash)+str(timestamp)+str(data)
    return hashlib.sha256(value.encode()).hexdigest()

def create_genesis_block():
    return block(0,"0",time.time(),"genesis block",calculate_hash(0,"0",time.time(),"genesis block"))

def create_new_block(previous_block,data):
    index=previous_block.index+1
    timestamp=time.time()
    current_hash=calculate_hash(index,previous_block.current_hash,timestamp,data)
    return block(index,previous_block.current_hash,timestamp,data,current_hash)

def print_block(blockchain):
    for block in blockchain:
        print(f"INDEX: {block.index}")
        print(f"PREVIOUS HASH: {block.previous_hash}")
        print(f"TIMESTRAMP: {block.timestamp}")
        print(f"DATA: {block.data}")
        print(f"CURRENT HASH: {block.current_hash}")
        print("\n"+"-"*30+"\n")

blockchain=[create_genesis_block()]

block1_data="teansaction data 1"
block1 = create_new_block(blockchain[-1],block1_data)
blockchain.append(block1)

block2_data="teansaction data 2"
block2 = create_new_block(blockchain[-1],block2_data)
blockchain.append(block2)

print_block(blockchain)
