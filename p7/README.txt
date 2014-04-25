In this phase you handle keyboard input.  gpl.cpp has a mechanism for 
reading keyboard input from a file in order to test how programs 
handle input.  

If there is a .keypresses file in the test directory, run_all_tests will
redirect this file into gpl's standard input and pass the flag "-stdin"
to gpl.  When gpl receives the "-stdin" flag, key presses are read from
standard input instead of the keyboard (usually the Glut library reads
the keypresses, this mechanism circumvents Glut's input mechanism).

Most tests include a 'q' in the .keypresses file.  That means the test
will complete w/o any interaction from you.  However, some tests will
require you to look at a .jpg file to make sure your graphics are correct.

When a test does not exit itself, you need to compare the current screen
to the .jpg file corresponding to this tests.  After you make the comparison,
press 'q' to exit gpl.  The run_all_tests script will start the next test.

If a test does not exit itself and there is NO .jpg file, your program
probably has an error.

If there is a .jpg file and your program does not wait for you to type 
'q' your program probably has an error.

For a basic description of how to run the tests, see:
    http://www.ecst.csuchico.edu/~tyson/classes/515.s11/docs/testing.html
