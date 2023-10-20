''' lab_06.py

    YOUR NAME HERE
    YOUR EMAIL ADDRESS
    DATE

    Description:
    This file creates a hash table of <student>s and tests performance
    with some simple inserts and lookups in <main>.

    Usage:
    python lab_06.py
    
'''

#################################################################
class student:

    def __init__(self,last,first,zip,gpa):
        self.last  = last
        self.first = first
        self.zip   = zip
        self.gpa   = gpa

    def display(self):
        print(self.last, " ", self.first , " " , self.gpa , " " , self.zip)
        
    # Getter for last name
    def get_last(self):
        return self.last

    # Getter for first name
    def get_first(self):
        return self.first

#################################################################
class hash_table:

    # constructor
    def __init__(self,buff_len=10):
        self.buff_len = buff_len
        self.buffer = [None]*self.buff_len

    # all-important hash-function
    def hash_function(self , std=None , last=None , first=None):

        # if a student is provided as input, use names in student
        # for the hash function. otherwise use the provided first
        # and last names
        if std: last,first = std.last, std.first
        
        # concatenate the names
        total_name = last+first

        # Make total_name case insensitive by setting all chars to their Uppercase version
        total_name = total_name.upper()

        s = 0
        for count, char in enumerate(total_name):
            
            # Makes it start at 1
            i = count+1
            
            # ord(char) converts char into ascii value
            # This equation takes the square of index+1 and multiplies it by
            # the ascii value of the char
            # This should act as a basic method of making the rudimentary hash-function
            # sensitive to the order of the characters.
            s += ((i*i)*ord(char))         
        
        # Calculate and return index
        index = s % self.buff_len
        return index
    
    # insert student into buffer
    def insert(self,std):
        index = self.hash_function(std=std)
        
        # Only inserts student if index is empty
        if self.buffer[index] is None:
            self.buffer[index] = std
            
        # Executes if index is not empty
        else:
            start = index
            
            # Runs until break condition is met
            while(True):
                
                # Increments index in circular fashion
                index = ((index + 1) % self.buff_len)
                
                # If empty location found, insert student and then break
                if (self.buffer[index] is None):
                    self.buffer[index] = std
                    break
                
                # Breaks out of loop if it reaches the start point without having found open space
                elif(index == start):
                    print("No available space left")
                    break
                

    # look up a student in the hash table by, 'student' or 'first' and 'last'
    def lookup(self,last,first,display=False):
        target_student = None

        # Find index from last and first name
        index = self.hash_function(last=last, first=first)
        
        # If location of index is populated in buffer, set target_student to equal that object
        if (self.buffer[index] is not None):
            start = index
            while(True):
                
                # Break out of loop if empty space found before proper student
                if ((start != index) and (self.buffer[index] is None)):
                    break
                
                # Set target_student and break out of loop if proper location is found
                elif((self.buffer[index].get_last().upper() == last.upper()) and ((self.buffer[index].get_first().upper() == first.upper()))):
                    target_student = self.buffer[index]
                    break
                
                # Increment index if strings don't match
                else:
                    index = ((index + 1) % self.buff_len)
                
                # if loop finds way back to initial posession, break  
                if (start == index):
                    break
                

        # display results if user requests it
        if display: 
            print("\n")
            print("Search result:" ,end=" ")
            if target_student: target_student.display()
            else: print(last,first, "not found")
            print("\n")

        return target_student

    # display contents of the buffer
    def display(self):
        print("\n")
        print("Displaying complete contents of hash table:")
        for i,s in enumerate(self.buffer):
            print(i,end=" ")
            if s:
                s.display()
            else:
                print("")            
        print("\n")

def main():

    # create the hash table
    # A larger buff_len means less chance of coincidental collisions
    my_table = hash_table(buff_len = 6)

    # create two new students and insert them into the hash table
    my_table.insert( student( "Obeid" , "Iyad" , 19143 , 3.99) )
    my_table.insert( student( "Obeid" , "Timmy", 19147 , 3.14) )
    my_table.insert( student( "OBEID", "IYAD", 19147 , 3.14))
    my_table.insert( student( "diebO" , "Timmy", 19147 , 3.14) )
    my_table.insert( student( "diebO" , "TIMMY", 19147 , 3.14) )
    # look up a student and display results
    my_table.lookup("Obeid","Iyad",display=True)
    my_table.lookup("bob", "thebuilder", display = True)
    my_table.lookup("diebo", "timMy", display = True)
    # display contents of hash table
    my_table.display()


if __name__=="__main__":
    main()
