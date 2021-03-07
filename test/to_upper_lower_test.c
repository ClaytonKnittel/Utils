
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] += 'A' - 'a';
		}
	}
}

void __attribute__((noinline)) naive_to_lower(char* s, uint64_t len) {
	for (uint64_t i = 0; i < len; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 'a' - 'A';
		}
	}
}

/*
 * calculates the average amount of time each function takes to capitalize
 * random strings of the given length
 */
void calc_avg_times_upper(uint64_t len, uint32_t n_trials, float* naive_s,
		float* my_s, bool verify, uint64_t rand_offset_amt) {
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

	*naive_s = (float) (((double) total_ns_1) / (1000000000. * (double) n_trials));
	*my_s = (float) (((double) total_ns_2) / (1000000000. * (double) n_trials));

	free(_str1);
	free(_str2);
}

/*
 * calculates the average amount of time each function takes to capitalize
 * random strings of the given length
 */
void calc_avg_times_lower(uint64_t len, uint32_t n_trials, float* naive_s,
		float* my_s, bool verify, uint64_t rand_offset_amt) {
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

	*naive_s = (float) (((double) total_ns_1) / (1000000000. * (double) n_trials));
	*my_s = (float) (((double) total_ns_2) / (1000000000. * (double) n_trials));

	free(_str1);
	free(_str2);
}

int main() {
	srand(time(NULL));
	float naive_s, my_s;
	calc_avg_times_upper(100000, 200, &naive_s, &my_s, true, 31);

	printf("upper:\n");
	printf("average naive: %f\n", naive_s);
	printf("average mine:  %f\n", my_s);
	printf("speedup:       %f\n", naive_s / my_s);

	calc_avg_times_upper(100000, 200, &naive_s, &my_s, true, 31);

	printf("lower:\n");
	printf("average naive: %f\n", naive_s);
	printf("average mine:  %f\n", my_s);
	printf("speedup:       %f\n", naive_s / my_s);
	return 0;
}
