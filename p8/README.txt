For the tests that have a .jpg file you need to wait until the animation
has stopped (might take a long time on slow machines) and then compare
the window to the .jpg file.  Then you will have to press 'q' to start 
the next tests.

If a test does not exit itself and there is NO .jpg file, there probably
is an error in your program.

If there is a .jpg file and your program does not wait for you to type 
'q' your program probably has an error.

FOR p8 YOU DO NOT WANT TO PRINT THE SYMBOL TABLE, MAKE SURE YOU EDIT
YOUR MAKEFILE SO YOU DO NOT PRINT THE SYMBOL TABLE (look for p8 in Makefile).

See the tests/p7/README for a description of how the .keypresses mechanism
works.

For a basic description of how to run the tests, see:
    http://www.ecst.csuchico.edu/~tyson/classes/515.s08/docs/testing.html
