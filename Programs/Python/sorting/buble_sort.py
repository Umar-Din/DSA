'''
buble sort 
algo -> comapre the adjecent element and swap if order is not satisfied
        sort till n-1 times
        n-ith iterations
'''

elements = [2,4,3,6,5,1,7,9,8]
def buble_sort(arr, assending = True):
    counter = 1
    if(assending == True):
        while(counter < len(arr)-1 and counter >=0):
            for i in range(len(arr)-counter):
                if(arr[i]>arr[i+1]):
                    temp = arr[i]
                    arr[i] = arr[i+1]
                    arr[i+1] = temp
            counter +=1
        return
    while(counter < len(arr)-1 and counter >=0):
        for i in range(len(arr)-counter):
            if(arr[i]<arr[i+1]):
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp
        counter +=1
    return
# len()
buble_sort(elements,assending=True)
print(elements)