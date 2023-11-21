# class Node:
class Node:
    def __init__(self,value):
        self.value = value
        self.next = None   
# class LinkedList:
class LinkedList:
    #constructor
    def __init__(self,value=None):
        new_node = Node(value)
        self.value = value
        self.head = new_node
        self.tail = new_node
        if value is None:
            self.length = 0
            return
        self.length = 1
    #print all elements of linkedlist    
    def print_linked_list(self):
        if self.head.value is None:
            print('Empty Linked List')
            return
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next
    #append new element to linked list at last
    def append(self,value):
        if self.head.value == None:
            self.head.value = value
            self.length +=1
        else:
            new_node = Node(value)
            self.tail.next = new_node
            self.tail = new_node
            self.value = value
            self.length +=1
    #remove last element of linkedlist
    def pop(self):
        if self.head.value is None:
            print('Empty Linked List')
            return None
        temp = self.head
        pre = self.head
        while temp.next is not None:
            pre = temp
            temp = temp.next
        pre.next = None
        self.length -=1
        return temp.value

    #insert or add new element to start of the linkedlist
    def prepend(self,value):
        new_node = Node(value)
        if self.head.value is None:
            self.head = new_node
            self.tail = new_node
            self.value = value
            self.length = 1
            return
        new_node.next = self.head
        self.head = new_node
        self.length +=1
        return
    #pop first element from the linkedlist
    def popfirst(self):
        if self.length==0:
            return None
        if self.length == 1:
            temp = self.head
            self.head= None
            self.length -=1
            return temp.value
        temp = self.head
        self.head = self.head.next
        temp.next = None
        self.length -=1
        return temp.value
    #get element of the linkedlist based on the index
    def get(self,index):
        if index < 0  and index >=self.length:
            return None
        temp = self.head
        for _ in range(index):
            temp = temp.next
        return temp.value
            


        
        

my_linked_list = LinkedList(2)

# my_linked_list.append()
my_linked_list.append(6)
my_linked_list.append(2)


my_linked_list.print_linked_list()

# print("*********")
# print(my_linked_list.length)

# print('********pop*********')
# pop = my_linked_list.pop()
# my_linked_list.print_linked_list()
# print('*****Length*******')
# print(my_linked_list.length)
# print('**element returned by pop**')
# print(pop)

# print('******prepend operations')
# my_linked_list.prepend(8)
# print("after prepend*********")
# my_linked_list.print_linked_list()
# print('*****after prepend length')
# print(my_linked_list.length)

# print('******pop first operation')
# print(my_linked_list.popfirst())
# print('*****length after pop')
# print(my_linked_list.length)

print('******element by index ****')
print(my_linked_list.get(1))
print('*****length after index')
print(my_linked_list.length)