// SPDX-License-Identifier: GPL-2.0
#include <stdlib.h>
#include "../tests.h"

#define BENCH_RUNS 999999

static volatile int cnt;

#ifdef __aarch64__
static void trap_bench(void)
{
	unsigned long val;

	asm("mrs %0, ID_AA64ISAR0_EL1" : "=r" (val));   /* TRAP + ERET */
}
#else
static void trap_bench(void)
{

}
#endif

static int traploop(int argc, const char **argv)
{
	int num_loops = BENCH_RUNS;

	if (argc > 0)
		num_loops = atoi(argv[0]);

	while (1) {
		if ((cnt++) > num_loops)
			break;

		trap_bench();
	}
	return 0;
}

DEFINE_WORKLOAD(traploop);
