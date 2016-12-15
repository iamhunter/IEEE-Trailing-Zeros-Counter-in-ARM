    .text
    .global trailing_zeros
    .type trailing_zeros, %function

word		.req r0
zero		.req r1
temp		.req r2
count		.req r3
countdown	.req r4

trailing_zeros:

push {lr}

	mov zero, #0
	mov count, #-1
	mov countdown, #31


loop:
	add count, count, #1 	@ increment count

	mov temp, word		@ store word in a temporary variable
	lsl temp, countdown	@ isolate the rightmost bit
	lsr temp, countdown	@ isolate the rightmost bit

	lsr word, #1		@ shift word right one (used on next loop if applicable)

	cmp count, #23		@ if count has reached the boundary, just end
	beq end			@ 1.0 goes to 24, but should end at 24

	cmp temp, zero		@ if isolated bit equals zero
	beq loop		@ keep looping for all trailing zeroes

end:	
	mov word, count
pop {pc}

.unreq word
.unreq zero
.unreq temp
.unreq count
.unreq countdown
