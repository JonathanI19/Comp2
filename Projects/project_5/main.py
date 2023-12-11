#################################################################
class movie:

    def __init__(self, id, name, year):
        self.id = id
        self.name = name
        self.year = year

    def display(self):
        print(self.name, " | ", self.year)
        
    # Getter for ID
    def get_id(self):
        return self.id
    
    # Getter for name
    def get_name(self):
        return self.name

    # Getter for year
    def get_year(self):
        return self.year

class hash_table:

    # constructor
    def __init__(self,buff_len):
        self.buff_len = buff_len
        
        # Buffer is list of lists. Allows for collision handling in manner similar to cpp vectors
        self.buffer = [[] for _ in range(self.buff_len)]

    # Generates hash_key based off of passed in ID
    def hash_function(self , id):

        s = 0
        
        for count, char in enumerate(id):
            
            # Makes it start at 1
            i = count+1
            
            # ord(char) converts char into ascii value
            # This equation takes the square of index+1 and multiplies it by
            # the ascii value of the char (not the actual digit value)
            s += ((i*i)*ord(char))         
        
        # Calculate and return index
        index = s % self.buff_len
        return index
    
    # insert object into buffer
    def insert(self,obj):
        index = self.hash_function(obj.get_id())
        
        # Appends obj info
        self.buffer[index].append(obj)          

    # look up an object by ID
    def lookup(self, target_id, display=False):
        target = target_id
        return_objs = []
        
        # Find index from ID
        index = self.hash_function(target)
        
        # Loop through elements in target list and find all that match
        for item in self.buffer[index]:
            if target == item.get_id():
                return_objs.append(item)
                
                # Print results if specified to do so
                if display == True:
                    item.display()

        return return_objs
    
    
def main():
    
    # Generate movie hash table
    movie_hash = hash_table(50000)
    
    movie_file = open("../project_5_data/movies.tsv", 'r')
    lines = movie_file.readlines()
    for line in lines:
        data = line.split("\t")
        obj = movie(data[0], data[2], data[5])
        movie_hash.insert(obj)
        
    movie_hash.lookup("tt9875554", display = True)
        
        
if __name__ == "__main__":
    main()
