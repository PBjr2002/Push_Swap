# Push_Swap

## Project Rules

- I worked with **two stacks** named `a` and `b`.
- At the start:
  - Stack `a` contained a random number of unique negative and/or positive integers.
  - Stack `b` was empty.
- My goal was to **sort the numbers in stack `a` in ascending order** with the **least number of moves possible**.
- I had the following operations available:

  - `sa` (swap a): Swapped the first 2 elements at the top of stack `a`.
  - `sb` (swap b): Swapped the first 2 elements at the top of stack `b`.
  - `ss`: Executed `sa` and `sb` at the same time.
  - `pa` (push a): Took the first element at the top of `b` and put it at the top of `a`.
  - `pb` (push b): Took the first element at the top of `a` and put it at the top of `b`.
  - `ra` (rotate a): Shifted up all elements of stack `a` by 1.
  - `rb` (rotate b): Shifted up all elements of stack `b` by 1.
  - `rr`: Executed `ra` and `rb` at the same time.
  - `rra` (reverse rotate a): Shifted down all elements of stack `a` by 1.
  - `rrb` (reverse rotate b): Shifted down all elements of stack `b` by 1.
  - `rrr`: Executed `rra` and `rrb` at the same time.


## Description

For this project, I needed to create a program named `push_swap` that sorted a list of integers using two stacks, called stack **a** and stack **b**. Initially, stack **a** contained a sequence of unique integers, and stack **b** was empty.
My task was to generate a minimal series of stack operations to arrange the numbers in ascending order on stack **a**.


## Key Aspects:
- Output the sequence of operations, each on its own line, that sorted the stack correctly.
- Try so the instructions were as few as possible.
- Usage of standard library functions such as `read`, `write`, `malloc`, `free`, and `exit`.
