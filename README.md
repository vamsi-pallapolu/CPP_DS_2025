# CPP_DS_2025

C++ practice programs and study notes for a Data Structures course, plus scratch work for interview-style problems.

## Layout

| Path | Contents |
|---|---|
| `SEC02_essentialcandcpp/` | Essential C / C++ warm-up — pointers, structs, references, templates. |
| `SEC05_Recursion/` | Recursion — direct, indirect, head vs. tail, memoisation. |
| `SEC06_Arrays/` | Array fundamentals — addresses, static vs. dynamic, growing, 2D representations. |
| `SEC07_ArrayADT/` | Array as an Abstract Data Type — buffer + length/size wrapper. |
| `A2Z/` | Striver's A2Z DSA sheet solutions (Arrays, Strings, ...). |
| `TopInterview150/` | LeetCode Top Interview 150 solutions. |
| `MathWorks/` | Interview-prep snippets (virtual functions, object cloning, ...). |
| `derived/` | Build artefacts / derived output — not source. |
| `Notes/` | Handwritten scratch notes (`.md`). |
| `resources/` | Topic-wise generated study notes — see [`resources/README.md`](resources/README.md). |

## Study notes

The `resources/` tree holds Markdown notes generated from the `.cpp` files in the `SEC*` folders (one `.md` per source file, mirrored subfolders). See [`resources/README.md`](resources/README.md) for the full index.

Bulk note generation deliberately skips `A2Z/`, `derived/`, `MathWorks/`, and `TopInterview150/` — those are problem-solution folders rather than topic explainers.

## Building and running

Each `.cpp` is a self-contained program. Typical build/run:

```sh
g++ -std=c++17 -Wall -Wextra SEC05_Recursion/6_Fact.cpp -o fact
./fact
```

Some files use VLAs or other GCC/Clang extensions — see the per-file notes in `resources/` when compilation fails on MSVC or with `-pedantic-errors`.

## Companion references

- `resources/1_Introduction_To_Recursions.pdf` — recursion slides.
- `resources/DS_ROADMAP.pdf` — course roadmap.

