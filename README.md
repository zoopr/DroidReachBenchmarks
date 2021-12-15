# DroidReachBenchmarks

Benchmark apps that highlights reachability challenges in the native world of Android applications.

### Benchmarks

|id  | name                    | description                                                                              | ArgusSaf | Ghidra  | DroidReach |
|----|-------------------------|------------------------------------------------------------------------------------------|----------|---------|------------|
| 0  | StaticMapping           | JNI Method bound to a Java native method through name mangling                           |  [x]     |   -     |    [x]     |
| 1  | StaticMappingOverload   | JNI Method bound to a Java native method through name mangling (method overload)         |  [x]     |   -     |    [x]     |
| 2  | DynamicMapping          | JNI Method bound to a Java native method using RegisterNatives API                       |  [x]     |   -     |    [x]     |
| 3  | DynamicMappingClash     | JNI Method bound to a Java native method using RegisterNatives API (clash in class name) |  [x]     |   -     |    [x]     |
| 4  | DynamicMappingNonglobal | JNI Method bound to a Java native method using RegisterNatives API (non-global array)    |  [x]     |   -     |    [x]     |
| 5  | DynamicMappingComplex   | JNI Method bound to a Java native method using RegisterNatives API (complex code)        |  [ ]     |   -     |    [x]     |
| 6  | NestedLib               | JNI Method calls another linked library                                                  |  [ ](1)  |  [ ](2) |    [x]     |
| 7  | HighDepth               | The target function is called with an high calldepth                                     |  [ ](3)  |  [ ]    |    [x]     |
| 8  | IndirectJmp             | The target function is called after an indirect jmp (C++ virtual call)                   |  [x]     |  [ ]    |    [x]     |
| 9  | IndirectJmpVariant      | The target function is called after an indirect jmp (C++ virtual call)                   |  [x]     |  [ ]    |    [x]     |
| 10 | IndirectJmpVariant2     | The target function is called after an indirect jmp (function pointer)                   |  [x]     |  [ ]    |    [x]     |
| 11 | IndirectJmpHighDepth    | The target function is called after an indirect jmp at high calldepth                    |  [ ]     |  [ ]    |    [x]     |

(1): It is possible to modify ArgusSaf so that it supports multiple libraries
(2): Ghidra can be enhanced to deal with multiple libraries
(3): It is possible to increase the calldepth, but there is a trade-off between running time/memory usage and desired calldepth.
