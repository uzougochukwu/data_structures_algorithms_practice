from random import randrange

input = [10, 5, 2, 3, 7, 0, 9, 12]

def quicksort(arr):
    if len(arr) < 2:
        return arr
    else:
        rand = randrange(0, len(arr))  # grab a random index
        pivot = arr.pop(rand)
        less = [i for i in arr if i <= pivot]
        greater = [i for i in arr if i > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

print("sorted:  ", quicksort(input))
