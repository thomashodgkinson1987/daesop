# daesop

> **Note:** This project is a continuation of work by several contributors over many years. The source code was originally ported from 16-bit DOS to 32-bit DOS, then to modern 64-bit systems.
>
> **AI Contribution:** This `README.md` was AI-generated. AI has been an instrumental partner in the modernisation, refactoring, and documentation of this project.

`daesop` is a specialised decompiler and resource manipulation tool designed for the AESOP engine, famously used in retro titles such as *Eye of the Beholder 3* and *Dungeon Hack*. It provides a suite of tools for reverse engineering `.RES` files, disassembling bytecode, and converting legacy assets.

## History & Credits

This project modernises the `daesop` utility, which has a long history in the retro-gaming and reverse-engineering communities.

- **John Miles**: The original creator of the AESOP engine (AESOP/16 and AESOP/32) and the AIL/VFX libraries. He graciously released the engine's compiler and documentation into the public domain in 2009.
- **John Ratcliff**: Co-developer and creator of the `MOD32SND` sound mixer used by the engine.
- **mirekluza**: The original author of the `daesop` utility and the driving force behind the [AESOP/32 modernisation project on VOGONS](https://www.vogons.org/viewtopic.php?t=20601).
- **Bret Curtis ([psi29a](https://github.com/psi29a))**: For his work on the [thirdeye](https://github.com/psi29a/thirdeye/) project, which served as a valuable reference for modernising AESOP tools.

The current version of this tool is a direct cross-platform port of the original 32-bit DOS source code.

## Features

- **Bytecode Disassembly:** Full disassembly of AESOP engine bytecode using a configurable instruction set definition.
- **Resource Extraction:** Extract individual or all resources from `.RES` containers.
- **Legacy Conversions:** Specialised support for converting "EOB 3 style" bitmaps and fonts.
- **Resource Management:** Inspect, replace, or patch resources within existing engine files.
- **AESOP/32 Compatibility:** Includes patches to help migrate resources to work with AESOP/32.

## License

This project is licensed under the **MIT License**. This applies to the modern port and any new modifications. The original AESOP/32 definitions and documentation were released into the public domain by John Miles.

See the `LICENSE` file for the full license text.

## Project Structure

- `src/`: Core logic and disassembler source files (C17).
- `data/`: Contains `bytecode.def`, which defines the engine's opcode mappings.
- `bin/`: Output directory for the compiled executable.
- `dist/`: Output directory for packaged releases.

## Getting Started

### Prerequisites

- A C compiler supporting the **C17** standard (e.g., GCC or Clang).
- **GNU Make** installed on your system.

### Building

To compile the project and generate the executable in the `bin/` directory:

```bash
make build
```

### Packaging

Since the tool requires `bytecode.def` to be present in the same directory as the executable to function correctly, use the package target to create a ready-to-use distribution:

```bash
make package
```

To create a versioned tarball for distribution:

```bash
make release
```
This will create a `dist/` directory containing both the `daesop` binary and the required `bytecode.def` file.

## Usage

The basic syntax for the tool is:

```bash
./bin/daesop <main_option> <res_file> [extra_options] <output_file>
```

### Common Commands

- **Get File Info:**
  `./bin/daesop -i EYE.RES info.txt`
- **Extract a Resource:**
  `./bin/daesop -e <resource_name> sample.res output.bin`
- **Extract All Resources:**
  `./bin/daesop -extract sample.res ./output_dir/`
- **Convert EOB3 Resources:**
  `./bin/daesop -eob3conv EYE.RES eye_fixed.res`
