#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char buf[256];
	int data, c, idx, length;
	unsigned char *imgbuf = NULL;
	char *p;

	c = 0;
	data = 0;
	idx = 0;
	length = 0;
	while (fgets(buf, sizeof(buf), stdin)) {
		if (strncmp(buf, "Bits:", 5) == 0) {
			for (p = buf + 5; *p && isspace(*p); p++)
				;
			if (! *p) {
				fprintf(stderr, "corrupted file in Bits line\n");
				return 1;
			}
			length = atoi(p);
			length /= 8;
			if (length <= 0) {
				fprintf(stderr, "corrupted file, detected length = %d\n", length);
				return 1;
			}
			imgbuf = malloc(length);
			if (! imgbuf) {
				fprintf(stderr, "cannot alloc %d bytes\n", length);
				return 1;
			}
			continue;
		}
		if (buf[0] != '0' && buf[1] != '1')
			continue;
		if (length <= 0) {
			fprintf(stderr, "corrupted file, starting without Bits line\n");
			return 1;
		}
		for (p = buf; *p == '0' || *p == '1'; p++) {
			data |= (*p - '0') << c;
			c++;
			if (c >= 8) {
				imgbuf[idx] = data;
				data = 0;
				c = 0;
				idx++;
				if (idx >= length)
					break;
			}
		}
	}
	if (c)
		imgbuf[idx++] = data;
	if (idx != length) {
		fprintf(stderr, "length doesn't match: %d != %d\n", idx, length);
		return 1;
	}

	for (idx = 0; idx < length; idx++)
		putchar(imgbuf[idx]);

	return 0;
}
