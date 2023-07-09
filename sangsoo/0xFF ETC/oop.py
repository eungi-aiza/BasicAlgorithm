# Encapsulation
class Encapsulation:
    def __init__(self):
        self.__private_var = None  

    def set_var(self, value):
        self.__private_var = value

    def get_var(self):
        return self.__private_var

encapsulation = Encapsulation()
encapsulation.set_var(5)
print(f'Encapsulation: {encapsulation.get_var()}')

# Inheritance
class Parent:
    def parent_function(self):
        print('This is a function in the Parent class.')

class Child(Parent):
    def child_function(self):
        print('This is a function in the Child class.')

child = Child()
child.parent_function()
child.child_function()

# Polymorphism
class Base:
    def show(self):
        print('Base class')

class Derived(Base):
    def show(self):
        print('Derived class')

derived = Derived()
derived.show()

# Abstraction
from abc import ABC, abstractmethod

class AbstractClass(ABC):
    @abstractmethod
    def abstract_method(self):
        pass

class ConcreteClass(AbstractClass):
    def abstract_method(self):
        print('Implemented abstract method')

concrete = ConcreteClass()
concrete.abstract_method()
