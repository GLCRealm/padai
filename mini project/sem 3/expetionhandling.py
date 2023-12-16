import logging

def fx():
    a = int(input("enter the number: "))
    print(100 / a)

try:
    fx()
except ZeroDivisionError:
    logging.error("you cannot divide with 0")
