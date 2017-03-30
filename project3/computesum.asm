;========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3=========4=========5=========6=========7**
;Author information
;  Author name: Floyd Holliday
;  Author email: holliday@fullerton.edu
;  Author location: Costa Mesa
;Course information
;  Course number: CPSC254
;  Assignment number: 3
;  Due date: 2017-Jul-01
;Project information
;  Project title: Data Analysis
;  Purpose: [Fill in a sentence here]
;  Project files: sum-driver.cpp, sum-array-64.asm
;Module information
;  This module's call name: sum
;  Language: X86-64
;  Syntax: Intel
;  Date last modified: 2017-Jul-01 [Fill in the correct date here]
;  Purpose: This module will compute the sum of 64-bit doubles stored in an array.
;  File name: sum-array-64.asm
;  Status: This module was module is ready for delivery to students who have not yet enrolled in CPSC240
;  Future enhancements: Improve execution speed by parallel processing: for instance, sum odd-numbered cells and even numbered cells concurrently,
;                       then add the partial sums to obtain the complete sum.
;  Parameters passed in: pointer to array of doubles
;                        integer showing count of doubles in the array
;  Parameters passed out: double containing the sum of doubles in the array
;Translator information
;  Linux: nasm -f elf64 -l sum-array-64.lis -o sum-array-64.o sum-array-64.asm
;References and credits
;  Seyfarth, Ray. Intro to 64 Bit Assembly Programming, ISBN=978-1484921906, Chapter 11.
;Source code formatting:
;  Page width: 172 columns
;  Begin comments: column 61
;  Optimal print specification: Landscape, 7 points or smaller, monospace, 8Â½x11 paper
;
;===== Begin code area =====================================================================================================================================================



;extern printf                                               ;External C++ function for writing to standard output device.  Not used in this function.

;extern scanf                                                ;External C++ function for reading from the standard input device.  Not used in this function.

global sum                                                   ;This makes sum-array callable by functions outside of this file.

segment .data                                                ;Place initialized data here

;This segment is empty because there are no messages to output from this function.

segment .bss                                                 ;Declare pointers to un-initialized space in this segment.

;This segment is empty because there are no (new) pointers to be declared.

;===========================================================================================================================================================================
;===== Begin the application here: Compute the sum of numbers in an array passed to this function
;===========================================================================================================================================================================

segment .text                                                ;Place executable instructions in this segment.

sum:                                                         ;Entry point.  Execution begins here.

;The next two instructions are performed at the start of every assembly program.
push       rbp                                               ;This marks the start of a new stack frame belonging to this execution of this function.
mov        rbp, rsp                                          ;rbp holds the address of the start of this new stack frame.  When this function returns to its caller rbp must
                                                             ;hold the same value it holds now.

;=========== Back up incoming parameters ===================================================================================================================================

mov        r14, rdi                                          ;Make a copy of the pointer to the incoming array
mov        r15, rsi                                          ;Make a second copy of the number elements in the array

;=========== Set up registers for the loop that follows ====================================================================================================================

mov qword  rcx, 0                                            ;The loop counter is initialized to zero
push qword 0                                                 ;Push 64 zero bits on the stack
movsd      xmm8, [rsp]                                       ;Zero out the accumulating register
pop        rax                                               ;Reverse the previous push

;===== Begin loop that will sum all numbers in the array ===================================================================================================================

begin_loop:
cmp        rcx, r15                                          ;Determine if the loop should continue or exit
jge        end_loop                                          ;Exit from loop
mov        r8, [r14]                                         ;Copy one number from the array to a general purpose register
push       r8                                                ;Put that number on top of the stack
movsd      xmm9, [rsp]                                       ;Copy that same floating point number to a 64-bit floating point register
pop        rax                                               ;Return the stack to the state it held before the recent push
addsd      xmm8, xmm9                                        ;Add the floating point number to the accumulator
inc        rcx                                               ;Increment the loop counter
add        r14, 8                                            ;Advance the pointer to the next position in the array
jmp        begin_loop                                        ;Continue executing at the beginning of the loop
end_loop:                                                    ;A marker for the lower boundary of the loop

;===== The loop has finished.  Prepare to exit from this function ==========================================================================================================

movsd      xmm0, xmm8                                        ;Copy the accumulated sum to the register designated for return values
pop        rbp                                               ;Resort to rbp the value it had in the function that called this assembly function.
ret                                                          ;Pop the stack into the rip register which is the register of the next instrucction.

;========== End of function sum-array.asm ==================================================================================================================================
;========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3=========4=========5=========6=========7**

