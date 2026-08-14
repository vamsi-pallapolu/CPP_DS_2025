# CPP DS 2025 — Study Notes

Topic-wise Markdown notes generated from the C++ practice files in this repo.
Each `.md` mirrors one `.cpp` under a same-named `SEC*` folder.

Generated via the `notes-from-code` skill.

## Excluded directories

Bulk note generation skips the following top-level dirs (competitive-programming / interview-problem sets):

- `A2Z/`
- `derived/`
- `MathWorks/`
- `TopInterview150/`

To generate notes for a single file inside an excluded dir, ask explicitly.

## Index

### SEC07_ArrayADT — Array as an Abstract Data Type

| Notes | Source | Topic |
|---|---|---|
| [01_Array.md](SEC07_ArrayADT/01_Array.md) | `SEC07_ArrayADT/1_Array.cpp` | Struct wrapping a heap buffer + capacity/length metadata |
| [02_Insert.md](SEC07_ArrayADT/02_Insert.md) | `SEC07_ArrayADT/2_Insert.cpp` | Same ADT with a fixed-size buffer + aggregate init |

### SEC02_essentialcandcpp — Essential C and C++

| Notes | Source | Topic |
|---|---|---|
| [01_VariableSizeArray.md](SEC02_essentialcandcpp/01_VariableSizeArray.md) | `SEC02_essentialcandcpp/1_VariableSizeArray.cpp` | VLAs (GCC/Clang extension) |
| [02_Pointers.md](SEC02_essentialcandcpp/02_Pointers.md) | `SEC02_essentialcandcpp/2_Pointers.cpp` | Heap allocation — `malloc` vs `new` |
| [03_PointToStruct.md](SEC02_essentialcandcpp/03_PointToStruct.md) | `SEC02_essentialcandcpp/3_PointToStruct.cpp` | Pointer to struct, `->` vs `(*p).` |
| [04_ArrayAsPointer.md](SEC02_essentialcandcpp/04_ArrayAsPointer.md) | `SEC02_essentialcandcpp/4_ArrayAsPoin.cpp` | Array-to-pointer decay, function params |
| [05_StructAsParam.md](SEC02_essentialcandcpp/05_StructAsParam.md) | `SEC02_essentialcandcpp/5_StructAsParam.cpp` | Passing structs — value, reference, const-reference |
| [06_TemplateClasses.md](SEC02_essentialcandcpp/06_TemplateClasses.md) | `SEC02_essentialcandcpp/6_TemplateClasses.cpp` | Class templates, out-of-line definitions |

### SEC05_Recursion — Recursion

| Notes | Source | Topic |
|---|---|---|
| [01_Example.md](SEC05_Recursion/01_Example.md) | `SEC05_Recursion/1_Example.cpp` | First recursive function; base case + recursive case |
| [02_StaticVariables.md](SEC05_Recursion/02_StaticVariables.md) | `SEC05_Recursion/2_StaticVariables.cpp` | `static` locals across recursive calls |
| [03_HeadAndTailRecursion.md](SEC05_Recursion/03_HeadAndTailRecursion.md) | `SEC05_Recursion/3_HeadAndTailRecursion.cpp` | Head vs tail recursion, TCO |
| [04_IndirectRecursion.md](SEC05_Recursion/04_IndirectRecursion.md) | `SEC05_Recursion/4_IndirectRecursion.cpp` | Mutual (indirect) recursion |
| [05_Sum.md](SEC05_Recursion/05_Sum.md) | `SEC05_Recursion/5_Sum.cpp` | Recursive sum 1..n |
| [06_Fact.md](SEC05_Recursion/06_Fact.md) | `SEC05_Recursion/6_Fact.cpp` | Factorial (recursive + iterative) |
| [07_Pow.md](SEC05_Recursion/07_Pow.md) | `SEC05_Recursion/7_Pow.cpp` | Power — naïve O(n) vs fast O(log n) |
| [08_Taylor.md](SEC05_Recursion/08_Taylor.md) | `SEC05_Recursion/8_Taylor.cpp` | Taylor series `e^x` — three implementations |
| [09_0_Fibonacci.md](SEC05_Recursion/09_0_Fibonacci.md) | `SEC05_Recursion/9_0_Fibonacci.cpp` | Iterative Fibonacci printer |
| [09_1_Fib.md](SEC05_Recursion/09_1_Fib.md) | `SEC05_Recursion/9_1_Fib.cpp` | Fibonacci — iterative / recursive / memoised |

### SEC06_Arrays — Arrays

| Notes | Source | Topic |
|---|---|---|
| [01_Addresses.md](SEC06_Arrays/01_Addresses.md) | `SEC06_Arrays/1_Addresses.cpp` | Contiguous memory, `&A[i]` vs `A + i` |
| [02_StaticAndDynamic.md](SEC06_Arrays/02_StaticAndDynamic.md) | `SEC06_Arrays/2_StaticAndDynamic.cpp` | Stack vs heap arrays |
| [03_IncreaseArraySize.md](SEC06_Arrays/03_IncreaseArraySize.md) | `SEC06_Arrays/3_IncreaseArraySize.cpp` | Growing a heap array (alloc → copy → free) |
| [04_2DArrays.md](SEC06_Arrays/04_2DArrays.md) | `SEC06_Arrays/4_2DArrays.cpp` | Three 2D-array representations |

## Companion resources

- `1_Introduction_To_Recursions.pdf` — slides for the recursion section.
- `DS_ROADMAP.pdf` — overall course roadmap.

## Regenerating notes

Ask Claude Code:

> Generate notes for the remaining cpp files.

The `notes-from-code` skill auto-applies the exclusion list above, mirrors the source folder under `resources/`, and runs a review pass.
