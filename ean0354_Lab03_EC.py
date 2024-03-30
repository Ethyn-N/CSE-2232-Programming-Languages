# Name: Ethyn Nguyen
# ID: 1001930354
# Date Turned In: March 30, 2023
# OS: Linux Ubuntu 20.04.1 LTS
# Python Version: Python 3.8.10

import os

# Calculates reverse polish notation expression from the input line file
# Returns the result of the expression
# Added modulo operator
def calculate_RPN(expression):
    numbers = []
    num1 = 0
    num2 = 0
    
    # Loop through each element in a line expression
    for element in expression:
        # If element is a number, add to numbers array
        if (element not in '+-*/%'):
            numbers.append(float(element))

        # If element is an operator, remove the 2 numbers beforehand and do the operator calulations on them
        # and add the return value to numbers array
        else:
            num2 = numbers.pop()
            num1 = numbers.pop()
            
            if element == '+':
                numbers.append(num1 + num2)
            elif element == '-':
                numbers.append(num1 - num2)
            elif element == '*':
                numbers.append(num1 * num2)
            elif element == '/':
                numbers.append(num1 / num2)
            elif element == '%':
                quotient = int(num1 / num2)
                numbers.append(num1 - (num2 * quotient))

    # Return resulting number from expression
    return numbers.pop()

# Dictionary with priorities of operators
priority = {'+':1, '-':1, '*':2, '/':2, '%':2}

# Converts algebraic expression to RPN
def algebraic_to_RPN(algebraic):
    RPN = '' 
    stack = []

    # Loop through each element in a line expression
    for element in algebraic:
        # If element is a number, add to RPN array
        if element not in "(+-*/%)":
            RPN += element
        
        # If element is an operator, add operator to the stack array
        elif element in "+-*/%":
            while stack and stack[-1] != '(' and priority[element] <= priority[stack[-1]]:
                RPN += stack.pop()
            stack.append(element)
        
        elif element == '(':
            stack.append('(')
        elif element ==')':
            while stack and stack[-1] != '(':
                RPN += stack.pop()
            if stack[-1] != '(':
                print("Mismatched parentheses")
            stack.pop()
    while stack:
        RPN += stack.pop()

    return RPN

# Open input file from current working directory
file = open(os.getcwd() + "/input_RPN_EC.txt", "r")

# # Calculate each RPN expression in the input file and output the results
for line in file:
    # Split line to remove whitespace
    expression = line.split()
    result = calculate_RPN(algebraic_to_RPN(expression))
    
    # Format result to print as either an int or float
    # depending on return value
    print('%g' % result)

file.close()