#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <flight_reservation.h>
#define PROJECT_NAME "Flight Reservation"

/* Prototypes for all the test functions */
void test_(void);
void test_book(void);
void test_cancel(void);
void test_serach(void);
void test_status(void);

/* Start of the application test */
int main()
{

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);

  //Test plans
  CU_add_test(suite, "book", test_book);
  CU_add_test(suite, "cancel", test_cancel);
  CU_add_test(suite, "search", test_search);
  CU_add_test(suite, "status", test_status);

  CU_basic_set_mode(CU_BRM_VERBOSE);

  //unit test
  CU_basic_run_tests();

  //clean resources
  CU_cleanup_registry();

  return 0;
}

/* Write all the test functions */
void test_book(void)
{
  CU_ASSERT("booking successfull" == book("subin", "tvm", "del", 12 - 09 - 2020, 23456));

  /* Dummy fail*/
  CU_ASSERT("booking unsuccessfull" == book());
}

void test_search(void)
{
  CU_ASSERT("Booking found" == book("T-4567"));

  /* Dummy fail*/
  CU_ASSERT("Booking not found" == book("T-4567"));
}

void test_cancel(void)
{
  CU_ASSERT("cancell successfull" == book("T-1234");

  /* Dummy fail*/
  CU_ASSERT("cancell unsuccessfull" == book("T-1234"));
}

void test_status(void)
{
  CU_ASSERT("Ticket is active" == book("T-2345"));

  /* Dummy fail*/
  CU_ASSERT("Ticket is inactive" == book("T-2345"));
}
