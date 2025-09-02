# 📑 Cheatsheets

> This article is a collection of **cheat sheets** you can use while solving problems and preparing for interviews.

You will find:
- ✅ Time complexity (Big O) cheat sheet
- ✅ General DS/A flowchart (when to use each DS/A)
- ✅ Stages of an interview cheat sheet

---

.                                                  ⏱️ Time Complexity (Big O) Cheat Sheet


=> Arrays (Dynamic Array / List)

Let  n = arr.length 

- Add/remove element at end   ------> O(1) (amortized)
- Add/remove element at arbitrary index   ------> O(n) <------ 
- Access/modify element at arbitrary index   ------> O(1) <------ 
- Check if element exists   ------> O(n) <------ 
- Two pointers (sliding window)   ------> O(n·k) <------   
  (k = work per iteration)
- Build prefix sum   ------> O(n) <------ 
- Get subarray sum from prefix sum   ------> O(1) <------ 

---

=> Strings (Immutable)

Let  n = s.length 

- Add/remove character   ------> O(n) <------ 
- Access element at index   ------> O(1) <------ 
- Concatenation (length n + m)   ------> O(n+m) <------ 
- Create substring (length m)   ------> O(m) <------ 
- Two pointers   ------> O(n·k) <------ 
- Build string (join/str builder)   ------> O(n) <------ 

---

=> Linked Lists
Let  n = number of nodes 

- Add/remove with pointer (before location)   ------> O(1) <------ 
- Add/remove with pointer (at location, DLL)   ------> O(1) <------ 
- Add/remove without pointer   ------> O(n) <------ 
- Access element without pointer   ------> O(n) <------ 
- Check if element exists   ------> O(n) <------ 
- Reverse between i and j   ------> O(j−i) <------ 
- Detect cycle (fast-slow pointers/hash)   ------> O(n) <------ 

---

=> Hash Table / Dictionary
Let  n = dic.length 

- Add/remove key-value   ------> O(1) <------ 
- Check if key exists   ------> O(1) <------ 
- Check if value exists   ------> O(n) <------ 
- Access/modify by key   ------> O(1) <------ 
- Iterate over keys/values   ------> O(n) <------ 

💡 Note: hashing string keys costs  ------> O(m) <------  where  m = length of string .

---

=> Set
Let  n = set.length 

- Add/remove element   ------> O(1) <------ 
- Check if element exists   ------> O(1) <------ 

(Same note as hash table applies.)

---

=> Stack (Dynamic Array Implementation)
Let  n = stack.length 

- Push   ------> O(1) <------ 
- Pop   ------> O(1) <------ 
- Peek (top element)   ------> O(1) <------ 
- Access element at index   ------> O(1) <------ 
- Check if element exists   ------> O(n) <------ 

---

=> Queue (Doubly Linked List Implementation)
Let  n = queue.length 

- Enqueue   ------> O(1) <------ 
- Dequeue   ------> O(1) <------ 
- Peek (front element)   ------> O(1) <------ 
- Access element at index   ------> O(n) <------ 
- Check if element exists   ------> O(n) <------ 

---

=> Binary Tree (DFS/BFS)
Let  n = number of nodes 

- Most algorithms   ------> O(n·k) <------   
  where  k = work per node , usually  ------> O(1) <------ .  
- BFS requires efficient queue.

---

=> Binary Search Tree
Let  n = nodes 

- Insert/remove   ------> O(log n) <------  avg,  ------> O(n) <------  worst
- Check if exists   ------> O(log n) <------  avg,  ------> O(n) <------  worst

💡 Balanced tree  average case.  
Unbalanced  worst case (like linked list).

---

=> Heap / Priority Queue
Let  n = heap.length 

- Insert element   ------> O(log n) <------ 
- Delete min/max   ------> O(log n) <------ 
- Find min/max   ------> O(1) <------ 
- Check if element exists   ------> O(n) <------ 

---

=> Binary Search
- Runs in  ------> O(log n) <------  worst case.

---

=> Miscellaneous
- Sorting   ------> O(n log n) <------ 
- DFS/BFS on graph   ------> O(n·k + e) <------   
  ( n = nodes ,  e = edges )
- DFS/BFS space   ------> O(n) <------  or  ------> O(n+e) <------  (graph storage)
- Dynamic Programming   
  - Time:  ------> O(n·k) <------  (n = states, k = work/state)  
  - Space:  ------> O(n) <------  (for storing states)

---

## 📊 Input Size vs Time Complexity

- **n ≤ 10**  factorial/exponential possible (e.g., backtracking).
- **10 < n ≤ 20**   ------> O(2^n) <------  acceptable.
- **20 < n ≤ 100**  up to  ------> O(n³) <------  okay.
- **100 < n ≤ 1000**  usually  ------> O(n²) <------  optimal.
- **1,000 < n ≤ 100,000**  must aim for  ------> O(n log n) <------  or  ------> O(n) <------ .
- **100,000 < n ≤ 1,000,000**  usually  ------> O(n) <------  or optimized  ------> O(n log n) <------ .
- **n ≥ 1,000,000**  need  ------> O(log n) <------  or  ------> O(1) <------ .

👉 Input constraints are **hints**. Always ask about them in interviews.

---

## 🔀 Sorting Algorithms (Quick Reference)

- Built-in sorts (Python: Timsort, C++: unspecified)   ------> O(n log n) <------ 
- Stable sort = maintains relative order of equal elements.

Sorting Algorithms Complexity Table

Algorithm        Best Case    Average Case  Worst Case   Space   Stable

Quicksort        O(n log n)   O(n log n)    O(n^2)       O(log n)  No
Merge Sort       O(n log n)   O(n log n)    O(n log n)   O(n)      Yes
Heapsort         O(n log n)   O(n log n)    O(n log n)   O(1)      No
Timsort          O(n)         O(n log n)    O(n log n)   O(n)      Yes
Bubble Sort      O(n)         O(n^2)        O(n^2)       O(1)      Yes
Insertion Sort   O(n)         O(n^2)        O(n^2)       O(1)      Yes
Selection Sort   O(n^2)       O(n^2)        O(n^2)       O(1)      No*
Shellsort        O(n log n)   Depends       O(n^2)       O(1)      No
Bucket Sort      O(n+k)       O(n+k)        O(n^2)       O(n+k)    Yes
Radix Sort       O(nk)        O(nk)         O(nk)        O(n+k)    Yes
Counting Sort    O(n+k)       O(n+k)        O(n+k)       O(k)      Yes

*Selection sort can be modified to be stable, but at the cost of efficiency.

📌 Example:  
If two records  R  and  S  have the same key, and  R  came before  S  in the input, then after sorting,  R  will still come before  S .

---

## 🗂️ General DS/A Flowchart

> A flowchart to help decide **which DS/Algo to use**.  
(Can t cover all cases, but good for quick reference.)

Problem-Solving Strategy Flowchart

Start
|
|-- Is input sorted?
|     |
|     |-- Yes --> Binary Search
|     |             |
|     |             --> Two Pointers (if pair/sum search)
|     |
|     |-- No --> Question is asking for...
|               |
|               |-- ALL of something --> Backtracking
|               |
|               |-- Number of ways / Max-Min of something
|               |        |
|               |        |-- Decisions affected by other decisions?
|               |                 |
|               |                 |-- Yes --> Dynamic Programming
|               |                 |-- No  --> Greedy
|               |
|               |-- Is something possible? --> Trie (Prefix Matching)
|               |
|               |-- String building / Distance --> Stack or Monotonic Stack
|               |
|               |-- Finding a specific element --> HashMap or Set
|               |
|               |-- Elements added/removed in sliding window fashion
|                        |
|                        |-- Continuously find max/min --> Monotonic Queue
|                        |-- Subarrays / substrings     --> Sliding Window / Count Map
|                        |-- Max/Min continuously removed --> Heap
|
--> Final Step: Think holistically before choosing an approach.

💡 Covers common methods (advanced like Dijkstra not included here).

---

## 🧑‍💻 Interview Stages Cheat Sheet (Condensed)

**Stage 1: Introductions**  
- Prepare a **30-60 sec intro**.  
- Smile & speak confidently.  
- Pay attention to interviewer s intro  reuse in questions.

**Stage 2: Problem Statement**  
- Paraphrase problem back.  
- Ask clarifying questions (inputs, edge cases, size).  
- Walk through an example test case.

**Stage 3: Brainstorming DS&A**  
- Think out loud.  
- Break down problem & identify DS/A.  
- Be receptive to hints.  
- Explain approach before coding.

**Stage 4: Implementation**  
- Explain reasoning while coding.  
- Follow language conventions, write clean code.  
- Avoid duplication (use helpers).  
- If stuck  communicate.  
- Start brute force  optimize later.

**Stage 5: Testing & Debugging**  
- Walk through test cases.  
- Track variable updates.  
- Use print statements if errors.  
- Be vocal during debugging.

**Stage 6: Explanations & Follow-ups**  
- Be ready for: time/space complexity, reasoning behind DS/A choice, and possible optimizations.  
- Don t claim optimal unless certain.

**Stage 7: Outro**  
- Prepare questions for interviewer (work, company culture, projects).  
- Stay interested & positive.

---

# ✅ Final Notes
- Keep this as a **quick reference during prep or remote interviews**.  
- Focus on **clarity, confidence, and collaboration**.  
