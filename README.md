# Linked List in C++

🚀 This repository contains **Linked List implementations and problems** in C++ for interview preparation and practice.

---

## 📌 What is a Linked List?
A **Linked List** is a linear data structure in which elements (called **nodes**) are connected using **pointers** instead of being stored in contiguous memory like arrays.  
Each node consists of:
- **Data** → the actual value
- **Next pointer** → address of the next node in the list

---

## 📂 Types of Linked Lists
1. **Singly Linked List (SLL)**  
   Each node points to the next node, and the last node points to `NULL`.

2. **Doubly Linked List (DLL)**  
   Each node has two pointers:
   - `prev` → previous node
   - `next` → next node

3. **Circular Linked List (CLL)**  
   - Last node points back to the head.
   - Can be singly or doubly circular.

---

## ✅ Advantages
- Dynamic memory allocation (no fixed size like arrays)
- Easy insertion and deletion (no shifting of elements)
- Efficient for implementing **stacks, queues, and graphs**

## ❌ Disadvantages
- More memory per node (extra pointer storage)
- Sequential access only (no direct indexing)
- Cache-unfriendly compared to arrays

---

## 📊 Time Complexity (Common Operations)

| Operation                  | Singly Linked List | Doubly Linked List |
|-----------------------------|--------------------|--------------------|
| Traversal                  | O(n)              | O(n)              |
| Insertion at Beginning      | O(1)              | O(1)              |
| Insertion at End            | O(n) (O(1) with tail pointer) | O(1) with tail pointer |
| Insertion at Nth Node       | O(n)              | O(n)              |
| Deletion at Beginning       | O(1)              | O(1)              |
| Deletion at End             | O(n)              | O(1)              |
| Deletion at Nth Node        | O(n)              | O(n)              |
| Search                      | O(n)              | O(n)              |

---

## 📝 Implemented Questions

### 🔹 Basic Operations
- [x] Insertion at the beginning (head)  
- [x] Insertion at the end (tail)  
- [x] Insertion at the Nth position  
- [x] Deletion at the beginning (head)  
- [x] Deletion at the end (tail)  
- [x] Deletion at the Nth position  

### 🔹 Intermediate Problems
- [x] Check if Linked List is a Palindrome  

### 🔹 Upcoming (To-Do 🚀)
- Reverse a Linked List (Iterative & Recursive)  
- Detect & Remove Loop in a Linked List  
- Find Middle Node  
- Merge Two Sorted Linked Lists  
- Remove Duplicates from Sorted/Unsorted Linked List  

---

## 📂 Project Structure
