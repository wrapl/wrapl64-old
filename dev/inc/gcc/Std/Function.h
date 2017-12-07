#ifndef STD_FUNCTION_H
#define STD_FUNCTION_H

#include <Std/Object.h>

#define RIVA_MODULE StdFunction
#include <Riva-Header.h>

RIVA_STRUCT(argument) {
	StdObject_t *Val;
	StdObject_t **Ref;
};

RIVA_STRUCT(state) {
	void *Run;
	StdFunction_state *Chain;
	void *Resume;
};

RIVA_STRUCT(result) {
	union {
		struct {
			StdObject_t *Val;
			StdObject_t **Ref;
		};
		StdFunction_argument Arg;
	};
	void *State;
};

typedef StdObject_t StdFunction_t;

#define FUNCTION_PARAMS const StdFunction_ct *Fun, unsigned long Count, const StdFunction_argument *Args
#define FUNCTION_ATTRS __attribute__ ((force_align_arg_pointer))

RIVA_STRUCT(ct) {
	const StdType_t *Type;
	StdFunction_result (*Invoke)(FUNCTION_PARAMS);
};

RIVA_STRUCT(checked_ct) {
	const StdType_t *Type;
	StdFunction_result (*Invoke)(FUNCTION_PARAMS);
	int Count;
	const char *File;
	int Line;
};

RIVA_TYPE(CT);
RIVA_TYPE(CheckedCT);

#define RESUME_FIELDS \
	void *Run; \
	StdFunction_state *Chain; \
	void *Resume; \
	StdFunction_result (*Invoke)(StdFunction_state *State);

extern const StdFunction_state StdFunction_Failure[1];
extern const StdFunction_state StdFunction_Message[1];

#define SUCCEED(Val, Ref) return (StdFunction_result) {Val, Ref, 0}
#define SUSPEND(Val, Ref, State) return (StdFunction_result) { Val, Ref, State}
#define FAIL return (StdFunction_result) {0, 0, StdFunction_Failure}
#define SEND(Msg) return (Std$Function) {Msg, 0, StdFunction_Message}

#ifdef DOCUMENTING

#define LOCAL_FUNCTION(ARGS...) LOCAL_FUNCTION(__LINE__, ARGS)
#define GLOBAL_FUNCTION(ARGS...) GLOBAL_FUNCTION(__LINE__, ARGS)

#else

#define LOCAL_FUNCTION(NAME) \
	static FUNCTION_ATTRS StdFunction_result invoke_ ## NAME(FUNCTION_PARAMS); \
	static StdFunction_ct NAME[] = {{StdFunction_CT, invoke_ ## NAME}}; \
	static FUNCTION_ATTRS StdFunction_result invoke_ ## NAME(FUNCTION_PARAMS)

#define GLOBAL_FUNCTION(NAME, TYPE...) \
	static FUNCTION_ATTRS StdFunction_result invoke_ ## NAME(FUNCTION_PARAMS); \
	StdFunction_checked_ct NAME[] = {{StdFunction_CheckedCT, invoke_ ## NAME, 0, __FILE__, __LINE__}}; \
	static FUNCTION_ATTRS StdFunction_result invoke_ ## NAME(FUNCTION_PARAMS)

#define RESUME_FUNCTION(NAME, TYPE) \
	static FUNCTION_ATTRS StdFunction_result resume_ ## NAME(TYPE *State)

#endif

#undef RIVA_MODULE

#endif
