# Chapter 7 Homework

## Question 1
> Compute the response time and turnaround time when running
> three jobs of length 200 with the SJF and FIFO schedulers

FIFO scheduler
Turnaround time = (200 + 400 + 600)/3 = 400
Response time = (0 + 200 + 400)/3 = 200

SJF scheduler
Turnaround time = (200 + 400 + 600)/3 = 400
Response time = (0 + 200 + 400)/3 = 200

## Question 2
> Now do the same but with jobs of different lengths: 100, 200, and 300.

FIFO scheduler
Turnaround time = (100 + 300 + 600)/3 = 333
Response time = (0 + 100 + 300)/3 = 133

SJF scheduler
Turnaround time = (100 + 300 + 600)/3 = 333
Response time = (0 + 100 + 200)/3 = 133

## Question 3
> Now do the same, but also with the RR scheduler and a time-slice of 1

Turnaround time = (300 + 500 + 600)/3 = 466
Response time = (0 + 1 + 2)/3 = 1

## Question 4
> For what types of workloads does SJF deliver the same turnaround times as FIFO?

Jobs with same length will have the same turnaround times.

## Question 5
> For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

Jobs which workload(length) is same as quantum.

## Question 6
> What happens to response time with SJF as job lengths increase?
> Can you use the simulator to demonstrate the trend?

As job length increases, response time with SJF will increase accordingly.

## Question 7
> What happens to response time with RR as quantum lengths increase?
> Can you write an equation that gives the worst-case response
> time, given N jobs?

The response time will increase when quantum length increases.
