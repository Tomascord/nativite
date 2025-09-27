# Nativite Engine

<div class="nativite-image">
  <img src="./Public/Assets/nativite-with-text.png" width="300" height="300" alt="Nativite Logo">
</div>

---

## Description

**Nativite Engine** is a bucket database engine, a new paradigm of bio-inspired databases
based on the human brain, storing data in a new way, with **Clusters**, **Buckets** and **Astructs**,
which are the main data structures.

## What is a bucket database?

in summary of what it is, Bucket database is a new paradigm of databases that 
consists of storing data in 3D vertical stacks nested in a container of containers,
Also the largest data container is Brain, This new database paradigm is bio-inspired by
the human brain, since the input is the buckets or 3D vertical stacks and the output is
the cache or terminals.

## Main Features

Its main data storage structures are:

- **Bucket Database**: The container of several brains, the equivalent of schemas 
- **Brain**: Information unit containing several clusters or neurons, the difference is
             that the clusters are not interconnected to be more parallelizable
- **Cluster**: The equivalent of the neuron, a container of several buckets
- **Bucket**: The equivalent to dendrites, a container of 3D vertical stacks of astructs which is the minimum
              unit of information,
              they can have several vertical layers
- **Terminal**: equivalent to axons, it contains an output with the most consulted structs,
                also in the stack of most used structs, the first to enter,
                last to leave the stack, Each cluster has an output box or, more simply,
                an output. It includes automatic terminal management or cache, even if the
                automatic terminal management is activated, if the user requires it, the cache
                can also be managed even if it is activated.
- **Astruct**: The minimum unit of information, it can be any type of data, a number,
               a string, a boolean, etc.

An example of what the structure would look like:

<pre>
  BucketDatabase([
    Brain([
      Cluster([
        Bucket([
          [
            *** 3D Vertical Stacks ***
            [   
              [Astruct("Hello")],
              [Astruct(12.5)],
              [Astruct(19.289389)],
              [Astruct("a")],
              [Astruct(true)],
              [Astruct(nullptr)],
              [Astruct([1, 2, 3, 4])],
              [Astruct({"name": "John", "age": 25, "other": {...}})]
            ],
            [   
              [Astruct("World")],
              [Astruct("other")],
              [Astruct(false)],
              [Astruct("empty")],
              [Astruct(true)],
              [Astruct((1, 2, 3, 4))],
              [Astruct([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])],
              [Astruct({"user": {"name": "Maria", "age": 37, "metadata": [{...}]}}})]
            ],
            *** More Stacks ***
            [
              ...
            ]
          ]
        ])
      ])
    ])
  ])
</pre>

### NOTE
3D vertical stacks do not necessarily have to be homogeneous, But in the example it
looks homogeneous just to demonstrate how the bucket database data structure
would look like.

## What problems do bucket databases solve?

The problems that bucket databases solve are:

- Data access speed:
  Since the most frequently used data is in the cache, instead of needlessly traversing the entire 3D vertical stack structure, which would be very slow, the cache is first searched, and if the data is found, it is returned. Otherwise, the buckets and clusters will need to be searched according to the suggested search algorithm.

- Better parallelization than other database engines:
  Since the clusters are not interconnected, it is more parallelizable than
  if they were connected, which can improve performance when searching all clusters
  at once with the TPS or Total-Path Search algorithm.

- Neural networks could be saved and simulated:
  Since buckets are 3D vertical stacks of data, buckets can be interconnected
  to connect neural network nodes and to model deep neural networks. Neural networks
  could also be stored in databases, not in RAM. A deep neural network can consume a lot of memory.
  and a neural database on disk would not take up gigabytes in the least, the advantage is that there
  is more space on the disk, which can be 256GB, 512GB, 1TB, 2TB, 4TB compared to RAM memory which can 
  be 8GB, 16GB, 32GB, 64GB

- New search algorithms:
  Not only is there DFS and BFS, which have always existed, there is also Flow_M 
  (a heucaritic search in clusters recursively or by breadth) and TPS 
  (a total path search in all directions, although it is slower,
  it ensures a greater probability of finding data). The advantage of TPS is that it searches all
  the clusters at once, unlike DFS, which searches each bucket one by one.

- Cache or terminals stored in CPU cache:
  By storing the terminals or caches in the CPU cache, it is much faster to access the data
  than if it were in RAM memory. Accessing the CPU cache takes between 10 and 20 ns, while RAM
  memory can take between 50 and 100 ns to access, Although they are nanoseconds, in many accesses those nanoseconds can be converted into microseconds and those microseconds into milliseconds

## Progress

The engine is in the development stages, the data structures brain, cluster, bucket, terminal,
astruct, and automatic terminal management are being developed, in the future, search algorithms authentication, http request management, data types, etc. will be implemented.

## License

This project is under the Apache License 2.0, in short what Apache License 2.0
does is a permissive license whose conditions require the preservation of copyright,
to make a fork of Nativite you have to ask the author's permission.

### Extra
- If you want to read more about Apache License 2.0, read [LICENSE.md](./LICENSE.md)

## Thanks

Thank you for your interest in Nativite Engine. If you want to support this project, you can start contributing. If you want to know in depth how Nativite Engine works, you can read the code documentation. If you want to start contributing, you must read the [CONTRIBUTING.md](./CONTRIBUTING.md) before starting to contribute to the project.

## TODO
Implement CONTRIBUTING.md

---

Copyright © 2025 Tomascord
Under **Apache License 2.0**