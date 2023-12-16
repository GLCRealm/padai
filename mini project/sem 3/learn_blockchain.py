import hashlib

class supercoin:

    def __init__(self, previous_block_hash, transtion):
        self.previous_block_hash=previous_block_hash
        self.transtion=transtion
        self.block_data="\n".join(transtion)+"\n"+previous_block_hash
        self.block_hash=hashlib.sha256(self.block_data.encode()).hexdigest()

t1 = "ansh sends 2 SC to akash"
t2 = "hritvik sends  SC to shilpa"
t3 = "shilpa sends 4.5 SC to akash"
t4 = "aarnav sends 0.2 SC to ansh"
t5 = "ansh sends 34 SC to shivam"

initial_block = supercoin("initilise string",[t1,t2])

print(initial_block.block_data)
print(initial_block.block_hash)