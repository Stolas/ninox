#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "gpio.h"

int gpio_init()
{
	int mem_fd;
	void *gpio_map;

	if(gpio != NULL) {
		return EXIT_FAILURE;
	}

	if((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
		return EXIT_FAILURE;
	}

	gpio_map = mmap(NULL, BLOCK_SIZE, PROT_READ|PROT_WRITE,
			MAP_SHARED, mem_fd, GPIO_BASE);
	close(mem_fd);

	if(gpio_map == MAP_FAILED) {
		return EXIT_FAILURE;
	}
	gpio = (volatile unsigned*)gpio_map;
	return EXIT_SUCCESS;
}
