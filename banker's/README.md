# Operating-System-Concepts
# Banker's Algorithm

# Available : 

It is a 1-d array of size ‘m’ indicating the number of available resources of each type.
Available[ j ] = k means there are ‘k’ instances of resource type Rj

# Max :

It is a 2-d array of size ‘n*m’ that defines the maximum demand of each process in a system.
Max[ i, j ] = k means process Pi may request at most ‘k’ instances of resource type Rj.

# Allocation :

It is a 2-d array of size ‘n*m’ that defines the number of resources of each type currently allocated to each process.
Allocation[ i, j ] = k means process Pi is currently allocated ‘k’ instances of resource type Rj

# Need :

 It is a 2-d array of size ‘n*m’ that indicates the remaining resource need of each process.
Need [ i,   j ] = k means process Pi currently need ‘k’ instances of resource type Rj
for its execution.

Need [ i,   j ] = Max [ i,   j ] – Allocation [ i,   j ]

Given that assumption, the algorithm determines if a state is safe by trying to find a hypothetical set of requests by the processes that would allow each to acquire its maximum resources and then terminate (returning its resources to the system). Any state where no such set exists is an unsafe state.


We can show that the state given in the previous example is a safe state by showing that it is possible for each process to acquire its maximum resources and then terminate.

P1 needs 2 A, 1 B and 1 D more resources, achieving its maximum
[available resource: <3 1 1 2> - <2 1 0 1> = <1 0 1 1>]
The system now still has 1 A, no B, 1 C and 1 D resource available
P1 terminates, returning 3 A, 3 B, 2 C and 2 D resources to the system
[available resource: <1 0 1 1> + <3 3 2 2> = <4 3 3 3>]
The system now has 4 A, 3 B, 3 C and 3 D resources available
P2 acquires 2 B and 1 D extra resources, then terminates, returning all its resources
[available resource: <4 3 3 3> - <0 2 0 1> + <1 2 3 4> = <5 3 6 6>]
The system now has 5 A, 3 B, 6 C and 6 D resources
P3 acquires 1 B and 4 C resources and terminates.
[available resource: <5 3 6 6> - <0 1 4 0> + <1 3 5 0> = <6 5 7 6>]
The system now has all resources: 6 A, 5 B, 7 C and 6 D
Because all processes were able to terminate, this state is safe
