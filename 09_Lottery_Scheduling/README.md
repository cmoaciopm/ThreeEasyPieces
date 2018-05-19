# Chapter 9 Lottery Scheduling
## Question 1
> Compute the solutions for simulations with 3 jobs and random seeds of 1, 2, and 3.

## Question 2
> Now run with two specific jobs: each of length 10, but one (job 0)
> with just 1 ticket and the other (job 1) with 100 (e.g., -l 10:1,10:100).
> What happens when the number of tickets is so imbalanced? Will
> job 0 ever run before job 1 completes? How often? In general, what
> does such a ticket imbalance do to the behavior of lottery scheduling?

Job 0 has 1/101 chance to be scheduled, thus seldom runs before job 1.

## Question 3
> When running with two jobs of length 100 and equal ticket allocations
> of 100 (-l 100:100,100:100), how unfair is the scheduler?
> Run with some different random seeds to determine the (probabilistic)
> answer; let unfairness be determined by how much earlier one
> job finishes than the other.

This is a fair scheduler. Longer jobs have higher probability of fairness over time.

## Question 4
> How does your answer to the previous question change as the quantum
> size (-q) gets larger?

The lager the quantum tends to make it less fair.

## Question 5
> Can you make a version of the graph that is found in the chapter?
> What else would be worth exploring? How would the graph look
> with a stride scheduler?
