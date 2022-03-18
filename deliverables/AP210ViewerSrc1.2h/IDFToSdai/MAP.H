typedef union
{
char charval;
char *SdaiString;
char *SdaiEnumeration;
double SdaiReal;
int SdaiInteger;
struct Sdai_Id* SdaiInstance;
struct InstanceList *List;
struct OutlineAndCutouts *OutlineAndCutouts;
} YYSTYPE;
#define	STRING	258
#define	RAWREAL	259
#define	RAWINTEGER	260
#define	START_HEADER	261
#define	END_HEADER	262
#define	BOARD_FILE	263
#define	MM	264
#define	TNM	265
#define	THOU	266
#define	TOP	267
#define	BOTTOM	268
#define	BOTH	269
#define	ALL	270
#define	PTH	271
#define	NPTH	272
#define	BOARD	273
#define	NOREFDES	274
#define	FIXED	275
#define	UNPLACED	276
#define	PLACED	277
#define	START_BOARD_OUTLINE	278
#define	END_BOARD_OUTLINE	279
#define	START_OTHER_OUTLINE	280
#define	END_OTHER_OUTLINE	281
#define	START_ROUTE_OUTLINE	282
#define	END_ROUTE_OUTLINE	283
#define	START_PLACE_OUTLINE	284
#define	END_PLACE_OUTLINE	285
#define	START_ROUTE_KEEPOUT	286
#define	END_ROUTE_KEEPOUT	287
#define	START_VIA_KEEPOUT	288
#define	END_VIA_KEEPOUT	289
#define	START_PLACE_KEEPOUT	290
#define	END_PLACE_KEEPOUT	291
#define	START_PLACE_REGION	292
#define	END_PLACE_REGION	293
#define	START_DRILLED_HOLES	294
#define	END_DRILLED_HOLES	295
#define	START_PLACEMENT	296
#define	END_PLACEMENT	297
#define	LIBRARY_FILE	298
#define	START_ELECTRICAL	299
#define	END_ELECTRICAL	300
#define	START_MECHANICAL	301
#define	END_MECHANICAL	302


extern YYSTYPE yylval;
