# DroidReachBenchmarks

Benchmark apps that highlights reachability challenges in the native world of Android applications.

### Benchmarks

|id  | name                    | description                                                                              | ArgusSaf                 | Ghidra                   | DroidReach            |
|----|-------------------------|------------------------------------------------------------------------------------------|--------------------------|--------------------------|-----------------------|
| 0  | StaticMapping           | JNI Method bound to a Java native method through name mangling                           | <ul><li>[x]</li></ul>    | -                        | <ul><li>[x]</li></ul> |
| 1  | StaticMappingOverload   | JNI Method bound to a Java native method through name mangling (method overload)         | <ul><li>[x]</li></ul>    | -                        | <ul><li>[x]</li></ul> |
| 2  | DynamicMapping          | JNI Method bound to a Java native method using RegisterNatives API                       | <ul><li>[x]</li></ul>    | -                        | <ul><li>[x]</li></ul> |
| 3  | DynamicMappingClash     | JNI Method bound to a Java native method using RegisterNatives API (clash in class name) | <ul><li>[x]</li></ul>    | -                        | <ul><li>[x]</li></ul> |
| 4  | DynamicMappingNonglobal | JNI Method bound to a Java native method using RegisterNatives API (non-global array)    | <ul><li>[x]</li></ul>    | -                        | <ul><li>[x]</li></ul> |
| 5  | DynamicMappingComplex   | JNI Method bound to a Java native method using RegisterNatives API (complex code)        | <ul><li>[ ]</li></ul>    | -                        | <ul><li>[x]</li></ul> |
| 6  | NestedLib               | JNI Method calls another linked library                                                  | <ul><li>[ ]</li></ul>(1) | <ul><li>[ ]</li></ul>(2) | <ul><li>[x]</li></ul> |
| 7  | HighDepth               | The target function is called with an high calldepth                                     | <ul><li>[ ]</li></ul>(3) | <ul><li>[x]</li></ul>    | <ul><li>[x]</li></ul> |
| 8  | IndirectJmp             | The target function is called after an indirect jmp (C++ virtual call)                   | <ul><li>[x]</li></ul>    | <ul><li>[ ]</li></ul>    | <ul><li>[x]</li></ul> |
| 9  | IndirectJmpVariant      | The target function is called after an indirect jmp (C++ virtual call)                   | <ul><li>[x]</li></ul>    | <ul><li>[ ]</li></ul>    | <ul><li>[x]</li></ul> |
| 10 | IndirectJmpVariant2     | The target function is called after an indirect jmp (function pointer)                   | <ul><li>[x]</li></ul>    | <ul><li>[ ]</li></ul>    | <ul><li>[x]</li></ul> |
| 11 | IndirectJmpHighDepth    | The target function is called after an indirect jmp at high calldepth                    | <ul><li>[ ]</li></ul>    | <ul><li>[ ]</li></ul>    | <ul><li>[x]</li></ul> |

(1): It is possible to modify ArgusSaf so that it supports multiple libraries

(2): Ghidra can be enhanced to deal with multiple libraries

(3): It is possible to increase the calldepth, but there is a trade-off between running time/memory usage and desired calldepth.
