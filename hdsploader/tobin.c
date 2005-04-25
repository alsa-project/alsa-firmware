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
