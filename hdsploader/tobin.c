#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <endian.h>

#include "digiface_firmware.dat"
#include "digiface_firmware_rev11.dat"
#include "multiface_firmware.dat"
#include "multiface_firmware_rev11.dat"

int write_bin_file(u_int32_t *array, const char *filename)
{
	FILE *out;
	
	if ((out = fopen(filename, "w+")) == NULL)
		return -1;
#if __BYTE_ORDER == __BIG_ENDIAN
	{
		unsigned int idx;
		for (idx = 0; idx < 24413; idx++)
			array[idx] = ((array[idx] & 0x000000ff) << 16) |
				     ((array[idx] & 0x0000ff00) << 8)  |
				     ((array[idx] & 0x00ff0000) >> 8)  |
				     ((array[idx] & 0xff000000) >> 16);
	}
#endif
	if (fwrite(array, 4, 24413, out) != 24413) {
		fclose(out);
		return -1;
	}
	fclose(out);
	return 0;
}

int main(void)
{
	if (write_bin_file(digiface_firmware, "digiface_firmware.bin"))
		return EXIT_FAILURE;
	if (write_bin_file(digiface_firmware_rev11, "digiface_firmware_rev11.bin"))
		return EXIT_FAILURE;
	if (write_bin_file(multiface_firmware, "multiface_firmware.bin"))
		return EXIT_FAILURE;
	if (write_bin_file(multiface_firmware_rev11, "multiface_firmware_rev11.bin"))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
