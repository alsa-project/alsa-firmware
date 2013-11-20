/*
 * 32bit LE only
 */

#include <stdio.h>

#define DSP_MAX_SYMBOL_NAME 100
typedef unsigned int u32;

struct dsp_symbol_entry {
	unsigned int address;
	char symbol_name[DSP_MAX_SYMBOL_NAME];
	int symbol_type;
};

struct dsp_segment_desc {
	int segment_type;
	unsigned int offset;
	unsigned int size;
	u32 *data;
};

struct dsp_symbol_desc {
	int nsymbols;
	struct dsp_symbol_entry *symbols;
};

struct dsp_module_desc {
	char * module_name;
	struct dsp_symbol_desc symbol_table;
	int nsegments;
	struct dsp_segment_desc * segments;
};

#define SEGTYPE_SP_PROGRAM              0x00000001
#define SEGTYPE_SP_PARAMETER            0x00000002
#define SEGTYPE_SP_SAMPLE               0x00000003
#define SEGTYPE_SP_COEFFICIENT          0x00000004


#include "cwc4630.h"
#include "cwcasync.h"
#include "cwcbinhack.h"
#include "cwcdma.h"
#include "cwcsnoop.h"

/* 3*1024 parameter, 3.5*1024 sample, 2*3.5*1024 code */
#define BA1_DWORD_SIZE		(13 * 1024 + 512)
#define BA1_MEMORY_COUNT	3

#include "cs46xx_image.h"

int main(int argc, char **argv)
{
	struct dsp_module_desc *desc;
	static struct dsp_module_desc *list[] = {
		&cwc4630_module,
		&cwcasync_module,
		&cwcbinhack_module,
		&cwcdma_module,
		&cwcsnoop_module,
	};
	static const char *names[] = {
		"cwc4630", "cwcasync", "cwcbinhack", "cwcdma", "cwcsnoop"
	};
	FILE *fp;
	int i, n;

	for (n = 0; n < 5; n++) {
		fp = fopen(names[n], "w");
		if (!fp)
			return 1;
		desc = list[n];
		fwrite(&desc->symbol_table.nsymbols, 4, 1, fp);
		fwrite(desc->symbol_table.symbols, sizeof(struct dsp_symbol_entry), desc->symbol_table.nsymbols, fp);
		fwrite(&desc->nsegments, 4, 1, fp);
		for (i = 0; i < desc->nsegments; i++) {
			fwrite(&desc->segments[i], 4, 3, fp);
			fwrite(desc->segments[i].data, 4, desc->segments[i].size, fp);
		}
		fclose(fp);
	}

	fp = fopen("ba1", "w");
	if (!fp)
		return 1;
	fwrite(&BA1Struct, sizeof(BA1Struct), 1, fp);
	fclose(fp);

	return 0;
}
