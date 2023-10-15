''' lab_05.cpp

   YOUR NAME HERE
   YOUR EMAIL ADDRESS
   DATE
   
   BRIEF DESCRIPTION OF FILE CONTENTS

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN

instructions
    One way of determining if a tree is well balanced is to count how many of the nodes
    have zero children, one child, or two children. Well-balanced trees will have very few
    nodes with just one child. A degenerate tree will have all nodes with one child, except the
    very last node which will have zero children.

    Write the function count() which will count the occurrences of nodes with zero, one, or two
    children. You may only edit the count() function. No other edits are permissable.

    There are three test cases. The first two are simple enough that you can manually validate
    your results. The third cases reads 1000 randomly generated ints out of a file and puts them
    in the tree. My results are:

        Nodes with 0 children: 345
        Nodes with 1 children: 311
        Nodes with 2 children: 344

    Your code should return the same. Is this a well-balanced tree? If the tree was _perfectly_ balanced,
    what would the node counts be?

'''

import sys

class node:

    def __init__(self,val):
        self.payload = val
        self.left  = None
        self.right = None
    
    def set_left(self, ptr):
        self.left = ptr
    
    def set_right(self,ptr):
       self.right = ptr

    def get_val(self):      return self.payload
    def get_left(self):     return self.left
    def get_right(self):    return self.right
    

class tree:

    def __init__(self):
        self.root = None
        self.cnt_0 , self.cnt_1 , self.cnt_2 = 0 , 0 , 0
    
    def insert(self,val):
        new_node = node(val)
        curr_node = self.root

        if curr_node is None:
            self.root = new_node
            return
        
        while True:
            
            if val < curr_node.get_val():
                if curr_node.get_left() is None:
                    curr_node.set_left(new_node)
                    return
                else:
                    curr_node = curr_node.get_left()
            else:
                if curr_node.get_right() is None:
                    curr_node.set_right(new_node)
                    return
                else:
                    curr_node = curr_node.get_right()

    def count(self,curr_node = None):
        '''
        WRITE THIS FILE
        THE GOAL IS TO COUNT HOW MANY NODES HAVE ZERO, ONE, OR TWO CHILD NODES
        STORE YOUR RESULT IN CNT_0, CNT_1, and CNT_2 (MEMBER VARS OF THE TREE CLASS) 
        '''

        if (curr_node == None):
            # if count is called without an input var, curr_node will be None
            # which means count is being called directly from testcase (not recursively).
            # in this case, init curr_node to root and set the count values = 0
            curr_node = self.root
            self.cnt_0 , self.cnt_1 , self.cnt_2 = 0 , 0 , 0

        if (curr_node == None):
            return

        # YOUR CODE HERE    
        
        # If curr_node is not Null, this conditional executes
        # The following code utilizes recursion to step through a binary tree
        if (curr_node):
            
            # Set curr_l and curr_r to next nodes (Null if empty)
            curr_l = curr_node.get_left()
            curr_r = curr_node.get_right()
            
            # Increase cnt_2 if both nodes exist
            if (curr_l is not None and curr_r is not None):
                self.cnt_2 += 1
                
            # If a left node exists, go into it
            # cnt_1 only increases if a right node doesn't exist
            if (curr_l is not None):
                if (curr_r is None):
                    self.cnt_1 += 1
                self.count(curr_l)
                
            # If a right node exists, go into it
            # cnt_1 only increases if a left node doesn't exist
            if (curr_r is not None):
                if (curr_l is None):
                    self.cnt_1 += 1
                self.count(curr_r)
                
            # If no child nodes exist, increase cnt_0
            if (curr_r is None and curr_l is None):
                self.cnt_0 +=1

    def print_count(self):
        print("Nodes with 0 children: " , self.cnt_0)
        print("Nodes with 1 children: " , self.cnt_1)
        print("Nodes with 2 children: " , self.cnt_2)
        print("")


def testcase_0():
    print("\nTestcase 0")
    print("---------------")
    x = tree()
    x.insert(8)
    x.insert(6)
    x.insert(7)
    x.insert(9)
    x.count()
    x.print_count()

def testcase_1():
    print("\nTestcase 1")
    print("---------------")
    x = tree()
    x.insert(9)
    x.insert(8)
    x.insert(7)
    x.insert(6)
    x.count()
    x.print_count()

def testcase_2():
    print("\nTestcase 2")
    print("---------------")
    x = tree()

    with open("/data/courses/ece_3822/current/lab_05/data.txt") as f:
        for str in f.readlines():
            x.insert( int(str) )

    x.count()
    x.print_count()


def main(argv):
    testcase_0()
    testcase_1()
    testcase_2()
    

if __name__ == "__main__":
    main(sys.argv)
