# 🔢 push_swap

push_swap is a sorting algorithm project from the 42 curriculum.  
The goal is to sort a stack of integers using a limited set of operations and the smallest number of moves possible.

---

## 🎥 Algorithm Demonstration

Visualization of the **Two-Phase Chunk Sort algorithm** sorting **500 randomly generated numbers**.

[Bildschirmaufzeichnung vom 2026-03-11 17-14-58.webm](https://github.com/user-attachments/assets/84d85988-3750-4ea5-8cd9-a941fd38d490)

---

## 📖 About the Project

The program receives a list of integers as arguments and sorts them using two stacks:

- **Stack A**
- **Stack B**

Only specific stack operations are allowed. The program outputs the sequence of operations needed to sort the numbers.

This project focuses on:

- Algorithm design
- Optimization
- Data structures (stacks)
- Complexity analysis

---

## ⚙️ Allowed Operations

- `sa` – swap the first two elements of stack A  
- `sb` – swap the first two elements of stack B  
- `ss` – `sa` and `sb` at the same time  

- `pa` – push the top element from B to A  
- `pb` – push the top element from A to B  

- `ra` – rotate stack A  
- `rb` – rotate stack B  
- `rr` – `ra` and `rb` at the same time  

- `rra` – reverse rotate stack A  
- `rrb` – reverse rotate stack B  
- `rrr` – `rra` and `rrb` at the same time  

---

## 🧠 Sorting Algorithm

This implementation uses a custom algorithm that can be described as **Two-Phase Chunk Sort**.

### Phase 1 – Rough Sort (A → B)

The unsorted numbers are divided into **chunks of 50 smallest elements**.  
The algorithm scans **from both the top and bottom of stack A** to find the element that requires the fewest moves.  
Elements are pushed to **stack B** in chunk order, resulting in a **roughly sorted descending stack B**.

### Phase 2 – Final Sort (B → A)

Stack B is processed in **chunks of 50 largest elements**.  
For each chunk, the algorithm evaluates candidates from **both ends of stack B** and calculates the total cost:

- moves needed in stack B
- insertion cost in stack A

The element with the **lowest total cost** is selected and inserted into the correct position in stack A.

The insertion logic works as follows:

- If the number is **smaller than all elements**, it is inserted after the smallest element  
- If it is **larger than all elements**, it is also inserted after the smallest element (wrap-around)  
- Otherwise, it is inserted **between the two correct elements**

This approach reduces unnecessary rotations and minimizes the total number of operations.

---

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/Mert5558/push_swap.git
cd push_swap
```

Compile the project:

```bash
make
```

---

## 🚀 Usage

Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

The program outputs the operations required to sort the stack.

Example:

```
pb
ra
pb
sa
pa
pa
```

---
