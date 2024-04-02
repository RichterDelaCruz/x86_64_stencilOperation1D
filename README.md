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

 **Calculation**

To provide a comparative analysis of the performance of the kernels, you can calculate the speedup achieved by the assembly function compared to the C function. The speedup can be calculated using the following formula:

<p style="text-align: center;"> Speedup = Time taken by C function / Time taken by assembly function </p>

**Debug Mode:**

 ![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/95424089-4b94-44b4-a407-c6631bcfebc7)
The table shows the average execution speeds of C and Assembly (ASM) code in debug mode. The results indicate that ASM is generally faster than C.

The comparison between Assembly and C programming languages reveals a clear advantage for Assembly in terms of execution speed. This advantage can be attributed to Assembly's low-level nature, which allows it to directly interact with the underlying hardware of a computer system. In Assembly, programmers have granular control over the processor's instructions, enabling them to fine-tune operations for optimal performance.

On the other hand, C operates at a higher level of abstraction, providing developers with a more user-friendly and portable language. While C compilers strive to optimize code for efficiency, they introduce an extra layer of interpretation between the source code and the hardware execution. This intermediate step, although beneficial for readability and portability, can sometimes result in less optimized performance compared to Assembly.

The results of the comparison consistently show Assembly outperforming C across various scenarios. This performance gap is more noticeable with larger computations, where the overhead introduced by C's abstraction becomes more significant. Essentially, as the problem size grows, the direct and streamlined nature of Assembly becomes increasingly advantageous, highlighting its efficiency in handling complex calculations.

This is evident in the results, where Assembly consistently outperforms C for all tested powers of 2. The margins are relatively small for smaller inputs (2^20 and 2^24) but become more significant for larger calculations (2^30). This suggests that the overhead of C's abstractions becomes more impactful as the problem size grows.

**Release Mode:**

![image](https://github.com/RichterDelaCruz/x86_64_stencilOperation1D/assets/137752802/3fe33067-b6ab-4c70-8aeb-987e4722eef9)
The table shows the average execution speeds of C and Assembly (ASM) code in release mode. The results indicate that ASM is generally faster than C.

Similar to the debug mode results, the release mode confirm Assembly's performance advantage over C. In all test cases (2^20, 2^24, and 2^30), Assembly code executes faster than its C counterpart.


Speedup is a measure of how much faster one method of performing a task is compared to another. In this context, the speedup ratio compares the execution time of a program written in C to the execution time of the same program written in Assembly language. It is calculated by dividing the execution time of the C program by the execution time of the Assembly program.

For example, if the speedup ratio is 1.05, it means that the Assembly program executes 5% faster than the equivalent C program. Conversely, if the ratio is less than 1, it means that the C program is faster than the Assembly program.

In the benchmarks provided, the speedup ratios range from 1.02 to 1.05. This indicates that Assembly is up to 5% faster than C in these scenarios. While the difference may seem small for smaller inputs (such as 2^20 and 2^24), it becomes more significant for larger calculations (such as 2^30).

The efficiency gap between Assembly and C widens as the problem size increases. This suggests that Assembly's direct control over hardware instructions likely contributes to its efficiency, while C's higher-level abstractions may introduce some overhead, despite compiler optimizations. This overhead becomes more pronounced with larger problem sizes, highlighting the advantage of Assembly in handling complex computations efficiently.

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

**Release Mode & Debug Mode Analysis**

Release mode consistently delivers faster execution times compared to debug mode for all test cases (powers of 2). This is likely due to compiler optimizations that occur during the release build process. Optimizations can involve techniques like removing unnecessary code, streamlining calculations, and potentially even altering the order of operations for better efficiency.

*C*: The performance difference between debug and release mode for C is more noticeable for larger inputs (2^30). This suggests that compiler optimizations can significantly impact C code, especially for complex calculations.

*Assembly*: While Assembly also benefits from optimizations in release mode, the speedup isn't as dramatic as with C. This might be because Assembly code already has a high level of control over hardware instructions, leaving less room for significant optimization improvements.

**Optimization**

There is a potential impact of compiler optimizations in release mode. Compilers often perform more aggressive optimizations for release builds compared to debug builds. These optimizations might narrow the performance gap between C and Assembly in some cases.

However, Assembly's inherent ability to precisely control hardware-specific operations can still offer an edge, especially for performance-critical sections of code.


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

