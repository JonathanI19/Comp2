import heapq
from argparse import ArgumentParser
from math import sqrt

''' lab_09.py

    Jonathan Isely
    jonathan.isely@temple.edu
    Due 12/3/2023
    
    Description:
    Implement the A* algorithm for graph path search. 
    Full instructions in readme.txt       

    Usage:
    python lab_09.py TESTCASE
        where TESTCASE is either 1 (default) or 2
        1 selects the smaller test file aoc_1.txt
        2 selects the larger file aoc_2.txt

    What to submit:
    The submit script will only submit lab_09.py   

'''

'''
LAB QUESTIONS

Both Djikstra's and AStar provide a shortest route of 528.

However, using the compute guess method, AStar requires fewer loops to get to the same result. It isn't terribly more efficient, and I noticed that my first attempt at computing this actually resulted in more loops. It seems to rely heavily on the quality of the algorithm used to pick the best guess.

'''

def load_grid(fname):
    '''Loads data from file into memory
    Args:
        fname:  filename to load
    Returns:
        grid:       list of lists containing grid values
        loc_start:  tuple of i,j coordinates of start location
        loc_end:    tuple of i,j coordinates of end location
    '''    

    # load grid
    with open(fname) as f:
        lines = f.readlines()
    
    # convert to numbers 
    grid = [ [ ord(c)-ord('a') for c in line[:-1]] for line in lines]
    
    # find start and end points
    for i in range(len(grid)):
        if -14 in grid[i]:
            i_start,j_start = i , grid[i].index(-14)
        if -28 in grid[i]:
            i_end,j_end = i , grid[i].index(-28)

    # replace start/end points with appropriate value
    grid[i_start][j_start] = 0
    grid[i_end][j_end]     = 25

    return grid , (i_start,j_start) , (i_end,j_end)

def djk(grid , loc_start , loc_end):
    '''Find shortest path from loc_start to loc_end in grid
    following the rules spelled out in AoC 2022 / Day 12
    
    Args:
        grid:       list of lists containing grid values
        loc_start:  tuple of i,j coordinates of start location
        loc_end:    tuple of i,j coordinates of end location
    Return:
        n:          length of shortest path
    '''

    # init misc vars
    n_rows,n_cols = len(grid) , len(grid[0])
    INF = int(1e6)

    # init dictionaries
    d_incomplete,d_complete = {} ,{}

    # add all nodes to the <incomplete> dictionary
    for i in range(n_rows):
        for j in range(n_cols):
            d_incomplete[(i,j)] = (INF,(99,99))

    # move <start> to <complete> list with distance 0
    d_complete[loc_start] = (0 , (99,99))
    del d_incomplete[loc_start]

    # init <current> location and distance
    loc_curr = loc_start
    dist_curr = 0

    # helper functions
    def get_val(loc):
        return grid[loc[0]][loc[1]]

    def reachable(loc_curr , loc_dst):
        return get_val(loc_curr) - get_val(loc_dst) >= -1

    def valid_loc(loc):
        return 0 <= loc[0] < n_rows and 0<=loc[1]< n_cols


    h = []

    count = 0
    
    while loc_curr != loc_end:
        count+=1
        incomplete_keys = d_incomplete.keys()

        # update all 4 neighbors of current node
        for delta in [(-1,0) , (1,0) , (0,-1) , (0,1)]:

            loc_neighbor = (loc_curr[0] + delta[0] , loc_curr[1] + delta[1])

            # check if loc_neighbor is actually on the grid
            if valid_loc(loc_neighbor):

                # check if loc_neighbor still hasn't been completed
                if loc_neighbor in incomplete_keys:

                    # check if loc_neighbor can be reached according to rules of AOC 2022/Day 12
                    if reachable(loc_curr , loc_neighbor):

                        # check if we've found a new shortest path to neighbor                       
                        if (dist_curr + 1) <= d_incomplete[loc_neighbor][0]:
                            d_incomplete[loc_neighbor] = (dist_curr+1 , loc_curr)
                            heapq.heappush(h , (dist_curr+1 , loc_neighbor) )

        # find minimum incomplete node
        while True:
            pv = heapq.heappop(h)
            loc_next = pv[1]
            min_dist = pv[0]
            if loc_next not in d_complete.keys():
                break

        # make min node the new current node
        dist_curr = min_dist
        loc_curr = loc_next

        # move new current node from incomplete
        # to complete dictionary
        d_complete[loc_next] = d_incomplete[loc_next]
        del d_incomplete[loc_next]


    print("Num of loops: ", count)
    # return shortest path length
    return d_complete[loc_end][0]

def AStar(grid , loc_start , loc_end):
    '''Find shortest path from loc_start to loc_end in grid
    following the rules spelled out in AoC 2022 / Day 12
    
    Args:
        grid:       list of lists containing grid values
        loc_start:  tuple of i,j coordinates of start location
        loc_end:    tuple of i,j coordinates of end location
    Return:
        n:          length of shortest path
    '''

    # init misc vars
    n_rows,n_cols = len(grid) , len(grid[0])
    INF = int(1e6)

    # init dictionaries
    d_incomplete,d_complete = {} ,{}

    # add all nodes to the <incomplete> dictionary
    for i in range(n_rows):
        for j in range(n_cols):
            d_incomplete[(i,j)] = (INF,(99,99))

    # move <start> to <complete> list with distance 0
    d_complete[loc_start] = (0 , (99,99))
    del d_incomplete[loc_start]

    # init <current> location and distance
    loc_curr = loc_start
    dist_curr = 0

    # helper functions
    def get_val(loc):
        return grid[loc[0]][loc[1]]

    def reachable(loc_curr , loc_dst):
        return get_val(loc_curr) - get_val(loc_dst) >= -1

    def valid_loc(loc):
        return 0 <= loc[0] < n_rows and 0<=loc[1]< n_cols

    # Computes Straight line distance between current node and target node
    def compute_guess(loc_curr,loc_end):
        row_end,col_end = loc_end
        row_curr,col_curr = loc_curr
        delta_row = row_end - row_curr
        delta_col = col_end - col_curr
        return sqrt(delta_row**2 + delta_col**2)

    h = []

    count = 0
    
    while loc_curr != loc_end:
        count += 1
        incomplete_keys = d_incomplete.keys()

        # update all 4 neighbors of current node
        for delta in [(-1,0) , (1,0) , (0,-1) , (0,1)]:

            loc_neighbor = (loc_curr[0] + delta[0] , loc_curr[1] + delta[1])

            # check if loc_neighbor is actually on the grid
            if valid_loc(loc_neighbor):

                # check if loc_neighbor still hasn't been completed
                if loc_neighbor in incomplete_keys:

                    # check if loc_neighbor can be reached according to rules of AOC 2022/Day 12
                    if reachable(loc_curr , loc_neighbor):

                        # check if we've found a new shortest path to neighbor                       
                        if (dist_curr + 1) <= d_incomplete[loc_neighbor][0]:
                            d_incomplete[loc_neighbor] = (dist_curr+1 , loc_curr)
                            
                            # heap is now sorted by min straight line distance
                            delta_m = compute_guess(loc_curr, loc_end)
                            heapq.heappush(h , (dist_curr+delta_m, dist_curr+1 , loc_neighbor) )

        # find minimum incomplete node
        while True:
            pv = heapq.heappop(h)
            loc_next = pv[2]
            min_dist = pv[1]
            if loc_next not in d_complete.keys():
                break

        # make min node the new current node
        dist_curr = min_dist
        loc_curr = loc_next

        # move new current node from incomplete
        # to complete dictionary
        d_complete[loc_next] = d_incomplete[loc_next]
        del d_incomplete[loc_next]

    print("Num of loops: ", count)

    # return shortest path length
    return d_complete[loc_end][0]

def get_opts():
    '''Get command line argument.
    User specifies either nothing OR 1 OR 2
    
    Return:
        option: integer 1 or 2
    '''

    # set up parser
    parser = ArgumentParser()
    parser.add_argument('option' , type=int, nargs='?', 
                        default=1, help="file load option: [1] or 2")

    # parse command line
    opts = parser.parse_args()
    option = opts.option

    #  make sure input is either 1 or 2
    if option not in [1,2]:
        raise ValueError("Specify input file 1 or 2")

    return option

def main():
    '''Find the shortest route from start to finish on the elevation map.
    Option 1 (default) use $SHARE/lab_09/aoc_1.txt (a smaller map that can be hand-analyzed if needed)
    Option 2 use $SHARE/lab_09/aoc_2.txt which is the much larger map
    
    Usage:
        python lab_09.py    [runs djkstras on aoc_1]
        python lab_09.py 1  [runs djystras on aoc_1]
        python lab_09.py 2  [runs djystras on aoc_2]
        '''
    opt = get_opts()

    fname = {1:'/data/courses/ece_3822/current/lab_09/aoc_1.txt',
             2:'/data/courses/ece_3822/current/lab_09/aoc_2.txt'}

    # load the data from file
    grid , loc_start, loc_end = load_grid(fname[opt])

    # find the shortest path from loc_start to loc_end
    #n = djk(grid,loc_start,loc_end)
    n = AStar(grid, loc_start, loc_end)

    # print the results
    print("\nshortest path: " , n)
    print("\n")

main()
