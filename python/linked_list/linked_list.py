
"""
Author: Umar Din Khan
Definations of the linked list
"""

class Node(object):
    def __init__(self,data:int,next=None) -> None:
        self.data = data
        self.next = next

class LL(object):
    def __init__(self,elements:list[int]):
        self.first = None
        if len(elements):
            self.first = self.__createll(elements)
    def __len__(self) -> int:
        _count = 0
        _temp = self.first
        while(_temp is not None):
            _count += 1
            _temp = _temp.next
        return _count

    def __createll(self,elements:list[int]):
        first = Node(elements[0])
        _temp = first
        for el in range(1,len(elements)):
            n = Node(elements[el])
            _temp.next = n
            _temp = _temp.next
        return first

    def display(self) -> None:
        print("Displaying Linked List ...")
        print('[ ',end='')
        _temp = self.first
        while(_temp is not None):
            print(_temp.data,end=" ")
            _temp = _temp.next
        print(']')

    def insert(self, index:int, element:int) -> Node:
        if(index < 0) or (index > self.__len__()):
            raise IndexError("Invalid Index")

        n = Node(element)
        if(index == 0):
            n.next = self.first
            self.first = n
            return n
        _temp = self.first
        for _ in range(index-1):
            _temp = _temp.next
        n.next = _temp.next
        _temp.next = n
        return n
        

if __name__ == '__main__':
    print(
        __doc__
    )