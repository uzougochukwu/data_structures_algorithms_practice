	; example 25 decimal
	; 25 decimal becomes 0010 0101 in bcd
	; two approaches, one for storing the bcd number in a register, the other for storing it in memory (same method for heap and stack)

	; store it in a register
	; let x be the decimal number
	; we repeatedly divide x by 10
	; don't forget to clear rdx after each division
	; remainder of x/10 is the digit we wish to move into the register
	; but we need to scale up the remainder of x/10 by its position
	; first we move it into nibble 0, then 1, 2 etc.
	; if the number of loop iterations is i
	; then after each x/10, we multiply that result by 2 to the power of (4 multiplied by i)
	; so that on the 0th iteration its x/10 multiplied by 2 to the power of 0
	; then 2 to the power of 4
	; then 2 to the power of 8
	; and so on until the result of x/10 is 0
	; after each x/10, the remainder is being multiplied by its scaling factor and added to the register we have designated to contain the bcd number

	; store it in memory
	; decide how much memory is needed - this is crucial to interpet the bcd number
	; let x be the decimal number
	; memlength = ceiling ( log_10(x) )
	; with memlength as an integer number of bytes
	; the number will be stored with the least sig digit at low memory
	; start mem index at memlength - 1
	; decrement mem index with each loop
	; on each loop iteration do x/10
	; don't forget to clear rdx after each division
	; then remainder of x/10 multiplied by 2 to the power of 4
	; add those two results together
	; then move them into the byte at mem index
	; continue until result of x/10 is 0
