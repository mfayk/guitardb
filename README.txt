Max Faykus
ECE 2230
Programming Assignment 1
mfaykus

This program is used to impliment a database for guitars. The array size for the guitars is
set with a #define in the database.c file.  To run the program the user has a list of 
commands ADD, LOOK, DEL, LIST, QUIT. The ADD command adds a new guitar to the database. 
The LOOK command will print the contents of a guitar in the database, the user needs
to input the key number of the guitar in stdin to have the command look for it. The DEL
command will remove a guitar from the list, it also will need a input for it to look for the 
key.  LIST when called will list out each guitar in the database. QUIT is what needs to be called
to end the program.

When testing this program i called each of the functions using the commands checking if they
work properly.  i also set the max_guitars to a low number and filled the array to check for 
any errors with the array. I also filled the array then removed an guitar then filled it again.
i checked the values while testing with gdb and compared it to the list call. I also tested 
with the database empty and tried calling the DEL and LIS ect.. and the program properly
returned an error.