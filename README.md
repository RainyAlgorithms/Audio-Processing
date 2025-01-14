# Audio Processing Tools

## Contributors
This project was collaboratively developed by:
- Esha Pakalapati
- Rayan Itani
- Sahaj Malavia

## Overview
This repository contains two audio processing programs written in C, created as part of the **CSC209: Software Tools and Systems Programming** course at the University of Toronto:
1. `addecho.c` - Adds an echo effect to a WAV audio file.
2. `remvocals.c` - Attempts to remove vocals from a stereo WAV audio file.

### Program Details

#### 1. Add Echo (`addecho.c`)
This program applies an echo effect to a WAV file by:
- Introducing a delay.
- Scaling the volume of the echo effect.

**Key Features:**
- Adjustable delay (`-d`) in samples.
- Adjustable volume scaling factor (`-v`) for the echo.

**Usage:**
```bash
./addecho -d <delay> -v <volume_scale> <sourcewav> <destwav>
```

**Example:**
```bash
./addecho -d 8000 -v 4 input.wav output.wav
```

#### 2. Remove Vocals (`remvocals.c`)
This program removes vocals from a stereo WAV file by:
- Subtracting the right channel from the left channel.
- Writing the resulting mono audio data to both channels of the output file.

**Usage:**
```bash
./remvocals <sourcewav> <destwav>
```

**Example:**
```bash
./remvocals input.wav output.wav
```

## Requirements
- C Compiler (e.g., GCC)
- WAV files with the appropriate format:
  - `addecho.c`: Header size of 22 (shorts).
  - `remvocals.c`: Header size of 44 (bytes), stereo input.

## Compilation
To compile the programs:
```bash
gcc addecho.c -o addecho
gcc remvocals.c -o remvocals
```

## Notes
- Ensure input WAV files match the expected format.
- For `addecho.c`, an echo buffer is dynamically allocated based on the specified delay.
- For `remvocals.c`, stereo input is necessary for the vocal removal algorithm to function correctly.
