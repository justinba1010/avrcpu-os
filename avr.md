# Compile Assembly to Object File

```
ASFLAGS= -g -Os -Wa,--no-pad-sections -DF_CPU=FREQ -mrelax -Iinclude --mmcu=atmega1284 -x assembler-with-cpp
avr-gcc ASFLAGS -include c_headers.h -c assembly.s -o build/assembly.o
```

# Compile C to Object File

```
CFLAGS="-g -Os -Wa,--no-pad-sections -DF_CPU=FREQ -include headers.h -Iinclude -mmcu=atmega1284 -mrelax -c"
avr-gcc CFLAGS file.c -o build/file.o
```

# Read Object File Headers

```
avr-objdump -h file.o
```

# Read Disassembly

```
avr-objdump =k .text -d output
```
