
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <string/string.h>

void gen_rand_str(char* rand_str, uint64_t len) {
	for (uint64_t i = 0; i < len; i++) {
		//rand_str[i] = rand() % 127 + 1;
		rand_str[i] = rand() % 95 + 32;
		//rand_str[i] = i % 95 + 32;
		//rand_str[i] = rand() % 26 + 'a';
	}
	rand_str[len] = '\0';
}

void __attribute__((noinline)) naive_to_upper(char* s, uint64_t len) {
	for (uint64_t i = 0; i < len; i++) {
		int8_t rotated = s[i];
		rotated += 0x05;
		rotated &= 0x7f;
		rotated += 0x1a;
		rotated &= ~s[i];
		rotated >>= 2;
		rotated &= 0xe0;
		s[i] += rotated;
	}
}

void __attribute__((noinline)) naive_to_lower(char* s, uint64_t len) {
	for (uint64_t i = 0; i < len; i++) {
		uint8_t rotated = s[i];
		rotated += 0x25;
		rotated &= 0x7f;
		rotated += 0x1a;
		rotated &= ~s[i];
		rotated >>= 2;
		rotated &= 0x20;
		s[i] += rotated;
	}
}

/*
 * calculates the average amount of time each function takes to capitalize
 * random strings of the given length
 */
void calc_avg_times_upper(uint64_t len, uint32_t n_trials, double* naive_s,
		double* my_s, bool verify, uint64_t rand_offset_amt) {
	char* _str = (char*) malloc(len + 1 + rand_offset_amt);
	char* _str1 = (char*) malloc(len + 1 + rand_offset_amt);
	char* _str2 = (char*) malloc(len + 1 + rand_offset_amt);

	struct timespec start1, end1;
	struct timespec start2, end2;

	uint64_t total_ns_1 = 0;
	uint64_t total_ns_2 = 0;

	uint32_t i;
	for (i = 0; i < n_trials / 2; i++) {
		uint64_t rand_offset = rand() % (rand_offset_amt + 1);
		char* str1 = _str1 + rand_offset;
		char* str2 = _str2 + rand_offset;

		gen_rand_str(_str, len);
		strcpy(str1, _str);
		strcpy(str2, _str);

		clock_gettime(CLOCK_MONOTONIC, &start1);
		naive_to_upper(str1, len);
		clock_gettime(CLOCK_MONOTONIC, &end1);

		clock_gettime(CLOCK_MONOTONIC, &start2);
		to_upper(str2, len);
		clock_gettime(CLOCK_MONOTONIC, &end2);

		total_ns_1 += (end1.tv_nsec - start1.tv_nsec) + (end1.tv_sec - start1.tv_sec) * 1000000000;
		total_ns_2 += (end2.tv_nsec - start2.tv_nsec) + (end2.tv_sec - start2.tv_sec) * 1000000000;

		//printf("naive took %f secs\n", (end1.tv_nsec - start1.tv_nsec) / 1000000000. + (end1.tv_sec - start1.tv_sec));
		//printf("mine took  %f secs\n", (end2.tv_nsec - start2.tv_nsec) / 1000000000. + (end2.tv_sec - start2.tv_sec));

		if (verify && strcmp(str1, str2) != 0) {
			printf("orig:  (%p) %s\n", _str1, _str);
			printf("naive: (%p) %s\n", str1, str1);
			printf("mine:  (%p) %s\n", str2, str2);
			abort();
		}
	}

	for (; i < n_trials; i++) {
		uint64_t rand_offset = rand() % (rand_offset_amt + 1);
		char* str1 = _str1 + rand_offset;
		char* str2 = _str2 + rand_offset;

		gen_rand_str(_str, len);
		strcpy(str1, _str);
		strcpy(str2, _str);

		clock_gettime(CLOCK_MONOTONIC, &start2);
		to_upper(str1, len);
		clock_gettime(CLOCK_MONOTONIC, &end2);

		clock_gettime(CLOCK_MONOTONIC, &start1);
		naive_to_upper(str2, len);
		clock_gettime(CLOCK_MONOTONIC, &end1);

		total_ns_1 += (end1.tv_nsec - start1.tv_nsec) + (end1.tv_sec - start1.tv_sec) * 1000000000;
		total_ns_2 += (end2.tv_nsec - start2.tv_nsec) + (end2.tv_sec - start2.tv_sec) * 1000000000;

		//printf("mine took  %f secs\n", (end2.tv_nsec - start2.tv_nsec) / 1000000000. + (end2.tv_sec - start2.tv_sec));
		//printf("naive took %f secs\n", (end1.tv_nsec - start1.tv_nsec) / 1000000000. + (end1.tv_sec - start1.tv_sec));

		if (verify && strcmp(str1, str2) != 0) {
			printf("orig:  (%p) %s\n", _str1, _str);
			printf("naive: (%p) %s\n", str1, str1);
			printf("mine:  (%p) %s\n", str2, str2);
			abort();
		}
	}

	*naive_s = ((double) total_ns_1) / (1000000000. * (double) n_trials);
	*my_s = ((double) total_ns_2) / (1000000000. * (double) n_trials);

	free(_str1);
	free(_str2);
}

/*
 * calculates the average amount of time each function takes to capitalize
 * random strings of the given length
 */
void calc_avg_times_lower(uint64_t len, uint32_t n_trials, double* naive_s,
		double* my_s, bool verify, uint64_t rand_offset_amt) {
	char* _str = (char*) malloc(len + 1 + rand_offset_amt);
	char* _str1 = (char*) malloc(len + 1 + rand_offset_amt);
	char* _str2 = (char*) malloc(len + 1 + rand_offset_amt);

	struct timespec start1, end1;
	struct timespec start2, end2;

	uint64_t total_ns_1 = 0;
	uint64_t total_ns_2 = 0;

	uint32_t i;
	for (i = 0; i < n_trials / 2; i++) {
		uint64_t rand_offset = rand() % (rand_offset_amt + 1);
		char* str1 = _str1 + rand_offset;
		char* str2 = _str2 + rand_offset;

		gen_rand_str(_str, len);
		strcpy(str1, _str);
		strcpy(str2, _str);

		clock_gettime(CLOCK_MONOTONIC, &start1);
		naive_to_lower(str1, len);
		clock_gettime(CLOCK_MONOTONIC, &end1);

		clock_gettime(CLOCK_MONOTONIC, &start2);
		to_lower(str2, len);
		clock_gettime(CLOCK_MONOTONIC, &end2);

		total_ns_1 += (end1.tv_nsec - start1.tv_nsec) + (end1.tv_sec - start1.tv_sec) * 1000000000;
		total_ns_2 += (end2.tv_nsec - start2.tv_nsec) + (end2.tv_sec - start2.tv_sec) * 1000000000;

		//printf("naive took %f secs\n", (end1.tv_nsec - start1.tv_nsec) / 1000000000. + (end1.tv_sec - start1.tv_sec));
		//printf("mine took  %f secs\n", (end2.tv_nsec - start2.tv_nsec) / 1000000000. + (end2.tv_sec - start2.tv_sec));

		if (verify && strcmp(str1, str2) != 0) {
			printf("orig:  (%p) %s\n", _str1, _str);
			printf("naive: (%p) %s\n", str1, str1);
			printf("mine:  (%p) %s\n", str2, str2);
			abort();
		}
	}

	for (; i < n_trials; i++) {
		uint64_t rand_offset = rand() % (rand_offset_amt + 1);
		char* str1 = _str1 + rand_offset;
		char* str2 = _str2 + rand_offset;

		gen_rand_str(_str, len);
		strcpy(str1, _str);
		strcpy(str2, _str);

		clock_gettime(CLOCK_MONOTONIC, &start2);
		to_lower(str1, len);
		clock_gettime(CLOCK_MONOTONIC, &end2);

		clock_gettime(CLOCK_MONOTONIC, &start1);
		naive_to_lower(str2, len);
		clock_gettime(CLOCK_MONOTONIC, &end1);

		total_ns_1 += (end1.tv_nsec - start1.tv_nsec) + (end1.tv_sec - start1.tv_sec) * 1000000000;
		total_ns_2 += (end2.tv_nsec - start2.tv_nsec) + (end2.tv_sec - start2.tv_sec) * 1000000000;

		//printf("mine took  %f secs\n", (end2.tv_nsec - start2.tv_nsec) / 1000000000. + (end2.tv_sec - start2.tv_sec));
		//printf("naive took %f secs\n", (end1.tv_nsec - start1.tv_nsec) / 1000000000. + (end1.tv_sec - start1.tv_sec));

		if (verify && strcmp(str1, str2) != 0) {
			printf("orig:  (%p) %s\n", _str1, _str);
			printf("naive: (%p) %s\n", str1, str1);
			printf("mine:  (%p) %s\n", str2, str2);
			abort();
		}
	}

	*naive_s = ((double) total_ns_1) / (1000000000. * (double) n_trials);
	*my_s = ((double) total_ns_2) / (1000000000. * (double) n_trials);

	free(_str1);
	free(_str2);
}

int main() {
	srand(time(NULL));
	double naive_s, my_s;

	uint64_t max = 65536;

	double n_times[max];
	double m_times[max];

	int sz = max;
	//for (int sz = 16; sz < max; sz += 16) {
		calc_avg_times_upper(sz, 100, &naive_s, &my_s, true, 0);

		/*printf("upper:\n");
		printf("average naive: %.9f\n", naive_s);
		printf("average mine:  %.9f\n", my_s);
		printf("speedup:       %f\n", naive_s / my_s);*/

		n_times[sz / 16] = naive_s;
		m_times[sz / 16] = my_s;
		/*printf("{%d, %f}", sz, (naive_s / my_s));
		if (sz < max - 1) {
			printf(",");
		}
		fflush(stdout);*/
		//usleep(10000);

		calc_avg_times_lower(sz, 200, &naive_s, &my_s, true, 0);

		/*printf("lower:\n");
		printf("average naive: %.9f\n", naive_s);
		printf("average mine:  %.9f\n", my_s);
		printf("speedup:       %f\n", naive_s / my_s);*/

	//}
	/*printf("{{");
	for (int i = 0; i < max / 16; i++) {
		printf("{%d,%.13f}", i * 16, n_times[i]);
		if (i < max - 16) {
			printf(",");
		}
	}
	printf("},");
	printf("{");
	for (int i = 0; i < max / 16; i++) {
		printf("{%d,%.13f}", i * 16, m_times[i]);
		if (i < max - 16) {
			printf(",");
		}
	}
	printf("}}\n");*/
	return 0;
}

