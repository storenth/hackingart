/* Stack updated with new stack frame when test_function called, mean
when the assembly call instruction is executed, the return
address is pushed onto the stack. In this step, the current
value of RBP is pushed to the stack. This value is called the saved frame pointer (SFP)
and is later used to restore RBP back to its original state.
The current value of RSP is then copied into EBP to set the new frame pointer.
This frame pointer is used to reference the local variables of the function 
(sometimes local variables are referenced as an offset relative to rbp rather than an offset to rsp) */

/* low adresses
------------------------------------------------------------------------
|             RSP (prev RBP-0x30 for exmaple)                          |
| (need note already existed SFP + ret address to get right new RSP)   |
|           so new RSP = (RBP-0x30) - 0x8 (SFP) - 0x8 (ret)            |

|                 func arguments a, b, c, d                            |
|               local variables flag, buffer                           |
|                    possible padding                                  |
|             SFP (previous RBP from main)                             |
|  return address, next of main's RIP after call this func             |
------------------------------------------------------------------------
high addresses */


void test_function(int a, int b, int c, int d) {
   int flag;
   char buffer[10];

   flag = 31337;
   buffer[0] = 'A';
}

int main() {
   test_function(1, 2, 3, 4);
}
