'''
Sorting of list by selection sort

algo# -> compare the ist element of list with the all next elements of list if the element requires swap then swap
'''

def sort(list:list, assending=True):
    if(assending == True):
        for i in range(len(list)-1):
            for j in range(i+1,len(list)):
                if(list[j]<list[i]):
                    temp = list[j]
                    list[j] = list[i]
                    list[i] = temp
        return            
    for i in range(len(list)-1):
            for j in range(i+1,len(list)):
                if(list[j]>list[i]):
                    temp = list[j]
                    list[j] = list[i]
                    list[i] = temp
                   
    return
list = [2,4,6,1,3,5]
sort(list,assending=False)
print(list)