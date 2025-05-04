# Prefix and Postfix Expression Evaluator Using Linked Stash

## Objective 

The purpose of this project is to build a C program that can **evaluate prefix and postfix mathematical expressions** entered by the user. The program detects the type of expression (prefix or postfix), parses it, and calculates the result using a **linked list-based stack** (referred to as a "linked stash" in this context).
---

## Key Concepts Used

- **Prefix and Postfix Notation**:
  - **Prefix**: Operator comes before the operands (e.g., `+ 2 3`)
  - **Postfix**: Operator comes after the operands (e.g., `2 3 +`)
- **Linked Stack (Stash)**:
  - A dynamic stack implementation using linked list nodes.
  - Supports basic operations: `push()`, `pop()`, and stack memory cleanup.

## Implementation Overview


###  Input Handling
- The user is prompted to input a prefix or postfix expression.
- The input is accepted as a string using `fgets`.

###  Expression Type Detection
- The program examines the first and last non-space characters.
  - If the first character is an operator: it's assumed to be **prefix**.
  - If the last character is an operator: it's assumed to be **postfix**.

###  Stack (Stash) Operations
- The linked stash uses dynamically allocated nodes.
- Each node stores an integer value and a pointer to the next node.
- Pushing and popping operations are used to evaluate expressions step-by-step.

###  Evaluation Process
- **For postfix**:
  1. Read left to right.
  2. Push operands to the stack.
  3. On encountering an operator, pop two operands, apply the operator, and push the result back.
- **For prefix**:
  1. Read right to left.
  2. Push operands to the stack.
  3. On encountering an operator, pop two operands, apply the operator, and push the result back.

###  Supported Operators
- `+` Addition  
- `-` Subtraction  
- `*` Multiplication  
- `/` Division  
- `^` Exponentiation  

---

## 🔢 Sample Problems


<img width="453" alt="Screenshot 2025-05-04 at 9 37 40 PM" src="https://github.com/user-attachments/assets/49dd1322-4b1a-4fff-aa1c-d71b0091edc5" />

## Advantages

- Supports dynamic expression input.
- Avoids fixed expression selection — user inputs their own expression.
- Efficient use of dynamic memory via linked stash.
- Can be extended to handle:
  - Multi-digit numbers
  - Variables
  - Floating-point operations

---

## Conclusion

This project effectively demonstrates how to evaluate mathematical expressions in prefix and postfix notation using a linked list-based stack in C. It handles user input dynamically, ensuring flexibility and adaptability. The use of a linked stash ensures memory efficiency and avoids overflow issues inherent to array-based stacks.
