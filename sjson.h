#ifndef __SJSON_H__
#define __SJSON_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* SJSON Types: */
#define SJSON_FALSE			0
#define SJSON_TRUE			1
#define SJSON_NULL			2
#define SJSON_NUMBER		3
#define SJSON_STRING		4
#define SJSON_ARRAY			5
#define SJSON_OBJECT		6

int SJSON_IsValid(char *json);
void SJSON_Minify(char *json);
int SJSON_Type(char *value);
int SJSON_ObjStrcmp(const char *obj, const char *name);
char *SJSON_ParseString(char *value, char *out, int len);
char *SJSON_ParseNum(char *value, double *out);

char *SJSON_ObjToNext(char *obj, int *type, char **end);
char *SJSON_ObjToValue(char *obj, int *type, char **end);

char *SJSON_ToIdxObj(char *value, unsigned idx, int *type, char **end);
char *SJSON_ToIdxObjValue(char *value, unsigned idx, int *type, char **end);
char *SJSON_ToObj(char *value, const char *name, int *type, char **end);
char *SJSON_ToObjValue(char *value, const char *name, int *type, char **end);
char *SJSON_ToArrayValue(char *value, unsigned idx, int *type, char **end);
char *SJSON_ToPathValue(char *value, const char *path, int *type, char **end);
char *SJSON_FindObjValue(char *value, const char *name, int *type, char **end);

char *SJSON_CreateRootObj(char *buf, char *end);
int SJSON_ObjSize(char *value);
char *SJSON_ObjAddString(char *buf, char *end, const char *name, const char* valueStr);
char *SJSON_ObjAddNum(char *buf, char *end, const char *name, double d);
char *SJSON_ObjAddTrue(char *buf, char *end, const char *name);
char *SJSON_ObjAddFalse(char *buf, char *end, const char *name);
char *SJSON_ObjAddNull(char *buf, char *end, const char *name);
char *SJSON_ObjAddObj(char *buf, char *end, const char *name);
char *SJSON_ObjAddArray(char *buf, char *end, const char *name);
int SJSON_ArraySize(char *value);
char *SJSON_ArrayAddString(char *buf, char *end, const char* valueStr);
char *SJSON_ArrayAddNum(char *buf, char *end, double d);
char *SJSON_ArrayAddTrue(char *buf, char *end);
char *SJSON_ArrayAddFalse(char *buf, char *end);
char *SJSON_ArrayAddNull(char *buf, char *end);
char *SJSON_ArrayAddObj(char *buf, char *end);
char *SJSON_ArrayAddArray(char *buf, char *end);

#ifdef __cplusplus
}
#endif

#endif // __SJSON_H__
