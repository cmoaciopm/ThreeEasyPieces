# Chapter 8 MLFQ Scheduling
## Question 1
> Run a few randomly-generated problems with just two jobs and
> two queues; compute the MLFQ execution trace for each. Make
> your life easier by limiting the length of each job and turning off
> I/Os.

./mlfq.py -s 3 -n 2 -j 2 -m 10 -M 0 -c

```
Job List:
  Job  0: startTime   0 - runTime   3 - ioFreq   0
  Job  1: startTime   0 - runTime   4 - ioFreq   0


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] JOB BEGINS by JOB 1
[ time 0 ] Run JOB 0 at PRIORITY 1 [ TICKSLEFT 9 RUNTIME 3 TIMELEFT 2 ]
[ time 1 ] Run JOB 0 at PRIORITY 1 [ TICKSLEFT 8 RUNTIME 3 TIMELEFT 1 ]
[ time 2 ] Run JOB 0 at PRIORITY 1 [ TICKSLEFT 7 RUNTIME 3 TIMELEFT 0 ]
[ time 3 ] FINISHED JOB 0
[ time 3 ] Run JOB 1 at PRIORITY 1 [ TICKSLEFT 9 RUNTIME 4 TIMELEFT 3 ]
[ time 4 ] Run JOB 1 at PRIORITY 1 [ TICKSLEFT 8 RUNTIME 4 TIMELEFT 2 ]
[ time 5 ] Run JOB 1 at PRIORITY 1 [ TICKSLEFT 7 RUNTIME 4 TIMELEFT 1 ]
[ time 6 ] Run JOB 1 at PRIORITY 1 [ TICKSLEFT 6 RUNTIME 4 TIMELEFT 0 ]
[ time 7 ] FINISHED JOB 1

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround   3
  Job  1: startTime   0 - response   3 - turnaround   7

  Avg  1: startTime n/a - response 1.50 - turnaround 5.00
```

## Question 2
> How would you run the scheduler to reproduce each of the examples
> in the chapter?

1. Figure 8.2: ./mlfq.py -n 3 -j 1 -l 0,200,0
2. Figure 8.3: ./mlfq.py -n 3 -j 2 -l 0,200,0:100,20,0
3. Figure 8.4: ./mlfq.py -n 3 -j 2 -l 0,200,0:50,20,1 -i 10
4. Figure 8.5:
..* Without Priority Boost: ./mlfq.py -n 3 -j 3 -S -l 0,200,0:100,50,5:100,50,5 -i 5
..* With Priority Boost:  ./mlfq.py -n 3 -j 3 -S -B 50 -l 0,200,0:100,50,5:100,50,5 -i 5
5. Figure 8.6: 
..* Without Gaming Tolerance: ./mlfq.py -n 3 -j 2 -q 10 -S -l 0,200,0:80,100,9 -i 1
..* With Gaming Tolerance: Remove -S of above command
6. Figure 8.7: ./mlfq.py -n 3 -j 2 -Q 10,20,40 -l 0,100,0:0,100,0

## Question 3
> How would you configure the scheduler parameters to behave just
> like a round-robin scheduler?

Use one queue only. ./mlfq.py -n 1 -M 0 -s 1

## Question 4
> Craft a workload with two jobs and scheduler parameters so that
> one job takes advantage of the older Rules 4a and 4b (turned on
> with the -S flag) to game the scheduler and obtain 99% of the CPU
> over a particular time interval.

./mlfq.py -n 3 -j 2 -q 100 -S -l 0,1000,0:500,300,99 -i 1

## Question 5
> Given a system with a quantum length of 10 ms in its highest queue,
> how often would you have to boost jobs back to the highest priority
> level (with the -B flag) in order to guarantee that a single longrunning
> (and potentially-starving) job gets at least 5% of the CPU?

200ms

## Question 6
> One question that arises in scheduling is which end of a queue to
> add a job that just finished I/O; the -I flag changes this behavior
> for this scheduling simulator. Play around with some workloads
> and see if you can see the effect of this flag.
