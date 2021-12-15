# DroidReachBenchmarks

Benchmark apps that highlights reachability challenges in the native world of Android applications.

### Benchmarks

|id  | name                    | description                                                                              | ArgusSaf            | Ghidra              | DroidReach       |
|----|-------------------------|------------------------------------------------------------------------------------------|---------------------|---------------------|------------------|
| 0  | StaticMapping           | JNI Method bound to a Java native method through name mangling                           | <ul><li>[x]</li>    | -                   | <ul><li>[x]</li> |
| 1  | StaticMappingOverload   | JNI Method bound to a Java native method through name mangling (method overload)         | <ul><li>[x]</li>    | -                   | <ul><li>[x]</li> |
| 2  | DynamicMapping          | JNI Method bound to a Java native method using RegisterNatives API                       | <ul><li>[x]</li>    | -                   | <ul><li>[x]</li> |
| 3  | DynamicMappingClash     | JNI Method bound to a Java native method using RegisterNatives API (clash in class name) | <ul><li>[x]</li>    | -                   | <ul><li>[x]</li> |
| 4  | DynamicMappingNonglobal | JNI Method bound to a Java native method using RegisterNatives API (non-global array)    | <ul><li>[x]</li>    | -                   | <ul><li>[x]</li> |
| 5  | DynamicMappingComplex   | JNI Method bound to a Java native method using RegisterNatives API (complex code)        | <ul><li>[ ]</li>    | -                   | <ul><li>[x]</li> |
| 6  | NestedLib               | JNI Method calls another linked library                                                  | <ul><li>[ ]</li>(1) | <ul><li>[ ]</li>(2) | <ul><li>[x]</li> |
| 7  | HighDepth               | The target function is called with an high calldepth                                     | <ul><li>[ ]</li>(3) | <ul><li>[x]</li>    | <ul><li>[x]</li> |
| 8  | IndirectJmp             | The target function is called after an indirect jmp (C++ virtual call)                   | <ul><li>[x]</li>    | <ul><li>[ ]</li>    | <ul><li>[x]</li> |
| 9  | IndirectJmpVariant      | The target function is called after an indirect jmp (C++ virtual call)                   | <ul><li>[x]</li>    | <ul><li>[ ]</li>    | <ul><li>[x]</li> |
| 10 | IndirectJmpVariant2     | The target function is called after an indirect jmp (function pointer)                   | <ul><li>[x]</li>    | <ul><li>[ ]</li>    | <ul><li>[x]</li> |
| 11 | IndirectJmpHighDepth    | The target function is called after an indirect jmp at high calldepth                    | <ul><li>[ ]</li>    | <ul><li>[ ]</li>    | <ul><li>[x]</li> |

(1): It is possible to modify ArgusSaf so that it supports multiple libraries

(2): Ghidra can be enhanced to deal with multiple libraries

(3): It is possible to increase the calldepth, but there is a trade-off between running time/memory usage and desired calldepth.
