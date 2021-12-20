# DroidReachBenchmarks

Benchmark apps that highlights reachability analysis challenges in the native world of Android applications.

The compiled applications are stored under the `apk` subdirectory.

### Benchmarks

|id  | name                        | description                                                                              | ArgusSaf    | Ghidra      | DroidReach |
|----|-----------------------------|------------------------------------------------------------------------------------------|-------------|-------------|------------|
| 0  | StaticMapping               | JNI Method bound to a Java native method through name mangling                           | &#9746;     | -           | &#9746;    |
| 1  | StaticMappingOverload       | JNI Method bound to a Java native method through name mangling (method overload)         | &#9746;     | -           | &#9746;    |
| 2  | DynamicMapping              | JNI Method bound to a Java native method using RegisterNatives API                       | &#9746; (*) | -           | &#9746;    |
| 3  | DynamicMappingClash         | JNI Method bound to a Java native method using RegisterNatives API (clash in class name) | &#9746; (*) | -           | &#9746; (*)|
| 4  | DynamicMappingNonglobal     | JNI Method bound to a Java native method using RegisterNatives API (non-global array)    | &#9746; (*) | -           | &#9746; (*)|
| 5  | DynamicMappingComplex       | JNI Method bound to a Java native method using RegisterNatives API (complex code)        | &#9744;     | -           | &#9746;    |
| 6  | NestedLib                   | JNI Method calls another linked library                                                  | &#9744; (1) | &#9744; (2) | &#9746;    |
| 7  | HighDepth                   | The target function is called with an high calldepth                                     | &#9744; (3) | &#9746;     | &#9746;    |
| 8  | IndirectJmp                 | The target function is called after an indirect jmp (C++ virtual call)                   | &#9746;     | &#9744;     | &#9746;    |
| 9  | IndirectJmpVariant          | The target function is called after an indirect jmp (C++ virtual call)                   | &#9746;     | &#9744;     | &#9746;    |
| 10 | IndirectJmpVariant2         | The target function is called after an indirect jmp (function pointer)                   | &#9746;     | &#9744;     | &#9746;    |
| 11 | IndirectJmpHighDepth        | The target function is called at high calldepth after an indirect jmp (at small depth)   | &#9744; (3) | &#9744;     | &#9746;    |
| 12 | IndirectJmpHighDepthVariant | The target function is called at high calldepth after an indirect jmp (at high depth)    | &#9744; (3) | &#9744;     | &#9744; (3)|

(*): Slow, uses symbolic execution.

(1): It is possible to modify ArgusSaf so that it supports multiple libraries

(2): Ghidra can be enhanced to deal with multiple libraries

(3): It is possible to increase the calldepth, but there is a trade-off between running time/memory usage and desired calldepth.

n/a: not applicable, e.g., Ghidra is not involved in the mapping.
