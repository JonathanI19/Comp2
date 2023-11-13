# Comp2 - ECE 3822

Welcome to my personal repo for ECE 3822: Engineering Computation 2, Data Structures and Algorithms!

Projects will primarily be written in Python and C++ over the course of various HWs, Projects, and Labs.

Grades will be posted in parentheses next to the heading for each project/lab shown below.

## Course Schedule
Week 1: Coding best practices, general review

Week 2: Object Oriented Programming

Week 3: Object Oriented Programming

Week 4: Circular Buffers

Week 5: Linked Lists

Week 6: Linked Lists

Week 7: Stacks

Week 8: Queues

Week 9: Hash Tables

Week 10: Heaps

Week 11: Binary Trees

Week 12: Binary Trees

Week 13: Graphs

Week 14: Sorting & Complexity (Big O)

## Lab Overview

### Lab 1 (10/10)
In this lab you will write one C++ file and one Python file to do the following tasks:
1. Read a list of integers from a text file
2. Print the average value, accurate to two decimal places
3. Print the square root of the product of the largest two values, accurate to two decimal places

### Lab 2 (10/10)
In this week's lab you will practice writing some straightforward
object-oriented code. You should write the code twice: once in Python
and again in C++

Write a class called "student" that stores a student's name and grades
and can return the maximum and the average grade, as well as display a
student summary. Do not change lab_02.py or lab_02.cpp.

### Lab 3 (10/10)
This week's lab will implement and expand on the circular buffer code
we wrote during Week 3. You are supplied with `lab_03.py`. This file 
includes an example of how to create a moving average filter by inheriting 
a circular buffer class, just how we did in class in C++. The circular 
buffer class is also provided for you. Do not edit that file.

Your goal is to implement a class for a Finite Impulse Response (FIR) filter.

### Lab 4 (10/10)
The goal of this assignment is to complete the following functions in linked_list.h:

clear_list()    // removes all data from the linked list
size()          // returns the number of nodes in the list
sum()           // returns the sum of the data in the list
is_empty()      // returns true if the list is empty, otherwise false

### Lab 5 (9/10)
The goal of this lab is to analyze a binary tree and count how many nodes have zero, one, or two valid children. Use the attached code as template. You should only edit the "count()" function.

### Lab 6
In lab_06.py you will find hash table code that is nearly identical
to what we have been working on in class. Take a minute to familiarize
yourself with the implementation differences between C++ and Python.

You have the following goals.

[1] Complete the lookup() function. You should be able
to look up a student that is in the hash table AND properly
return a None if that student is not in the hash table

[2] Improve the hash_function() in two ways. First, make it
case insensitive, so if someone searches for "Obeid" or "obeid"
it won't make a difference. Secondly, make the hash-function
sensitive to the order of the characters, so that "obeid" and "deibo"
don't map to the same array location

[3] During the insert function, if there is already data in the
buffer (eg a collision), try inserting at the next index location
until you find an empty spot.

Make sure to include enough test code in main() to demonstrate
that items [1]-[3] are working properly

### Lab 7
In this lab, you will use the concepts of class inheritance to create hash_tables that store student objects by:

1. Last name
2. First name
3. ID

You will also generate a db class that automates this process for all 3 hash tables.

### Lab 8
The purpose of this lab is to complete the <are_connected> function that returns "True" if there is a path from src to dst and "False" otherwise. This includes indirect paths! If there is no direct connection between Nodes 0 and 3, but you can get from 0 to 3 by passing through Nodes 1 and 2 then your code should return True.


## Project Overview

### Project 1 (50/50)
In this project, you will used C++ to code up a simple game I have invented.
The purpose of the project is to practice using classes and objects.
The game consists of `players`. Multiple players can be grouped into `teams`
and two `teams` can play each other. You can make the coding easier by starting
by building and testing `player` before moving on to `team` and then `competition`.

PROVIDED: 

**play_game.cpp** was provided as a complete file

**Makefile** was provided - links to file in server that contains code for **int generate_score(int)**, which is not included in the GitHub.

### Project 2
The goal of Project 2 is to practice using objects and re-using pre-written linked-list code.
I have already written a generic linked list class which you can read at $SHARE/include. You will
*not* copy this code to your local directory.

**Problem: **
You work for an online video streaming service, and you have to manage data on your customers. Each 
customer has an ID number and a list of movies they watched last month. The data is stored in a text 
file in the following format:
* customer ID number
* number of movies watched last month
* ID numbers of the movies watched last month

For example: suppose a file has data on two customers, it might look like this:

724
3
225
502
109
449
2
109
305

Customer #1 has ID number 724 and watched 3 movies whose ID numbers are 225, 502, and 109.
Customer #2 has ID number 449 and watched 2 movies whose ID numbers are 109 and 305

As you can see, both customers watched the movie whose ID number is 109

Your goals is to get the following functions to work:

clients.print_all() - prints all the customer information in this format:

Customer 724 watched 225, 502, 109
Customer 449 watched 109, 305

clients.print_customer(customerID) - prints the information for a specific customer

Customer 724 watched 225, 502, 109

clients.print_views(movieID) - prints the number of customers who watched a movie

Movie 109 was watched 2 time(s)

### Project 3
In this project we will simulate incoming data packets with a text file that contains packet information and the packet arrival time. The code automatically inserts a time delay to simulate the packet's arrival time. While you are reading data into the queue, a separate thread will be simultaneously running.  This thread will be constantly checking the queue. If the queue contains data, then you will pop one student packet from the queue, hash it, and store it in the hash table.
