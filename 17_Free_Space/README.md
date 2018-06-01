# Chapter 17 Free-Space Management
## Question 1
> First run with the flags -n 10 -H 0 -p BEST -s 0 to generate
> a few random allocations and frees. Can you predict what alloc()/free()
> will return? Can you guess the state of the free list after
> each request? What do you notice about the free list over time?

./malloc.py -n 10 -H 0 -p BEST -s 0
```
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList
compute True

ptr[0] = Alloc(3)  returned 1000 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1003 sz:97 ]

Free(ptr[0]) returned 0
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:97 ]

ptr[1] = Alloc(5)  returned 1003 (searched 2 elements)
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1008 sz:92 ]

Free(ptr[1]) returned 0
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:92 ]

ptr[2] = Alloc(8)  returned 1008 (searched 3 elements)
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[2]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[3] = Alloc(8)  returned 1008 (searched 4 elements)
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[3]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[4] = Alloc(2)  returned 1000 (searched 4 elements)
Free List [ Size 4 ]:  [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[5] = Alloc(7)  returned 1008 (searched 4 elements)
Free List [ Size 4 ]:  [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1015 sz:1 ] [ addr:1016 sz:84 ]
```

## Question 2
> How are the results different when using a WORST fit policy to
> search the free list (-p WORST)? What changes?

./malloc.py -n 10 -H 0 -p WORST -s 0
```
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy WORST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList
compute True

ptr[0] = Alloc(3)  returned 1000 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1003 sz:97 ]

Free(ptr[0]) returned 0
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:97 ]

ptr[1] = Alloc(5)  returned 1003 (searched 2 elements)
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1008 sz:92 ]

Free(ptr[1]) returned 0
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:92 ]

ptr[2] = Alloc(8)  returned 1008 (searched 3 elements)
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[2]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[3] = Alloc(8)  returned 1016 (searched 4 elements)
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1024 sz:76 ]

Free(ptr[3]) returned 0
Free List [ Size 5 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:8 ] [ addr:1024 sz:76 ]

ptr[4] = Alloc(2)  returned 1024 (searched 5 elements)
Free List [ Size 5 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:8 ] [ addr:1026 sz:74 ]

ptr[5] = Alloc(7)  returned 1026 (searched 5 elements)
Free List [ Size 5 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:8 ] [ addr:1033 sz:67 ]
```

## Question 3
> What about when using FIRST fit (-p FIRST)? What speeds up
> when you use first fit?

./malloc.py -n 10 -H 0 -p FIRST -s 0
```
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList
compute True

ptr[0] = Alloc(3)  returned 1000 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1003 sz:97 ]

Free(ptr[0]) returned 0
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:97 ]

ptr[1] = Alloc(5)  returned 1003 (searched 2 elements)
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1008 sz:92 ]

Free(ptr[1]) returned 0
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:92 ]

ptr[2] = Alloc(8)  returned 1008 (searched 3 elements)
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[2]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[3] = Alloc(8)  returned 1008 (searched 3 elements)
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[3]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[4] = Alloc(2)  returned 1000 (searched 1 elements)
Free List [ Size 4 ]:  [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[5] = Alloc(7)  returned 1008 (searched 3 elements)
Free List [ Size 4 ]:  [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1015 sz:1 ] [ addr:1016 sz:84 ]
```

## Question 4
> For the above questions, how the list is kept ordered can affect the
> time it takes to find a free location for some of the policies. Use
> the different free list orderings (-l ADDRSORT, -l SIZESORT+,
> -l SIZESORT-) to see how the policies and the list orderings interact.

## Question 5
> Coalescing of a free list can be quite important. Increase the number
> of random allocations (say to -n 1000). What happens to larger
> allocation requests over time? Run with and without coalescing
> (i.e., without and with the -C flag). What differences in outcome do
> you see? How big is the free list over time in each case? Does the
> ordering of the list matter in this case?

## Question 6
> What happens when you change the percent allocated fraction -P
> to higher than 50? What happens to allocations as it nears 100?
> What about as it nears 0?

## Question 7
> What kind of specific requests can you make to generate a highlyfragmented
> free space? Use the -A flag to create fragmented free
> lists, and see how different policies and options change the organization
> of the free list.

./malloc.py -S 15 -A +1,+2,+3,+4,+5,-0,-1,-2,-3,-4
```
seed 0
size 15
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList +1,+2,+3,+4,+5,-0,-1,-2,-3,-4
compute True

ptr[0] = Alloc(1)  returned 1000 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1001 sz:14 ]

ptr[1] = Alloc(2)  returned 1001 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1003 sz:12 ]

ptr[2] = Alloc(3)  returned 1003 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1006 sz:9 ]

ptr[3] = Alloc(4)  returned 1006 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1010 sz:5 ]

ptr[4] = Alloc(5)  returned 1010 (searched 1 elements)
Free List [ Size 0 ]:

Free(ptr[0]) returned 0
Free List [ Size 1 ]:  [ addr:1000 sz:1 ]

Free(ptr[1]) returned 0
Free List [ Size 2 ]:  [ addr:1000 sz:1 ] [ addr:1001 sz:2 ]

Free(ptr[2]) returned 0
Free List [ Size 3 ]:  [ addr:1000 sz:1 ] [ addr:1001 sz:2 ] [ addr:1003 sz:3 ]

Free(ptr[3]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:1 ] [ addr:1001 sz:2 ] [ addr:1003 sz:3 ] [ addr:1006 sz:4 ]

Free(ptr[4]) returned 0
Free List [ Size 5 ]:  [ addr:1000 sz:1 ] [ addr:1001 sz:2 ] [ addr:1003 sz:3 ] [ addr:1006 sz:4 ] [ addr:1010 sz:5 ]
```
