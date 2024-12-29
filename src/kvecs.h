
typedef struct {
    unsigned int signed : 1;
    unsigned long long integer;
    unsigned long long decimal;
} kv_Number;

typedef struct {
    char * ptr;
    unsigned long len;
} kv_String;

typedef struct {
    unsigned int value : 1;
} kv_Boolean;

/* Main types */
typedef union {
    kv_Number number;
    kv_String string;
    kv_Boolean boolean;
} kv_Value;

typedef enum {
    kv_Tag_NUMBER, 
    kv_Tag_STRING, 
    kv_Tag_BOOLEAN, 
} kv_Tag;

typedef struct {
    kv_Tag tag;
    kv_Value value;
} kv_TaggedValue;

/*Sparse File*/


