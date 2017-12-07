#ifndef STD_TYPE_H
#define STD_TYPE_H

#define RIVA_MODULE StdType
#include <Riva-Header.h>

RIVA_STRUCT(t) {

};

RIVA_TYPE(T);

#define LEVELS_1 {1, 0}
#define LEVELS_2 {2, 0, 1}
#define LEVELS_3 {3, 0, 1, 2}
#define LEVELS_4 {4, 0, 1, 2, 3}
#define LEVELS_5 {5, 0, 1, 2, 3, 4}
#define LEVELS_6 {6, 0, 1, 2, 3, 4, 5}
#define LEVELS_7 {7, 0, 1, 2, 3, 4, 5, 6}
#define LEVELS_8 {8, 0, 1, 2, 3, 4, 5, 6, 7}
#define LEVELS_9 {9, 0, 1, 2, 3, 4, 5, 6, 7, 8}
#define LEVELS_10 {10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
#define LEVELS_11 {11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
#define LEVELS_12 {12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
#define LEVELS_13 {13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
#define LEVELS_14 {14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
#define LEVELS_15 {15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
#define LEVELS_16 {16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
#define LEVELS_17 {17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
#define LEVELS_18 {18, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}
#define LEVELS_19 {19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}
#define LEVELS_20 {20, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}

#define TYPE(NAME, PARENTS...)\
	extern const StdType_t NAME[];\
	static const StdType_t *NAME ## _parents[] = {NAME, ## PARENTS, 0};\
	static const StdArray_t NAME ## _fields[] = {{\
		StdArray_T, 0,\
		{StdInteger_SmallT, 0}\
	}};\
	static unsigned long NAME ## _levels[] = __concat(LEVELS_, PP_NARG(NAME, ## PARENTS));\
	const StdType_t NAME[] = {{\
		StdType_T, \
		NAME ## _parents, \
		StdType_default_invoke, \
		NAME ## _fields, \
		NAME ## _levels\
	}}

#define __strip(FIELDS...) FIELDS

#define TYPEF(NAME, FIELDS, PARENTS...)\
	extern const StdType_t NAME[];\
	static const StdType_t *NAME ## _parents[] = {NAME, ## PARENTS, 0};\
	static StdObject_t * const NAME ## _fields[] = {__strip FIELDS};\
	static const StdArray_t NAME ## _fields_array[] = {{\
		StdArray_T, (StdObject_t **)NAME ## _fields,\
		{StdInteger_SmallT, PP_NARG FIELDS}\
	}};\
	static unsigned long NAME ## _levels[] = __concat(LEVELS_, PP_NARG(NAME, ## PARENTS));\
	const StdType_t NAME[] = {{\
		StdType_T, \
		NAME ## _parents, \
		StdType_default_invoke, \
		NAME ## _fields_array, \
		NAME ## _levels\
	}}

#undef RIVA_MODULE

#endif
