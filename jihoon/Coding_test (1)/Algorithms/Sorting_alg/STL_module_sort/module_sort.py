# Basic Sorting
numbers = [34, 1, 5, 3, 11]
print("Basic Sorting:", sorted(numbers))

# Sorting Strings
words = ["apple", "pear", "banana", "cherry"]
print("Sorting Strings:", sorted(words))

# Sorting in Descending Order
print("Sorting in Descending Order:", sorted(numbers, reverse=True))

# Sorting by Length
print("Sorting by Length:", sorted(words, key=len))

# Sorting by Last Character of the Word
print("Sorting by Last Character:", sorted(words, key=lambda x: x[-1]))

# Sorting Tuples by the Second Element
pairs = [(1, 2), (3, 1), (4, 10), (7, 7)]
print("Sorting Tuples by the Second Element:", sorted(pairs, key=lambda x: x[1]))

# Sorting Using Multiple Criteria
words_multicriteria = ["apple", "Apples", "PEAR", "PeaR", "banana"]
print("Sorting Using Multiple Criteria:", sorted(words_multicriteria, key=lambda x: (len(x), x.lower())))

# Case-Insensitive Sorting
mixed_case = ["apple", "Pear", "banana", "Cherry"]
print("Case-Insensitive Sorting:", sorted(mixed_case, key=str.lower))

# Sorting a String by its Characters
s = "banana"
print("Sorting a String by its Characters:", "".join(sorted(s)))

# Sorting with Custom Objects
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __repr__(self):
        return self.name

people = [Person("Alice", 32), Person("Bob", 25), Person("Charlie", 40)]
print("Sorting with Custom Objects:", sorted(people, key=lambda x: x.age))


pairs = [(3, 2), (7, 2), (2, 5), (10, 1), (8, 2)]

# Sorting by second element primarily, and by the first element (in reverse) as a tiebreaker
sorted_pairs = sorted(pairs, key=lambda x: (x[1], -x[0]))

print(sorted_pairs)