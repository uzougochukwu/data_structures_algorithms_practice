
target = 10

array = [1,2,3,4,5,6,7,8,9,10,11]

low = 0


count = len(array)-1

high = count

answer = []

i = high

first = 0
second = 0

#find the larger number
while i > 0:
    if array[i] >= target:
      i-=1
    else:
      first = array[i]
      answer.append( array[i])
      break

#find the smaller number
i = 0
gap = target - first

while i < len(array):
    if array[i] != gap:
        i+=1
    else:
        second = array[i]
        answer.append( array[i])
        break

print(answer)
