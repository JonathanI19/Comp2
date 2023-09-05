# note -> delete the "pass" statements. Those are placeholders
# until you replace them with actual code

class student:

    def __init__(self):
        self.name = ""
        self.grades = []

    def set_name(self,name):
        self.name = name

    def add_grade(self,grade):
        self.grades.append(grade)

    def get_max(self):
        return max(self.grades)

    def get_average(self):
        total = sum(self.grades)
        return total/len(self.grades)

    def display(self):
        for count, item in enumerate(self.grades, 1):
            print("grade", count, ": ", item)
            
    
