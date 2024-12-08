"""
elementary data structure
1. stack
2. queue
3. btree
"""

class Stack:
    def __init__(self):
        self.stack = []

    def push(self, x):
        self.stack.append(x)
    
    def pop(self):
        self.stack.pop()
    
    def peek(self):
        if len(self.stack):
            print(self.stack[-1])
        raise IndexError("Empty stack!!")

class TwoStacks:    
    def __init__(self, sz):
        self.stack = [0 for _ in range(sz)]
        self.first_idx = -1 
        self.second_idx = sz
    
    def push_first(self, x):
        if self.first_idx + 1 == self.second_idx:
            raise IndexError("Stack overflow!")
        self.first_idx += 1
        self.stack[self.first_idx] = x

    def push_second(self, x):
        if self.first_idx + 1 == self.second_idx:
            raise IndexError("Stack overflow!")
        self.second_idx -= 1
        self.stack[self.second_idx] = x

    def pop_first(self):
        if self.first_idx < 0:
            raise IndexError("Stack underflow!")
        self.first_idx -= 1
        

    def pop_second(self):
        if self.second_idx >= len(self.stack):
            raise IndexError("Stack underflow!")
        self.second_idx += 1
    
    def peek_first(self):
        if self.first_idx >= 0:
            print(self.stack[self.first_idx])
        else:
            raise IndexError("Stack underflow!")

    def peek_second(self):
        if self.second_idx < len(self.stack):
            print(self.stack[self.second_idx])
        else:
            raise IndexError("Stack underflow!")
        

class Deque:
    def __init__(self, sz):
        self.stack = [0 for _ in range(sz)]
        self.head = 0 
        self.tail = -1 
    
    def push_head(self, x):
        if self.tail + 1 - self.head >= len(self.stack):
            raise IndexError("Deque overflow")
        self.head -= 1
        self.stack[self.head] = x

    def push_tail(self, x):
        if self.tail + 1 - self.head >= len(self.stack):
            raise IndexError("Deque overflow")
        self.tail += 1
        self.stack[self.tail] = x

    def pop_head(self):
        if self.head > -1:
            raise IndexError("Deque underflow")
        self.stack[self.head] = 0
        self.head += 1

    def pop_tail(self):
        if self.tail < 0:
            raise IndexError("Deque underflow")
        self.stack[self.tail] = 0
        self.tail -= 1


class TwoStacksQueue:
    def __init__(self):
        self.s1 = []
        self.s2 = []
    
    def enqueue(self, x):
        if self.s1:
            self.s1.append(x)
        else:
            self.s2.append(x)
    
    def dequeue(self):
        if not self.s2:
            while self.s1:
                tmp = self.s1.pop()
                self.s2.append(tmp)
            self.s2.pop()
        else:
            while self.s2:
                tmp = self.s2.pop()
                self.s1.append(tmp)
            self.s1.pop()
            

class TwoQueuesStack:
    def __init__(self):
        pass

class Queue:
    def __init__(self):
        self.q = []
        self.head = 0
        self.tail = 0

    def enqueue(self, x):
        self.tail += 1
        self.q.append(x)

    def dequeue(self):
        if self.tail - self.head > 0:
            self.head += 1
        raise IndexError("empty queue!!")
    
    def peek(self):
        pass

if __name__ == "__main__":
    #dq = Deque(5)
    #dq.push_head(3)
    #dq.push_tail(12)
    #dq.push_tail(34)
    #dq.push_tail(112)
    #dq.push_tail(65)
    #print(dq.stack)
    #dq.pop_head()
    #print(dq.stack)
    #dq.pop_tail()
    #print(dq.stack)
    #dq.pop_tail()
    #print(dq.stack)
    #s = TwoStacks(5)
    #s.push_first(3)
    #s.push_second(9)
    #s.push_second(11)
    #s.push_second(33)
    #s.push_first(12)
    #print(s.stack)
    #s.pop_first()
    #s.peek_second()
    #s.pop_second()
    #s.pop_second()
    #s.peek_second()
    #s.peek_first()
    #s.pop_first()
    #s.pop_second()
    #s.peek_first()
    #s.peek_second()
