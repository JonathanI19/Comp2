'''
Lab 01

Performs the following tasks:
1. Read a list of integers from a text file
2. Print the average value, accurate to two decimal places
3. Print the square root of the product of the largest two values (non-duplicates), accurate to two decimal places

@Author: Jonathan Isely
@Contact: tuf91237@temple.edu
@Date: 9/3/2023

Example:
    This file can be run by typing
    $ python lab_01.py
'''

import sys
import math

def main(argv):

    # don't mess with this part
    filename = "/data/courses/ece_3822/current/lab_01/data.txt"
    if len(argv) > 1:
        filename = argv[1]

    # This is some demo code to show you how to read an integer out of a text
    # file. There are other ways to do this and those are fine too if you prefer
    x = []
    with open(filename) as f:
        for line in f:
            x.append(int(line))
    f.close()

    # Calling functions to get results
    arr_length=len(x)
    avg = findAvg(x, arr_length)
    max1,max2 = findMax2(x)
    product = max1*max2
    
    # Determine if root will be complex
    if (product >= 0):
        i = False
    else:
        product = product * -1
        i = True
    
    # Calculate root of positive product
    root = math.sqrt(product)
    
    dispResults(avg, root, i)
    
def findAvg(x, arr_length):
    ''' Calculates the average of an array of numbers
    
    Args:
        x (numeric list): list of numbers
    Returns:
        numeric: the average of x
    '''

    arr_sum=sum(x)
    return(arr_sum/arr_length)
        
def findMax2(x):
    """find 2 largest non-duplicate numbers in list

    Args:
        x (numeric list): list of numbers

    Returns:
        numeric tuple: largest 2 numbers in list
    """

    # Sort list in descending order
    x.sort(reverse=True)

    max1 = x[0]

    val=1
    while(True):
        max2 = x[val]
        if max1 == max2:
            val += 1
        else:
            return max1, max2

def dispResults(avg, root, i):
    """Displays results to two decimal places

    Args:
        avg (numeric): Average value
        root (numeric): Root of product of two largest (non-duplicates) values
        i (boolean): True if root was complex
    """    
    
    # Determine if root is complex and adjust formatting
    if i == True:
        str = "Avg: {0:.2f}\nRoot: {1:.2f}i"
    else:
        str = "Avg: {0:.2f}\nRoot: {1:.2f}"

    # Print w/Formatting    
    print(str.format(avg, root))

if __name__=="__main__":
    main(sys.argv)