### Operating Systems Assignment #1 (Ariel University 2024B)

---

**Question 1: Compilation and Debugging in Linux**
- **Explanation:** This question evaluates the ability to compile and debug code in a Unix environment using tools like **gdb** and **ddd**.
- **Skills Required:** Understanding of compilation flags like **-g**, **debugging commands** like print, where, break, etc.
- **Work Done:** Implemented debugging scenarios including browsing from the stack, division by zero, and accessing undefined memory. Used gdb and ddd to **analyze core dumps and debug code**.

---

**Question 2: Using the Mathematical Library**
- **Explanation:** This question focuses on **utilizing mathematical libraries** in C to perform computations.
- **Skills Required:** Understanding of mathematical functions, usage of libraries like math.h, knowledge of compilation flags like -lm.
- **Work Done:** Developed a program to calculate the probability of a **Poisson distribution** using the expf function from the math library. Ensured proper handling of command-line arguments and precision.

---

**Question 3: Building a Library**
- **Explanation:** This question evaluates the creation and utilization of **dynamic libraries** in Unix environments.
- **Skills Required:** Knowledge of creating shared objects (**.so files**), familiarity with linking libraries during compilation.
- **Work Done:** Implemented a function to calculate the **Poisson distribution** and compiled it into a dynamic library (libpoisson.so). Wrote a program to use this library and compute Poisson distributions for given values of lambda and k.

---

**Question 4: Code Coverage**
- **Explanation:** This question assesses understanding of **code coverage and testing methodologies** using tools like **gcov**.
- **Skills Required:** Knowledge of **Dijkstra's algorithm**, understanding of input validation, familiarity with code coverage tools like gcov.
- **Work Done:** Modified Dijkstra's algorithm implementation to support input from stdin. Designed test cases to cover various scenarios and used gcov to analyze code coverage. Ensured correctness of the algorithm and input validation.

---

**Question 5: Profiling**
- **Explanation:** This question evaluates the ability to **profile code and analyze performance using tools like gprof**.
- **Skills Required:** Understanding of algorithms' **time complexity**, proficiency in profiling tools like gprof.
- **Work Done:** Implemented three solutions for the **max sub-array sum problem** and profiled their performance. Generated random inputs for different input sizes and analyzed algorithmic efficiency.

---

**Question 6: Creating Processes and Pipes**
- **Explanation:** This question tests the understanding of **process creation and communication using pipes** in Unix environments.
- **Skills Required:** Knowledge of **fork**, **execve**, and **pipe** system calls, understanding of **file descriptors**.
- **Work Done:** Developed programs to **add entries to a phonebook** and **find phone** numbers using processes and pipes. Utilized commands like **cat**, **grep**, **awk**, **sed** for text processing. Ensured proper handling of input/output and process communication.
