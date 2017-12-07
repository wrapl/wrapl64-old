#ifndef RIVA64_H
#define RIVA64_H

#define RIVA_VERSION 4

enum {
    SECT_GENERIC,
	SECT_TEXT,
	SECT_DATA,
	SECT_LIBRARY,
	SECT_IMPORT,
	SECT_BSS,
	SECT_SYMBOL,
	SECT_CONSTANT,
	SECT_INITIAL,
	SECT_METHODS,
	SECT_TYPEDFN,
	SECT_MODULE,
	SECT_TDATA,
	SECT_TBSS,
	SECT_GOT
};

typedef struct riva64_header_t {
	unsigned int Riva : 32;
	unsigned int Version : 32;
	unsigned int Flags : 8;
	unsigned int NoOfSections : 24;
	unsigned int NoOfExports : 32;
} riva64_header_t;

typedef struct riva64_relocation_t {
	unsigned int Size : 4;
	unsigned int Flags : 4;
	unsigned int Section : 24;
	unsigned int Position : 32;
} riva64_relocation_t;

#define RELOC_SIZE_1		0
#define RELOC_SIZE_2		1
#define RELOC_SIZE_4		2
#define RELOC_SIZE_8		3

#define RELOC_ABS			0
#define RELOC_REL			1
#define RELOC_IND			2
#define RELOC_GOT			3

#define LIBRARY_ABS			0
#define LIBRARY_REL			1
#define LIBRARY_REQ			2

#define FLAG_GC				1
#define FLAG_DELAY			2

#endif
