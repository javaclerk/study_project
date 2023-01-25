SYSC4001A ASSIGNMENT 3
------------------------------------------------------

AUTHOR
------------------------------------------------------

Name: Jeremy Trendoff
Student Number: 101160306

If you have any questions, comments, or concerns, please 
feel free to contact me at jeremytrendoff@cmail.carleton.ca.

------------------------------------------------------

HOW TO COMPILE AND RUN THE CALCULATOR PROGRAM
------------------------------------------------------

1. Download and unpack the Assignment3.tar archive.

2. Navigate to the location where the archive was unpacked 
using the terminal or open two new terminal windows in that directory.

3. Run the "make" command in either of the terminals to compile the program. 
The executables "user" and "calculator" should have been created.

4. In one of the terminal windows, run the "./calculator" command to
run the calculator, server, process.

5. In the other terminal window, run the "./user" command to run the user, 
client, process.

6. You may now enter any of the valid commands into the program. Valid commands are:
insert(integer goes here), delete(integer goes here), sum, average, min, and median.

Note: Before trying the delete, sum, average, min, or median commands, make sure to
insert some numbers into the list. Also, make sure to check your input is correct, the 
program may behave strangely if it encounters an invalid input.

-------------------------------------------------------

TROUBLESHOOTING
-------------------------------------------------------

In the case of an error with obtaining the message queue memory
, i.e. msgget failed error, try to change the key's for each 
message queue. To do this, go into the source code and change the 
number in each create_message_queue() function call to a new number. 
Make sure that msqid1 and msqid2 on both the calculator and the user 
have the same keys.

-------------------------------------------------------

END OF README
-------------------------------------------------------

