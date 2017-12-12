De Anza College<BR>
Manish Goel<BR>
Fall 2017<BR>
CIS22C Data Abstract & Structures<BR>

# Instructions
This assignment was locked Nov 1 at 3:30pm.
<br />This should be done in HW pairs.  Each person should submit their own copy of the same program.  You will also need to grade your partner's effort on a scale of 1:5 where 1 means you did all the work and 5 means your partner did all the work.

 

For this assignment, you need to implement a link-based Stack ADT.  To complete this, you will need the following:

 

A Node ADT which will have two attributes - a data attribute and a pointer attribute.  Remember the Node has to be an ADT, so that it can hold any kind of data.
<br />You can choose to use this node as both a data and a head-pointing node or as a simple data node in which case you will need a new head pointing node.
<br />A Singly Linked List ADT which will be composed of one or more of your nodes.  Implement the most common linked-list behaviors as explained in class - new list, add anywhere, delete anywhere, find anywhere, count of items in the list, empty the list, etc.
<br />Finally, implement a Stack ADT derived from your singly linked list which will implement the most common Stack operations like push, pop, isempty etc. and only expose them.
<br />Ensure that your Node, List and Stack ADTs are mimimal and cohesive with adequate walls around them.  Define interfaces as needed, so you can reuse them in all your subsequent assignments.
<br />Then write a main that will demonstrate the capabilities of you Stack ADT with different types of data - numbers, strings and your currency objects from Lab 1. Make sure that your currency files are not edited to fit the needs of this lab - I have the previous ones to compare.
<br />Remember the template class code cannot be split into .h and .cpp files - you need to define them in one file and you can give it the .h extension. Create separate code files for Node, List and Stack ADTs.
 

Grading:

5 pts - EXE works from command line on class/lab machines.
<br />3 pts - complete and working MSVC17 solution with a minimum of 5 code files (one each for node, linked list, stack, main and any currency related files) and proper styling.
<br />2 pts - Node template definition
<br />4 pts - Linked List template definition with commonly accepted behaviors of List ADTs.
<br />4 pts - Stack template inheriting from Linked List such that only stack behaviors are exposed for use in the main.
<br />2 pts - Adequate demonstration of Stack ADT use in main.
 

This lab is due before class one week from today. As already explained, this assignment should be done in Visual Studio or properly changed into a Visual Studio format before submitting. Include your entire VS folder structure zipped as attachment to this question.  The exe should work on its own before the coding will be graded. Also, include screenshots of the output. Remember to name your project and zip file name as StackADT_initial1_initial2. Put adequate documentation in code, including name blocks. Add the team member names in the response box of the question for the answer to be accepted.

# Outcome
-2 using inline definitions in template methods despite warnings
<br />Other things noted but no penalty:
<br />a. Your VS code structure is non-standard
<br />b. Your implementation of stack using push_back is counter intuitive and it shows up in the UI when you print the stack as the stack grows downward, instead of upward.