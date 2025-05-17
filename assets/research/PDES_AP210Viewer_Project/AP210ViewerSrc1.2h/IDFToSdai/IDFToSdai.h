// IDFToSdai.h: interface for the IDFToSdai class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IDFTOSDAI_H__8403F442_70CB_11D3_817E_00C04FEDCEC8__INCLUDED_)
#define AFX_IDFTOSDAI_H__8403F442_70CB_11D3_817E_00C04FEDCEC8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

typedef struct yy_buffer_state *YY_BUFFER_STATE;
typedef int yy_state_type;
typedef unsigned int yy_size_t;

#ifdef YY_USE_CONST
#define yyconst const
#else
#define yyconst
#endif

class IDFToSdai  
{
private:
	YY_BUFFER_STATE yy_scan_string( yyconst char *yy_str );
	static void yy_flush_buffer( YY_BUFFER_STATE b );
	static void yy_init_buffer( YY_BUFFER_STATE b, FILE *file );
	void yy_delete_buffer( YY_BUFFER_STATE b );
	static YY_BUFFER_STATE yy_create_buffer( FILE *file, int size );
	YY_BUFFER_STATE yy_scan_buffer( char *base, yy_size_t size );
	void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
	static int yyleng;
	void yyunput( int c, register char *yy_bp );
	static yy_state_type yy_get_previous_state();
	static char * yytext;
	static int yywrap();
	static void yy_load_buffer_state( void );
	static void yyrestart( FILE *input_file );
	int yyinput();
	static int yy_get_next_buffer();
	static FILE * yyout;
	static int yylex(void);
	static void yyerror(char *error);
	static int yychar;
	static int yynerrs;
	static void MTKsdaiInsertAfterBN(SdaiInstance instance, char *attribute_name, SdaiPrimitiveType type, SdaiInstance attribute);
	static int yydebug;
	static int yyparse(void);
	static char * OriginatingSystem;
	static FILE * yyin;
	static char * second_file;
	static char * current_file;
	static SdaiModel myModel;
	IDFToSdai();
public:
	static int parseIDF(char *designname, SdaiModel IDFModel);
	virtual ~IDFToSdai();

};

#endif // !defined(AFX_IDFTOSDAI_H__8403F442_70CB_11D3_817E_00C04FEDCEC8__INCLUDED_)
