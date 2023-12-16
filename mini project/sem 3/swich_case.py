def menu_option_1():
    print("You selected Option 1.")

def menu_option_2():
    print("You selected Option 2.")

def menu_option_3():
    print("You selected Option 3.")

def menu_option_default():
    print("Invalid selection. Please choose a valid option.")

# Define a dictionary mapping menu options to functions
menu_options = {
    1: menu_option_1,
    2: menu_option_2,
    3: menu_option_3,
}

while True:
    print("Menu:")
    print("1. Option 1")
    print("2. Option 2")
    print("3. Option 3")
    print("0. Exit")

    choice = input("Enter your choice: ")

    if choice.isdigit():
        choice = int(choice)

        # Check if the choice is a valid option
        if choice in menu_options:
            # Call the function associated with the chosen option
            menu_options[choice]()
        elif choice == 0:
            print("Exiting the program.")
            break
        else:
            menu_option_default()
    else:
        menu_option_default()