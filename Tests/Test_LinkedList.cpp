/* Created By: Anonyman637
 * Created On: 8/12/2020; 2:31 PM
 */


#include <gtest/gtest.h>

#include "../lib/src/DataStruct/node.c"
#include "../lib/src/exception.c"


class LLTest : public ::testing::Test {

protected:
	void TearDown() override {
		destroy(ll);
	}
	
	void SetUp() override {
		ll = (LinkedList *) init();
		append(ll, 5);
		append(ll, 2);
		append(ll, 3);
		append(ll, 7);
		
		// We will check the return values and not fatal
		setDefaultExceptionHandlerFatality(VERBOSE);
	}
	
	LinkedList *ll;
};


TEST_F(LLTest, Get) {
	// We already appended three data in setup, lets check those in order
	EXPECT_EQ(get(ll, 0), 5);
	EXPECT_EQ(get(ll, 1), 2);
	EXPECT_EQ(get(ll, 2), 3);
	EXPECT_EQ(get(ll, 3), 7);
	
	// Now lets test with reverse index
	EXPECT_EQ(get(ll, -1), 7);
	EXPECT_EQ(get(ll, -2), 3);
	EXPECT_EQ(get(ll, -3), 2);
	EXPECT_EQ(get(ll, -4), 5);
	
	traverse(ll);
	
	// Lets test forbidden things
	ASSERT_EQ(get(ll, 4), INDEX_OUT_OF_BOUNDS);
	ASSERT_EQ(get(ll, -10), INDEX_OUT_OF_BOUNDS);
	ASSERT_EQ(get(nullptr, -10), INVALID_POINTER);
}


TEST_F(LLTest, Size) {
	// The expected size should be 4
	EXPECT_EQ(size(ll), 4);
	// After this size should be 5
	append(ll, 6);
	EXPECT_EQ(size(ll), 5);
	
	traverse(ll);
	
	// Lets test forbidden things
	ASSERT_EQ(size(nullptr), -1);
}


TEST_F(LLTest, Empty) {
	// The list is not empty now
	EXPECT_FALSE(empty(ll));
	
	// Lets erase some data
	erase(ll, 0);
	erase(ll, -1);
	erase(ll, 0);
	erase(ll, -1);
	
	// It should now be empty
	EXPECT_TRUE(empty(ll));
}


TEST_F(LLTest, Insert) {
	// We will insert data into the head
	insert(ll, 0, 55);
	EXPECT_EQ(get(ll, 0), 55);
	
	// We will insert data at the very end which is same as append
	insert(ll, -1, 77);
	EXPECT_EQ(get(ll, 0), 55);
	
	traverse(ll);
	
	// Lets insert some data in the middle
	insert(ll, 2, 22);
	EXPECT_EQ(get(ll, 2), 22);
	insert(ll, -3, 33);
	EXPECT_EQ(get(ll, -3), 33);
	
	traverse(ll);
	
	// Lets insert into non-existent indexes
	ASSERT_EQ(insert(ll, 100, 100), INDEX_OUT_OF_BOUNDS);
	ASSERT_EQ(insert(ll, -(size(ll) + 1), 99), INDEX_OUT_OF_BOUNDS);
}


TEST_F(LLTest, Erase) {
	// Lets erase the head and the tail
	erase(ll, 0);
	erase(ll, -1);
	
	// Now size should be 2
	EXPECT_EQ(size(ll), 2);
	
	// Lets test the remaining values
	EXPECT_EQ(get(ll, 0), 2);
	EXPECT_EQ(get(ll, -1), 3);
	
	traverse(ll);
	
	// Lets try to erase something that dont exist
	ASSERT_EQ(erase(ll, 10), INDEX_OUT_OF_BOUNDS);
}


TEST_F(LLTest, Set) {
	// Lets change some values
	set(ll, 0, 0);
	set(ll, 1, 6);
	set(ll, -2, 3);
	set(ll, -1, 7);
	
	// Lets see if the values are in right place
	EXPECT_EQ(get(ll, 0), 0);
	EXPECT_EQ(get(ll, 1), 6);
	EXPECT_EQ(get(ll, 2), 3);
	EXPECT_EQ(get(ll, 3), 7);
	
	traverse(ll);
	
	// Lets try to modify something that dont exist
	ASSERT_EQ(set(ll, -10, 10), INDEX_OUT_OF_BOUNDS);
}

