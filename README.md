# Task Processing System — C

## Overview
This project demonstrates processing tasks using FIFO, where tasks are processed in the order they were added.

## Features
- Add tasks with an ID and name.
- View the next task without removing it.
- Process tasks in FIFO order.
- Handle empty queues.
- Handle memory allocation failures.
- Reject task names that exceed the available storage.

## Implementation
For this project I used a linked-list queue (a sequence of nodes connected by pointers) I can essentially add as many tasks without an explicit cap. What makes this a queue is the  implementation of the first (front) and last (rear) nodes as a structure.

## What I Learned
- What FIFO looks like in actual scenarios.
- How Dynamic memory works and how it looks like without a cap.
- How to use pointers and how to clean up memory.

## Limitations
- Task names can only be up to 19 characters
- The program execution itself isn't saved after program ends.
- It's only a stimulation. No real-world execution is actually being done.
