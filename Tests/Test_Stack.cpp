
/* Created By: Anonyman637
 * Created On: 8/12/2020; 7:16 AM
 */

#include <gtest/gtest.h>


#include "../lib/src/DataStruct/node.c"
#include "../lib/src/DataStruct/stack.c"
#include "../lib/src/exception.c"


class StackTest : public ::testing::Test {

protected:
	void TearDown() override {
		destroy(stack);
	}
	
	void SetUp() override {
		stack = init();
		// Lets push some data into the stack
		push(stack, 7);
		push(stack, 3);
		push(stack, 2);
		push(stack, 5);
		
		// We will check the return values and not fatal
		setDefaultExceptionHandlerFatality(VERBOSE);
	}
	
	Stack *stack;
};


TEST_F(StackTest, Size) {
	// As far as we know the size should be 4
	EXPECT_EQ(size(stack), 4);
	
	// Lets pop some value and check the size again
	pop(stack);
	pop(stack);
	pop(stack);
	
	// There should only one left to tell the tale
	EXPECT_EQ(size(stack), 1);
	
	traverse(stack);
}


TEST_F(StackTest, Empty) {
	// The stack is not empty now
	EXPECT_FALSE(empty(stack));
	
	// Lets pop some data
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	
	// It should now be empty
	EXPECT_TRUE(empty(stack));
}


TEST_F(StackTest, PopTop) {
	// Lets check the top data
	EXPECT_EQ(top(stack), 5);
	
	// Lets pop some data and check the stack again
	pop(stack);
	pop(stack);
	EXPECT_EQ(top(stack), 3);
	
	traverse(stack);
	
	// Lets pop some more
	pop(stack);
	pop(stack);
	
	// There shouldn't be anything in the stack
	ASSERT_EQ(top(stack), INDEX_OUT_OF_BOUNDS);
	
	// And we can't also pop more
	ASSERT_EQ(pop(stack), INDEX_OUT_OF_BOUNDS);
}

