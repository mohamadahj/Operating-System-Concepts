# Operating-System-Concepts
# Merge two sorted arrays using shared memory

The main.c inputs two arrays with the size of m and n. Then it puts them in shared memory with the name of M and N. Then, it creates a shared memory R with the size of m+n.
Then it creates n+m processes with the type of merger. Then merger.c merges two arrays, and main.c prints R and removes the shared memories.
