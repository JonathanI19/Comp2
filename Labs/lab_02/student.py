'''
    Utility file for student class
    
    @Author: Jonathan Isely
    @Contact: jonathan.isely@temple.edu
    @Date: 9/10/2023

'''

class student:
    '''Class: Student information
    A class for storing student names and grades and displaying relevant data
    '''

    def __init__(self):
        '''Constructor'''
        self.name = "NAME_PENDING"
        self.grades = []

    def set_name(self,name):
        '''Set the students name in the object
        
        Args:
            name (numeric): name of the student
        Returns:
            None
        '''
        self.name = name

    def add_grade(self,grade):
        '''Append a new grade into the list
        
        Args:
            grade (numeric): New grade to be added to list
        Returns:
            None
        '''
        self.grades.append(grade)

    def get_max(self):
        '''Get max grade from list of grades
        
        Args:
            None
        Returns:
            numeric: Maximum grade; 0 if no grades added
        '''
        
        # Error handling for if no grades are entered
        try:
            return max(self.grades)
        except ValueError:
            print("ERROR: No grades entered. Max is None")
            
    def get_average(self):
        '''Get average of grades list
        
        Args:
            None
        Returns:
            numeric: Average grade; 0 if no grades added
        '''
        total = sum(self.grades)
        
        # Error handling for if no grades are entered
        try:
            return total/len(self.grades)
        except ZeroDivisionError:
            print("ERROR: No grades entered. Average set to 0.")
            return 0

    def display(self):
        '''Display each grade value
        
        Args:
            None
        Returns:
            None
        '''
        print(self.name, "Summary:\n")
        for count, item in enumerate(self.grades, 1):
            print("grade", count, ": ", item)
            
    
