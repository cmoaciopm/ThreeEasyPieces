# Chapter 14 VM API
## Question 1
> First, write a simple program called null.c that creates a pointer
> to an integer, sets it to NULL, and then tries to dereference it. Compile
> this into an executable called null. What happens when you
> run this program?

Nothing happened when running this program, it exited normally.

## Question 2
> Next, compile this program with symbol information included (with
> the -g flag). Doing so let’s put more information into the executable,
> enabling the debugger to access more useful information
> about variable names and the like. Run the program under the debugger
> by typing gdb null and then, once gdb is running, typing
> run. What does gdb show you?

No special output from gdb.

## Question 3
> Finally, use the valgrind tool on this program. We’ll use the memcheck
> tool that is a part of valgrind to analyze what happens. Run
> this by typing in the following: valgrind --leak-check=yes
> null. What happens when you run this? Can you interpret the
> output from the tool?

Below are valgrind output
```
==29991== Memcheck, a memory error detector
==29991== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==29991== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==29991== Command: ./a.out
==29991== 
==29991== 
==29991== HEAP SUMMARY:
==29991==     in use at exit: 4 bytes in 1 blocks
==29991==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==29991== 
==29991== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==29991==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29991==    by 0x40057E: main (null.c:4)
==29991== 
==29991== LEAK SUMMARY:
==29991==    definitely lost: 4 bytes in 1 blocks
==29991==    indirectly lost: 0 bytes in 0 blocks
==29991==      possibly lost: 0 bytes in 0 blocks
==29991==    still reachable: 0 bytes in 0 blocks
==29991==         suppressed: 0 bytes in 0 blocks
==29991== 
==29991== For counts of detected and suppressed errors, rerun with: -v
==29991== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Question 4
> Write a simple program that allocates memory using malloc() but
> forgets to free it before exiting. What happens when this program
> runs? Can you use gdb to find any problems with it? How about
> valgrind (again with the --leak-check=yes flag)?

Nothing happened when running this program, it exited normally.
I can not find any problem using gdb.
Below are valgrind output
```
==29809== Memcheck, a memory error detector
==29809== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==29809== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==29809== Command: ./a.out
==29809== 
==29809== 
==29809== HEAP SUMMARY:
==29809==     in use at exit: 10 bytes in 1 blocks
==29809==   total heap usage: 1 allocs, 0 frees, 10 bytes allocated
==29809== 
==29809== 10 bytes in 1 blocks are definitely lost in loss record 1 of 1
==29809==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29809==    by 0x40053E: main (q4.c:4)
==29809== 
==29809== LEAK SUMMARY:
==29809==    definitely lost: 10 bytes in 1 blocks
==29809==    indirectly lost: 0 bytes in 0 blocks
==29809==      possibly lost: 0 bytes in 0 blocks
==29809==    still reachable: 0 bytes in 0 blocks
==29809==         suppressed: 0 bytes in 0 blocks
==29809== 
==29809== For counts of detected and suppressed errors, rerun with: -v
==29809== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Question 5
> Write a program that creates an array of integers called data of size
> 100 using malloc; then, set data[100] to zero. What happens
> when you run this program? What happens when you run this
> program using valgrind? Is the program correct?

Nothing happened when running this program, it exited normally.
Below are valgrind output
```
==29796== Memcheck, a memory error detector
==29796== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==29796== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==29796== Command: ./a.out
==29796== 
==29796== Invalid write of size 4
==29796==    at 0x40058D: main (q5.c:5)
==29796==  Address 0x52041d0 is 0 bytes after a block of size 400 alloc'd
==29796==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29796==    by 0x40057E: main (q5.c:4)
==29796== 
==29796== 
==29796== HEAP SUMMARY:
==29796==     in use at exit: 0 bytes in 0 blocks
==29796==   total heap usage: 1 allocs, 1 frees, 400 bytes allocated
==29796== 
==29796== All heap blocks were freed -- no leaks are possible
==29796== 
==29796== For counts of detected and suppressed errors, rerun with: -v
==29796== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Question 6
> Create a program that allocates an array of integers (as above), frees
> them, and then tries to print the value of one of the elements of
> the array. Does the program run? What happens when you use
> valgrind on it?


Nothing happened when running this program, it exited normally.
Below are valgrind output
```
==29771== Memcheck, a memory error detector
==29771== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==29771== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==29771== Command: ./a.out
==29771== 
==29771== Invalid read of size 4
==29771==    at 0x4005E3: main (q6.c:7)
==29771==  Address 0x5204040 is 0 bytes inside a block of size 400 free'd
==29771==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29771==    by 0x4005DE: main (q6.c:6)
==29771==  Block was alloc'd at
==29771==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29771==    by 0x4005CE: main (q6.c:5)
==29771== 
The 1st element of array is 0
==29771== 
==29771== HEAP SUMMARY:
==29771==     in use at exit: 0 bytes in 0 blocks
==29771==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==29771== 
==29771== All heap blocks were freed -- no leaks are possible
==29771== 
==29771== For counts of detected and suppressed errors, rerun with: -v
==29771== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Question 7
> Now pass a funny value to free (e.g., a pointer in the middle of the
> array you allocated above). What happens? Do you need tools to
> find this type of problem?

The program exited with below error message
```
*** Error in `./a.out': free(): invalid pointer: 0x000000000256c0d8 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7f30036017e5]
/lib/x86_64-linux-gnu/libc.so.6(+0x8037a)[0x7f300360a37a]
/lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7f300360e53c]
./a.out[0x4005e5]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7f30035aa830]
./a.out[0x4004e9]
======= Memory map: ========
00400000-00401000 r-xp 00000000 08:02 32667714                           /home/agong/myGithub/ThreeEasyPieces/14_VM_API/a.out
00600000-00601000 r--p 00000000 08:02 32667714                           /home/agong/myGithub/ThreeEasyPieces/14_VM_API/a.out
00601000-00602000 rw-p 00001000 08:02 32667714                           /home/agong/myGithub/ThreeEasyPieces/14_VM_API/a.out
0256c000-0258d000 rw-p 00000000 00:00 0                                  [heap]
7f2ffc000000-7f2ffc021000 rw-p 00000000 00:00 0 
7f2ffc021000-7f3000000000 ---p 00000000 00:00 0 
7f3003374000-7f300338a000 r-xp 00000000 08:02 58986883                   /lib/x86_64-linux-gnu/libgcc_s.so.1
7f300338a000-7f3003589000 ---p 00016000 08:02 58986883                   /lib/x86_64-linux-gnu/libgcc_s.so.1
7f3003589000-7f300358a000 rw-p 00015000 08:02 58986883                   /lib/x86_64-linux-gnu/libgcc_s.so.1
7f300358a000-7f300374a000 r-xp 00000000 08:02 58982572                   /lib/x86_64-linux-gnu/libc-2.23.so
7f300374a000-7f300394a000 ---p 001c0000 08:02 58982572                   /lib/x86_64-linux-gnu/libc-2.23.so
7f300394a000-7f300394e000 r--p 001c0000 08:02 58982572                   /lib/x86_64-linux-gnu/libc-2.23.so
7f300394e000-7f3003950000 rw-p 001c4000 08:02 58982572                   /lib/x86_64-linux-gnu/libc-2.23.so
7f3003950000-7f3003954000 rw-p 00000000 00:00 0 
7f3003954000-7f300397a000 r-xp 00000000 08:02 58982570                   /lib/x86_64-linux-gnu/ld-2.23.so
7f3003b5c000-7f3003b5f000 rw-p 00000000 00:00 0 
7f3003b78000-7f3003b79000 rw-p 00000000 00:00 0 
7f3003b79000-7f3003b7a000 r--p 00025000 08:02 58982570                   /lib/x86_64-linux-gnu/ld-2.23.so
7f3003b7a000-7f3003b7b000 rw-p 00026000 08:02 58982570                   /lib/x86_64-linux-gnu/ld-2.23.so
7f3003b7b000-7f3003b7c000 rw-p 00000000 00:00 0 
7ffe3450a000-7ffe3452b000 rw-p 00000000 00:00 0                          [stack]
7ffe34536000-7ffe34539000 r--p 00000000 00:00 0                          [vvar]
7ffe34539000-7ffe3453b000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
Aborted (core dumped)
```

Below are valgrind output
```
==29891== Memcheck, a memory error detector
==29891== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==29891== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==29891== Command: ./a.out
==29891== 
==29891== Invalid free() / delete / delete[] / realloc()
==29891==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29891==    by 0x4005E4: main (q7.c:6)
==29891==  Address 0x5204108 is 200 bytes inside a block of size 400 alloc'd
==29891==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29891==    by 0x4005CE: main (q7.c:5)
==29891== 
==29891== Conditional jump or move depends on uninitialised value(s)
==29891==    at 0x4E87B83: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
==29891== Use of uninitialised value of size 8
==29891==    at 0x4E8476B: _itoa_word (_itoa.c:179)
==29891==    by 0x4E8812C: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
==29891== Conditional jump or move depends on uninitialised value(s)
==29891==    at 0x4E84775: _itoa_word (_itoa.c:179)
==29891==    by 0x4E8812C: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
==29891== Conditional jump or move depends on uninitialised value(s)
==29891==    at 0x4E881AF: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
==29891== Conditional jump or move depends on uninitialised value(s)
==29891==    at 0x4E87C59: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
==29891== Conditional jump or move depends on uninitialised value(s)
==29891==    at 0x4E8841A: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
==29891== Conditional jump or move depends on uninitialised value(s)
==29891==    at 0x4E87CAB: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
==29891== Conditional jump or move depends on uninitialised value(s)
==29891==    at 0x4E87CE2: vfprintf (vfprintf.c:1631)
==29891==    by 0x4E8F898: printf (printf.c:33)
==29891==    by 0x4005FB: main (q7.c:7)
==29891== 
The 1st element of array is 0
==29891== 
==29891== HEAP SUMMARY:
==29891==     in use at exit: 400 bytes in 1 blocks
==29891==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==29891== 
==29891== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==29891==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29891==    by 0x4005CE: main (q7.c:5)
==29891== 
==29891== LEAK SUMMARY:
==29891==    definitely lost: 400 bytes in 1 blocks
==29891==    indirectly lost: 0 bytes in 0 blocks
==29891==      possibly lost: 0 bytes in 0 blocks
==29891==    still reachable: 0 bytes in 0 blocks
==29891==         suppressed: 0 bytes in 0 blocks
==29891== 
==29891== For counts of detected and suppressed errors, rerun with: -v
==29891== Use --track-origins=yes to see where uninitialised values come from
==29891== ERROR SUMMARY: 10 errors from 10 contexts (suppressed: 0 from 0)
```

## Question 8
> Try out some of the other interfaces to memory allocation. For example,
> create a simple vector-like data structure and related routines
> that use realloc() to manage the vector. Use an array to
> store the vectors elements; when a user adds an entry to the vector,
> use realloc() to allocate more space for it. How well does
> such a vector perform? How does it compare to a linked list? Use
> valgrind to help you find bugs.

## Question 9
> Spend more time and read about using gdb and valgrind. Knowing
> your tools is critical; spend the time and learn how to become
> an expert debugger in the UNIX and C environment.
