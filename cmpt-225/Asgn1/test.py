#!/usr/bin/env python
import subprocess
import sys
import os

# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 1)

# Initialize the number of passed tests.
passed = 0

# Set the number of tests.
n_tests = 1

# Run a loop for each test case.
for i in range(1, n_tests + 1):
    sys.stdout.write("Running test " + str(i) + "... ")
    # Compile the TestDriver.cpp along with MyADT.cpp and Profile.cpp
    compile_result = subprocess.call(
        "g++ -o TestDriver MyADTTestDriver.cpp MyADT.cpp Profile.cpp", shell=True
    )
    
    if compile_result != 0:
        sys.stdout.write("compilation failed\n")
        continue
    
    # Execute the test case by redirecting the input file.
    rt = subprocess.call(f"./TestDriver < {i}.in > {i}.out", shell=True)
    
    # Open the output and expected result files.
    with open(f"{i}.out", 'r') as outf, open(f"{i}.er", 'r') as erf:
        output = outf.read()
        expected = erf.read()
    
    # Compare the output to the expected result.
    if output.strip() == expected.strip():
        passed += 1
        sys.stdout.write("passed\n")
    else:
        sys.stdout.write("failed\n")
        sys.stdout.write("Expected:\n" + expected + "\n")
        sys.stdout.write("Got:\n" + output + "\n")

# Output the total number of passed tests.
sys.stdout.write("Passed " + str(passed) + " of " + str(n_tests) + " tests.\n")