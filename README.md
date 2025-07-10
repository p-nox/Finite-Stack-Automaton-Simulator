# Finite Stack-Based Automaton Simulator

This project implements a **Pushdown Automaton (PDA)** simulator in C. 
It reads a PDA configuration from a text file, processes input strings, and determines whether they are accepted or rejected based on the PDA's transition rules and stack behavior.


## Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [File Structure](#file-structure)
4. [Getting Started](#getting-started)

## Overview

The finite automaton simulator is designed to read a configuration file containing information about the automaton's states, transitions, and initial/final states. Users can then input words to be processed by the automaton, and the program will determine whether each word is accepted or rejected.

## Features
The main functionalities include:
   * **Finite Automaton with Stack:** The program models a finite automaton with a stack, allowing it to process input strings and make decisions based on transitions between states.
   * **Transition Specification:** Transitions are defined in the input file, indicating the source state, input character, target state, and stack manipulation operations (push and pop).
   * **User Interaction:** The program interacts with the user, prompting them to provide an input file containing the automaton's specifications. Users can then input words to be processed by the automaton.
   * **Word Acceptance:** The automaton determines whether a given input word is accepted or rejected based on the defined transitions and the final state.
   * **Dynamic Memory Allocation:** The program uses dynamic memory allocation for storing transition information, providing flexibility for automata with varying numbers of states and transitions.

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
    
## Getting Started

   1. **Input File Specification:** The user is required to provide an input file containing the specifications of the finite automaton. This includes the number of states, initial and final states, and the transitions.

   2. **User Interaction:** After reading the input file, the program prompts the user to input words for the automaton to process. The user can choose to continue or exit after each word.

   3. **Word Processing:** The program processes each input word using the specified transitions and determines whether the word is accepted or rejected.

## Notes

 * The simulator relies on standard input for word input, and it can be terminated by entering 'N' when prompted to continue.
 * Ensure that the input file adheres to the specified format   
