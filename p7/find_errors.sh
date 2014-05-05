#!/bin/bash
#Script to find errors, so i can add them to my gpl

for gpl_test in tests/t[0-9][0-9][0-9].err
do
    echo $gpl_test;
    cat $gpl_test;
done
