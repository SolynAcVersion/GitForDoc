## Description

A CLI git version controlling framework for documents like `.doc` or `.docx` files.

The library for the upcoming *ImGui* UI version of doc's version controlling software.

Validated under *Manjaro*, not sure if satisfying *Windows*.


We actually unzip the doc file and format the `xml` files in the `{fileName}` folder, then version controlling the unzipped one. Much raw but efficient operation. XD


## Current state 

- Version controlling for single `.doc` or `.docx` file
- git `init` / `add` / `commit` / `diff` / `status` / `log` / `reset` / `revert`
- Support for most *Linux* Systems
- Raw output of commands `diff` for changes
- Origin parser by UNIX


## WIP 

- Cross-platform support
- git commands related to `branch`
- Smart analysis of what really changed in doc, not xml in the unzipped one.
- Smarter args parser.

## External commands used:

`echo`
`git`
`xmllint`
`cd`

You **SHOULD** ensure your having this commands available in you terminal (Bash, Zsh, Powershell, Command Prompt, etc.)

## Usage

Use `make` for the compiling.

Then execute:

```Bash
./g4d help
```

for assistance

