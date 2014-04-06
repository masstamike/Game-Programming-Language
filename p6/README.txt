In this phase you create graphics.  Thus you can't test your program 
without comparing the graphics your program generates with the graphics 
my program generates.

Use the run_all_tests script as the previous phases, however:

    If the program does not have any errors, a window will pop up.  You
    will have to close the application by typing a q into the window.

    Starting with this phase, your program will produce a dump of the
    pixel values (called t***.pixels) when your program terminates.  If
    your program does not generate the same pixels as my program, you will
    fail the test.  NOTE: the pixel file does not check the window title,
    you have to check it by looking at your program.

    If there is a .jpg file for a given test (e.g. t001.jpg) this file
    contains a screen dump of the correct graphis.  If you pass the
    pixel test mentioned above, your window should look the same as
    the provided .jpg file.  .jpg files are not provided for tests that
    do not have graphics.


For a basic description of how to run the tests, see:
    http://www.ecst.csuchico.edu/~tyson/515/docs/testing.html

