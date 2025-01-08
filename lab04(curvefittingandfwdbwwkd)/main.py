import sys

for i in range(10):
    print(f"Iteration {i}")
    def my_function():
        print("This is a function")

    my_function()
    def my_function(counter):
        print(f"Recursion depth: {counter}")
        try:
            my_function(counter + 1)
        except RecursionError:
            print(f"Max recursion depth reached: {counter}")

    my_function(1)