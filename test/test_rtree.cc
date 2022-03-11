
/**********************************************************
 *                       Includes                         *
 **********************************************************/

#include <fcntl.h>

#include <iostream>

#include <utils/data_structs/rtree.h>

#include "test_utils.h"


/**********************************************************
 *                 Silence Test Fixtures                  *
 **********************************************************/

static int stderr_tmp;
static int dev_null_fd;

static void
silence_stderr_setup(void)
{
	stderr_tmp = dup(STDERR_FILENO);
	dev_null_fd = open("/dev/null", O_WRONLY);
	dup2(dev_null_fd, STDERR_FILENO);
}

static void
silence_stderr_teardown(void)
{
	dup2(stderr_tmp, STDERR_FILENO);
	close(stderr_tmp);
	close(dev_null_fd);
}


/**********************************************************
 *                       Test Init                        *
 **********************************************************/

class El : public Utils::RTreeEl {
public:
	uint32_t id;

	El(uint32_t id, const Utils::RTreeRect& rect) : Utils::RTreeEl(rect), id(id) {}
};

START_TEST(test_init_half_min)
{
	Utils::RTree tree(2, 4);
	tree.Validate();
}


/**********************************************************
 *                      Test Suite                        *
 **********************************************************/

Suite*
test_rtree_cc()
{
	TCase* tc_init;

	Suite* s = suite_create("R* tree C++");

	tc_init = tcase_create("Init");
	tcase_add_checked_fixture(tc_init, silence_stderr_setup,
			silence_stderr_teardown);
	tcase_add_test(tc_init, test_init_half_min);
	suite_add_tcase(s, tc_init);

	return s;
}

