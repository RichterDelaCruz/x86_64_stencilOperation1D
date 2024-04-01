## Machine Project Specification: 
Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform 1-D stencil of vector X place the result in vector Y.

**Input**: Scalar variable n (integer) contains the length of the vector;  Vectors X and Y are both single-precision float.

**Process**:  ![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/5f01447f-bdba-4226-911a-71c2ca8dd705)

**Output**: store result in vector Y.  Display the result of 1st ten elements of vector Y for all versions of kernel (i.e., C and x86-64).

## How to Run: 

1. Duplicate the repository.
2. Launch the .sln file using Visual Studio.
3. Execute the code with the suitable mode (debug/release).
4. Input your preferred number of X values (e.g., 2^20,2^24,2^30).
5. Await completion of the code execution.

 ## Comparative execution time and short analysis of the performance of the kernels

**Debug Mode:**

 ![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/95424089-4b94-44b4-a407-c6631bcfebc7)
The table shows the average execution speeds of C and Assembly (ASM) code in debug mode. The results indicate that ASM is generally faster than C.

**Release Mode:**

![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/3fe33067-b6ab-4c70-8aeb-987e4722eef9)
The table shows the average execution speeds of C and Assembly (ASM) code in release mode. The results indicate that ASM is generally faster than C.

**Comparison Graphs:**

*Line Graph 1: Debug Mode for ASM*
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/efdad3ab-3766-42c9-8a7c-f353c84bbb6c)


A closer look for the comparison of 2^20 and 2^24

![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/51c96dfc-758d-4fb0-9f73-7507df548d81)


*Line Graph 2: Debug Mode for C*

![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/8f4c658d-9d51-4884-8a08-5662b6a6fad8)

A closer look for the comparison of 2^20 and 2^24
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/3887977f-e209-4775-9f7f-7981ec7ff248)

*Line Graph 3: Release Mode for ASM*
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/16294593-7283-425c-a016-30cc999907bc)

A closer look for the comparison of 2^20 and 2^24
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/6fc0b1ef-65fa-4684-864d-00b520295d0b)

*Line Graph 4: Release Mode for C*

![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/eda60af3-cc4f-4c90-a5b5-08b6f44db455)

A closer look for the comparison of 2^20 and 2^24
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/5448a263-9a4a-43b4-95db-123ee3b346e7)

**Calculation**

To provide a comparative analysis of the performance of the kernels, you can calculate the speedup achieved by the assembly function compared to the C function. The speedup can be calculated using the following formula:

<p style="text-align: center;"> Speedup = Time taken by C function / Time taken by assembly function </p>



## Screenshots with Correctness Check
Since the terminal output is lengthy, we will provide snippets from the first iterations up to the last iteration, along with the average time it takes. The full output will be stored in a folder named “x86_64_stencilOperation1D Outputs”.

**Screenshots for Debug Mode**

**2^30**
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/26996e43-8505-45bd-a211-06e94b2e7756)
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/52985a03-586a-457b-95d8-f10e6a0d44e8)


**2^20**
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/fcc072ec-a56f-478e-9235-51c2e207a3c8)
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/80cc5494-5382-4094-a950-b4aa8db37bb8)

**2^24**
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/d9216867-570c-4d33-b1ef-116c6ba7a678)
![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/ee52971e-1e65-4108-a8c5-79fa2a17b546)

