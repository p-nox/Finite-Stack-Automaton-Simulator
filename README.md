# Finite Stack-Based Automaton Simulator

This repository contains a C program for simulating a finite automaton based on the input provided in a configuration file. The program reads the configuration file, which specifies the number of states, initial and final states, and transitions, and allows users to input words to be checked against the defined automaton.

## Table of Contents

1. [Overview](#overview)
2. [Usage](#usage)
3. [File Structure](#file-structure)
4. [Contributing](#contributing)
5. [License](#license)

## Overview

The finite automaton simulator is designed to read a configuration file containing information about the automaton's states, transitions, and initial/final states. Users can then input words to be processed by the automaton, and the program will determine whether each word is accepted or rejected.

The main functionalities include:
- Reading the configuration file to initialize the finite automaton.
- Accepting user input words for processing.
- Checking whether each input word is accepted or rejected by the automaton.
- Providing feedback on the acceptance/rejection status and the current state of the automaton.

## Usage

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/finite-automaton-simulator.git
   cd finite-automaton-simulator
   
2. **Compile the Program:**
   ```bash
   gcc finite_automaton.c -o finite_automaton

3. **Run the Program:**
   ```bash
   ./finite_automaton

## File Structure
    
  * **stack_automaton.c**: The main C program file containing the implementation of the finite automaton simulator.
  
  * **genlib.h, simpio.h**: Header files providing general and simple input/output functionalities.
    
  - **sample1.txt:** contains an example of a language grammar in the form of a context-free grammar (CFG) that generates strings in the language $\{b^na^m:n=m}$. This language consists of strings with an equal number of 'b's and 'a's.
    And the transition rules:
     * **Transition 1 (1bea1):** From state 1, when encountering 'b', stay in state 1, pop 'e' from the stack, and push 'a' onto the stack. Then, transition to state 1.
     * **Transition 2 (1aae1):** From state 1, when encountering 'a', stay in state 1, pop 'a' from the stack, and push 'e' onto the stack. Then, transition to state 1.
     * **Transition 3 (1eSe1):** From state 1, when encountering 'e', stay in state 1, pop 'e' from the stack, stay in state 1, and push 'e' onto the stack. Then, transition to state 1.
       
  - **sample2.txt:** contains an example of a language grammar in the form of a context-free grammar (CFG) that generates strings in the language $\{a^nb^m:n≥m}$. This language consists of strings with zero or more 'a's followed by zero or more       'b's, where the number of 'a's is greater than or equal to the number of 'b's.
    And the transition rules:

     * **Transition 1 (1eeS2):** From state 1, when encountering 'e' (epsilon), stay in state 1 and push 'e' onto the stack. Then, transition to state 2.
     * **Transition 2 (2aea2):** From state 2, when encountering 'a', stay in state 2 and push 'a' onto the stack. Then, transition to state 2.
     * **Transition 3 (2bae3):** From state 2, when encountering 'b', pop 'a' from the stack and transition to state 3.
     * **Transition 4 (3bae3):** From state 3, when encountering 'b', pop 'a' from the stack and stay in state 3.
     * **Transition 5 (3#ee4):** From state 3, when encountering '#' (end of input), stay in state 3 and push 'e' onto the stack. Then, transition to state 4.
     * **Transition 6 (4eae4):** From state 4, when encountering 'e', stay in state 4 and push 'a' onto the stack. Then, transition to state 4.
     * **Transition 7 (4eSe5):** From state 4, when encountering 'e', pop 'a' from the stack, pop 'e' from the stack, stay in state 4, and push 'e' onto the stack. Then, transition to state 5.
    

   
