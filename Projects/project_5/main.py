
#################################################################

# Holds movie data in objects
class movie:

    # Constructor
    def __init__(self, id, name, year):
        self.id = id
        self.name = name
        self.year = year

    # Displays formatted object data
    def display(self):
        print("Movie Name: ", self.name, " | Release Year: ", self.year)
        
    # Getter for ID
    def get_id(self):
        return self.id
    
    # Getter for name
    def get_name(self):
        return self.name

    # Getter for year
    def get_year(self):
        return self.year


#################################################################

# Holds actor data in objects
class actor:
    
    # Constructor
    def __init__(self, id, name, birth, death):
        self.id = id
        self.name = name
        self.birth = birth
        self.death = death

    # Displays formatted object data
    def display(self):
        print("Name: ", self.name, " | Born: ", self.birth, " | Died: ", self.death)
        
    # Getter for ID
    def get_id(self):
        return self.id
    
    # Getter for name
    def get_name(self):
        return self.name

    # Getter for birth year
    def get_birth(self):
        return self.year
    
    # Getter for death year
    def get_death(self):
        return self.death


#################################################################

# Stores role data in objects
class starring_roles:
    
    # Constructor
    def __init__(self, movie_id, name_id):
        self.movie_id = movie_id
        self.name_id = name_id

    # Displays formatted object data
    def display(self):
        print("Name ID: ", self.name_id, " | Movie ID: ", self.movie_id)
        
    # Getter for name ID
    def get_id(self):
        return self.name_id
    
    # Getter for movie ID
    def get_movie_id(self):
        return self.movie_id


#################################################################

# Generic Hash Table data structure
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
            
            # If target matches item id, append to return_objs
            if target == item.get_id():
                return_objs.append(item)
                
                # Print results if specified to do so
                if display == True:
                    item.display()

        # Handles invalid lookup ids
        if len(return_objs) == 0:
            return_objs = None
            print(target, " Not Found")
            
        # Return list of objects that match target id
        return return_objs


#################################################################    
    
def main():
    
    # Flag for ignoring first row
    flag = False
    
    # Generate movie hash table
    movie_hash = hash_table(50000)
    
    # Read movie data into movie_hash
    movie_file = open("../project_5_data/movies.tsv", 'r')
    lines = movie_file.readlines()
    for line in lines:
        if flag is True:
            data = line.split("\t")
            
            # Insert id, movie name, release year
            obj = movie(data[0], data[2], data[5])
            movie_hash.insert(obj)
        flag = True    
        
    movie_file.close()
    
    
    ##########################################################
    
    lines = []
    
    # Flag for ignoring first row
    flag = False
    
    # Generate actor hash table
    actor_hash = hash_table(50000)
    
    # Read movie data into movie_hash
    actor_file = open("../project_5_data/names.tsv", 'r')
    lines = actor_file.readlines()
    for line in lines:
        if flag is True:
            data = line.split("\t")
            
            # Reformat death data as needed
            if data[3] == "\\N":
                data[3] = "N/A"
            
            # Insert id, name, birth year, death year
            obj = actor(data[0], data[1], data[2], data[3])
            actor_hash.insert(obj)
        flag = True
        
    actor_file.close()
    
        
    ##########################################################
    
    lines = []
   
    # Flag for ignoring first row
    flag = False
    
    # Generate actor hash table
    roles_hash = hash_table(50000)
    
    # Read movie data into movie_hash
    roles_file = open("../project_5_data/starring_roles.tsv", 'r')
    lines = roles_file.readlines()
    for line in lines:
        if flag is True:
            data = line.split("\t")
            
            # Insert movie ID and actor ID
            obj = starring_roles(data[0], data[2])
            roles_hash.insert(obj)
        flag = True
        
    roles_file.close()    
    
    ##########################################################
    
    # Nested Function for lookup - Requires actor name id
    def lookup_roles(name_id):
        
        # Collect role_objs that match target name_id
        role_objs = roles_hash.lookup(name_id, display = False)
        
        # Print out actor name from actor_hash table per target name_id
        print("\nMovies Starring ", actor_hash.lookup(name_id, display = False)[0].get_name(), ":")
        
        # Print out movie names stored in role_objs
        for item in role_objs:
            print(movie_hash.lookup(item.get_movie_id())[0].get_name())
        print("\n")
        
    
    # Lookup all movies featuring "nm0000129"
    lookup_roles("nm0000129")
    
    # Lookup movie by ID
    movie_hash.lookup("tt9875554", display = True)
    
    # Lookup actor by ID
    actor_hash.lookup("nm0000129", display = True)
    
if __name__ == "__main__":
    main()
