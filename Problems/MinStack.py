#Question Link: https://leetcode.com/problems/min-stack/description/
'''Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input -> ["MinStack","push","push","push","getMin","pop","top","getMin"]    [[],[-2],[0],[-3],[],[],[],[]]
Output -> [null,null,null,null,-3,null,0,-2]   '''

#Time Complexity: O(1) for all operations
#Space Complexity: O(n) for storing the stack

class MinStack:
	def __init__(self):
		self.stack =[]
	def push(self, x):
		#determine the new minimum value 
		if not self.stack:
			curr_min = x #if stack is empty, new element = new min
		else:
			curr_min = min(x, self.stack[-1][1])
		self.stack.append((x, curr_min))
	def pop(self):
		self.stack.pop()
	def top(self):
		return self.stack[-1][0]
	def getMin(self):
		return self.stack[-1][1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()