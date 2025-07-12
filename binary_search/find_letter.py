alphabet = ["A","B","C","D"]

target = "D"

start = 0
end = len(alphabet)-1
initial_length = end

median = 0

#print(alphabet[start:end+1])

while alphabet[median] != target:

  gap = end - start

  if (gap%2) == 0:
      median = int(gap/2)
  else:
      median = int((gap+1)/2)

  if alphabet[median] > target:
      start = median  
  else:
      end = median

print(alphabet[median])



