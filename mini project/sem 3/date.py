import date

# datetime in string format for may 25 1999

a = input("enter the date: ")
format = '%d/%m/%Y'

# convert from string format to datetime format
b = datetime.datetime.strptime(a, format)

# get the date from the datetime using date()
#