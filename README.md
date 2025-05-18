# 📁 push_swap

## 📌 goal

sort a stack of integers with the smallest number of operations using two stacks and a limited set of allowed moves.

> *Why use standard sorting algorithms when you can suffer creatively?*

---

## 🧠 concept

you are given a stack of integers (stack A).  
your task is to sort it using:

- a second stack (stack B)
- only these operations:
  - `sa`, `sb`, `ss`
  - `pa`, `pb`
  - `ra`, `rb`, `rr`
  - `rra`, `rrb`, `rrr`

each operation must be printed as output.

---

## usage

```bash
make
./push_swap 3 2 1 6 5
```

---



# 📁 minitalk

## 📌 goal

create a simple messaging system using UNIX signals.

---

## 🧠 concept

send strings from a client to a server using only:

- `SIGUSR1` and `SIGUSR2`  
- bitwise logic  
- manual buffering

---

## how it works

- each bit of a character is sent as a signal from client to server
- the server rebuilds characters one bit at a time
- a confirmation signal (ACK) is sent after each bit is received

---

## compile

```
make
```
```
./server
```
>you will receive server pid here.
```
./client <server_pid> "Hey there."
```
# 🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
